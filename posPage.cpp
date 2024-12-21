#include "posPage.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDateEdit>

POSPage::POSPage(QWidget *parent)
    : QWidget(parent), total(0.0) {

    // Set the window title
    setWindowTitle("Point of Sale");

    QLabel *pageTitle = new QLabel("Payments and Billing", this);
    QFont titleFont = pageTitle->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    pageTitle->setFont(titleFont);
    pageTitle->setAlignment(Qt::AlignCenter);

    // Create input fields
    itemNameInput = new QLineEdit(this);
    itemPriceInput = new QLineEdit(this);
    itemQuantityInput = new QLineEdit(this);
    itemDescriptionInput = new QLineEdit(this);  // Add Description input field
    itemDateInput = new QDateEdit(QDate::currentDate(), this);

    // Create table
    itemTable = new QTableWidget(this);
    itemTable->setColumnCount(6); // Updated to 6 columns
    itemTable->setHorizontalHeaderLabels({"Date", "Name", "Price", "Quantity", "Description", "Total"}); // Reordered headers
    itemTable->horizontalHeader()->setStretchLastSection(true);

    // Create buttons
    QPushButton *addItemButton = new QPushButton("Add Item", this);
    connect(addItemButton, &QPushButton::clicked, this, &POSPage::addItem);

    QPushButton *checkoutButton = new QPushButton("Checkout", this);
    connect(checkoutButton, &QPushButton::clicked, this, &POSPage::checkout);

    // Create total label
    totalLabel = new QLabel("Total: 0.00", this);

    // Layout setup
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Add page title to main layout
    mainLayout->addWidget(pageTitle);

    // Input layout
    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(new QLabel("Date:"));
    inputLayout->addWidget(itemDateInput);
    inputLayout->addWidget(new QLabel("Name:"));
    inputLayout->addWidget(itemNameInput);
    inputLayout->addWidget(new QLabel("Price:"));
    inputLayout->addWidget(itemPriceInput);
    inputLayout->addWidget(new QLabel("Quantity:"));
    inputLayout->addWidget(itemQuantityInput);
    inputLayout->addWidget(new QLabel("Description:"));  // Add label for description
    inputLayout->addWidget(itemDescriptionInput);  // Add description input field
    inputLayout->addWidget(addItemButton);

    // Bottom layout
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(totalLabel);
    bottomLayout->addWidget(checkoutButton);

    // Add layouts to main layout
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(itemTable);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}

void POSPage::addItem() {
    QDate date = itemDateInput->date();
    QString name = itemNameInput->text();
    double price = itemPriceInput->text().toDouble();
    int quantity = itemQuantityInput->text().toInt();
    double totalItem = price * quantity;
    QString description = itemDescriptionInput->text(); // Get the description text

    if (name.isEmpty() || price <= 0 || quantity <= 0) {
        QMessageBox::warning(this, "Input Error", "Please provide valid inputs.");
        return;
    }

    // Add item to the table
    int row = itemTable->rowCount();
    itemTable->insertRow(row);
    itemTable->setItem(row, 0, new QTableWidgetItem(date.toString())); // Date
    itemTable->setItem(row, 1, new QTableWidgetItem(name)); // Name
    itemTable->setItem(row, 2, new QTableWidgetItem(QString::number(price, 'f', 2))); // Price
    itemTable->setItem(row, 3, new QTableWidgetItem(QString::number(quantity))); // Quantity
    itemTable->setItem(row, 4, new QTableWidgetItem(description)); // Description
    itemTable->setItem(row, 5, new QTableWidgetItem(QString::number(totalItem, 'f', 2))); // Total (last column)

    // Update total
    total += totalItem;
    updateTotal();

    // Clear inputs
    itemNameInput->clear();
    itemPriceInput->clear();
    itemQuantityInput->clear();
    itemDescriptionInput->clear();
}

void POSPage::updateTotal() {
    totalLabel->setText(QString("Total: %1").arg(total, 0, 'f', 2));
}

void POSPage::checkout() {
    if (total <= 0) {
        QMessageBox::warning(this, "Checkout Error", "No items in the cart to checkout.");
        return;
    }

    QMessageBox::information(this, "Checkout", QString("Total amount to be paid: %1").arg(total, 0, 'f', 2));

    // Reset table and total
    itemTable->setRowCount(0);
    total = 0.0;
    updateTotal();
}

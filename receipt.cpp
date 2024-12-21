#include "receipt.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QHeaderView>

Receipt::Receipt(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Receipts");
    resize(600, 400);

    // Table setup
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(3);
    tableWidget->setHorizontalHeaderLabels({"Date", "Description", "Amount"});
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->verticalHeader()->setVisible(false); // Hides vertical header for cleaner UI
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // Make table read-only

    // Add button
    addButton = new QPushButton("Add Receipt", this);
    connect(addButton, &QPushButton::clicked, this, &Receipt::addReceipt);

    // Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tableWidget);
    mainLayout->addWidget(addButton);
    setLayout(mainLayout);

    // Populate the table with dummy data initially
    setDummyReceipts();
}

void Receipt::setDummyReceipts()
{
    receipts.append({"2024-12-15", "Laundry Service", 10.00});
    receipts.append({"2024-12-16", "Dry Cleaning", 15.50});
    receipts.append({"2024-12-17", "Ironing Service", 5.00});

    updateTable(); // Update the table with the dummy data
}

void Receipt::addReceipt()
{
    QString date = QInputDialog::getText(this, "Add Receipt", "Enter date (YYYY-MM-DD):");
    if (date.isEmpty()) return;

    QString description = QInputDialog::getText(this, "Add Receipt", "Enter description:");
    if (description.isEmpty()) return;

    double amount = QInputDialog::getDouble(this, "Add Receipt", "Enter amount:", 0, 0, 100000, 2);

    receipts.append({date, description, amount});
    updateTable(); // Update the table after adding a new receipt
}

void Receipt::updateTable()
{
    tableWidget->setRowCount(receipts.size());
    for (int i = 0; i < receipts.size(); ++i) {
        const ReceiptData &data = receipts[i];
        tableWidget->setItem(i, 0, new QTableWidgetItem(data.date));
        tableWidget->setItem(i, 1, new QTableWidgetItem(data.description));
        tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(data.amount, 'f', 2)));
    }
}

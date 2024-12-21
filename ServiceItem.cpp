#include "ServiceItem.h"
#include <QMessageBox>

ServiceItem::ServiceItem(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Service Item");

    // Initialize UI components
    setupUI();

    // Set dummy data to pre-fill the fields (for testing purposes)
    setDummyData();
}

void ServiceItem::setupUI()
{
    // Create the input fields
    nameLineEdit = new QLineEdit(this);
    priceLineEdit = new QLineEdit(this);
    descriptionLineEdit = new QTextEdit(this);  // Using QTextEdit for multi-line description

    // Create labels for the input fields
    QLabel *nameLabel = new QLabel("Service Name:", this);
    QLabel *priceLabel = new QLabel("Price:", this);
    QLabel *descriptionLabel = new QLabel("Description:", this);

    // Create the save, cancel, reset and add buttons
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);
    resetButton = new QPushButton("Reset", this);
    addButton = new QPushButton("Add Service", this);

    // Connect button actions to respective functions
    connect(saveButton, &QPushButton::clicked, this, &ServiceItem::saveServiceItem);
    connect(cancelButton, &QPushButton::clicked, this, &ServiceItem::cancelChanges);
    connect(resetButton, &QPushButton::clicked, this, &ServiceItem::resetFields);
    connect(addButton, &QPushButton::clicked, this, &ServiceItem::addServiceItem);

    // Create a list widget to display added service items
    serviceListWidget = new QListWidget(this);

    // Layout to organize the input fields, buttons, and service list
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QVBoxLayout *formLayout = new QVBoxLayout();

    formLayout->addWidget(nameLabel);
    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(priceLabel);
    formLayout->addWidget(priceLineEdit);
    formLayout->addWidget(descriptionLabel);
    formLayout->addWidget(descriptionLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(resetButton);
    buttonLayout->addWidget(addButton);

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(serviceListWidget);  // Adding the list widget to display services
    setLayout(mainLayout);
}

void ServiceItem::setDummyData()
{
    // Set dummy values for testing
    nameLineEdit->setText("Laundry Service");
    priceLineEdit->setText("10.00");
    descriptionLineEdit->setText("Basic laundry service including washing and drying.");
}

void ServiceItem::saveServiceItem()
{
    // Retrieve data from input fields
    QString name = nameLineEdit->text();
    QString price = priceLineEdit->text();
    QString description = descriptionLineEdit->toPlainText();  // Get multi-line description

    if (name.isEmpty() || price.isEmpty() || description.isEmpty()) {
        // Show an error message if any field is empty
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
        return;
    }

    // Simulate saving the service item (e.g., saving to a database or file)
    QMessageBox::information(this, "Saved", "Service item saved successfully!");

    // Close the dialog
    accept();
}

void ServiceItem::cancelChanges()
{
    // Close the dialog without saving
    reject();
}

void ServiceItem::resetFields()
{
    // Reset all fields to be empty
    nameLineEdit->clear();
    priceLineEdit->clear();
    descriptionLineEdit->clear();
}

void ServiceItem::addServiceItem()
{
    // Retrieve data from input fields
    QString name = nameLineEdit->text();
    QString price = priceLineEdit->text();
    QString description = descriptionLineEdit->toPlainText();  // Get multi-line description

    if (name.isEmpty() || price.isEmpty() || description.isEmpty()) {
        // Show an error message if any field is empty
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
        return;
    }

    // Add the new service item to the list
    QString serviceItem = "Name: " + name + ", Price: " + price + ", Description: " + description;
    serviceListWidget->addItem(serviceItem);

    // Reset fields after adding the service item
    resetFields();
}

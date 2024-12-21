#include "BusinessInfo.h"
#include <QMessageBox>
#include <QStringList>

BusinessInfo::BusinessInfo(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Customer Management");

    // Initialize UI
    setupUI();

    // Set dummy data
    setDummyData();
}

void BusinessInfo::setupUI()
{
    // Create the input fields
    nameLineEdit = new QLineEdit(this);
    addressLineEdit = new QLineEdit(this);
    contactNumberLineEdit = new QLineEdit(this);
    emailLineEdit = new QLineEdit(this);

    // Create labels for the input fields
    QLabel *nameLabel = new QLabel("Business Name:", this);
    QLabel *addressLabel = new QLabel("Address:", this);
    QLabel *contactNumberLabel = new QLabel("Contact Number:", this);
    QLabel *emailLabel = new QLabel("Email:", this);

    // Create buttons for save, cancel, add and delete customer
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);
    addCustomerButton = new QPushButton("Add Customer", this);
    deleteCustomerButton = new QPushButton("Delete Customer", this);

    // Create customer list widget
    customerListWidget = new QListWidget(this);

    // Set up button connections
    connect(saveButton, &QPushButton::clicked, this, &BusinessInfo::saveBusinessInfo);
    connect(cancelButton, &QPushButton::clicked, this, &BusinessInfo::cancelChanges);
    connect(addCustomerButton, &QPushButton::clicked, this, &BusinessInfo::addCustomer);
    connect(deleteCustomerButton, &QPushButton::clicked, this, &BusinessInfo::deleteCustomer);

    // Layout to organize the input fields and buttons
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QVBoxLayout *formLayout = new QVBoxLayout();

    formLayout->addWidget(nameLabel);
    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(addressLabel);
    formLayout->addWidget(addressLineEdit);
    formLayout->addWidget(contactNumberLabel);
    formLayout->addWidget(contactNumberLineEdit);
    formLayout->addWidget(emailLabel);
    formLayout->addWidget(emailLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(addCustomerButton);
    buttonLayout->addWidget(deleteCustomerButton);

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(customerListWidget);

    setLayout(mainLayout);
}

void BusinessInfo::setDummyData()
{
    // Dummy data for business info
    nameLineEdit->setText("Business Name");
    addressLineEdit->setText("123 Main St, City, Country");
    contactNumberLineEdit->setText("+1 234 567 890");
    emailLineEdit->setText("business@example.com");
}

void BusinessInfo::saveBusinessInfo()
{
    // Save the business info, could be saved to a file or database
    QString name = nameLineEdit->text();
    QString address = addressLineEdit->text();
    QString contactNumber = contactNumberLineEdit->text();
    QString email = emailLineEdit->text();

    if (name.isEmpty() || address.isEmpty() || contactNumber.isEmpty() || email.isEmpty()) {
        // Show error message if any field is empty
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
        return;
    }

    QMessageBox::information(this, "Saved", "Business info saved successfully!");

    // Close the dialog
    accept();
}

void BusinessInfo::cancelChanges()
{
    reject();
}

void BusinessInfo::addCustomer()
{
    // Retrieve customer details from input fields
    QString name = nameLineEdit->text();
    QString address = addressLineEdit->text();
    QString contactNumber = contactNumberLineEdit->text();
    QString email = emailLineEdit->text();

    // Validate fields before adding customer
    if (name.isEmpty() || address.isEmpty() || contactNumber.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
        return;
    }

    // Add customer to the list
    customerListWidget->addItem("Name: " + name + ", Address: " + address + ", Contact: " + contactNumber + ", Email: " + email);

    // Clear input fields after adding
    nameLineEdit->clear();
    addressLineEdit->clear();
    contactNumberLineEdit->clear();
    emailLineEdit->clear();
}

void BusinessInfo::deleteCustomer()
{
    // Get selected customer
    QListWidgetItem *selectedItem = customerListWidget->currentItem();

    if (selectedItem) {
        // Remove the selected customer from the list
        delete customerListWidget->takeItem(customerListWidget->row(selectedItem));
    } else {
        QMessageBox::warning(this, "Selection Error", "Please select a customer to delete.");
    }
}

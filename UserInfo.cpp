#include "UserInfo.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QStringList>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QHeaderView>  // Make sure QHeaderView is included

UserInfo::UserInfo(QWidget *parent)
    : QDialog(parent)
{
    // Set the title of the dialog
    setWindowTitle("User Information");

    // Call the setupUI function to initialize the components
    setupUI();

    // Set the dummy data for the fields
    setDummyData();
}

void UserInfo::setupUI()
{
    // Create the input fields
    nameLineEdit = new QLineEdit(this);
    emailLineEdit = new QLineEdit(this);
    addressLineEdit = new QLineEdit(this);

    // Create labels for the input fields
    QLabel *nameLabel = new QLabel("Name:", this);
    QLabel *emailLabel = new QLabel("Email:", this);
    QLabel *addressLabel = new QLabel("Address:", this);

    // Create the buttons
    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);
    addButton = new QPushButton("Add User", this);     // Button for adding user
    deleteButton = new QPushButton("Delete User", this); // Button for deleting user

    // Set up button connections
    connect(saveButton, &QPushButton::clicked, this, &UserInfo::saveUserInfo);
    connect(cancelButton, &QPushButton::clicked, this, &UserInfo::cancelChanges);
    connect(addButton, &QPushButton::clicked, this, &UserInfo::addUser);      // Add user
    connect(deleteButton, &QPushButton::clicked, this, &UserInfo::deleteUser); // Delete user

    // Create the table to display users
    userTable = new QTableWidget(this);
    userTable->setColumnCount(3); // Three columns: Name, Email, Address
    userTable->setHorizontalHeaderLabels({"Name", "Email", "Address"});
    userTable->horizontalHeader()->setStretchLastSection(true);  // This line will now work

    // Layout to organize the input fields, buttons, and table
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QVBoxLayout *formLayout = new QVBoxLayout();
    formLayout->addWidget(nameLabel);
    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(emailLabel);
    formLayout->addWidget(emailLineEdit);
    formLayout->addWidget(addressLabel);
    formLayout->addWidget(addressLineEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(addButton);     // Add button to layout
    buttonLayout->addWidget(deleteButton);  // Delete button to layout

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(userTable); // Add table to layout

    setLayout(mainLayout);
}

void UserInfo::setDummyData()
{
    // Dummy data for 5 records
    QStringList names = {"John Doe", "Jane Smith", "Alice Johnson", "Bob Brown", "Charlie Davis"};
    QStringList emails = {"john@example.com", "jane@example.com", "alice@example.com", "bob@example.com", "charlie@example.com"};
    QStringList addresses = {
        "123 Main St, City, Country",
        "456 Oak Ave, Town, Country",
        "789 Pine Rd, Village, Country",
        "101 Maple Blvd, City, Country",
        "202 Birch Dr, Suburb, Country"
    };

    // Add the dummy data to the users list
    for (int i = 0; i < names.size(); ++i) {
        users.append({names.at(i), emails.at(i), addresses.at(i)});
    }

    // Update the table to show the dummy users
    updateTable();
}

void UserInfo::saveUserInfo()
{
    // Save the user info, this could be saving to a file, database, etc.
    QString name = nameLineEdit->text();
    QString email = emailLineEdit->text();
    QString address = addressLineEdit->text();

    if (name.isEmpty() || email.isEmpty() || address.isEmpty()) {
        // Show error message if any field is empty
        QMessageBox::warning(this, "Input Error", "All fields must be filled!");
        return;
    }

    // Add the new user to the list
    users.append({name, email, address});

    // Update the table to show the new user
    updateTable();

    QMessageBox::information(this, "Saved", "User info saved successfully!");

    // Clear the input fields
    nameLineEdit->clear();
    emailLineEdit->clear();
    addressLineEdit->clear();
}

void UserInfo::cancelChanges()
{
    // Close the dialog without saving
    reject();
}

void UserInfo::addUser()
{
    // Show an input dialog to add a new user
    bool ok;
    QString name = QInputDialog::getText(this, "Add User", "Enter Name:", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    QString email = QInputDialog::getText(this, "Add User", "Enter Email:", QLineEdit::Normal, "", &ok);
    if (!ok || email.isEmpty()) return;

    QString address = QInputDialog::getText(this, "Add User", "Enter Address:", QLineEdit::Normal, "", &ok);
    if (!ok || address.isEmpty()) return;

    // Add the new user to the list
    users.append({name, email, address});

    // Update the table to show the new user
    updateTable();

    QMessageBox::information(this, "User Added", "New user added successfully!");
}

void UserInfo::deleteUser()
{
    // Show a list of users to choose from
    QStringList userNames;
    for (const UserData &user : users) {
        userNames.append(user.name);
    }

    bool ok;
    QString nameToDelete = QInputDialog::getItem(this, "Delete User", "Select user to delete:", userNames, 0, false, &ok);
    if (!ok || nameToDelete.isEmpty()) return;

    // Find the user to delete
    for (int i = 0; i < users.size(); ++i) {
        if (users.at(i).name == nameToDelete) {
            users.removeAt(i);
            // Update the table after deletion
            updateTable();
            QMessageBox::information(this, "User Deleted", "User has been deleted successfully!");
            return;
        }
    }

    QMessageBox::warning(this, "Delete Error", "User not found!");
}

void UserInfo::updateTable()
{
    // Clear the table before updating it
    userTable->setRowCount(0);

    // Update the table with current user data
    for (int i = 0; i < users.size(); ++i) {
        const UserData &user = users.at(i);
        userTable->insertRow(i);
        userTable->setItem(i, 0, new QTableWidgetItem(user.name));
        userTable->setItem(i, 1, new QTableWidgetItem(user.email));
        userTable->setItem(i, 2, new QTableWidgetItem(user.address));
    }
}

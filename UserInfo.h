#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QList>
#include <QStringList>
#include <QTableWidget>
#include <QHeaderView>  // Add this include for QHeaderView

class UserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);

private slots:
    void saveUserInfo();        // Slot to save user info
    void cancelChanges();       // Slot to cancel changes
    void addUser();             // Slot to add a new user
    void deleteUser();          // Slot to delete a user
    void updateTable();         // Slot to update the table view

private:
    void setupUI();             // Function to set up the UI components
    void setDummyData();        // Function to set dummy data for the fields

    QLineEdit *nameLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *addressLineEdit;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *addButton;     // Button to add a new user
    QPushButton *deleteButton;  // Button to delete a user

    QTableWidget *userTable;    // Table to display user information

    struct UserData {
        QString name;
        QString email;
        QString address;
    };

    QList<UserData> users;      // List to store users
};

#endif // USERINFO_H

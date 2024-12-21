#ifndef BUSINESSINFO_H
#define BUSINESSINFO_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QListWidget>

class BusinessInfo : public QDialog
{
    Q_OBJECT

public:
    explicit BusinessInfo(QWidget *parent = nullptr);

private slots:
    void saveBusinessInfo();
    void cancelChanges();
    void addCustomer();
    void deleteCustomer();

private:
    void setupUI();
    void setDummyData();

    // Input fields for business information
    QLineEdit *nameLineEdit;
    QLineEdit *addressLineEdit;
    QLineEdit *contactNumberLineEdit;
    QLineEdit *emailLineEdit;

    // Buttons
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *addCustomerButton;
    QPushButton *deleteCustomerButton;

    // Customer list
    QListWidget *customerListWidget;
};

#endif // BUSINESSINFO_H

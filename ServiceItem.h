#ifndef SERVICEITEM_H
#define SERVICEITEM_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>  // To display the added service items

class ServiceItem : public QDialog
{
    Q_OBJECT

public:
    explicit ServiceItem(QWidget *parent = nullptr);

private slots:
    void saveServiceItem();    // Slot to save the service item
    void cancelChanges();      // Slot to cancel changes
    void resetFields();        // Slot to reset all fields
    void addServiceItem();     // Slot to add a new service item to the list

private:
    // UI components
    QLineEdit *nameLineEdit;
    QLineEdit *priceLineEdit;
    QTextEdit *descriptionLineEdit;   // Multi-line description input
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *resetButton;         // Added reset button
    QPushButton *addButton;           // Button to add a new service item

    QListWidget *serviceListWidget;   // To display the added service items

    // Method to setup the UI layout
    void setupUI();

    // Method to set dummy data for testing
    void setDummyData();
};

#endif // SERVICEITEM_H

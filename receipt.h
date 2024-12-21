#ifndef RECEIPT_H
#define RECEIPT_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QTableWidgetItem>

class Receipt : public QDialog
{
    Q_OBJECT

public:
    explicit Receipt(QWidget *parent = nullptr);

private slots:
    void addReceipt();              // Slot to handle adding a receipt
    void setDummyReceipts();        // Method to set initial dummy receipts
    void updateTable();             // Method to update the table with receipt data

private:
    QTableWidget *tableWidget;      // Table to display receipt data
    QPushButton *addButton;        // Button to trigger adding new receipts

    struct ReceiptData {
        QString date;
        QString description;
        double amount;
    };

    QList<ReceiptData> receipts;    // List to store receipts

};

#endif // RECEIPT_H

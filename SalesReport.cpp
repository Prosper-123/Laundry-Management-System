#include "SalesReport.h"
#include <QVBoxLayout>
#include <QMessageBox>

SalesReport::SalesReport(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Sales Report");

    // Initialize table widget
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels({"Date", "Amount"});

    // Initialize buttons
    addButton = new QPushButton("Add Sale", this);
    generateButton = new QPushButton("Generate Report", this);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    layout->addWidget(addButton);
    layout->addWidget(generateButton);

    setLayout(layout);

    // Connect buttons to slots
    connect(addButton, &QPushButton::clicked, this, &SalesReport::addSale);
    connect(generateButton, &QPushButton::clicked, this, &SalesReport::generateReport);
}

void SalesReport::addSale()
{
    // Simple example: hardcoding a sale record
    SaleData newSale;
    newSale.date = "2024-12-17";  // Example date
    newSale.amount = 100.50;      // Example sale amount

    salesRecords.append(newSale);

    // Update table with new data
    updateTable();
}

void SalesReport::updateTable()
{
    tableWidget->setRowCount(salesRecords.size());

    for (int i = 0; i < salesRecords.size(); ++i) {
        tableWidget->setItem(i, 0, new QTableWidgetItem(salesRecords[i].date));
        tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(salesRecords[i].amount)));
    }
}

void SalesReport::generateReport()
{
    double totalSales = 0.0;
    for (const SaleData &sale : salesRecords) {
        totalSales += sale.amount;
    }

    QString reportMessage = "Total Sales: " + QString::number(totalSales, 'f', 2);

    // Display the report
    QMessageBox::information(this, "Sales Report", reportMessage);
}

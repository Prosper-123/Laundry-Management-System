#ifndef SALESREPORT_H
#define SALESREPORT_H

#include <QDialog>
#include <QTableWidget>
#include <QPushButton>
#include <QVector>

struct SaleData {
    QString date;
    double amount;
};

class SalesReport : public QDialog
{
    Q_OBJECT
public:
    explicit SalesReport(QWidget *parent = nullptr);

private slots:
    void addSale();
    void updateTable();
    void generateReport();

private:
    QTableWidget *tableWidget;
    QPushButton *addButton;
    QPushButton *generateButton;
    QVector<SaleData> salesRecords;
};

#endif // SALESREPORT_H

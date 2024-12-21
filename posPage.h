#ifndef POSPAGE_H
#define POSPAGE_H

#include <QWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class POSPage : public QWidget {
    Q_OBJECT

public:
    explicit POSPage(QWidget *parent = nullptr);

private slots:
    void addItem();

private:
    QTableWidget *itemTable;
    QLineEdit *itemNameInput;
    QLineEdit *itemPriceInput;
    QLineEdit *itemQuantityInput;
    QLineEdit *itemServiceInput;
    QLineEdit *itemDescriptionInput;
    QDateEdit *itemDateInput;
    QLabel *totalLabel;
    double total;

    void updateTotal();
    void checkout();
};

#endif // POSPAGE_H

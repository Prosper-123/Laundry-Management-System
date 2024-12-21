#ifndef EXPENSES_H
#define EXPENSES_H

#include <vector>
#include <QString>

class Expense {
public:
    QString category;
    QString description;
    double amount;

    Expense(const QString& category, const QString& description, double amount);
};

class Expenses {
public:
    std::vector<Expense> expenseRecords;

    void addExpense(const QString& category, const QString& description, double amount);
    double calculateTotalExpenses() const;
    QString generateExpenseReport() const;
};

#endif // EXPENSES_H

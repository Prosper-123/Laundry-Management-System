#include "expenses.h"
#include <numeric>

// Expense constructor
Expense::Expense(const QString& category, const QString& description, double amount)
    : category(category), description(description), amount(amount) {}

// Add a new expense to the list
void Expenses::addExpense(const QString& category, const QString& description, double amount) {
    expenseRecords.emplace_back(category, description, amount);
}

// Calculate the total amount of all expenses
double Expenses::calculateTotalExpenses() const {
    return std::accumulate(expenseRecords.begin(), expenseRecords.end(), 0.0,
                           [](double sum, const Expense& expense) { return sum + expense.amount; });
}

// Generate a report of all expenses
QString Expenses::generateExpenseReport() const {
    QString report;
    for (const auto& expense : expenseRecords) {
        report += QString("Category: %1, Description: %2, Amount: %3\n")
        .arg(expense.category)
            .arg(expense.description)
            .arg(expense.amount);
    }
    return report;
}

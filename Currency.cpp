#include "Currency.h"
#include <QString>
#include <QMap>
#include <QTextStream>

QMap<QString, Currency> Currency::currencyMap;

Currency::Currency(const QString &code, const QString &symbol, double exchangeRate)
    : code(code), symbol(symbol), exchangeRate(exchangeRate)
{
    // Add this currency to the static map for easy access
    currencyMap[code] = *this;
}

QString Currency::getCode() const
{
    return code;
}

QString Currency::getSymbol() const
{
    return symbol;
}

double Currency::getExchangeRate() const
{
    return exchangeRate;
}

void Currency::setExchangeRate(double exchangeRate)
{
    this->exchangeRate = exchangeRate;
}

// Function to convert an amount from one currency to another
double Currency::convert(double amount, const Currency &fromCurrency, const Currency &toCurrency)
{
    // Convert amount using the exchange rates of the currencies
    double baseAmount = amount / fromCurrency.getExchangeRate();
    return baseAmount * toCurrency.getExchangeRate();
}

// Function to format a currency amount according to its symbol and decimal places
QString Currency::formatAmount(double amount, const Currency &currency)
{
    QString formattedAmount = QString::number(amount, 'f', 2);  // Format to 2 decimal places
    return currency.getSymbol() + " " + formattedAmount;  // Add the symbol in front of the amount
}

// Static method to get a currency by its code (e.g., USD, EUR)
Currency* Currency::getCurrencyByCode(const QString &code)
{
    if(currencyMap.contains(code)) {
        return &currencyMap[code];
    }
    return nullptr;
}

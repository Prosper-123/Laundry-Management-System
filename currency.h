#ifndef CURRENCY_H
#define CURRENCY_H

#include <QString>
#include <QMap>

class Currency
{
public:
    // Constructor to initialize a currency with its code, symbol, and exchange rate
    Currency(const QString &code, const QString &symbol, double exchangeRate = 1.0)
        : code(code), symbol(symbol), exchangeRate(exchangeRate) {}

    // Member variables to hold currency details
    QString code;      // Currency code (e.g., USD, EUR)
    QString symbol;    // Currency symbol (e.g., $, €, £)
    double exchangeRate; // Exchange rate relative to a base currency (e.g., USD)

    // Static function to convert an amount from one currency to another
    static double convert(double amount, const Currency &fromCurrency, const Currency &toCurrency)
    {
        // Convert amount using exchange rates
        double baseAmount = amount / fromCurrency.exchangeRate;
        return baseAmount * toCurrency.exchangeRate;
    }

    // Static function to format a currency amount with the correct symbol and decimal places
    static QString formatAmount(double amount, const Currency &currency)
    {
        QString formattedAmount = QString::number(amount, 'f', 2); // Format to 2 decimal places
        return currency.symbol + " " + formattedAmount;  // Add the symbol in front of the amount
    }

    // Static map to store currency codes and their corresponding Currency objects
    static QMap<QString, Currency> currencyMap;

    // Static function to get a currency by its code
    static Currency* getCurrencyByCode(const QString &code)
    {
        if(currencyMap.contains(code)) {
            return &currencyMap[code];
        }
        return nullptr;
    }
};

#endif // CURRENCY_H

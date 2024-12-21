#include "dashboard.h"
#include "pospage.h"
#include "BusinessInfo.h"
#include "expenses.h"
#include "SalesReport.h"
#include "receipt.h"
#include "ServiceItem.h"
#include "UserInfo.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent), menuList(new QListWidget(this)), contentArea(new QStackedWidget(this))
{
    setWindowTitle("Dashboard - Laundry Management System");
    resize(900, 700);

    // Set up side menu and content area
    setupMenu();
    setupContent();

    // Layout for the dashboard
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(menuList, 1);
    mainLayout->addWidget(contentArea, 3);

    setLayout(mainLayout);

    // Simplified styling for the menu and content area
    styleMenu();
}

void Dashboard::setupMenu()
{
    // Add features to the side menu
    menuList->addItem("Payment and Billing");
    menuList->addItem("Service Item Info");
    menuList->addItem("Order Management");
    menuList->addItem("Transactions");
    menuList->addItem("Users");
    menuList->addItem("Customer Management");
    menuList->addItem("Inventory Management");
    menuList->addItem("Reports");

    // Add Settings and Logout to the bottom of the menu
    menuList->addItem("Settings");
    menuList->addItem("Logout");

    // Connect menu selection to the content area
    connect(menuList, &QListWidget::currentRowChanged, contentArea, &QStackedWidget::setCurrentIndex);

    // Connect Settings and Logout buttons
    connect(menuList, &QListWidget::itemClicked, this, &Dashboard::onMenuItemClicked);
}

void Dashboard::setupContent()
{
    // Add content widgets
    POSPage *posPage = new POSPage(this);
    contentArea->addWidget(posPage);

    ServiceItem *serviceItemPage = new ServiceItem(this);
    contentArea->addWidget(serviceItemPage);

    Receipt *receiptPage = new Receipt(this);
    contentArea->addWidget(receiptPage);

    SalesReport *salesReportPage = new SalesReport(this);
    contentArea->addWidget(salesReportPage);

    UserInfo *userInfoPage = new UserInfo(this);
    contentArea->addWidget(userInfoPage);

    BusinessInfo *businessInfoPage = new BusinessInfo(this);
    contentArea->addWidget(businessInfoPage);
}

void Dashboard::styleMenu()
{
    // Simple menu styling
    menuList->setStyleSheet(
        "QListWidget {"
        "    background-color: #2C3E50;"
        "    color: #ECF0F1;"
        "    font-size: 14px;"
        "    border: none;"
        "}"
        "QListWidget::item {"
        "    background-color: #34495E;"
        "    padding: 10px;"
        "}"
        "QListWidget::item:selected {"
        "    background-color: #2980B9;"
        "}");

    // Simple content area styling
    contentArea->setStyleSheet(
        "QStackedWidget {"
        "    background-color: #ECF0F1;"
        "}");
}

void Dashboard::onMenuItemClicked(QListWidgetItem *item)
{
    QString itemText = item->text();

    // Handle Settings menu item click
    if (itemText == "Settings") {
        // Show settings page or open settings dialog
        QMessageBox::information(this, "Settings", "Opening Settings Page...");
        // You can create a settings page and show it here
    }
    // Handle Logout menu item click
    else if (itemText == "Logout") {
        // Perform logout action, such as clearing session or showing a logout confirmation
        int response = QMessageBox::question(this, "Logout", "Are you sure you want to logout?",
                                             QMessageBox::Yes | QMessageBox::No);

        if (response == QMessageBox::Yes) {
            // Code to handle logout logic, such as clearing session data, going back to login page, etc.
            QMessageBox::information(this, "Logout", "You have been logged out.");
            close(); // Close the dashboard after logout
        }
    }
}

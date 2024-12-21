#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>

class POSPage;
class ServiceItem;
class Receipt;
class SalesReport;
class UserInfo;
class BusinessInfo;

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);

private:
    QListWidget *menuList;
    QStackedWidget *contentArea;

    void setupMenu();
    void setupContent();
    void styleMenu();

    // Declare the onMenuItemClicked function
    void onMenuItemClicked(QListWidgetItem *item);
};

#endif // DASHBOARD_H

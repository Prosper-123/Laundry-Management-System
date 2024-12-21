QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BusinessInfo.cpp \
    SalesReport.cpp \
    ServiceItem.cpp \
    UserInfo.cpp \
    dailyIncome.cpp \
    dashboard.cpp \
    expenses.cpp \
    main.cpp \
    posPage.cpp \
    receipt.cpp \
    widget.cpp

HEADERS += \
    BusinessInfo.h \
    SalesReport.h \
    ServiceItem.h \
    UserInfo.h \
    dailyIncome.h \
    dashboard.h \
    expenses.h \
    posPage.h \
    receipt.h \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

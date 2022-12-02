QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dashboard_1.cpp \
    main.cpp \
    mainwindow.cpp \
    passback.cpp \
    profile.cpp \
    registration.cpp

HEADERS += \
    dashboard_1.h \
    mainwindow.h \
    passback.h \
    profile.h \
    registration.h

FORMS += \
    dashboard_1.ui \
    mainwindow.ui \
    passback.ui \
    profile.ui \
    registration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

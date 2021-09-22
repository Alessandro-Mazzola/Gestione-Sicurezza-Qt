QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/lib
SOURCES += \
    dialog_add_allarme.cpp \
    dialog_add_sensore.cpp \
    dialog_add_telall.cpp \
    dialog_add_telecamera.cpp \
    main.cpp \
    mainwindow.cpp \
    $$PWD/lib/dispositivo/DispositivoSicurezza.cpp \
    $$PWD/lib/dispositivo/Produttore.cpp \
    $$PWD/lib/dispositivo/Allarme.cpp \
    $$PWD/lib/dispositivo/SesnoriRaggInfrarossi.cpp \
    $$PWD/lib/dispositivo/Telecamera.cpp \
    $$PWD/lib/dispositivo/TelecameraAllarmata.cpp \
    $$PWD/lib/gestoredispositivo/gestoreSicurezza.cpp \




HEADERS += \
    dialog_add_allarme.h \
    dialog_add_sensore.h \
    dialog_add_telall.h \
    dialog_add_telecamera.h \
    mainwindow.h

FORMS += \
    dialog_add_allarme.ui \
    dialog_add_sensore.ui \
    dialog_add_telall.ui \
    dialog_add_telecamera.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

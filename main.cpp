#include <QApplication>
#include <QFile>
#include <QObject>

#include "lib/qtsingleapplication/qtsingleapplication.h"

#include "controllers/applicationcontroller.hpp"
#include "helpers/uihelper.hpp"
#include "ui/windows/mainwindow.hpp"


int main(int argc, char *argv[])
{
    QtSingleApplication app(argc, argv);

    if(app.isRunning())
    {
        if(!app.sendMessage(QString("WAKEUP"), 10))
            qDebug() << "Error : App currently launch don't respond";
    }
    else
    {
        ApplicationController * applicationController = new ApplicationController();
        QObject::connect(&app, SIGNAL(messageReceived(const QString&)),
                         applicationController, SLOT(wakeUp(const QString&)));

				app.setQuitOnLastWindowClosed(true);

        QCoreApplication::setOrganizationName("Azika-Eros Ventures");
        QCoreApplication::setOrganizationDomain("christ.azika-eros.org");
        QCoreApplication::setApplicationName("OneVCard");
/*
				QFile styleFile(":/assets/style/style.css");

        if(!styleFile.open(QIODevice::ReadOnly))
            qDebug() << "Error while loading stylesheet file";
        else
            app.setStyleSheet(styleFile.readAll());
*/
/*
        QFontDatabase fontDB;
        fontDB.addApplicationFont(":/assets/fonts/HelveticaNeueLTStd-Lt.otf");
*/
        UiHelper * uiHelper = new UiHelper();
        MainWindow * mainWindow = new MainWindow(applicationController, uiHelper);

        uiHelper->fadeIn(mainWindow);

        app.exec();
    }

    return 0;
}

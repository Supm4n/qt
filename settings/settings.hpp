#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QDir>
#include <QtGlobal>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QStandardPaths>
#include <QtCore/QtCore>

#if defined(Q_OS_MAC)
#	define SOFTWARE_VERSION "1.0.osx.0"
#elif defined(Q_OS_WIN32)
#	define SOFTWARE_VERSION "1.0.win32.0"
#elif defined(Q_OS_WIN64)
#	define SOFTWARE_VERSION "1.0.win64.0"
#else
#	define SOFTWARE_VERSION NONE
#endif

/**
* This class handles the settings of the application
*/
class Settings : QSettings
{
    Q_OBJECT

public:
    /**
    * Constructor of the class handling the application's settings:
    * @param parent the parent object
    */
    Settings(QObject * parent = 0);

    /**
    * Save the settings in the appropriate file
    */
    void save();

    /**
    * @return Returns the folder where the settings file and records are stored
    */
    QString settingsFolder();

		QString softwareVersion();

private:
    QString _settingsFolder; ///< Settings and records folder
};

#endif // SETTINGS_HPP

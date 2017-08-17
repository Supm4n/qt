#include "settings.hpp"

/**
* Constructor of the class handling the application's settings:
* @param parent the parent object
*/
Settings::Settings(QObject * parent) : QSettings(parent)
{
  _settingsFolder = QStandardPaths::standardLocations(QStandardPaths::DataLocation)[0] + "/";
  // create the setting file
	setPath(QSettings::IniFormat, QSettings::UserScope, _settingsFolder + "instabeat-settings.ini");
  qDebug() << settingsFolder();
}

/**
* Save the settings in the appropriate file
*/
void Settings::save()
{
	sync();
	qDebug() << "Synced : " << _settingsFolder;
}

QString Settings::softwareVersion()
{
	return SOFTWARE_VERSION;
}

/**
* @return Returns the folder where the settings file and records are stored
*/
QString Settings::settingsFolder()
{
	return _settingsFolder;
}

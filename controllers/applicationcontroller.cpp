#include "applicationcontroller.hpp"

/**
* Constructor of the class instantiated in the main.
*
* @param parent the supposed parent object. There is no parent
*		     for the moment as the object is instantiated in the main function.
*/
ApplicationController::ApplicationController(QObject *parent) : QObject(parent)
{
	_settings = new Settings(this);
  _uiHelper = new UiHelper(this);
}

/**
* This slot quits the soft properly.
*/
void ApplicationController::quitHandler()
{
	qDebug() << "Quitting the software";
	//_settings->save();
	QApplication::exit();
}

/**
* This slot warns the user that the software is currently running. Called by a second
* process of the application launched by the user.
* @param message the message sent (WAKEUP). Not used.
*/
void ApplicationController::wakeUp(QString const & message) {}

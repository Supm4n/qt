#ifndef APPLICATIONCONTROLLER_HPP
#define APPLICATIONCONTROLLER_HPP

#include <QApplication>
#include <QDialog>

#include "helpers/uihelper.hpp"
#include "settings/settings.hpp"

/**
* The main class of the software. It lauches the software and manages
* actions between ui and logic.
*/
class ApplicationController : public QObject
{
    Q_OBJECT
public:
    /**
    * Constructor of the class instantiated in the main.
    *
    * @param parent the supposed parent object. There is no parent
    *		     for the moment as the object is instantiated in the main function.
    */
    explicit ApplicationController(QObject *parent = 0);

private:
	UiHelper * _uiHelper;
	Settings * _settings;

public slots:

private slots:

  /**
  * This slot warns the user that the software is currently running. Called by a second
  * process of the application launched by the user.
  * @param message the message sent (WAKEUP). Not used.
  */
  void wakeUp(QString const & message);
  
  /**
  * This slot quits the soft properly.
  */
  void quitHandler();

signals:
};

#endif // APPLICATIONCONTROLLER_HPP

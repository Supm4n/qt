#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "controllers/applicationcontroller.hpp"
#include "helpers/uihelper.hpp"

/**
* The main window of the software.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Contructor of the application main window
     * @param appController the controller of the app
     * @param UiHelper the helper for UI
     * @param parent the supposed parent object. There is no parent for the moment
     *				as the object is instantiated in the main function.
     */
    explicit MainWindow(ApplicationController * appController,
                        UiHelper * uiHelper,
                        QWidget *parent = 0);

private:
    ApplicationController * _appController;
    UiHelper * _uiHelper;

signals:

public slots:

};

#endif // MAINWINDOW_HPP

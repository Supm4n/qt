#include "mainwindow.hpp"


/**
 * @brief Contructor of the application main window
 * @param appController the controller of the app
 * @param UiHelper the helper for UI
 * @param parent the supposed parent object. There is no parent for the moment
 *				as the object is instantiated in the main function.
 */
MainWindow::MainWindow(ApplicationController * appController,
                       UiHelper * uiHelper,
                       QWidget *parent) :
    QMainWindow(parent)
{
    setFixedSize(500,400);
}

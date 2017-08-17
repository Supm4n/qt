#ifndef UIHELPER_HPP
#define UIHELPER_HPP

#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QDialog>
#include <QObject>
#include <QPoint>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QRect>
#include <QWidget>

/**
* This class contains usefull general fonctions concerning UI such as fadeIn
* to show a window smoothly. Wondering if functions cannot just be static.
*/
class UiHelper : public QObject
{
public :

    /**
    * Constructor of the class containing general functions to manipulate the UI.
    * @param parent supposed parent of the class
    */
    UiHelper(QObject *parent = 0);

public slots :

    /**
    * Fade in a QWidget in 300 ms
    * @param QWidget object whis has to fade in
    */
    void fadeIn(QWidget * dialog);

    /**
    * Fade out a QDialog in 300 ms
    * @param QWidget object whis has to fade out
    */
		void fadeOut(QDialog * dialog);

     /**
     * @brief windowGeametry returns the geometry of the width, centered
     *				on the screen
     * @param width the width of the window
     * @param height the height of the window
     * @param parent the parent widget
     * @return the QRect of the QDialog::setGeometry() method
     */
    QRect windowGeametry(int width, int height, QWidget * parent = NULL);
};


#endif // UIHELPER_HPP

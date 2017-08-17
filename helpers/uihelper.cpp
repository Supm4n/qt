#include "uihelper.hpp"

/**
* Constructor of the class containing general functions to manipulate the UI.
* @param parent supposed parent of the class
*/
UiHelper::UiHelper(QObject *parent) : QObject(parent)
{
}

/**
* Fade in a QWidget in 300 ms
* @param QWidget object whis has to fade in
*/
void UiHelper::fadeIn(QWidget * widget)
{
    int widgetY = widget->pos().y();

    qDebug() << widgetY;

    widget->setWindowOpacity(0);
    widget->setWindowFlags(Qt::WindowStaysOnTopHint);
    widget->show();

    QPropertyAnimation * opacityAnimation = new QPropertyAnimation(widget, "windowOpacity");
    opacityAnimation->setDuration(300);
    opacityAnimation->setStartValue(0);
    opacityAnimation->setEndValue(1);

    QPropertyAnimation * moveAnimation = new QPropertyAnimation(widget, "pos");
    moveAnimation->setDuration(300);
    moveAnimation->setStartValue(QPoint(widget->pos().x(), (QDesktopWidget().height()/2 - widget->height()/2) - 50));
    moveAnimation->setEndValue(QPoint(widget->pos().x(), QDesktopWidget().height()/2 - widget->height()/2));

    QParallelAnimationGroup * fadinGroup = new QParallelAnimationGroup();
    fadinGroup->addAnimation(opacityAnimation);
    fadinGroup->addAnimation(moveAnimation);
    fadinGroup->start();
}

/**
* Fade out a QDialog in 300 ms
* @param QObject object which has to fade out
*/
void UiHelper::fadeOut(QDialog * dialog)
{
    dialog->hide();

    QPropertyAnimation * animation = new QPropertyAnimation(dialog, "windowOpacity");
    animation->setDuration(300);
    animation->setStartValue(1); animation->setEndValue(0);
    animation->start();

    connect(animation, SIGNAL(finished()), dialog, SLOT(hide()));
}

/**
* @brief  windowGeametry returns the geometry of the width, centered
*				  on the screen
* @param  width the width of the window
* @param  height the height of the window
* @return the QRect of the QDialog::setGeometry() method
*/
QRect UiHelper::windowGeametry(int width, int height, QWidget * parent)
{
    if(parent == NULL)
      return QRect(((QApplication::desktop()->width()/2) - (width/2)),
				  				  ((QApplication::desktop()->height()/2) - (height/2)),
              		  width, height);
		else
      return QRect(((parent->width()/2) - (width/2)),
				  				  ((parent->height()/2) - (height/2)),
              		  width, height);
}

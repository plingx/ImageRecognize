/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *frame;
    QLabel *picture;
    QLabel *title;
    QTextBrowser *recve;
    QPushButton *identifyBt;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(428, 241);
        frame = new QLabel(Widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 40, 191, 151));
        picture = new QLabel(Widget);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(220, 40, 191, 161));
        title = new QLabel(Widget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(130, 10, 141, 21));
        recve = new QTextBrowser(Widget);
        recve->setObjectName(QStringLiteral("recve"));
        recve->setGeometry(QRect(100, 210, 231, 31));
        identifyBt = new QPushButton(Widget);
        identifyBt->setObjectName(QStringLiteral("identifyBt"));
        identifyBt->setGeometry(QRect(340, 210, 80, 26));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        frame->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        picture->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        title->setText(QApplication::translate("Widget", "\346\231\272\350\203\275\350\257\206\345\210\253\347\263\273\347\273\237", Q_NULLPTR));
        identifyBt->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

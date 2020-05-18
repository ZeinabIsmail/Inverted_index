/********************************************************************************
** Form generated from reading UI file 'Main.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_H
#define MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton* directory_btn;
    QPushButton* word_btn;
    QPushButton* simulate_btn;
    QLineEdit* directory_text;
    QLineEdit* word_text;
    QLabel* label;
    QScrollArea* ButtonScrollArea;
    QWidget* scrollAreaWidgetContents;
    QScrollArea* fileScrollArea;
    QWidget* scrollAreaWidgetContents_2;
    QLabel* output_lable;

    void setupUi(QWidget* Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(516, 425);
        Form->setStyleSheet(QString::fromUtf8("background-color:#fde7ff;"));
        directory_btn = new QPushButton(Form);
        directory_btn->setObjectName(QString::fromUtf8("directory_btn"));
        directory_btn->setGeometry(QRect(240, 130, 91, 31));
        directory_btn->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 2px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));
        word_btn = new QPushButton(Form);
        word_btn->setObjectName(QString::fromUtf8("word_btn"));
        word_btn->setGeometry(QRect(240, 80, 91, 31));
        word_btn->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 2px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;    "));
        simulate_btn = new QPushButton(Form);
        simulate_btn->setObjectName(QString::fromUtf8("simulate_btn"));
        simulate_btn->setGeometry(QRect(150, 180, 111, 31));
        simulate_btn->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 2px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));
        directory_text = new QLineEdit(Form);
        directory_text->setObjectName(QString::fromUtf8("directory_text"));
        directory_text->setGeometry(QRect(10, 80, 211, 31));
        QFont font;
        font.setPointSize(10);
        directory_text->setFont(font);
        directory_text->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 2px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));
        directory_text->setAlignment(Qt::AlignCenter);
        word_text = new QLineEdit(Form);
        word_text->setObjectName(QString::fromUtf8("word_text"));
        word_text->setGeometry(QRect(10, 130, 211, 31));
        word_text->setFont(font);
        word_text->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 2px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));
        word_text->setAlignment(Qt::AlignCenter);
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 10, 191, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 2px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));
        label->setAlignment(Qt::AlignCenter);
        ButtonScrollArea = new QScrollArea(Form);
        ButtonScrollArea->setObjectName(QString::fromUtf8("ButtonScrollArea"));
        ButtonScrollArea->setGeometry(QRect(380, 70, 121, 141));
        ButtonScrollArea->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 1px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));
        ButtonScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ButtonScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 119, 139));
        ButtonScrollArea->setWidget(scrollAreaWidgetContents);
        fileScrollArea = new QScrollArea(Form);
        fileScrollArea->setObjectName(QString::fromUtf8("fileScrollArea"));
        fileScrollArea->setGeometry(QRect(300, 240, 201, 161));
        fileScrollArea->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 1px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));
        fileScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        fileScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        fileScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 182, 142));
        fileScrollArea->setWidget(scrollAreaWidgetContents_2);
        output_lable = new QLabel(Form);
        output_lable->setObjectName(QString::fromUtf8("output_lable"));
        output_lable->setGeometry(QRect(10, 250, 271, 41));
        output_lable->setStyleSheet(QString::fromUtf8("background-color:#ffd7ff;\n"
            " border: 2px solid ;\n"
            " border-radius: 10px;\n"
            "border-color:#610945;\n"
            "color:#610945;  "));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget* Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        directory_btn->setText(QCoreApplication::translate("Form", "Enter ", nullptr));
        word_btn->setText(QCoreApplication::translate("Form", "Enter", nullptr));
        simulate_btn->setText(QCoreApplication::translate("Form", "Simulate", nullptr));
        directory_text->setText(QCoreApplication::translate("Form", "Enter Directory", nullptr));
        directory_text->setPlaceholderText(QCoreApplication::translate("Form", "Enter Hole Name", nullptr));
        word_text->setText(QCoreApplication::translate("Form", "Enter Word", nullptr));
        word_text->setPlaceholderText(QCoreApplication::translate("Form", "Enter Hole Name", nullptr));
        label->setText(QCoreApplication::translate("Form", "Inverted Index", nullptr));
        output_lable->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form : public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAIN_H

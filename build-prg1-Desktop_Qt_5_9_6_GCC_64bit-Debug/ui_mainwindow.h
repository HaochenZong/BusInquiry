/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *graphics_view;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *stops_checkbox;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *stopnames_checkbox;
    QCheckBox *regions_checkbox;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *regionnames_checkbox;
    QCheckBox *routes_checkbox;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *routeids_checkbox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *zoom_plus;
    QToolButton *zoom_minus;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *zoom_1;
    QToolButton *zoom_fit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QDoubleSpinBox *pointscale;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QDoubleSpinBox *fontscale;
    QPlainTextEdit *output;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *cmd_info_text;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cmd_select;
    QLabel *label_2;
    QComboBox *number_select;
    QPushButton *file_button;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QPushButton *stop_button;
    QPushButton *execute_button;
    QPushButton *clear_input_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(749, 661);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphics_view = new QGraphicsView(layoutWidget);
        graphics_view->setObjectName(QStringLiteral("graphics_view"));
        graphics_view->setInteractive(true);
        graphics_view->setDragMode(QGraphicsView::NoDrag);

        horizontalLayout_2->addWidget(graphics_view);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        stops_checkbox = new QCheckBox(layoutWidget);
        stops_checkbox->setObjectName(QStringLiteral("stops_checkbox"));
        stops_checkbox->setChecked(true);

        verticalLayout_2->addWidget(stops_checkbox);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        stopnames_checkbox = new QCheckBox(layoutWidget);
        stopnames_checkbox->setObjectName(QStringLiteral("stopnames_checkbox"));
        stopnames_checkbox->setChecked(true);

        horizontalLayout_7->addWidget(stopnames_checkbox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        regions_checkbox = new QCheckBox(layoutWidget);
        regions_checkbox->setObjectName(QStringLiteral("regions_checkbox"));
        regions_checkbox->setChecked(false);

        verticalLayout_2->addWidget(regions_checkbox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        regionnames_checkbox = new QCheckBox(layoutWidget);
        regionnames_checkbox->setObjectName(QStringLiteral("regionnames_checkbox"));
        regionnames_checkbox->setEnabled(false);
        regionnames_checkbox->setChecked(true);

        horizontalLayout_8->addWidget(regionnames_checkbox);


        verticalLayout_2->addLayout(horizontalLayout_8);

        routes_checkbox = new QCheckBox(layoutWidget);
        routes_checkbox->setObjectName(QStringLiteral("routes_checkbox"));
        routes_checkbox->setEnabled(false);
        routes_checkbox->setChecked(false);

        verticalLayout_2->addWidget(routes_checkbox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        routeids_checkbox = new QCheckBox(layoutWidget);
        routeids_checkbox->setObjectName(QStringLiteral("routeids_checkbox"));
        routeids_checkbox->setEnabled(false);

        verticalLayout_5->addWidget(routeids_checkbox);


        horizontalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        zoom_plus = new QToolButton(layoutWidget);
        zoom_plus->setObjectName(QStringLiteral("zoom_plus"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(zoom_plus->sizePolicy().hasHeightForWidth());
        zoom_plus->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(zoom_plus);

        zoom_minus = new QToolButton(layoutWidget);
        zoom_minus->setObjectName(QStringLiteral("zoom_minus"));
        sizePolicy.setHeightForWidth(zoom_minus->sizePolicy().hasHeightForWidth());
        zoom_minus->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(zoom_minus);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        zoom_1 = new QToolButton(layoutWidget);
        zoom_1->setObjectName(QStringLiteral("zoom_1"));
        sizePolicy.setHeightForWidth(zoom_1->sizePolicy().hasHeightForWidth());
        zoom_1->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(zoom_1);

        zoom_fit = new QToolButton(layoutWidget);
        zoom_fit->setObjectName(QStringLiteral("zoom_fit"));
        sizePolicy.setHeightForWidth(zoom_fit->sizePolicy().hasHeightForWidth());
        zoom_fit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(zoom_fit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_10->addWidget(label_4);

        pointscale = new QDoubleSpinBox(layoutWidget);
        pointscale->setObjectName(QStringLiteral("pointscale"));
        pointscale->setMinimum(0.01);
        pointscale->setSingleStep(0.1);
        pointscale->setValue(1);

        horizontalLayout_10->addWidget(pointscale);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_9->addWidget(label_3);

        fontscale = new QDoubleSpinBox(layoutWidget);
        fontscale->setObjectName(QStringLiteral("fontscale"));
        fontscale->setMinimum(0.01);
        fontscale->setSingleStep(0.1);
        fontscale->setValue(1);

        horizontalLayout_9->addWidget(fontscale);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_2->addLayout(verticalLayout_2);

        splitter->addWidget(layoutWidget);
        output = new QPlainTextEdit(splitter);
        output->setObjectName(QStringLiteral("output"));
        output->setUndoRedoEnabled(false);
        output->setLineWrapMode(QPlainTextEdit::NoWrap);
        splitter->addWidget(output);

        verticalLayout->addWidget(splitter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        cmd_info_text = new QLabel(centralWidget);
        cmd_info_text->setObjectName(QStringLiteral("cmd_info_text"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmd_info_text->sizePolicy().hasHeightForWidth());
        cmd_info_text->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(cmd_info_text);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_4->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        cmd_select = new QComboBox(centralWidget);
        cmd_select->setObjectName(QStringLiteral("cmd_select"));

        horizontalLayout->addWidget(cmd_select);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        number_select = new QComboBox(centralWidget);
        number_select->setObjectName(QStringLiteral("number_select"));

        horizontalLayout->addWidget(number_select);

        file_button = new QPushButton(centralWidget);
        file_button->setObjectName(QStringLiteral("file_button"));

        horizontalLayout->addWidget(file_button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        stop_button = new QPushButton(centralWidget);
        stop_button->setObjectName(QStringLiteral("stop_button"));
        stop_button->setEnabled(false);

        verticalLayout_3->addWidget(stop_button);

        execute_button = new QPushButton(centralWidget);
        execute_button->setObjectName(QStringLiteral("execute_button"));

        verticalLayout_3->addWidget(execute_button);

        clear_input_button = new QPushButton(centralWidget);
        clear_input_button->setObjectName(QStringLiteral("clear_input_button"));

        verticalLayout_3->addWidget(clear_input_button);


        horizontalLayout_5->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_5);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        stops_checkbox->setText(QApplication::translate("MainWindow", "Stops", Q_NULLPTR));
        stopnames_checkbox->setText(QApplication::translate("MainWindow", "Stop names", Q_NULLPTR));
        regions_checkbox->setText(QApplication::translate("MainWindow", "Regions", Q_NULLPTR));
        regionnames_checkbox->setText(QApplication::translate("MainWindow", "Region names", Q_NULLPTR));
        routes_checkbox->setText(QApplication::translate("MainWindow", "Routes", Q_NULLPTR));
        routeids_checkbox->setText(QApplication::translate("MainWindow", "Route IDs", Q_NULLPTR));
        zoom_plus->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        zoom_minus->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        zoom_1->setText(QApplication::translate("MainWindow", "1:1", Q_NULLPTR));
        zoom_fit->setText(QApplication::translate("MainWindow", "Fit", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Pointscale", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Fontscale", Q_NULLPTR));
        cmd_info_text->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Command:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Number:", Q_NULLPTR));
        file_button->setText(QApplication::translate("MainWindow", "File...", Q_NULLPTR));
        stop_button->setText(QApplication::translate("MainWindow", "Stop test", Q_NULLPTR));
        execute_button->setText(QApplication::translate("MainWindow", "Execute", Q_NULLPTR));
        clear_input_button->setText(QApplication::translate("MainWindow", "Clear input", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_30;
    QGroupBox *GB_temp;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *PR_temp;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *MX_temp;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *MIN_temp;
    QGroupBox *GB_hum;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *PR_hum;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *MX_hum;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *MIN_hum;
    QGroupBox *GB_hum_suelo;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *PR_hum_suel;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *MX_hum_suel;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_12;
    QLineEdit *MIN_hum_suel;
    QGroupBox *GB_velocidad;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_14;
    QLineEdit *PR_vel;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_15;
    QLineEdit *MX_vel;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_16;
    QLineEdit *MIN_vel;
    QHBoxLayout *horizontalLayout_31;
    QGroupBox *GB_direccion;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_18;
    QLineEdit *PR_dir;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_19;
    QLineEdit *MX_dir;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_20;
    QLineEdit *MIN_dir;
    QGroupBox *GB_precipitacion;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_22;
    QLineEdit *PR_pre;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_23;
    QLineEdit *MX_pre;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_24;
    QLineEdit *MIN_pre;
    QGroupBox *GB_intensidad;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_26;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_26;
    QLineEdit *PR_in;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_27;
    QLineEdit *MX_in;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_28;
    QLineEdit *MIN_in;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_29;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *minutos;
    QLCDNumber *segundos;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(876, 390);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_8 = new QGridLayout(centralwidget);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        GB_temp = new QGroupBox(centralwidget);
        GB_temp->setObjectName(QString::fromUtf8("GB_temp"));
        sizePolicy.setHeightForWidth(GB_temp->sizePolicy().hasHeightForWidth());
        GB_temp->setSizePolicy(sizePolicy);
        GB_temp->setMaximumSize(QSize(500, 500));
        gridLayout = new QGridLayout(GB_temp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        label = new QLabel(GB_temp);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(GB_temp);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        PR_temp = new QLineEdit(GB_temp);
        PR_temp->setObjectName(QString::fromUtf8("PR_temp"));
        sizePolicy.setHeightForWidth(PR_temp->sizePolicy().hasHeightForWidth());
        PR_temp->setSizePolicy(sizePolicy);
        PR_temp->setMaximumSize(QSize(100, 30));
        PR_temp->setReadOnly(true);

        horizontalLayout_2->addWidget(PR_temp);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(GB_temp);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        MX_temp = new QLineEdit(GB_temp);
        MX_temp->setObjectName(QString::fromUtf8("MX_temp"));
        sizePolicy.setHeightForWidth(MX_temp->sizePolicy().hasHeightForWidth());
        MX_temp->setSizePolicy(sizePolicy);
        MX_temp->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(MX_temp);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(GB_temp);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        MIN_temp = new QLineEdit(GB_temp);
        MIN_temp->setObjectName(QString::fromUtf8("MIN_temp"));
        sizePolicy.setHeightForWidth(MIN_temp->sizePolicy().hasHeightForWidth());
        MIN_temp->setSizePolicy(sizePolicy);
        MIN_temp->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(MIN_temp);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout_30->addWidget(GB_temp);

        GB_hum = new QGroupBox(centralwidget);
        GB_hum->setObjectName(QString::fromUtf8("GB_hum"));
        sizePolicy.setHeightForWidth(GB_hum->sizePolicy().hasHeightForWidth());
        GB_hum->setSizePolicy(sizePolicy);
        GB_hum->setMaximumSize(QSize(500, 500));
        gridLayout_2 = new QGridLayout(GB_hum);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        label_5 = new QLabel(GB_hum);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(GB_hum);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        PR_hum = new QLineEdit(GB_hum);
        PR_hum->setObjectName(QString::fromUtf8("PR_hum"));
        sizePolicy.setHeightForWidth(PR_hum->sizePolicy().hasHeightForWidth());
        PR_hum->setSizePolicy(sizePolicy);
        PR_hum->setMaximumSize(QSize(100, 30));
        PR_hum->setReadOnly(true);

        horizontalLayout_7->addWidget(PR_hum);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(GB_hum);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        MX_hum = new QLineEdit(GB_hum);
        MX_hum->setObjectName(QString::fromUtf8("MX_hum"));
        sizePolicy.setHeightForWidth(MX_hum->sizePolicy().hasHeightForWidth());
        MX_hum->setSizePolicy(sizePolicy);
        MX_hum->setMaximumSize(QSize(100, 30));

        horizontalLayout_8->addWidget(MX_hum);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(GB_hum);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        MIN_hum = new QLineEdit(GB_hum);
        MIN_hum->setObjectName(QString::fromUtf8("MIN_hum"));
        sizePolicy.setHeightForWidth(MIN_hum->sizePolicy().hasHeightForWidth());
        MIN_hum->setSizePolicy(sizePolicy);
        MIN_hum->setMaximumSize(QSize(100, 30));

        horizontalLayout_9->addWidget(MIN_hum);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        horizontalLayout_30->addWidget(GB_hum);

        GB_hum_suelo = new QGroupBox(centralwidget);
        GB_hum_suelo->setObjectName(QString::fromUtf8("GB_hum_suelo"));
        sizePolicy.setHeightForWidth(GB_hum_suelo->sizePolicy().hasHeightForWidth());
        GB_hum_suelo->setSizePolicy(sizePolicy);
        GB_hum_suelo->setMaximumSize(QSize(500, 500));
        gridLayout_3 = new QGridLayout(GB_hum_suelo);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        label_9 = new QLabel(GB_hum_suelo);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_10 = new QLabel(GB_hum_suelo);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_11->addWidget(label_10);

        PR_hum_suel = new QLineEdit(GB_hum_suelo);
        PR_hum_suel->setObjectName(QString::fromUtf8("PR_hum_suel"));
        sizePolicy.setHeightForWidth(PR_hum_suel->sizePolicy().hasHeightForWidth());
        PR_hum_suel->setSizePolicy(sizePolicy);
        PR_hum_suel->setMaximumSize(QSize(100, 30));
        PR_hum_suel->setReadOnly(true);

        horizontalLayout_11->addWidget(PR_hum_suel);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(GB_hum_suelo);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_12->addWidget(label_11);

        MX_hum_suel = new QLineEdit(GB_hum_suelo);
        MX_hum_suel->setObjectName(QString::fromUtf8("MX_hum_suel"));
        sizePolicy.setHeightForWidth(MX_hum_suel->sizePolicy().hasHeightForWidth());
        MX_hum_suel->setSizePolicy(sizePolicy);
        MX_hum_suel->setMaximumSize(QSize(100, 30));

        horizontalLayout_12->addWidget(MX_hum_suel);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_12 = new QLabel(GB_hum_suelo);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_13->addWidget(label_12);

        MIN_hum_suel = new QLineEdit(GB_hum_suelo);
        MIN_hum_suel->setObjectName(QString::fromUtf8("MIN_hum_suel"));
        sizePolicy.setHeightForWidth(MIN_hum_suel->sizePolicy().hasHeightForWidth());
        MIN_hum_suel->setSizePolicy(sizePolicy);
        MIN_hum_suel->setMaximumSize(QSize(100, 30));

        horizontalLayout_13->addWidget(MIN_hum_suel);


        verticalLayout_3->addLayout(horizontalLayout_13);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        horizontalLayout_30->addWidget(GB_hum_suelo);

        GB_velocidad = new QGroupBox(centralwidget);
        GB_velocidad->setObjectName(QString::fromUtf8("GB_velocidad"));
        sizePolicy.setHeightForWidth(GB_velocidad->sizePolicy().hasHeightForWidth());
        GB_velocidad->setSizePolicy(sizePolicy);
        GB_velocidad->setMaximumSize(QSize(500, 500));
        gridLayout_4 = new QGridLayout(GB_velocidad);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_7);

        label_13 = new QLabel(GB_velocidad);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_14->addWidget(label_13);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_14 = new QLabel(GB_velocidad);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_15->addWidget(label_14);

        PR_vel = new QLineEdit(GB_velocidad);
        PR_vel->setObjectName(QString::fromUtf8("PR_vel"));
        sizePolicy.setHeightForWidth(PR_vel->sizePolicy().hasHeightForWidth());
        PR_vel->setSizePolicy(sizePolicy);
        PR_vel->setMaximumSize(QSize(100, 30));
        PR_vel->setReadOnly(true);

        horizontalLayout_15->addWidget(PR_vel);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_15 = new QLabel(GB_velocidad);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_16->addWidget(label_15);

        MX_vel = new QLineEdit(GB_velocidad);
        MX_vel->setObjectName(QString::fromUtf8("MX_vel"));
        sizePolicy.setHeightForWidth(MX_vel->sizePolicy().hasHeightForWidth());
        MX_vel->setSizePolicy(sizePolicy);
        MX_vel->setMaximumSize(QSize(100, 30));

        horizontalLayout_16->addWidget(MX_vel);


        verticalLayout_4->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_16 = new QLabel(GB_velocidad);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_17->addWidget(label_16);

        MIN_vel = new QLineEdit(GB_velocidad);
        MIN_vel->setObjectName(QString::fromUtf8("MIN_vel"));
        sizePolicy.setHeightForWidth(MIN_vel->sizePolicy().hasHeightForWidth());
        MIN_vel->setSizePolicy(sizePolicy);
        MIN_vel->setMaximumSize(QSize(100, 30));

        horizontalLayout_17->addWidget(MIN_vel);


        verticalLayout_4->addLayout(horizontalLayout_17);


        gridLayout_4->addLayout(verticalLayout_4, 0, 0, 1, 1);


        horizontalLayout_30->addWidget(GB_velocidad);


        verticalLayout_9->addLayout(horizontalLayout_30);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        GB_direccion = new QGroupBox(centralwidget);
        GB_direccion->setObjectName(QString::fromUtf8("GB_direccion"));
        sizePolicy.setHeightForWidth(GB_direccion->sizePolicy().hasHeightForWidth());
        GB_direccion->setSizePolicy(sizePolicy);
        GB_direccion->setMaximumSize(QSize(500, 500));
        gridLayout_5 = new QGridLayout(GB_direccion);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_9);

        label_17 = new QLabel(GB_direccion);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_18->addWidget(label_17);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_10);


        verticalLayout_5->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_18 = new QLabel(GB_direccion);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_19->addWidget(label_18);

        PR_dir = new QLineEdit(GB_direccion);
        PR_dir->setObjectName(QString::fromUtf8("PR_dir"));
        sizePolicy.setHeightForWidth(PR_dir->sizePolicy().hasHeightForWidth());
        PR_dir->setSizePolicy(sizePolicy);
        PR_dir->setMaximumSize(QSize(100, 30));
        PR_dir->setReadOnly(true);

        horizontalLayout_19->addWidget(PR_dir);


        verticalLayout_5->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_19 = new QLabel(GB_direccion);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_20->addWidget(label_19);

        MX_dir = new QLineEdit(GB_direccion);
        MX_dir->setObjectName(QString::fromUtf8("MX_dir"));
        sizePolicy.setHeightForWidth(MX_dir->sizePolicy().hasHeightForWidth());
        MX_dir->setSizePolicy(sizePolicy);
        MX_dir->setMaximumSize(QSize(100, 30));

        horizontalLayout_20->addWidget(MX_dir);


        verticalLayout_5->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_20 = new QLabel(GB_direccion);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_21->addWidget(label_20);

        MIN_dir = new QLineEdit(GB_direccion);
        MIN_dir->setObjectName(QString::fromUtf8("MIN_dir"));
        sizePolicy.setHeightForWidth(MIN_dir->sizePolicy().hasHeightForWidth());
        MIN_dir->setSizePolicy(sizePolicy);
        MIN_dir->setMaximumSize(QSize(100, 30));

        horizontalLayout_21->addWidget(MIN_dir);


        verticalLayout_5->addLayout(horizontalLayout_21);


        gridLayout_5->addLayout(verticalLayout_5, 0, 0, 1, 1);


        horizontalLayout_31->addWidget(GB_direccion);

        GB_precipitacion = new QGroupBox(centralwidget);
        GB_precipitacion->setObjectName(QString::fromUtf8("GB_precipitacion"));
        sizePolicy.setHeightForWidth(GB_precipitacion->sizePolicy().hasHeightForWidth());
        GB_precipitacion->setSizePolicy(sizePolicy);
        GB_precipitacion->setMaximumSize(QSize(500, 500));
        gridLayout_6 = new QGridLayout(GB_precipitacion);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_11);

        label_21 = new QLabel(GB_precipitacion);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_22->addWidget(label_21);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_12);


        verticalLayout_6->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_22 = new QLabel(GB_precipitacion);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_23->addWidget(label_22);

        PR_pre = new QLineEdit(GB_precipitacion);
        PR_pre->setObjectName(QString::fromUtf8("PR_pre"));
        sizePolicy.setHeightForWidth(PR_pre->sizePolicy().hasHeightForWidth());
        PR_pre->setSizePolicy(sizePolicy);
        PR_pre->setMaximumSize(QSize(100, 30));
        PR_pre->setReadOnly(true);

        horizontalLayout_23->addWidget(PR_pre);


        verticalLayout_6->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_23 = new QLabel(GB_precipitacion);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_24->addWidget(label_23);

        MX_pre = new QLineEdit(GB_precipitacion);
        MX_pre->setObjectName(QString::fromUtf8("MX_pre"));
        sizePolicy.setHeightForWidth(MX_pre->sizePolicy().hasHeightForWidth());
        MX_pre->setSizePolicy(sizePolicy);
        MX_pre->setMaximumSize(QSize(100, 30));

        horizontalLayout_24->addWidget(MX_pre);


        verticalLayout_6->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_24 = new QLabel(GB_precipitacion);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_25->addWidget(label_24);

        MIN_pre = new QLineEdit(GB_precipitacion);
        MIN_pre->setObjectName(QString::fromUtf8("MIN_pre"));
        sizePolicy.setHeightForWidth(MIN_pre->sizePolicy().hasHeightForWidth());
        MIN_pre->setSizePolicy(sizePolicy);
        MIN_pre->setMaximumSize(QSize(100, 30));

        horizontalLayout_25->addWidget(MIN_pre);


        verticalLayout_6->addLayout(horizontalLayout_25);


        gridLayout_6->addLayout(verticalLayout_6, 0, 0, 1, 1);


        horizontalLayout_31->addWidget(GB_precipitacion);

        GB_intensidad = new QGroupBox(centralwidget);
        GB_intensidad->setObjectName(QString::fromUtf8("GB_intensidad"));
        sizePolicy.setHeightForWidth(GB_intensidad->sizePolicy().hasHeightForWidth());
        GB_intensidad->setSizePolicy(sizePolicy);
        GB_intensidad->setMaximumSize(QSize(500, 500));
        gridLayout_7 = new QGridLayout(GB_intensidad);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_13);

        label_25 = new QLabel(GB_intensidad);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_26->addWidget(label_25);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_14);


        verticalLayout_7->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        label_26 = new QLabel(GB_intensidad);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_27->addWidget(label_26);

        PR_in = new QLineEdit(GB_intensidad);
        PR_in->setObjectName(QString::fromUtf8("PR_in"));
        sizePolicy.setHeightForWidth(PR_in->sizePolicy().hasHeightForWidth());
        PR_in->setSizePolicy(sizePolicy);
        PR_in->setMaximumSize(QSize(100, 30));
        PR_in->setReadOnly(true);

        horizontalLayout_27->addWidget(PR_in);


        verticalLayout_7->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        label_27 = new QLabel(GB_intensidad);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_28->addWidget(label_27);

        MX_in = new QLineEdit(GB_intensidad);
        MX_in->setObjectName(QString::fromUtf8("MX_in"));
        sizePolicy.setHeightForWidth(MX_in->sizePolicy().hasHeightForWidth());
        MX_in->setSizePolicy(sizePolicy);
        MX_in->setMaximumSize(QSize(100, 30));

        horizontalLayout_28->addWidget(MX_in);


        verticalLayout_7->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        label_28 = new QLabel(GB_intensidad);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_29->addWidget(label_28);

        MIN_in = new QLineEdit(GB_intensidad);
        MIN_in->setObjectName(QString::fromUtf8("MIN_in"));
        sizePolicy.setHeightForWidth(MIN_in->sizePolicy().hasHeightForWidth());
        MIN_in->setSizePolicy(sizePolicy);
        MIN_in->setMaximumSize(QSize(100, 30));

        horizontalLayout_29->addWidget(MIN_in);


        verticalLayout_7->addLayout(horizontalLayout_29);


        gridLayout_7->addLayout(verticalLayout_7, 0, 0, 1, 1);


        horizontalLayout_31->addWidget(GB_intensidad);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Serif"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_29->setFont(font);

        verticalLayout_8->addWidget(label_29);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        minutos = new QLCDNumber(centralwidget);
        minutos->setObjectName(QString::fromUtf8("minutos"));
        sizePolicy.setHeightForWidth(minutos->sizePolicy().hasHeightForWidth());
        minutos->setSizePolicy(sizePolicy);
        minutos->setMaximumSize(QSize(150, 400));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(26);
        font1.setBold(true);
        font1.setWeight(75);
        minutos->setFont(font1);

        horizontalLayout->addWidget(minutos);

        segundos = new QLCDNumber(centralwidget);
        segundos->setObjectName(QString::fromUtf8("segundos"));
        sizePolicy.setHeightForWidth(segundos->sizePolicy().hasHeightForWidth());
        segundos->setSizePolicy(sizePolicy);
        segundos->setMaximumSize(QSize(150, 400));
        segundos->setFont(font1);

        horizontalLayout->addWidget(segundos);


        verticalLayout_8->addLayout(horizontalLayout);


        horizontalLayout_31->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_31);


        gridLayout_8->addLayout(verticalLayout_9, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 876, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        GB_temp->setTitle(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "(\302\260C)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        MX_temp->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Min\303\255mo", nullptr));
        GB_hum->setTitle(QCoreApplication::translate("MainWindow", "humedad ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "(%)", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        MX_hum->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Min\303\255mo", nullptr));
        GB_hum_suelo->setTitle(QCoreApplication::translate("MainWindow", "Humedad del suelo", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "(%)", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        MX_hum_suel->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Min\303\255mo", nullptr));
        GB_velocidad->setTitle(QCoreApplication::translate("MainWindow", "velocidad del viento", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", " m/s)", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        MX_vel->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Min\303\255mo", nullptr));
        GB_direccion->setTitle(QCoreApplication::translate("MainWindow", "direcci\303\263n del viento", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "(\302\260 Norte)", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        MX_dir->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", "Min\303\255mo", nullptr));
        GB_precipitacion->setTitle(QCoreApplication::translate("MainWindow", "precipitaci\303\263n", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "(mm)", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        MX_pre->setText(QString());
        label_24->setText(QCoreApplication::translate("MainWindow", "Min\303\255mo", nullptr));
        GB_intensidad->setTitle(QCoreApplication::translate("MainWindow", "Intensidad de luz.", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "(Lumen)", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Promedio", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "M\303\241ximo", nullptr));
        MX_in->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "Min\303\255mo", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Temporizador", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

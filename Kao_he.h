#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Kao_he.h"
#include <QLabel>
#include <QPushButton>
#include "G2_66.h"
#include "G2_72.h"
#include "G2_76.h"
#include "G3_30.h"
#include "G3_31.h"
#include "G3_32.h"
#include "G4_39.h"
#include "G4_43.h"
#include "G4_47.h"
#include "G4_56.h"
#include "G4_58.h"
#include "G4_59.h"

class Kao_he : public QMainWindow
{
    Q_OBJECT

public:
    Kao_he(QWidget *parent = Q_NULLPTR);
    QWidget* centralWidget;
    QLabel* label;
    QPushButton* jin;
    QPushButton* chou;
    QLabel* haoyun;
    QLabel* t_1;
    QLabel* t_2;
    QLabel* t_4;
    QLabel* t_3;
    QLabel* t_6;
    QLabel* t_5;
    QLabel* t_8;
    QLabel* t_7;
    QLabel* t_10;
    QLabel* t_9;
    QLabel* t_12;
    QLabel* t_11;
    QLineEdit* tip;
private slots:
    void chou_ti();
    void jin_chuang();
    QString Get_name();///得到控件名字
    void Change_name(QString thing);///对控件内容更改
    void Change_color(int x);///对控件内容更改

private:
    Ui::Kao_heClass ui;
};

#pragma once

#include <QWidget>
#include "ui_G4_59.h"
#include <iostream>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
using namespace std;

class G4_59 : public QWidget
{
	Q_OBJECT

public:
	G4_59(QWidget *parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLineEdit* s2;
    QLabel* label_3;
    QLineEdit* f1;
    QLabel* label_4;
    QLabel* label_7;
    QPushButton* he;
    QLabel* label_6;
    QLineEdit* f2;
    QLineEdit* s1;
    QLabel* label_8;
    QLabel* label_9;
    QLabel* daan;
    QCheckBox* jia;
    QCheckBox* jian;
    QLabel* label_10;
private slots:
    void key_k();
    void jia_2();
    void jian_2();
public:
    int wan_zheng();

private:
	Ui::G4_59 ui;
};



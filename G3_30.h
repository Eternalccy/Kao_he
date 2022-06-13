#pragma once

#include "ui_G3_30.h"
#include <QWidget>
#include <QTextBrowser>
#include <iostream>


class G3_30 : public QWidget
{
	Q_OBJECT

public:
	G3_30(QWidget *parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLineEdit* jg_90;
    QLabel* label;
    QPushButton* g_90;
    QPushButton* g_93;
    QLineEdit* jg_93;
    QLabel* label_2;
    QLabel* label_3;
    QPushButton* g_98;
    QLineEdit* jg_98;
    QComboBox* xuan_you;
    QLabel* label_4;
    QFrame* line;
    QFrame* line_2;
    QFrame* line_3;
    QLineEdit* you_liang;
    QFrame* line_4;
    QFrame* line_5;
    QFrame* line_6;
    QLabel* label_5;
    QPushButton* jia_man;
    QLabel* label_6;
    QLabel* you_money;
    QLabel* you_money_3;
    QLabel* label_8;
    QLabel* you_money_4;
    QLabel* label_9;
    QTabWidget* tabWidget;
    QWidget* all;
    QListView* all_d_1;
    QWidget* all_90;
    QListView* all_d_2;
    QWidget* all_93;
    QListView* all_d_3;
    QWidget* all_98;
    QListView* all_d_4;
    QLabel* label_10;
    QLabel* you_money_5;

private slots:
    void xuan_yy();
    void jia_yy();
    void yy_98_g();
    void yy_93_g();
    void yy_90_g();
public:
    void xian_you_all_3();
    QString Get_name(int a);
    void Change_name(QString thing);

private:
	Ui::G3_30 ui;
};

class CPetrol    //CPetrol¿‡
{
private:
    float j_oil[3];
    float price[3];
    float z_price[3];

public:
    void Set_oil_price(float a, float b, float c);
    float Get_oil_price(int all_dan);
    void js_price(int a, float p_price);
    float chu_price();
    CPetrol();
};
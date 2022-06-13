#pragma once

#include <QWidget>
#include "ui_G4_58.h"
#include <iostream>
#include <QLabel>
#include <QTextBrowser>
#include <QPushButton>
#include <QComboBox>
#include <QListView>
using namespace std;

class G4_58 : public QWidget
{
	Q_OBJECT

public:
	G4_58(QWidget *parent = Q_NULLPTR);
    QLabel* label_6;
    QLineEdit* name_1;
    QLabel* label;
    QLabel* label_13;
    QLabel* label_2;
    QLineEdit* money_1;
    QLabel* ti_shi;
    QLineEdit* tax_1;
    QLabel* label_5;
    QTextBrowser* textBrowser;
    QLineEdit* id_1;
    QListView* xian_shi;
    QPushButton* tian_jia;
    QLineEdit* base_1;
    QLabel* label_11;
    QLabel* label_10;
    QFrame* line;
    QComboBox* MOMO;
    QLabel* MOMO_M;
    QLabel* AA_L;
    QComboBox* AA_X;
    QLabel* BB_L;
    //QComboBox* BB_X;
    QLabel* ti_shi_2;
    QPushButton* tian_jia_2;
    QLabel* MOMO_M_2;
    QLineEdit* jia_money;
private slots:
    void lu_ru();
    void mo_kuai();
    void A_nnn();
    void geng_xin();
public:
    int wan_zheng();
    void no_see();
    void xian_shishi();

private:
	Ui::G4_58 ui;
};

class CTeacher {
public:
    string name;
    string id;
    float actual_salary;
private:
    
    float base_salary;
    float award_salary;
    float tax_salary;
    float add_salary;
    float kou_add_salary;
public:
    CTeacher(string n = "张三", string i = "2016222016")
    {
        name = n;
        id = i;
    }

    CTeacher(float b = 0, float a = 0, float t = 0,
        string n = "张三", string i = "2016222016") :CTeacher(n, i)
    {
        base_salary = b;
        award_salary = a;
        tax_salary = t;
        add_salary = 0;
        kou_add_salary = 0;
    }

    void Set(float a, float b, float c)
    {
        base_salary = a;
        award_salary = b;
        tax_salary = c;
        add_salary = 0;
        kou_add_salary = 0;
    }

    void Base() { actual_salary = (base_salary + award_salary)*(1 - tax_salary) + add_salary - kou_add_salary; }
    QString Get_new() {return QString::fromStdString( name + '\t' + id + '\n');}
    QString Get_all(int i);
    void Add(int b, float a);
    void Add(float a);
};
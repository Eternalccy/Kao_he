#pragma once

#include <QWidget>
#include <iostream>
#include "ui_G4_47.h"
#include <QTextBrowser>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QListView>
using namespace std;

class G4_47 : public QWidget
{
	Q_OBJECT

public:
	G4_47(QWidget *parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLineEdit* name;
    QLabel* label;
    QLineEdit* id;
    QLabel* label_6;
    QCheckBox* manager;
    QCheckBox* sale;
    QCheckBox* number;
    QCheckBox* hour;
    QLabel* label_7;
    QLabel* b_4;
    QLineEdit* a_2_3_4_pp;
    QLineEdit* b_4_pp;
    QLabel* a_2_3_4;
    QFrame* line;
    QFrame* line_2;
    QPushButton* jie_suan;
    QLabel* ti_shi;
    QListView* tiao_tiao;
    QLineEdit* b_4_pp_2;
    QLabel* b_5;
private slots:
    void count();
    void xx_1();
    void xx_2();
    void xx_3();
    void xx_4();
public:
    int wan_zheng(int a,int b);
    int only_id(string xx);
    void no_see();
    void xian_shi();

private:
	Ui::G4_47 ui;
};

class Employee {
protected:
    string name;
    string idd;
    float salary;
public:
    void SetEmployee(string nn, string ii) { name = nn; idd = ii; }
    string GetEmployee() { return (name + '\t' + idd + "\t\t"); }
    string Get_idd() { return  idd; }
    void SetSalary(float base_dan_hour, float ticheng_jiaban) { salary = base_dan_hour + ticheng_jiaban; }
};
class Manger :public Employee {
public:
    QString GetManger() { return QString::fromStdString(GetEmployee()) + QString::number(salary); }
};
class Salesperson :public Employee {
private:
    float sales_volume;
    float ti_cheng22;
    float base_bb;
public:
    void SetSalesperson(float xx, float tt, float bb) { sales_volume = xx; ti_cheng22 = tt/100; base_bb = bb; SetSalary(base_bb, sales_volume * ti_cheng22); }
    QString GetSalesperson() { return QString::fromStdString(GetEmployee()) + QString::number(base_bb) + "\t\t" + QString::number(sales_volume) + "\t\t" + QString::number(ti_cheng22 * 100) + "\t\t" + QString::number(salary); }
};
class Piecework :public Employee {
private:
    int number;
    float dan_price;
public:
    void SetPiecework(int xx, float tt) { number = xx; dan_price = tt; SetSalary(number * dan_price, 0); }
    QString GetPiecework() { return QString::fromStdString(GetEmployee()) + QString::number(number) + "\t\t" + QString::number(dan_price) + "\t\t" + QString::number(salary); }
};
class Hourly_Worker :public Employee {
private:
    float hour;
    float hour_price;
    float overtime;
public:
    void SetHourly_Worker(float aa, float bb, float pp) { hour = aa; overtime = bb; hour_price = pp; SetSalary(hour * hour_price, overtime); }
    QString GetHourly_Worker() { return QString::fromStdString(GetEmployee()) + QString::number(hour) + "\t\t" + QString::number(hour_price) + "\t\t" + QString::number(overtime) + "\t\t" + QString::number(salary); }
};
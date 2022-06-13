#include "G4_59.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")

G4_59::G4_59(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 4-59" << endl;
	ui.setupUi(this);
}

class Vector {
public:
    float x;
    float y;
public:
    Vector(float a = 0, float b = 0) { x = a; y = b; }
};

Vector operator +(Vector c1, Vector c2)
{
    Vector tt;
    tt.x = c1.x + c2.x;
    tt.y = c1.y + c2.y;
    return tt;
}

class Complex {
public:
    float p;
    float q;
public:
    Complex(float a = 0, float b = 0) { p = a; q = b; }
    Complex operator -(Complex c3)
    {
        Complex tt;
        tt.p = p - c3.p;
        tt.q = q - c3.q;
        return tt;
    }
};

//static  Vector vv1, vv2, vv3;
static int ff = 0;

void G4_59::key_k()////按钮
{
    ui.daan->setText("");
    string xx;
    if (wan_zheng())  ui.daan->setText("请输入完整信息！");
    else
    {
        if(ff==0) ui.daan->setText("请选择算法！");
        else
            if (ff == 1)
            {
                Vector vv1(ui.f1->text().toFloat(), ui.f2->text().toFloat()), vv2(ui.s1->text().toFloat(), ui.s2->text().toFloat());
                Vector vv3;
                vv3 = vv1 + vv2;
                xx = "(" + ui.f1->text().toStdString() + "," + ui.f2->text().toStdString() + ")+(" +
                    ui.s1->text().toStdString() + "," + ui.s2->text().toStdString() + ")\n=";
                ui.daan->setText(QString::fromStdString(xx) + "(" + QString::number(vv3.x) + "," + QString::number(vv3.y) + ")");
                xx = "";
            }
            else
            {
                Complex cc1(ui.f1->text().toFloat(), ui.f2->text().toFloat()), cc2(ui.s1->text().toFloat(), ui.s2->text().toFloat());
                Complex cc3;
                cc3 = cc1 - cc2;
                xx = "(" + ui.f1->text().toStdString() + "," + ui.f2->text().toStdString() + ")-(" +
                    ui.s1->text().toStdString() + "," + ui.s2->text().toStdString() + ")\n=";
                ui.daan->setText(QString::fromStdString(xx) + "(" + QString::number(cc3.p) + "," + QString::number(cc3.q) + ")");
                xx = "";
            }
    }
}

void G4_59::jia_2()//加减算法判断
{
    if (ui.jia->isChecked()) { ff = 1; ui.jian->setChecked(false); }
    else ff = 0;
}

void G4_59::jian_2()
{
    if (ui.jian->isChecked()) { ff = 2; ui.jia->setChecked(false); }
    else ff = 0;
}

int G4_59::wan_zheng()
{
    if (ui.f1->text() == "" || ui.f2->text() == "" || ui.s1->text() == "" || ui.s2->text() == "")
        return 1;
    else return 0;
}




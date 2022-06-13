#include "G2_66.h"
#include <iostream>
using namespace std;

G2_66::G2_66(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 2-66" << endl;
	ui.setupUi(this);
}

void G2_66::f1s2he()
{
	float a, b, c, d, s1, s2,x,y;
	QString xx;
	a = ui.f1->text().toFloat();
	b = ui.f2->text().toFloat();
	if (b >= 0)  xx = '(' + ui.f1->text() + '+' + ui.f2->text() + "i)+";
	else  xx = '(' + ui.f1->text() + ui.f2->text() + "i)+";
	c = ui.s1->text().toFloat(); 
	d = ui.s2->text().toFloat();
	if (d >= 0)  xx = xx + '(' + ui.s1->text() + '+' + ui.s2->text() + "i)";
	else  xx=xx+ '(' + ui.s1->text() + ui.s2->text() + "i)";
	ui.shizi->setText(xx);
	s1 = a + c;
	s2 = b + d;
	if (s2 >= 0)  ui.daan->setText('=' + QString::number(s1) + '+' + QString::number(s2) + 'i');
	else ui.daan->setText('=' + QString::number(s1) + QString::number(s2) + 'i');
}


#include "G2_72.h"
#include <QStandardItemModel>
#include <iostream>
using namespace std;
G2_72::G2_72(QWidget *parent)
	: QWidget(parent)
{
	
	cout << "Enter 2-72" << endl;
	ui.setupUi(this);
}

static QString show_xx[100];
static QString xx = "", xx_s[100];//目前存放   上一个存放
static int ff = 0, f, k = 0, k2 = 0;
static float b = 0, a = 0, a1, a2, s = -1, aa[100];//上一个存放

void G2_72::tui()//  退格
{
	if (k2 >= 1)
	{
	  k2--;
	  a = aa[k2];
	  xx = xx_s[k2];
	  if (k2 == ff) s--;//判断第一个数是否结束
	  if (k2 == 0)  b = 0;//退格全部后小数点为0
	  //cout << a << "  " << endl;
	  ui.gensui->setText(xx);
	}
}

void G2_72::shang_cun()
{
	aa[k2] = a;
	xx_s[k2++] = xx;
}

void G2_72::suan()//  =
{
	xx = xx + "=";
	ui.gensui->setText(xx);
	a2 = a;
	//cout << a1 <<"    " << a2 << endl;
	switch (f)
	{
	  case 1:s = a1 + a2; break;
	  case 2:s = a1 - a2; break;
	  case 3:s = a1 * a2; break;
	 default:s = a1 / a2; break;
	}
	xx = xx + QString::number(s);
	show_xx[k++] = xx;
	ui.gensui->setText("");//刷新
	xx = "";
	a = 0;//以上两个存放当前的整数，字符串
	b = 0;//判断是否小数
	s = 0;//计算两整数的计算
	k2 = 0;//存放整数和符号（式子），现清理
	ff = 0;//记录第一个整数下标，现清理
	s = -1;////////////////////确保刷新回到第一个数，同时也表示计算值
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.jxian->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	for (int i = k - 1; i >= 0; i--)
		model->appendRow(new QStandardItem(show_xx[i]));
	ui.jxian->setWordWrap(true);//自动换行
	ui.jxian->setModel(model);
}

void G2_72::j_jian()//  -
{
	if (s == -1) gui_ling();
	f = 2;
	shang_cun();
	xx = xx + "-";
	ui.gensui->setText(xx);
}

void G2_72::j_jia()//  +
{
	if (s == -1) gui_ling();
	f = 1;
	shang_cun();
	xx = xx + "+";
	ui.gensui->setText(xx);
}

void G2_72::j_chu()//  /
{
	if (s == -1) gui_ling();
	f = 4;
	shang_cun();
	xx = xx + "/";
	ui.gensui->setText(xx);
}

void G2_72::j_cheng()//  *
{
	if (s == -1) gui_ling();
	f = 3;
	shang_cun();
	xx = xx + "*";
	ui.gensui->setText(xx);
}

void G2_72::gui_ling()//简便清零
{
	s++;
	ff = k2 - 1;//第一个整数结束的下标
	a1 = a;
	a = 0;
	b = 0;
}

void G2_72::jj9()////////以下10个按键
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 9; }
	else a = a * 10 + 9;
	xx = xx + "9";
	ui.gensui->setText(xx);
}

void G2_72::jj8()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 8; }
	else a = a * 10 + 8;
	xx = xx + "8";
	ui.gensui->setText(xx);
}

void G2_72::jj7()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 7; }
	else a = a * 10 + 7;
	xx = xx + "7";
	ui.gensui->setText(xx);
}

void G2_72::jj6()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 6; }
	else a = a * 10 + 6;
	xx = xx + "6";
	ui.gensui->setText(xx);
}

void G2_72::jj5()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 5; }
	else a = a * 10 + 5;
	xx = xx + "5";
	ui.gensui->setText(xx);
}

void G2_72::jj4()
{
	shang_cun(); 
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 4; }
	xx = xx + "4";
	ui.gensui->setText(xx);
}

void G2_72::jj3()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 3; }
	else a = a * 10 + 3;
	xx = xx + "3";
	ui.gensui->setText(xx);
}

void G2_72::jj2()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 2; }
	else a = a * 10 + 2;
	xx = xx + "2";
	ui.gensui->setText(xx);
}

void G2_72::jj1()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 1; }
	else a = a * 10 + 1;
	xx = xx + "1";
	ui.gensui->setText(xx);
}

void G2_72::jj0()
{
	shang_cun();
	if (b > 0 && b <= 1) { b = b * 0.1; a = a + b * 0; }
	else a = a * 10 + 0;
	xx =xx+ "0";
	ui.gensui->setText(xx);
}

void G2_72::jj_d()//小数专用
{
	b = 1;
	shang_cun();
	xx = xx + ".";
	ui.gensui->setText(xx);
}

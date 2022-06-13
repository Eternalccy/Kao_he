#include "G4_43.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")
G4_43::G4_43(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 4-43" << endl;
	ui.setupUi(this);
}
static Father fat;
static Mother mot;
static Child chi[10];//一户最多十个baby？
static int k = 0;

void G4_43::father_first()//父亲姓氏
{
	ui.child_first->setText(ui.father_first1->text());
}

void G4_43::mother_nation()//母亲民族
{
	ui.child_nation->setText(ui.mother_nation1->text());
}

void G4_43::next_child()
{
	ui.ti_shi->setText("");
	if (wan_zheng(ui.father_first1->text().toStdString(), ui.father_name->text().toStdString(),//判断是否空消息
		ui.father_nation->text().toStdString(), ui.father_age->text().toStdString()) ||
		wan_zheng(ui.mother_first->text().toStdString(), ui.mother_name->text().toStdString(),
			ui.mother_nation1->text().toStdString(), ui.mother_age->text().toStdString()) ||
		wan_zheng("child first", ui.child_name->text().toStdString(), "child nation", ui.child_age->text().toStdString()) ||
		ui.child_gender->text().toStdString() == "")//性别临时加
		ui.ti_shi->setText("请输入完整信息！");
	else
	{
		if ((ui.mother_age->text().toInt() - ui.child_age->text().toInt() >= 20) &&
			(ui.mother_age->text().toInt() - ui.child_age->text().toInt() <= ui.mother_age->text().toInt()))
		{
			chi[k].SetChild(ui.father_first1->text().toStdString(), ui.child_name->text().toStdString(),
				ui.mother_nation1->text().toStdString(), ui.child_age->text().toInt(), ui.child_gender->text().toStdString());
			ui.child_name->setText("");
			ui.child_age->setText("");
		}
		else  ui.ti_shi->setText("请正确输入上一位子女！");
	}
}

void G4_43::f_m_c_xian()
{
	int ff_next = 0;
	ui.ti_shi->setText("");
	if (wan_zheng(ui.father_first1->text().toStdString(), ui.father_name->text().toStdString(),//判断是否空消息
		ui.father_nation->text().toStdString(), ui.father_age->text().toStdString()) ||
		wan_zheng(ui.mother_first->text().toStdString(), ui.mother_name->text().toStdString(),
			ui.mother_nation1->text().toStdString(), ui.mother_age->text().toStdString()) ||
		wan_zheng("child first", ui.child_name->text().toStdString(), "child nation", ui.child_age->text().toStdString())||
		ui.child_gender->text().toStdString()=="")//性别临时加
		    ui.ti_shi->setText("请输入完整信息！");
	else
	{
		if ((ui.mother_age->text().toInt() - ui.child_age->text().toInt() >= 20) &&
			(ui.mother_age->text().toInt() - ui.child_age->text().toInt() <= ui.mother_age->text().toInt()))
		{
			fat.SetFather(ui.father_first1->text().toStdString(), ui.father_name->text().toStdString(),
				ui.father_nation->text().toStdString(), ui.father_age->text().toInt());
			mot.SetMonther(ui.mother_first->text().toStdString(), ui.mother_name->text().toStdString(),
				ui.mother_nation1->text().toStdString(), ui.mother_age->text().toInt());
			chi[k].SetChild(ui.father_first1->text().toStdString(), ui.child_name->text().toStdString(),
				ui.mother_nation1->text().toStdString(), ui.child_age->text().toInt(), ui.child_gender->text().toStdString());
			QStandardItemModel* model = new QStandardItemModel(this);
			QStandardItem* item = new QStandardItem();
			ui.xian_shi_n->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
			model->appendRow(new QStandardItem("姓名\t        民族\t年龄\t性别"));
			model->appendRow(new QStandardItem(fat.GetFather()));
			model->appendRow(new QStandardItem(mot.GetMonther()));
			for (int i = 0; i < k; i++)
				model->appendRow(new QStandardItem(chi[i].GetChild(i)));
			ui.xian_shi_n->setWordWrap(true);//自动换行
			ui.xian_shi_n->setModel(model);
			ff_next = 0;
		}
		else { ui.ti_shi->setText("巨婴！"); ff_next = 1; }
	}
	if (ff_next) k = k;
	else k = 0;//新一户
}

int G4_43::wan_zheng(string xx, string nn, string zz, string aa)//判断是否信息空缺
{
	if (xx == "" || nn == "" || zz == "" || aa == "") return 1;
	else return 0;
}

void Father::SetFather(string xx, string nn, string zz, int aa) // father mother child类
{
	first = xx;
	name = nn;
	nation = zz;
	age = aa;
	gender = "男";
}

QString Father::GetFather()
{
	string xx;
	xx = first + name + "(父亲)        " + nation + '\t' + to_string(age) + '\t' + gender;
	return QString::fromStdString(xx);
}

void Mother::SetMonther(string xx, string nn, string zz, int aa)
{
	first = xx;
	name = nn;
	nation = zz;
	age = aa;
	gender = "女";
}

QString Mother::GetMonther()
{
	string xx;
	xx = first + name + "(母亲)       " + nation +'\t' + to_string(age)+'\t' + gender;
	return QString::fromStdString(xx);
}

void Child::SetChild(string xx, string nn, string zz, int aa, string gg)
{
	first = xx;
	name = nn;
	nation = zz;
	age = aa;
	gender = gg;
	k++;
}

QString Child::GetChild(int num)
{
	string xx;
	xx = first + name + "(子女" + to_string(num) + ")      " + nation + '\t' + to_string(age) + '\t' + gender;
	return QString::fromStdString(xx);
}

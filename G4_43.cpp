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
static Child chi[10];//һ�����ʮ��baby��
static int k = 0;

void G4_43::father_first()//��������
{
	ui.child_first->setText(ui.father_first1->text());
}

void G4_43::mother_nation()//ĸ������
{
	ui.child_nation->setText(ui.mother_nation1->text());
}

void G4_43::next_child()
{
	ui.ti_shi->setText("");
	if (wan_zheng(ui.father_first1->text().toStdString(), ui.father_name->text().toStdString(),//�ж��Ƿ����Ϣ
		ui.father_nation->text().toStdString(), ui.father_age->text().toStdString()) ||
		wan_zheng(ui.mother_first->text().toStdString(), ui.mother_name->text().toStdString(),
			ui.mother_nation1->text().toStdString(), ui.mother_age->text().toStdString()) ||
		wan_zheng("child first", ui.child_name->text().toStdString(), "child nation", ui.child_age->text().toStdString()) ||
		ui.child_gender->text().toStdString() == "")//�Ա���ʱ��
		ui.ti_shi->setText("������������Ϣ��");
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
		else  ui.ti_shi->setText("����ȷ������һλ��Ů��");
	}
}

void G4_43::f_m_c_xian()
{
	int ff_next = 0;
	ui.ti_shi->setText("");
	if (wan_zheng(ui.father_first1->text().toStdString(), ui.father_name->text().toStdString(),//�ж��Ƿ����Ϣ
		ui.father_nation->text().toStdString(), ui.father_age->text().toStdString()) ||
		wan_zheng(ui.mother_first->text().toStdString(), ui.mother_name->text().toStdString(),
			ui.mother_nation1->text().toStdString(), ui.mother_age->text().toStdString()) ||
		wan_zheng("child first", ui.child_name->text().toStdString(), "child nation", ui.child_age->text().toStdString())||
		ui.child_gender->text().toStdString()=="")//�Ա���ʱ��
		    ui.ti_shi->setText("������������Ϣ��");
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
			ui.xian_shi_n->setEditTriggers(QAbstractItemView::NoEditTriggers);//ֻ��
			model->appendRow(new QStandardItem("����\t        ����\t����\t�Ա�"));
			model->appendRow(new QStandardItem(fat.GetFather()));
			model->appendRow(new QStandardItem(mot.GetMonther()));
			for (int i = 0; i < k; i++)
				model->appendRow(new QStandardItem(chi[i].GetChild(i)));
			ui.xian_shi_n->setWordWrap(true);//�Զ�����
			ui.xian_shi_n->setModel(model);
			ff_next = 0;
		}
		else { ui.ti_shi->setText("��Ӥ��"); ff_next = 1; }
	}
	if (ff_next) k = k;
	else k = 0;//��һ��
}

int G4_43::wan_zheng(string xx, string nn, string zz, string aa)//�ж��Ƿ���Ϣ��ȱ
{
	if (xx == "" || nn == "" || zz == "" || aa == "") return 1;
	else return 0;
}

void Father::SetFather(string xx, string nn, string zz, int aa) // father mother child��
{
	first = xx;
	name = nn;
	nation = zz;
	age = aa;
	gender = "��";
}

QString Father::GetFather()
{
	string xx;
	xx = first + name + "(����)        " + nation + '\t' + to_string(age) + '\t' + gender;
	return QString::fromStdString(xx);
}

void Mother::SetMonther(string xx, string nn, string zz, int aa)
{
	first = xx;
	name = nn;
	nation = zz;
	age = aa;
	gender = "Ů";
}

QString Mother::GetMonther()
{
	string xx;
	xx = first + name + "(ĸ��)       " + nation +'\t' + to_string(age)+'\t' + gender;
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
	xx = first + name + "(��Ů" + to_string(num) + ")      " + nation + '\t' + to_string(age) + '\t' + gender;
	return QString::fromStdString(xx);
}

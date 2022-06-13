#include "G4_56.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")

G4_56::G4_56(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 4-56" << endl;
	ui.setupUi(this);
}

static int f = 1, k = 0;
static QString show_xx[2];
static string iddd_c;
//static Add stu[100];

void G4_56::lu_ru()
{
	ui.ti_shi->setText("");
	if (wan_zheng()) ui.ti_shi->setText("������������Ϣ��");
	else
	{/////1 2�ض�����Ŀ��
		if (f == 2)//bͬѧ����
		{
			if (ui.id_1->text().toStdString() == iddd_c)  ui.ti_shi->setText("�Ѵ��ڸ�ѧ����");
			else
			{
				Add stuB(ui.math_1->text().toFloat(), ui.english_1->text().toFloat(), ui.caozuo_1->text().toFloat(), ui.data_1->text().toFloat(),
					ui.name_1->text().toStdString(), ui.id_1->text().toStdString(), ui.gender_1->text().toStdString(), ui.age_1->text().toInt());//��������b
				show_xx[1] = stuB.chu() + "\n�ߵ���ѧ: " + stuB.GetAll(0) + "\n\nӢ  ��: " + stuB.GetAll(1) + "\n\n����ϵͳ: " + stuB.GetAll(2) +
					"\n\n���ݽṹ: " + stuB.GetAll(3) + "\n\n\t\t\t�ܳɼ���" + stuB.GetAll(4);//Ϊ�˺ÿ�
				ui.tian_jia->setText("¼ �� ѧ �� A");
				f++;
			}
			//stu[k++] = stuB;
		}
		if (f == 1)//aͬѧԭ����
		{
			Add stuA(ui.name_1->text().toStdString(), ui.id_1->text().toStdString(), ui.gender_1->text().toStdString(), ui.age_1->text().toInt());//��������a
			stuA.SetScore(ui.math_1->text().toFloat(), ui.english_1->text().toFloat(), ui.caozuo_1->text().toFloat(), ui.data_1->text().toFloat());
			show_xx[0] = stuA.chu()+ "\n�ߵ���ѧ: " + stuA.GetAll(0) +"\n\nӢ  ��: " + stuA.GetAll(1) + "\n\n����ϵͳ: " + stuA.GetAll(2) +
				"\n\n���ݽṹ: " + stuA.GetAll(3) + "\n\n\t\t\t�ܳɼ���" + stuA.GetAll(4);//Ϊ�˺ÿ�
			f++;
			//stu[k++] = stuA;
			iddd_c = ui.id_1->text().toStdString();
			ui.tian_jia->setText("¼ �� ѧ �� B");
		}
	xian_shishi();
	}
}

int G4_56::wan_zheng()
{
	if (ui.name_1->text().toStdString() == "" || ui.id_1->text().toStdString() == "" || ui.gender_1->text().toStdString() == "" ||
		ui.age_1->text().toStdString() == "" || ui.math_1->text().toStdString() == "" || ui.english_1->text().toStdString() == "" ||
		ui.caozuo_1->text().toStdString() == "" || ui.data_1->text().toStdString() == "")
		return  1;
	else return 0;
}

void G4_56::xian_shishi()
{
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.xian_shi->setEditTriggers(QAbstractItemView::NoEditTriggers);//ֻ��
	model->appendRow(new QStandardItem("����\tѧ��\t\t�Ա�\t����\n"));
	model->appendRow(new QStandardItem(show_xx[0]));
	if (f == 3) 
	{
		model->appendRow(new QStandardItem('\n' + show_xx[1]));
		f = 1; 
	}//���ӳ�
	ui.xian_shi->setWordWrap(true);//�Զ�����
	ui.xian_shi->setModel(model);
}




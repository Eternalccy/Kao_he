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
	if (wan_zheng()) ui.ti_shi->setText("请输入完整信息！");
	else
	{/////1 2特定（题目）
		if (f == 2)//b同学后构造
		{
			if (ui.id_1->text().toStdString() == iddd_c)  ui.ti_shi->setText("已存在该学生！");
			else
			{
				Add stuB(ui.math_1->text().toFloat(), ui.english_1->text().toFloat(), ui.caozuo_1->text().toFloat(), ui.data_1->text().toFloat(),
					ui.name_1->text().toStdString(), ui.id_1->text().toStdString(), ui.gender_1->text().toStdString(), ui.age_1->text().toInt());//构造输入b
				show_xx[1] = stuB.chu() + "\n高等数学: " + stuB.GetAll(0) + "\n\n英  语: " + stuB.GetAll(1) + "\n\n操作系统: " + stuB.GetAll(2) +
					"\n\n数据结构: " + stuB.GetAll(3) + "\n\n\t\t\t总成绩：" + stuB.GetAll(4);//为了好看
				ui.tian_jia->setText("录 入 学 生 A");
				f++;
			}
			//stu[k++] = stuB;
		}
		if (f == 1)//a同学原构造
		{
			Add stuA(ui.name_1->text().toStdString(), ui.id_1->text().toStdString(), ui.gender_1->text().toStdString(), ui.age_1->text().toInt());//构造输入a
			stuA.SetScore(ui.math_1->text().toFloat(), ui.english_1->text().toFloat(), ui.caozuo_1->text().toFloat(), ui.data_1->text().toFloat());
			show_xx[0] = stuA.chu()+ "\n高等数学: " + stuA.GetAll(0) +"\n\n英  语: " + stuA.GetAll(1) + "\n\n操作系统: " + stuA.GetAll(2) +
				"\n\n数据结构: " + stuA.GetAll(3) + "\n\n\t\t\t总成绩：" + stuA.GetAll(4);//为了好看
			f++;
			//stu[k++] = stuA;
			iddd_c = ui.id_1->text().toStdString();
			ui.tian_jia->setText("录 入 学 生 B");
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
	ui.xian_shi->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	model->appendRow(new QStandardItem("姓名\t学号\t\t性别\t年龄\n"));
	model->appendRow(new QStandardItem(show_xx[0]));
	if (f == 3) 
	{
		model->appendRow(new QStandardItem('\n' + show_xx[1]));
		f = 1; 
	}//有延迟
	ui.xian_shi->setWordWrap(true);//自动换行
	ui.xian_shi->setModel(model);
}




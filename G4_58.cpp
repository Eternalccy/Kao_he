#include "G4_58.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")

G4_58::G4_58(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 4-58" << endl;
	ui.setupUi(this);
	no_see();
}
static int f = 1, mm, taa;
static QString show_xx[2];
static CTeacher tea1("");
static CTeacher tea2("");

void  G4_58::lu_ru()
{
	if (f == 3) f = 1;//重置二人转
	ui.ti_shi->setText("");
	if (wan_zheng()) ui.ti_shi->setText("请输入完整信息！");
	else
	{
		if (f == 2)//b教师后构造
		{
			if(ui.id_1->text().toStdString()==tea1.id)  ui.ti_shi->setText("已存在该教师！");
			else
			{
				if (ui.tax_1->text().toFloat() > 0 && ui.tax_1->text().toFloat() < 1)
				{
					CTeacher teaB(ui.base_1->text().toFloat(), ui.money_1->text().toFloat(), ui.tax_1->text().toFloat(),
						ui.name_1->text().toStdString(), ui.id_1->text().toStdString());
					teaB.Base();
					tea2 = teaB;
					show_xx[1] = tea2.Get_new() + "\n基本工资: " + tea2.Get_all(1) + "\n\n奖  金: " + tea2.Get_all(2) + "\n\n所得税: " + tea2.Get_all(3) +
						"\n\n替课/加工资(所得): " + tea2.Get_all(5) + "\n\n被替课(所扣): " + tea2.Get_all(6) + "\n\n\t\t\t实际发放数：" + tea2.Get_all(4);//为了好看
					f++;
					ui.AA_X->addItem(ui.name_1->text());
				}
				else ui.ti_shi->setText("请正确填写所得税率！");
			}
		}
		if (f == 1)//a教师原构造
		{
			if (ui.tax_1->text().toFloat() > 0 && ui.tax_1->text().toFloat() < 1)
			{
				int nn = ui.AA_X->count();//清空下拉名字选项
				for (int i = nn - 1; i >= 0; i--)
				{
					ui.AA_X->removeItem(i);
				}
				CTeacher teaA(ui.name_1->text().toStdString(), ui.id_1->text().toStdString());
				teaA.Set(ui.base_1->text().toFloat(), ui.money_1->text().toFloat(), ui.tax_1->text().toFloat());
				teaA.Base();
				tea1 = teaA;
				show_xx[0] = tea1.Get_new() + "\n基本工资: " + tea1.Get_all(1) + "\n\n奖  金: " + tea1.Get_all(2) + "\n\n所得税: " + tea1.Get_all(3) +
					"\n\n替课/加工资(所得): " + tea1.Get_all(5) + "\n\n被替课(所扣): " + tea1.Get_all(6) + "\n\n\t\t\t实际发放数：" + tea1.Get_all(4);//为了好看
				f++;
				ui.tian_jia->setText("录 入 教 师 B");
				ui.AA_X->addItem(ui.name_1->text());
			}
		else ui.ti_shi->setText("请正确填写所得税率！");
		}
		xian_shishi();
	}
}

void G4_58::mo_kuai()
{
	no_see();
	mm = ui.MOMO->currentIndex();//取出序号    内容
	if (mm == 0)
	{
		ui.AA_X->setVisible(true);
		ui.AA_L->setVisible(true);
		ui.BB_L->setVisible(true);
		//ui.BB_X->setVisible(true);
		ui.MOMO_M_2->setVisible(true);
		ui.jia_money->setVisible(true);
		ui.ti_shi_2->setVisible(true);
		ui.BB_L->setText("  B ：");
		ui.ti_shi_2->setText("（ A 替 B 代 课 ）");
		//ui.tian_jia_2->setGeometry(30, 615, 151, 25);
	}
	else
	{
		ui.AA_X->setVisible(true);
		ui.AA_L->setVisible(true);
		ui.MOMO_M_2->setVisible(true);
		ui.jia_money->setVisible(true);
		ui.ti_shi_2->setVisible(true);
		ui.ti_shi_2->setText("（ 给 A 加 工 资 ）");
		//ui.tian_jia_2->setGeometry(30, 720, 151, 25);
	}
}

void G4_58::A_nnn()//名字ab互相显示（只能出现一个）
{
	taa = ui.AA_X->currentIndex();//取出序号    内容
	if (taa == 0)
		ui.BB_L->setText(QString::fromStdString("  B ：" + tea2.name));
	else
		ui.BB_L->setText(QString::fromStdString("  B ：" + tea1.name));
}

void G4_58::geng_xin()
{
	ui.ti_shi->setText("");
	if(ui.jia_money->text().toStdString()=="") ui.ti_shi->setText("请输入完整信息！");
	else
	{
		int tt;
		int mm = ui.MOMO->currentIndex();//取出序号    内容
		if (mm == 0)//代课
		{
			tt = ui.AA_X->currentIndex();
			if (tt == 0)
				if ((tea2.actual_salary - ui.jia_money->text().toFloat()) < 0) ui.ti_shi->setText("超过此人工资额度！");
				else  tea1.Add(2, ui.jia_money->text().toFloat());
			else
				if ((tea1.actual_salary - ui.jia_money->text().toFloat()) < 0) ui.ti_shi->setText("超过此人工资额度！");
				else  tea2.Add(1, ui.jia_money->text().toFloat());
		}
		else//加工资
		{
			tt = ui.AA_X->currentIndex();
			if (tt == 0)
				tea1.Add(ui.jia_money->text().toFloat());
			else
				tea2.Add( ui.jia_money->text().toFloat());
		}
	}
	show_xx[0] = tea1.Get_new() + "\n基本工资: " + tea1.Get_all(1) + "\n\n奖  金: " + tea1.Get_all(2) + "\n\n所得税: " + tea1.Get_all(3) +
		"\n\n替课/加工资(所得): " + tea1.Get_all(5) + "\n\n被替课(所扣): " + tea1.Get_all(6) + "\n\n\t\t\t实际发放数：" + tea1.Get_all(4);//为了好看
	show_xx[1] = tea2.Get_new() + "\n基本工资: " + tea2.Get_all(1) + "\n\n奖  金: " + tea2.Get_all(2) + "\n\n所得税: " + tea2.Get_all(3) +
		"\n\n替课/加工资(所得): " + tea2.Get_all(5) + "\n\n被替课(所扣): " + tea2.Get_all(6) + "\n\n\t\t\t实际发放数：" + tea2.Get_all(4);//为了好看
	xian_shishi();
}

int G4_58::wan_zheng()//判断信息完整
{
	if (ui.name_1->text().toStdString() == "" || ui.id_1->text().toStdString() == "" || ui.base_1->text().toStdString() == "" ||
		ui.money_1->text().toStdString() == "" || ui.tax_1->text().toStdString() == "")
		return 1;
	else return 0;
}

void G4_58::no_see()
{
	ui.AA_X->setVisible(false);
	ui.AA_L->setVisible(false);
	ui.BB_L->setVisible(false);
	ui.ti_shi_2->setVisible(false);
	ui.MOMO_M_2->setVisible(false);
	ui.jia_money->setVisible(false);
}

void G4_58::xian_shishi()
{
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.xian_shi->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	model->appendRow(new QStandardItem("姓名\tID号\n"));
	model->appendRow(new QStandardItem(show_xx[0]));
	if (f == 3)
	{
		model->appendRow(new QStandardItem('\n' + show_xx[1]));
		//f = 1;
	}//有延迟
	ui.xian_shi->setWordWrap(true);//自动换行
	ui.xian_shi->setModel(model);
}



QString CTeacher::Get_all(int i)////类的工资获取       工资转移
{
	float xx;
	if (i == 4)  return QString::number(actual_salary);
	else
	{
		i == 1 ? xx = (base_salary) :
			i == 2 ? xx = (award_salary) :
			i == 3 ? xx = (tax_salary) :
			i == 5 ? xx = (add_salary) :
			i == 6 ? xx = (kou_add_salary) : xx = -5;
		return QString::number(xx);
	}
}

void CTeacher::Add(int b, float a)
{
	add_salary = add_salary + a;
	actual_salary = actual_salary + add_salary;
	if (b == 1)
	{
		tea1.kou_add_salary = tea1.kou_add_salary + a;
		tea1.actual_salary = tea1.actual_salary - tea1.kou_add_salary;
	}
	else
	{
		tea2.kou_add_salary = tea2.kou_add_salary + a;
		tea2.actual_salary = tea2.actual_salary - tea2.kou_add_salary;
	}
}

void CTeacher::Add(float a)
{
	add_salary = add_salary + a;
	actual_salary = actual_salary + add_salary;
}


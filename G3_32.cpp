#include "G3_32.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")
G3_32::G3_32(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 3-32" << endl;
	ui.setupUi(this);
}
static CStudent student_ss[100];
static QString show_xx[100];//��Ŷ��ѧ����Ϣ
static int k = 0, ff = 0;//�Ƿ񳬳����

void G3_32::shang_jiao3()
{
    int f = 0;
    ui.ti_shi->setText("");
    if (ui.money_1->text().toStdString() == "")  ui.ti_shi->setText("������������Ϣ��");
    else
    {
        if (ui.id_1->text().toStdString() == "" || ui.name_1->text().toStdString() == "")  ui.ti_shi->setText("������������Ϣ��");
        else
        {
            for (int i = k - 1; i >= 0; i--)
                if (ui.id_1->text().toStdString() == student_ss[i].id) { f = 0; break; }
                else f = 1;
            if (f || k == 0) student_ss[k++].Contribute(ui.name_1->text().toStdString(), ui.id_1->text().toStdString(), ui.money_1->text().toFloat());
            else ui.ti_shi->setText("�Ѵ��ڸ�ѧ����");
        }
    }
    ui.all_money->setText(CStudent::Display());//����
    ui.all_student->setText(QString::number(CStudent::all_stu));//����
    show_money();//����

}

void G3_32::hua_fei()
{
    int i;
    ui.ti_shi->setText("");
    string aa, bb, cc;
    float dd;
    aa = ui.name_2->text().toStdString();
    bb = ui.id_2->text().toStdString();
    cc = ui.gender_2->text().toStdString();
    if (ui.money_2->text().toStdString() == "")  ui.ti_shi->setText("������������Ϣ��");
    else
    {
        dd = ui.money_2->text().toFloat();
        if (aa == "" || bb == "" || cc == "")  ui.ti_shi->setText("������������Ϣ��");
        else
        {
            for (i = k - 1; i >= 0; i--)
                if (student_ss[i].std == aa && student_ss[i].id == bb)
                {
                    student_ss[i].Spend(cc, dd);
                    if (!ff) ui.all_money->setText(CStudent::Display());
                    else ui.ti_shi->setText("�������ð�ѣ�");
                    break;
                }
            if (i < 0)  ui.ti_shi->setText("�Ǳ���ѧ����");
            show_money();
        }
    }
}

void G3_32::show_money()
{
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem();
    ui.money_xian->setEditTriggers(QAbstractItemView::NoEditTriggers);//ֻ��
        model->appendRow(new QStandardItem("����\tѧ��\t�Ͻ�(Ԫ)\t����(Ԫ)\t\t��;"));
        for (int i = k - 1; i >= 0; i--)
        {
            model->appendRow(new QStandardItem(show_xx[i]));
            //if (xx) model->appendRow(new QStandardItem(""));
        }
    ui.money_xian->setWordWrap(true);//�Զ�����
    ui.money_xian->setModel(model);
}

int CStudent::all_stu = 0;
float CStudent::z_money = 0;
void CStudent::Contribute(string name, string i_id ,float price)//Student ��
{
    std = name;
    id = i_id;
    show_xx[k++] = QString::fromStdString(std + '\t' + id + '\t') + QString::number(price) + "\t\\\t\t\\";
    all_stu++;
    z_money = z_money + price;
}

void CStudent::Spend(string t_thing, float m_money)
{
    ff = 0;
    thing = t_thing;
    money = m_money;
    z_money = z_money - money;
    if (z_money < 0) { z_money = z_money + money; ff = 1; }//������ʣ���ӻ�ȥ
    else show_xx[k++] = QString::fromStdString(std + '\t' + id + "\t\\\t") + QString::number(money) + "\t\t" + QString::fromStdString(thing);
}

QString CStudent::Display()
{
    return QString::number(z_money);
}


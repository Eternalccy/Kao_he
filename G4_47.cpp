#include "G4_47.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")

G4_47::G4_47(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 4-47" << endl;
	ui.setupUi(this);    
    no_see();
}
static Manger m[100];
static Salesperson s[100];
static Piecework p[100];
static Hourly_Worker h[100];
static int k1 = 0, k2 = 0, k3 = 0, k4 = 0, gou[4];

void G4_47::count()//����
{
    ui.ti_shi->setText("");
    string aa, bb;
    aa = ui.name->text().toStdString();
    bb = ui.id->text().toStdString();
    //no_see();
    if (wan_zheng(1,-5)) ui.ti_shi->setText("������������Ϣ��");//��Ϣ������
    else
    {
        if(only_id(bb)) ui.ti_shi->setText("�Ѵ��ڸù�Ա��");
        else
        {
            if (gou[0] && wan_zheng(0, 1)) ui.ti_shi->setText("������������Ϣ��");//һ��������     
            else
                if (gou[0])
                {
                    m[k1].SetEmployee(aa, bb);
                    m[k1++].SetSalary(ui.a_2_3_4_pp->text().toFloat(), 0);
                }

            if (gou[1] && wan_zheng(0, 3)) ui.ti_shi->setText("������������Ϣ��");//����������
            else
                if (gou[1])
                {
                    if (ui.b_4_pp->text().toFloat() < 0 || ui.b_4_pp->text().toFloat() > 100) ui.ti_shi->setText("����������");
                    else
                    {
                        s[k2].SetEmployee(aa, bb);
                        s[k2++].SetSalesperson(ui.a_2_3_4_pp->text().toFloat(), ui.b_4_pp->text().toFloat(), ui.b_4_pp_2->text().toFloat());
                    }
                }

            if (gou[2] && wan_zheng(0, 2)) ui.ti_shi->setText("������������Ϣ��");//����������   
            else
                if (gou[2])
                {
                    p[k3].SetEmployee(aa, bb);
                    p[k3++].SetPiecework(ui.a_2_3_4_pp->text().toInt(), ui.b_4_pp->text().toFloat());
                }

            if (gou[3] && wan_zheng(0, 3)) ui.ti_shi->setText("������������Ϣ��");//�Ŀ������� 
            else
                if (gou[3])
                {
                    if (ui.b_4_pp->text().toStdString() == "") ui.ti_shi->setText("������������Ϣ��");
                    else
                    {
                        h[k4].SetEmployee(aa, bb);
                        h[k4++].SetHourly_Worker(ui.a_2_3_4_pp->text().toFloat(), ui.b_4_pp->text().toFloat(), ui.b_4_pp_2->text().toFloat());
                    }
                }
        }
    }
    xian_shi();
}

void G4_47::xx_1()//�ĸ���ѡ  ���� ���� �Ƽ� ��ʱ
{
    no_see();
    if (ui.manager->isChecked() == true)
    {
        gou[2] = 0; gou[1] = 0; gou[3] = 0;
        ui.number->setChecked(false); ui.hour->setChecked(false); ui.sale->setChecked(false);
        ui.jie_suan->setVisible(true);
        ui.a_2_3_4->setVisible(true);
        ui.a_2_3_4_pp->setVisible(true);
        ui.a_2_3_4->setText("��  н��");
        ui.a_2_3_4_pp->setText("");
        // ui.jie_suan->setGeometry(350,153, 61, 25);
        ui.jie_suan->setVisible(true);
        gou[0] = 1;
    }
    else { no_see(); gou[0] = 0; }
}

void G4_47::xx_2()
{
    no_see();
    if (ui.sale->isChecked() == true)
    {
        gou[2] = 0; gou[0] = 0; gou[3] = 0;
        ui.number->setChecked(false); ui.manager->setChecked(false); ui.hour->setChecked(false);
            ui.jie_suan->setVisible(true);
            ui.a_2_3_4->setVisible(true);
            ui.a_2_3_4_pp->setVisible(true);
            ui.a_2_3_4->setText("���۶");
            ui.a_2_3_4_pp->setText("");
            ui.b_4->setVisible(true);
            ui.b_4_pp->setVisible(true);
            ui.b_4->setText("�� ��(%)��");
            ui.b_4_pp->setText("");
            ui.b_4_pp_2->setVisible(true);
            ui.b_5->setVisible(true);
            ui.b_4_pp_2->setText("");
            ui.b_5->setText("�������ʣ�");
            gou[1] = 1;
    }
    else { no_see(); gou[1] = 0; }
}

void G4_47::xx_3()
{
    no_see();
    if (ui.number->isChecked() == true)
    {
        gou[1] = 0; gou[0] = 0; gou[3] = 0;
        ui.hour->setChecked(false); ui.manager->setChecked(false); ui.sale->setChecked(false);
            ui.jie_suan->setVisible(true);
            ui.a_2_3_4->setVisible(true);
            ui.a_2_3_4_pp->setVisible(true);
            ui.a_2_3_4->setText("����������");
            ui.a_2_3_4_pp->setText("");
            ui.b_4->setVisible(true);
            ui.b_4_pp->setVisible(true);
            ui.b_4->setText("�������ۣ�");
            ui.b_4_pp->setText("");
            gou[2] = 1;
    }
    else { no_see(); gou[2] = 0; }
}

void G4_47::xx_4()
{
    no_see();
    if (ui.hour->isChecked() == true)
    {
        gou[2] = 0; gou[0] = 0; gou[1] = 0;
        ui.number->setChecked(false); ui.manager->setChecked(false); ui.sale->setChecked(false);
            ui.jie_suan->setVisible(true);
            ui.a_2_3_4->setVisible(true);
            ui.a_2_3_4_pp->setVisible(true);
            ui.a_2_3_4->setText("Сʱ����");
            ui.a_2_3_4_pp->setText("");
            ui.b_4_pp_2->setVisible(true);
            ui.b_5->setVisible(true);
            ui.b_4_pp_2->setText("");
            ui.b_5->setText("Сʱ/Ԫ��");
            ui.b_4->setVisible(true);
            ui.b_4_pp->setVisible(true);
            ui.b_4->setText("�Ӱ�ѣ�");
            ui.b_4_pp->setText("");
            gou[3] = 1;
    }
    else { no_see(); gou[3] = 0; }
}

int G4_47::wan_zheng(int a,int b)
{
    if(a)
      if (ui.name->text().toStdString() == "" || ui.id->text().toStdString() == "")
        return 1;
      else return 0; 
    if (b > 0)
    {
        int x, y, z, all= 0;
        if (all < b && ui.a_2_3_4_pp->text().toStdString() == "") { x = 1; all++; }
        else { x = 0; all++; }
        if (all < b && ui.b_4_pp->text().toStdString() == "") { y = 1; all++; }
        else { y = 0; all++; }
        if (all < b && ui.b_4_pp_2->text().toStdString() == "") { z = 1; all++; }
        else { z = 0; all++; }
        if ((x + y + z)) return 1;
        else return 0;
    }
}

int  G4_47::only_id(string xx)
{
    int i, j, kk, ff_id = 0;
    string xx_id;
    for (i = 0; i < 4; i++)
    {
        i == 0 ? kk = k1 : i == 1 ? kk = k2 : i == 2 ? kk = k3 : kk = k4;
        for (j = 0; j < kk; j++)
        {
            i == 0 ? xx_id = m[j].Get_idd() : i == 1 ? xx_id = s[j].Get_idd() : i == 2 ? xx_id = p[j].Get_idd() : xx_id = h[j].Get_idd();
            if (xx == xx_id) { ff_id = 1; break; }
        }
        if (ff_id) break;
    }
    if (ff_id) return 1;
    else return 0;
}

void G4_47::no_see()//���ɼ�ˢ��
{
    ui.jie_suan->setGeometry(780,153, 61, 25);
    ui.a_2_3_4->setVisible(false);
    ui.a_2_3_4_pp->setVisible(false);
    ui.b_4_pp->setVisible(false);
    ui.b_4->setVisible(false);
    ui.b_4_pp_2->setVisible(false);
    ui.b_5->setVisible(false);
    ui.jie_suan->setVisible(false);
}

void G4_47::xian_shi()
{
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem();
    ui.tiao_tiao->setEditTriggers(QAbstractItemView::NoEditTriggers);//ֻ��
    if (k1 > 0) model->appendRow(new QStandardItem("\t\t\t��   ��\n����\t���֤\t\t��нˮ"));
    for (int i = k1 - 1; i >= 0; i--)
        model->appendRow(new QStandardItem(m[i].GetManger()));
    if (k2 > 0) model->appendRow(new QStandardItem("\n\t\t\t�� �� Ա\n����\t���֤\t\t��������\t\t���۶�\t\t���(%)\t\t��нˮ"));
    for (int i = k2 - 1; i >= 0; i--)
        model->appendRow(new QStandardItem(s[i].GetSalesperson()));
    if (k3 > 0) model->appendRow(new QStandardItem("\n\t\t\t�� �� ��\n����\t���֤\t\t��������\t\t��������\t\t��нˮ"));
    for (int i = k3 - 1; i >= 0; i--)
        model->appendRow(new QStandardItem(p[i].GetPiecework()));
    if (k4 > 0) model->appendRow(new QStandardItem("\n\t\t\t\tС ʱ ��\n����\t���֤\t\tСʱ��\t\tСʱ/Ԫ\t\t�Ӱ��\t\t��нˮ"));
    for (int i = k4 - 1; i >= 0; i--)
        model->appendRow(new QStandardItem(h[i].GetHourly_Worker()));
    ui.tiao_tiao->setWordWrap(true);//�Զ�����
    ui.tiao_tiao->setModel(model);
}
#include "G3_30.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")
G3_30::G3_30(QWidget *parent)
	: QWidget(parent)
{
    cout << "Enter 3-30" << endl;
	ui.setupUi(this);
}

static QListView* now;
static QString show_xx[100];
static int yy, k = 0, show_yy[100];
static CPetrol jj_oil;
static float aa = 3.96, bb = 4.05, cc = 4.38;

void G3_30::xuan_yy()//ѡ��Ҫ�����͵���
{
    yy = ui.xuan_you->currentIndex();//ȡ�����    ����
    show_yy[k] = yy;//ʲô�ͺ�
    if (yy == 0)
    {
        show_xx[k] = "90��     " + QString::number(aa)+"Ԫ/L     ";
    }
    else if (yy == 1) 
    {
        show_xx[k] = "93��     " + QString::number(bb) + "Ԫ/L     ";
    }
    else 
    {
        show_xx[k] = "98��     " + QString::number(cc) + "Ԫ/L     ";
    }
    jj_oil.Set_oil_price(aa, bb, cc);
}

void G3_30::jia_yy()//�ɾ���   yy��֪�Ǹ��ͺ�
{
    if (ui.you_liang->text().toFloat())
    {
        xuan_yy();
        jj_oil.js_price(yy, ui.you_liang->text().toFloat());
        //cout << jj_oil.Get_oil_price(1) << "\t" << ui.you_liang->text().toFloat() << endl;
        show_xx[k] = show_xx[k] + QString::number(ui.you_liang->text().toFloat()) + "L         "
            + QString::number(jj_oil.Get_oil_price(1) * ui.you_liang->text().toFloat()) + "Ԫ     ";
        k++;
        xian_you_all_3();//��ʾ���׼�¼
        if (yy == 0) ui.you_money->setText(QString::number(jj_oil.Get_oil_price(0)));
        else if (yy == 1) ui.you_money_3->setText(QString::number(jj_oil.Get_oil_price(0)));
        else ui.you_money_4->setText(QString::number(jj_oil.Get_oil_price(0)));
        ui.you_money_5->setText(QString::number(jj_oil.chu_price()));
        //ui.you_liang->setText("0");
    }
}

QString G3_30::Get_name(int a)//��ȡlist����
{
    QString name, chuan2;
    chuan2 = QString::number(a);
    name = "all_d_" + chuan2;
    return name;
}

void  G3_30::Change_name(QString thing)
{
    QString objectNameBtn = thing;
    now = this->findChild<QListView*>(objectNameBtn);
}


void G3_30::xian_you_all_3()//��ʾ���׼�¼
{
    Change_name(Get_name(1));//����
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem();
    now->setEditTriggers(QAbstractItemView::NoEditTriggers);//ֻ��
    for (int i = k - 1; i >= 0; i--)
        model->appendRow(new QStandardItem(show_xx[i]));
    now->setWordWrap(true);//�Զ�����
    now->setModel(model);
    Change_name(Get_name(yy + 2));//90 93 98
    QStandardItemModel* model2 = new QStandardItemModel(this);
    QStandardItem* item2 = new QStandardItem();
    now->setEditTriggers(QAbstractItemView::NoEditTriggers);//ֻ��
    for (int i = k - 1; i >= 0; i--)
        if(yy==show_yy[i]) model2->appendRow(new QStandardItem(show_xx[i]));
    now->setWordWrap(true);//�Զ�����
    now->setModel(model2);
}

void G3_30::yy_98_g()//ui��ȡ�ͼ�
{
    cc = ui.jg_98->text().toFloat();
}

void G3_30::yy_93_g()
{
    bb = ui.jg_93->text().toFloat();
}

void G3_30::yy_90_g()
{
    aa = ui.jg_90->text().toFloat();
}



void CPetrol::Set_oil_price(float a, float b, float c)     //CPetrol���������
{
    price[0] = a;
    price[1] = b;
    price[2] = c;
}

float CPetrol::Get_oil_price(int all_dan)//���ض�Ӧ�۸�
{
    if (all_dan)
        return price[yy];
    else 
        return z_price[yy];
}


void CPetrol::js_price(int a, float p_price)  //90 93 98��Ӧ�ܼ�
{
    j_oil[a] = p_price;
    z_price[a] = z_price[a] + price[a] * j_oil[a];
}

float CPetrol::chu_price()//������
{
    float ss;
    ss = z_price[0] + z_price[1] + z_price[2];
    return ss;
}

CPetrol::CPetrol()
{
    price[0] = aa; price[1] = bb; price[2] = cc;
    j_oil[0] = 0; j_oil[1] = 0; j_oil[2] = 0;
    z_price[0] = 0; z_price[1] = 0; z_price[2] = 0;
}

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

void G3_30::xuan_yy()//选择要加类型的油
{
    yy = ui.xuan_you->currentIndex();//取出序号    内容
    show_yy[k] = yy;//什么型号
    if (yy == 0)
    {
        show_xx[k] = "90号     " + QString::number(aa)+"元/L     ";
    }
    else if (yy == 1) 
    {
        show_xx[k] = "93号     " + QString::number(bb) + "元/L     ";
    }
    else 
    {
        show_xx[k] = "98号     " + QString::number(cc) + "元/L     ";
    }
    jj_oil.Set_oil_price(aa, bb, cc);
}

void G3_30::jia_yy()//可劲加   yy得知那个型号
{
    if (ui.you_liang->text().toFloat())
    {
        xuan_yy();
        jj_oil.js_price(yy, ui.you_liang->text().toFloat());
        //cout << jj_oil.Get_oil_price(1) << "\t" << ui.you_liang->text().toFloat() << endl;
        show_xx[k] = show_xx[k] + QString::number(ui.you_liang->text().toFloat()) + "L         "
            + QString::number(jj_oil.Get_oil_price(1) * ui.you_liang->text().toFloat()) + "元     ";
        k++;
        xian_you_all_3();//显示交易记录
        if (yy == 0) ui.you_money->setText(QString::number(jj_oil.Get_oil_price(0)));
        else if (yy == 1) ui.you_money_3->setText(QString::number(jj_oil.Get_oil_price(0)));
        else ui.you_money_4->setText(QString::number(jj_oil.Get_oil_price(0)));
        ui.you_money_5->setText(QString::number(jj_oil.chu_price()));
        //ui.you_liang->setText("0");
    }
}

QString G3_30::Get_name(int a)//获取list名字
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


void G3_30::xian_you_all_3()//显示交易记录
{
    Change_name(Get_name(1));//所有
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem();
    now->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
    for (int i = k - 1; i >= 0; i--)
        model->appendRow(new QStandardItem(show_xx[i]));
    now->setWordWrap(true);//自动换行
    now->setModel(model);
    Change_name(Get_name(yy + 2));//90 93 98
    QStandardItemModel* model2 = new QStandardItemModel(this);
    QStandardItem* item2 = new QStandardItem();
    now->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
    for (int i = k - 1; i >= 0; i--)
        if(yy==show_yy[i]) model2->appendRow(new QStandardItem(show_xx[i]));
    now->setWordWrap(true);//自动换行
    now->setModel(model2);
}

void G3_30::yy_98_g()//ui获取油价
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



void CPetrol::Set_oil_price(float a, float b, float c)     //CPetrol类具体内容
{
    price[0] = a;
    price[1] = b;
    price[2] = c;
}

float CPetrol::Get_oil_price(int all_dan)//返回对应价格
{
    if (all_dan)
        return price[yy];
    else 
        return z_price[yy];
}


void CPetrol::js_price(int a, float p_price)  //90 93 98对应总价
{
    j_oil[a] = p_price;
    z_price[a] = z_price[a] + price[a] * j_oil[a];
}

float CPetrol::chu_price()//总收入
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

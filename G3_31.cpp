#include "G3_31.h"
#include <iostream>
#include <string>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")
G3_31::G3_31(QWidget *parent)
	: QWidget(parent)
{
	cout << "Enter 3-31" << endl;
	ui.setupUi(this);
}

static Student student_ss[100];
static QString show_xx[100];//存放多个学生
static int k = 0, show_yy[100], tiao_jian[4];//存放单个学生
int Student::sum = 0;
void G3_31::add_student()
{
    int aa, f=0;
    string bb, cc, dd;
    ui.ti_shi->setText("");
    bb = ui.name_1->text().toStdString();
    cc = ui.id_1->text().toStdString();
    dd = ui.gender_1->text().toStdString();
    if(ui.age_1->text()=="") ui.ti_shi->setText("请输入完整信息！");//判断是否输入完整
    else
    {
        aa = ui.age_1->text().toInt();
        if (bb == "" || cc == "" || dd == "" ) ui.ti_shi->setText("请输入完整信息！");
        else
        {
            for (int i = k - 1; i >= 0; i--)
            {
                if(student_ss[i].id==cc) { f = 1; break; }//学号重复
            }
            if (!f) 
            {
                show_xx[k] = student_ss[k].Set_student(bb, cc, dd, aa);
                k++;
                all_all2();
            }
            else ui.ti_shi->setText("已存在该学生，请重新输入！");
            f = 0;
        }

    }
}

int G3_31::xx_1()//判断选框是否可用
{
    if (ui.xx_name->isChecked() == true)
    {
        ui.name_2->setEnabled(true);
        return 1;
    }
    else 
    {
        ui.name_2->setDisabled(true);
        ui.name_2->setText("");
        return 0;
    }
}

int G3_31::xx_2()
{
    if (ui.xx_id->isChecked() == true)  
    {
        ui.id_2->setEnabled(true);
        return 1;
    }
    else 
    {
        ui.id_2->setDisabled(true);
        ui.id_2->setText("");
        return 0;
    }
}

int G3_31::xx_3()
{
    if (ui.xx_gender->isChecked() == true)  
    {
        ui.gender_2->setEnabled(true);
        return 1;
    }
    else 
    { 
        ui.gender_2->setDisabled(true); 
        ui.gender_2->setText("");
        return 0;
    }
}

int G3_31::xx_4()
{
    if (ui.xx_age->isChecked() == true)  
    {
        ui.age_2->setEnabled(true);
        return 1;
    }
    else 
    {
        ui.age_2->setDisabled(true);
        ui.age_2->setText("");
        return 0;
    }
}

void G3_31::all_all2() //快捷显示学生信息
{
    show_student_new(-5);
    ui.all_student->setText(QString::number(Student::sum_stu()));
    ui.all_all->setStyleSheet("background-color:#cbffd3");
    ui.sou_sou->setStyleSheet("background-color:#e1e1e1");
}
void G3_31::sou_sou2() 
{ 
    search_student();
}

void G3_31::search_student()//查找学生
{
    string aa, bb, cc;
    ui.sou_sou->setStyleSheet("background-color:#cbffd3");
    ui.all_all->setStyleSheet("background-color:#e1e1e1");
    int f, age;
    ui.ti_shi->setText("");//刷新提示
    aa = ui.name_2->text().toStdString();
    bb = ui.id_2->text().toStdString();
    cc = ui.gender_2->text().toStdString();
    tiao_jian[0] = xx_1();//条件用于判断复选框的判断个数
    tiao_jian[1] = xx_2();
    tiao_jian[2] = xx_3();
    tiao_jian[3] = xx_4();
    if (ui.age_2->text().toStdString() == "")  age = 0;
    else age = ui.age_2->text().toInt();
    f = Student::search_name_id_stu(ui.name_2->text().toStdString(), ui.id_2->text().toStdString(),
        ui.gender_2->text().toStdString(), age);//查找学生

    if (ui.age_2->text() == "" && tiao_jian[3]) f = -10;//判断是否输入完整
    else
        if ((aa == "" && tiao_jian[0]) || (bb == "" && tiao_jian[1]) || (cc == "" && tiao_jian[2]))
            f = -10;

    if (f < 0)//-5  -10 
    {
        if(f==-5)  ui.ti_shi->setText("查无此人！");
        else ui.ti_shi->setText("请输入完整信息！");
        show_student_new(-3);
        ui.all_student->setText("0");
    }
    else
    {
        show_student_new(f);
        //cout << "now=" << f << endl;
        ui.all_student->setText(QString::number(f));
    }
}

void G3_31::show_student_new(int pp)
{
    //cout << pp << endl;//////////////
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem();
    ui.student_new->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
    if (pp == -5)//所有人
    {
        model->appendRow(new QStandardItem("姓名\t学号\t\t性别\t年龄"));
        for (int i = k - 1; i >= 0; i--)
            model->appendRow(new QStandardItem(show_xx[i]));
    }
    else if (pp == -3)//找不到人，空白
        model->appendRow(new QStandardItem(""));
    else//找到人
    {
        model->appendRow(new QStandardItem("姓名\t\t\t学号"));
        for (int i = pp - 1; i >= 0; i--)
        {
            QString xx;
            xx = QString::fromStdString(student_ss[show_yy[i]].name + "\t\t\t" + student_ss[show_yy[i]].id);
            model->appendRow(new QStandardItem(xx));
            //model->appendRow(new QStandardItem(show_xx[show_yy[i]]));
        }
    }
    ui.student_new->setWordWrap(true);//自动换行
    ui.student_new->setModel(model);
}

QString Student::Set_student(string nn, string ii, string gg, int aa)
{
    name = nn;
    id = ii;
    gender = gg;
    age = aa;
    sum++;
    return chu(nn, ii, gg, aa);
}

QString Student::chu(string n, string i, string x, int a) 
{
    string xx;
    xx = n + '\t' + i + "\t\t" + x + '\t' + to_string(a);
    return QString::fromStdString(xx);
}

int Student::sum_stu() 
{
    return sum;
}

int Student::search_name_id_stu(string nn, string ii, string gg, int aa)
{
    int j = 0, a, b;
    a = tiao_jian[0] + tiao_jian[1] + tiao_jian[2] + tiao_jian[3];
    for (int i = 0; i < k; i++)
    {
        b = 0; 
        int idx, idx2, idx3, idx4;
        student_ss[i].name == nn ? idx = 0 : idx = 1;
        student_ss[i].id == ii ? idx2 = 0 : idx2 = 1;
        student_ss[i].gender == gg ? idx3 = 0 : idx3 = 1;
        student_ss[i].age == aa ? idx4 = 0 : idx4 = 1;
        if (tiao_jian[0] == 1 && idx == 0) b++;
        if (tiao_jian[1] == 1 && idx2 == 0) b++;
        if (tiao_jian[2] == 1 && idx3 == 0) b++;
        if (tiao_jian[3] == 1 && idx4 == 0) b++;
        if (a == b) show_yy[j++] = i;
    }
    if (j > 0) return j;
    else return -5;
}

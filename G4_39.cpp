#include "G4_39.h"
#include <iostream>
#include <QStandardItemModel>
using namespace std;
#pragma execution_character_set("utf-8")
G4_39::G4_39(QWidget* parent)
    : QWidget(parent)
{
    cout << "Enter 4-39" << endl;
    ui.setupUi(this);
}

static Book book_bb[100];
static Reader read_bb[100];
static int k = 0, k2 = 0;
static QListView* now;

void G4_39::shou_lu()
{
    string aa, bb, cc, dd;
    aa = ui.book_name->text().toStdString();
    bb = ui.book_writer->text().toStdString();
    cc = ui.book_nation->text().toStdString();
    dd = ui.book_number->text().toStdString();
    ui.ti_shi->setText("");
    if (aa == "" || bb == "" || cc == "" || dd == "") ui.ti_shi->setText("请输入完整信息！");
    else
        book_bb[k].SetBook(aa, bb, cc, ui.book_number->text().toInt(), ui.book_id->text().toInt());
    show_book_nei(-5,0);//显示书本信息
    ui.book_id->setText(QString::number(k+1));//book  id更新
    ui.all_book_number->setText(QString::number(Book::sum_39));
}

void G4_39::jie_yue()
{
    int i;
    string aa, bb, cc, dd;
    aa = ui.stu_name->text().toStdString();
    bb = ui.stu_id->text().toStdString();
    cc = ui.stu_book->text().toStdString();
    dd = ui.stu_book_id->text().toStdString();
    ui.ti_shi->setText("");
    if (aa == "" || bb == "" || cc == "" || dd == "") ui.ti_shi->setText("请输入完整信息！");
    else
    {
        if (ui.stu_book_id->text().toInt() > 0 && ui.stu_book_id->text().toInt() <= k)//借阅的书编号是否书图书馆内的书
        {
            for (i = k2 - 1; i >= 0; i--)
                if (ui.stu_id->text().toStdString() == read_bb[i].id)
                {
                    if (read_bb[i].jie_book_num == 6)      ui.ti_shi->setText("最多可借  6  本！");
                    else
                        for (int j = 0; j < k; j++)//判断是否被借阅
                        {
                            if (book_bb[j].jie_huan == 1 && ui.stu_book_id->text().toInt() == book_bb[j].book_idd[0])  ui.ti_shi->setText("此书已被借阅！");
                            else
                                read_bb[i].SetReader(ui.stu_name->text().toStdString(), ui.stu_id->text().toStdString(),
                                    ui.stu_book->text().toStdString(), ui.stu_book_id->text().toInt(), 0);
                            break;

                        }
                    break;
                }
            if (i < 0 || k2 == 0)//还没接过书或第一个
                read_bb[k2].SetReader(ui.stu_name->text().toStdString(), ui.stu_id->text().toStdString(),
                    ui.stu_book->text().toStdString(), ui.stu_book_id->text().toInt(), 1);
        }
        else ui.ti_shi->setText("还未收录！");
    }
    show_book_nei(-5,0);
}

void G4_39::reader_cha()
{
    int i;
    ui.ti_shi->setText("");
    for (i = k2 - 1; i >= 0; i--)
        if (ui.stu_id2->text().toStdString() == read_bb[i].id)
        { 
            show_book_nei(i,1);
            break;
        }
    if (i < 0) ui.ti_shi->setText("不是本校学生！");
}

void G4_39::book_id_cha()//不是id，是书名查找，懒得改
{
    int i;
    ui.ti_shi->setText("");
    for (i = k - 1; i >= 0; i--)
        if (ui.book_id2->text().toStdString() == book_bb[i].GetBook_new(1))
        {
            show_book_nei(i, 2);
            break;
        }

    if (i < 0) ui.ti_shi->setText("还未收录！");
}

void G4_39::huan_shu()//还书
{
    int ffx = 0;
    if(ui.huan_book_idd->text().toStdString()=="")   ui.ti_shi->setText("请输入完整信息！");
    else 
    {
        int i;
        for (i = k - 1; i >= 0; i--)
            if (ui.huan_book_idd->text().toInt() == book_bb[i].book_idd[0])
            {
                if (book_bb[i].jie_huan == 0) {  ui.ti_shi->setText("本书并未借阅！"); break; }//b本身没有借阅
                else
                {
                    book_bb[i].jie_huan = 0;//还书记号
                    for (int j = k2 - 1; j >= 0; j--)                //读者记录删除
                    {
                        for (int k3 = 0; k3 < read_bb[j].jie_book_num; k3++)
                        {
                            if (read_bb[j].book_idd[k3] == ui.huan_book_idd->text().toInt())
                            {
                                for (int p = k3; p < read_bb[j].jie_book_num - 1; p++)
                                {
                                    read_bb[j].book_idd[p] = read_bb[j].book_idd[p + 1];
                                    read_bb[j].title[p] = read_bb[j].title[p + 1];
                                }
                                read_bb[j].jie_book_num--;
                                ffx = 1;
                                break;
                            }
                        }
                        if (ffx)  break;
                    }
                    break;
                }
            }
        if (i < 0) ui.ti_shi->setText("还未收录！");
    }
    show_book_nei(-5, 0);//更新书本信息
    
}

void G4_39::show_book_nei(int p, int f)//f  读者还是书本
{
    QString objectNameBtn;//获取哪一个显示
    if (p == -5)
        objectNameBtn = QString::fromStdString("all_book_xian");
    else
        objectNameBtn = QString::fromStdString("reader_book");
    now = this->findChild<QListView*>(objectNameBtn);
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem();
    now->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
    if (p == -5)//显示所有
    {
        model->appendRow(new QStandardItem("书名\t作者\t国籍\t本数\t编号\t借阅情况"));
        for (int i = k - 1; i >= 0; i--)
            model->appendRow(new QStandardItem(book_bb[i].ShowBook()));
    }
    else//显示对应借阅者   或
    {
        if (f == 1)
        {
            model->appendRow(new QStandardItem(QString::fromStdString("姓名： " + read_bb[p].name + "\t\t\tID： " + read_bb[p].id)));
            model->appendRow(new QStandardItem(QString::fromStdString("\n书名\t\t\t编号")));
            for (int i = read_bb[p].jie_book_num - 1; i >= 0; i--)
                model->appendRow(new QStandardItem(read_bb[p].GetReader(i)));
        }
        else
        {
            model->appendRow(new QStandardItem(QString::fromStdString("书名： " +book_bb[p].GetBook_new(1) + "\t\t作者： " + book_bb[p].GetBook_new(2) + "\t\t国籍:" + book_bb[p].GetBook_new(3))));
            model->appendRow(new QStandardItem(QString::fromStdString("\n编号\t\t借阅情况\t借阅者\t\t借阅ID")));
            int i = p;
            while(book_bb[i].GetBook_new(1)==ui.book_id2->text().toStdString())
            {
                model->appendRow(new QStandardItem(book_bb[i].GetBook(i)));
                i--;
            }
        }
    }
    now->setWordWrap(true);//自动换行
    now->setModel(model);
}

int Book::sum_39 = 0;
void Book::SetBook(string nn, string aa, string nat, int numb, int idd)///BOOK类
{
    for (int i = 0; i < numb; i++)
    {
        book_bb[k].jie_huan = 0;
        book_bb[k].title[0] = nn;
        book_bb[k].author = aa;
        book_bb[k].nation = nat;
        book_bb[k].number = numb;
        book_bb[k++].book_idd[0] = idd + i;
        sum_39++;
    }
}

string  Book::GetBook_new(int a)//1  书名  2作者 3国籍
{
    if (a == 1) return title[0];
    else if(a==2)     return author;
    else return nation;
}

QString Book::GetBook(int ben)//第二个list辅助
{
    string xx, xx2, xx3;
    jie_huan == 1 ? xx2 = "已借" : xx2 = "\\";
    for (int i = 0; i < k2; i++)//查找谁借阅了本书
        for (int j = 0; j < read_bb[i].jie_book_num; j++)
            if (read_bb[i].book_idd[j] == book_idd[0])
            {
                xx3 = read_bb[i].name + "\t\t" + read_bb[i].id;
                break;
            }
            else xx3 = "\\\t\t\\";
    if (k2 == 0) xx3 = "\\\t\t\\";
    xx = to_string(book_idd[0]) + "\t\t" + xx2 + "\t" + xx3;
    return  QString::fromStdString(xx);
}

QString Book::ShowBook()//书的全部
{
    string xx, xx2;
    jie_huan == 1 ? xx2 = "已借" : xx2 = "";
    xx = title[0] + '\t' + author + '\t' + nation + '\t' + to_string(number) + '\t'
        + to_string(book_idd[0]) + '\t' + xx2;
    return  QString::fromStdString(xx);
}

void  Reader::SetReader(string nn, string iid, string book_n, int book_ii,int ff)//READER类
{
    for (int i = 0; i < k; i++)//设置书本借阅与否
        if (book_ii == book_bb[i].book_idd[0])
        {
            book_bb[i].jie_huan = 1; break;
        }
    name = nn;
    id = iid;
    title[jie_book_num] = book_n;
    book_idd[jie_book_num++] = book_ii;
    if (ff) k2++;
}

QString  Reader::GetReader(int ben)//第二个list辅助
{
    string xx;
    xx = title[ben] + "\t\t\t" + to_string(book_idd[ben]);
    return  QString::fromStdString(xx);
}

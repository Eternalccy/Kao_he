#pragma once

#include <QWidget>
#include "ui_G4_39.h"
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include <QTextBrowser>
using namespace std;
class G4_39 : public QWidget
{
	Q_OBJECT

public:
	G4_39(QWidget *parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLabel* label_5;
    QLineEdit* book_writer;
    QPushButton* shang_jiao;
    QLabel* label;
    QLineEdit* book_name;
    QLabel* label_6;
    QLineEdit* book_id;
    QLabel* label_7;
    QLineEdit* stu_name;
    QPushButton* shang_jiao2;
    QLabel* label_4;
    QLabel* label_12;
    QLabel* label_3;
    QLineEdit* stu_book;
    QLineEdit* stu_id;
    QLabel* label_8;
    QFrame* line;
    QLineEdit* stu_book_id;
    QLabel* label_9;
    QTabWidget* ji_lu;
    QWidget* all_shuben;
    QListView* all_book_xian;
    QWidget* tab_2;
    QLabel* label_10;
    QLineEdit* stu_id2;
    QPushButton* shang_jiao2_2;
    QLineEdit* book_id2;
    QLabel* label_13;
    QPushButton* shang_jiao2_3;
    QListView* reader_book;
    QLabel* label_11;
    QLineEdit* book_nation;
    QLabel* label_14;
    QLabel* all_book_number;
    QLabel* ti_shi;
    QLineEdit* book_number;
    QLabel* label_15;
    QLabel* label_16;
    QFrame* line_2;
    QLineEdit* huan_book_idd;
    QLabel* label_17;
    QPushButton* shang_jiao2_4;

private slots:
    void shou_lu();
    void jie_yue();
    void reader_cha();
    void book_id_cha();
    void huan_shu();
public:
    void show_book_nei(int p, int f);
private:
	Ui::G4_39 ui;
};

class Book
{
protected:

    string author;
    string nation;
    int number;
public:
    string title[6];
    int book_idd[6];
    int jie_huan;
    static int sum_39;
    void SetBook(string nn, string aa, string nat, int numb, int idd);
    string GetBook_new(int a);//获取book信息
    QString GetBook(int ben);//辅助listview 显示
    QString ShowBook();//listview战术书本全部内容
};

class Reader :public Book
{
public:
    string name;
    string id;
    int jie_book_num;//借书最多六本
public:
    
    Reader() { jie_book_num = 0; }
    void SetReader(string nn, string id, string book_n, int book_ii, int ff);
    QString GetReader(int ben);//辅助listview 显示
};
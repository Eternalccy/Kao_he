#pragma once

#include <QWidget>
#include "ui_G3_31.h"
#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>
#include <QListView>
#include <QCheckBox>
using namespace std;

class G3_31 : public QWidget
{
    Q_OBJECT

public:
    G3_31(QWidget* parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLabel* label_2;
    QLabel* label;
    QLineEdit* id_1;
    QLabel* label_3;
    QLineEdit* name_1;
    QLineEdit* gender_1;
    QLabel* label_4;
    QLineEdit* age_1;
    QPushButton* tian_jia;
    QLabel* label_5;
    QLabel* label_6;
    QLabel* all_student;
    QFrame* line;
    QLabel* label_8;
    QPushButton* sou_suo;
    QLabel* ti_shi;
    QListView* student_new;
    QCheckBox* xx_name;
    QCheckBox* xx_id;
    QCheckBox* xx_gender;
    QCheckBox* xx_age;
    QLineEdit* age_2;
    QLineEdit* id_2;
    QLineEdit* name_2;
    QLabel* label_7;
    QLabel* label_11;
    QLabel* label_12;
    QLabel* label_13;
    QLineEdit* gender_2;
    QPushButton* all_all;
    QPushButton* sou_sou;

private slots:
    void add_student();
    void search_student();
    void show_student_new(int pp);
    int xx_1();
    int xx_2();
    int xx_3();
    int xx_4();
    void all_all2();//快捷显示学生信息
    void sou_sou2();

private:
    Ui::G3_31 ui;
};

class Student
{
private:
    string gender;
    int age;
    static int sum;
public:
    string name;
    string id;
    Student(string nn = "张三", string ii = "2016222016", string gg = "女", int aa = 20)//Student类
    {
        name = nn;
        id = ii;
        gender = gg;
        age = aa;
    }
    QString Set_student(string nn, string ii, string gg, int aa);//1
    QString chu(string n, string i, string x, int a);
    static int sum_stu();
    static int search_name_id_stu(string nn, string ii, string gg, int aa);//2
};
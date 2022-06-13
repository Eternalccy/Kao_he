#pragma once

#include <QWidget>
#include "ui_G4_56.h"
#include <iostream>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QTextBrowser>
using namespace std;
class G4_56 : public QWidget
{
	Q_OBJECT

public:
	G4_56(QWidget *parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLineEdit* id_1;
    QLabel* label_4;
    QLineEdit* age_1;
    QLineEdit* gender_1;
    QLabel* label_2;
    QPushButton* tian_jia;
    QLabel* label_3;
    QLineEdit* name_1;
    QLabel* label;
    QLabel* label_5;
    QLabel* label_6;
    QLabel* label_10;
    QLineEdit* math_1;
    QFrame* line;
    QLabel* label_11;
    QLabel* label_12;
    QLabel* label_13;
    QLineEdit* caozuo_1;
    QLineEdit* data_1;
    QLineEdit* english_1;
    QListView* xian_shi;
    QLabel* ti_shi;

private slots:
    void lu_ru();
public:
    int wan_zheng();
    void xian_shishi();
private:
	Ui::G4_56 ui;
};

class CXStudent
{
protected:
    string name;
    string id;
    string xb;
    int age;
public:
    CXStudent(string n = "张三", string i = "2016222016", string x = "女", int a = 20)
    {
        name = n;
        id = i;
        xb = x;
        age = a;
    }
    QString chu()
    {
        string xx;
        xx = name + '\t' + id + "\t\t" + xb + '\t' + to_string(age) + '\n';
        return QString::fromStdString(xx);
    }
};

class Add :public CXStudent
{
private:
    float score[4];
    float  sum_score;
public:
    static int all_stu_score;
    Add(string nn = "张三", string ii = "2016222016", string xx = "女", int aa = 20) :CXStudent(nn, ii, xx, aa)
    {
    }
    Add(float  o = 0, float  p = 0, float  q = 0, float  r = 0,
        string n = "张三", string i = "2016222016", string x = "女", int a = 20) :CXStudent(n, i, x, a)
    {
        score[0] = o; score[1] = p; score[2] = q; score[3] = r;
        sum_score = score[0] + score[1] + score[2] + score[3];
    }
    void SetScore(float a, float b, float c, float d) 
    {
        score[0] = a; score[1] = b; score[2] = c; score[3] = d;
        GetScore();
    }
    void GetScore() 
    {
        sum_score = score[0] + score[1] + score[2] + score[3];
    }
    QString GetAll(int i)
    {
        if(i==4)  return QString::number(sum_score);
        else return QString::number(score[i]);
    }
}; 
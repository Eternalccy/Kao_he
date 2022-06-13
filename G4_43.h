#pragma once

#include <QWidget>
#include "ui_G4_43.h"
#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>
#include <QListView>
using namespace std;
class G4_43 : public QWidget
{
	Q_OBJECT

public:
	G4_43(QWidget *parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLineEdit* father_age;
    QLabel* label_15;
    QLabel* label_11;
    QLabel* label_6;
    QPushButton* shang_jiao;
    QLineEdit* father_name;
    QLineEdit* father_nation;
    QLabel* label_5;
    QLineEdit* father_first1;
    QLabel* label;
    QFrame* line;
    QLabel* label_2;
    QLineEdit* mother_first;
    QLabel* label_12;
    QLineEdit* mother_name;
    QLineEdit* mother_nation1;
    QLineEdit* mother_age;
    QLabel* label_7;
    QLabel* label_16;
    QLabel* label_8;
    QLabel* label_3;
    QLineEdit* child_first;
    QLabel* label_13;
    QLineEdit* child_name;
    QLineEdit* child_nation;
    QLineEdit* child_age;
    QLabel* label_9;
    QLabel* label_17;
    QLabel* label_10;
    QFrame* line_2;
    QListView* xian_shi_n;
    QPushButton* shang_jiao_2;
    QLabel* ti_shi;
    QLabel* label_18;
    QLineEdit* child_gender;

private slots:
    void father_first();
    void mother_nation();
    void next_child();
    void f_m_c_xian();
public:
    int wan_zheng(string xx, string nn, string zz, string aa);
private:
	Ui::G4_43 ui;
};

class Father {
protected:
    string first;
    string name;
    string nation;
    int age;
    string gender;
public:
    void SetFather(string xx, string nn, string zz, int aa);
    QString GetFather();
};
class Mother:public Father
{
public:
    void SetMonther(string xx, string nn, string zz, int aa);
    QString GetMonther();
};

class Child :public Mother
{
public:
    void SetChild(string xx, string nn, string zz, int aa, string gg);
    QString GetChild(int num);
};

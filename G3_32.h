#pragma once

#include <QWidget>
#include "ui_G3_32.h"
#include <iostream>
#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>
#include <QListView>
using namespace std;

class G3_32 : public QWidget
{
	Q_OBJECT

public:
	G3_32(QWidget *parent = Q_NULLPTR);
    QTextBrowser* textBrowser;
    QLineEdit* money_1;
    QLabel* label_12;
    QLabel* label_5;
    QPushButton* shang_jiao;
    QLabel* label;
    QLineEdit* name_1;
    QLineEdit* gender_2;
    QLabel* label_8;
    QPushButton* shang_jiao2;
    QFrame* line;
    QLabel* label_2;
    QListView* money_xian;
    QLabel* all_money;
    QLabel* label_9;
    QLabel* label_3;
    QLabel* label_4;
    QLineEdit* name_2;
    QLineEdit* money_2;
    QLabel* all_student;
    QLabel* label_10;
    QLabel* label_6;
    QLineEdit* id_1;
    QLabel* label_7;
    QLineEdit* id_2;
    QLabel* ti_shi;

private slots:
    void shang_jiao3();
    void hua_fei();
public:
    void show_money();
private:
	Ui::G3_32 ui;
};

class CStudent
{
private:
    string thing;
    float money;
    static float z_money;
public:
    string std;
    string id;
    static int all_stu;
    void Contribute(string name, string i_id, float price);
    void Spend(string t_thing, float m_money);
    static QString Display();
};

#pragma once

#include <QWidget>
#include "ui_G2_72.h"
#include <QPushButton>
#include <QLabel>
#include <QListView>

class G2_72 : public QWidget
{
	Q_OBJECT

public:
	G2_72(QWidget *parent = Q_NULLPTR);
    QPushButton* j7;
    QPushButton* j8;
    QPushButton* j9;
    QPushButton* j6;
    QPushButton* j4;
    QPushButton* j5;
    QPushButton* j3;
    QPushButton* j2;
    QPushButton* j1;
    QPushButton* cheng;
    QPushButton* jian;
    QPushButton* jia;
    QPushButton* j0;
    QPushButton* chu;
    QPushButton* jisuan;
    QPushButton* tuige;
    QListView* jxian;
    QLabel* gensui;
    QPushButton* j_d;
    QTextBrowser* textBrowser;
    QPushButton* fang;
public:
    void gui_ling();//¼ò±ã
    void shang_cun();//ÍË¸ñ×¨ÓÃ
private slots:    
    void tui();
    void suan();
    void j_jian();
    void j_jia();
    void j_chu();
    void j_cheng();
    void jj9();
    void jj8();
    void jj7();
    void jj6();
    void jj5();
    void jj4();
    void jj3();
    void jj2();
    void jj1();
    void jj0();
    void jj_d();
private:
	Ui::G2_72 ui;
};

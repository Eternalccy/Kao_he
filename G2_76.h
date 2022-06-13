#pragma once

#include <QWidget>
#include "ui_G2_76.h"
#include <QPlainTextEdit>
#include <QLabel>

class G2_76 : public QWidget
{
	Q_OBJECT

public:
	G2_76(QWidget *parent = Q_NULLPTR);
    QPlainTextEdit* chuan;
    QLabel* label;
    QLabel* label_2;
    QLabel* dan_shu;
    QLabel* da_shu;
    QLabel* label_3;
    QLabel* ju_shu;
    QLabel* label_6;
    QLabel* kong_shu;
    QLabel* label_7;
    QTextBrowser* textBrowser;
private slots:
    void y_cont();
private:
	Ui::G2_76 ui;
};

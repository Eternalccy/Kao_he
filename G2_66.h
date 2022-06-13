#pragma once

#include <QWidget>
#include "G2_66.h"
#include "ui_G2_66.h"
#include <QLabel>
#include <QPushButton>
#include <QtWidgets/QMainWindow>
class G2_66 : public QWidget
{
	Q_OBJECT

public:
	G2_66(QWidget *parent = Q_NULLPTR);
    QLabel* label;
    QLabel* label_2;
    QLineEdit* f1;
    QLineEdit* f2;
    QLabel* label_4;
    QLabel* label_5;
    QLabel* label_3;
    QLineEdit* s2;
    QLineEdit* s1;
    QLabel* label_6;
    QLabel* label_7;
    QLabel* shizi;
    QLabel* daan;
    QPushButton* he;
private slots:
    void f1s2he();

private:
	Ui::G2_66 ui;
};

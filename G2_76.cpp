#include "G2_76.h"
#include <iostream>
using namespace std;
//#pragma execution_character_set("utf-8")
G2_76::G2_76(QWidget* parent)
    : QWidget(parent)
{
    cout << "Enter 2-76" << endl;
    ui.setupUi(this);
}

void G2_76::y_cont()
{//a_单词  b_大写  c_句子   d_空格
    string xx = ui.chuan->toPlainText().toStdString();
    int a, b, c, d, i = 0, k = 0, f = 0;;
    a = 0; b = 0; c = 0; d = 0;
    //cout << xx << endl;
    while (xx[i] != '\0')//可判断句子
    {
        if (isupper(xx[i])) b++;
        if (xx[i] == ' ') d++;
        if (xx[i] == '.') c++;
        if (isalpha(xx[i]) != 0 && (xx[i + 1] == ' ' ||
            xx[i + 1] == '\n'|| xx[i + 1] == ','|| xx[i + 1] == '.'))
        {
            a++; i++;
        }
        else   i++;
        
    }
    ui.dan_shu->setText(QString::number(a));
    ui.da_shu->setText(QString::number(b));
    ui.ju_shu->setText(QString::number(c));
    ui.kong_shu->setText(QString::number(d));
    //cout << "有" << a << "个单词" << endl;
}
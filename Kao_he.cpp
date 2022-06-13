#include "Kao_he.h"
#include <QMovie>
#include <iostream>
#include "G2_66.h"
#include "G2_72.h"
#include "G2_76.h"
#include "G3_30.h"
#include "G3_31.h"
#include "G3_32.h"
#include "G4_39.h"
#include "G4_43.h"
#include "G4_47.h"
#include "G4_56.h"
#include "G4_58.h"
#include "G4_59.h"

using namespace std;
//#pragma execution_character_set("utf-8")
string Ti_hao;
int Xu_hao=1;
QLabel* now;
Kao_he::Kao_he(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    /*QMovie* movie = new QMovie("C:\\Users\\Nitro-cy\\Desktop\\jinli.gif");//路径要用双斜杠
    ui.label_2->setMovie(movie);
    ui.label_2->setScaledContents(true);//用来自适应label大小，图片填充label空间
    movie->start();*/
    ui.haoyun->setPixmap(QPixmap("haoyun.jpeg"));
    ui.haoyun->setScaledContents(true); 
}

class CDrawLots
{
private:
	int TestIndex;
public:
	CDrawLots(int TestIndex1 = 0)
	{
		TestIndex = TestIndex1;
	}

	static void ShowAllTest()
	{
		vector<string> TestName{ "2-66","2-72","2-76","3-30","3-31","3-32","4-39","4-43","4-47","4-56","4-58","4-59" };
		vector<string>::iterator itor;

		cout << "全部练习题共计" << TestName.size() << "项，其中包括：" << endl;
		for (itor = TestName.begin(); itor != TestName.end(); itor++)
			cout << *itor << "; ";
		cout << endl << endl;
	}

	static void Draw()
	{
		vector<string> TestName{ "2-66","2-72","2-76","3-30","3-31","3-32","4-39","4-43","4-47","4-56","4-58","4-59" };
		int index = 11;

		//		cout << "请输入题号选择，正确范围应该在1-12：" << endl;
		//		cin >> index;

		srand((int)(time(NULL)));
		index = rand() % 12 + 1;
		if (index >= 1 && index <= 12)
		{ cout << "当前选定题目序号为：" << index << "，对应练习题为：" << TestName.at(index - 1);
		  Xu_hao = index;
		  Ti_hao = TestName.at(index - 1);
		}
		else
			cout << "选择错误，正确范围应该在1-12！" << endl;
		cout << endl;
	}
};
void Kao_he::chou_ti()
{
	Change_color(0);
	CDrawLots::ShowAllTest();
	CDrawLots::Draw();
	time_t timer;
	tm info;
	char buf[80];
	time(&timer);
	localtime_s(&info, &timer);
	strftime(buf, 80, "%Y年%m月%e日 %H时%M分%S秒", &info);//按照指定的格式输出为字符串
	cout << "当前时间为：" << buf << endl;
	cout << endl << endl;
	Change_color(1);
	ui.tip->setText(QString::fromStdString(Ti_hao));
	//ui.tip->setText("恭喜你抽到题号为     " );
}

void Kao_he::jin_chuang()
{
	string xx=ui.tip->text().toStdString();
	//Xu_hao
	//for (int i = 1; i <= 12; i++)
	switch (5)
	{
	case 1: {G2_66* configWindow = new G2_66; configWindow->show(); break; }
	case 2: {G2_72* configWindow = new G2_72; configWindow->show(); break; }
    case 3: {G2_76* configWindow = new G2_76; configWindow->show(); break; }
    case 4: {G3_30* configWindow = new G3_30; configWindow->show(); break; }
	case 5: {G3_31* configWindow = new G3_31; configWindow->show(); break; }
	case 6: {G3_32* configWindow = new G3_32; configWindow->show(); break; }
    case 7: {G4_39* configWindow = new G4_39; configWindow->show(); break; }
	case 8: {G4_43* configWindow = new G4_43; configWindow->show(); break; }
	case 9: {G4_47* configWindow = new G4_47; configWindow->show(); break; }
	case 10: {G4_56* configWindow = new G4_56; configWindow->show(); break; }
	case 11: {G4_58* configWindow = new G4_58; configWindow->show(); break; }
	default: {G4_59* configWindow = new G4_59; configWindow->show(); break; }
	}
}

QString Kao_he::Get_name()
{
	QString name;
	name = "t_" + QString::number(Xu_hao);
	return name;
}

void Kao_he::Change_name(QString thing)
{
	QString objectNameBtn = thing;
	now = this->findChild<QLabel*>(objectNameBtn);
}

void Kao_he::Change_color(int x)
{
	QPalette pe;
	if(x)  pe.setColor(QPalette::WindowText, Qt::green);
	else pe.setColor(QPalette::WindowText, Qt::black);
	QString name;
	name = Get_name();
	Change_name(name);
	now->setPalette(pe);
}


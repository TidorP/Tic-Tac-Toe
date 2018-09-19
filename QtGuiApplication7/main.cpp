#include <QtWidgets/QApplication>
#include "GUI.h"
#include "Tests.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testAll();
	std::string fName = "file.txt";
	Repository repo{ fName };
	Service serv{ repo };
	GUI gui{ serv };
	return a.exec();
}

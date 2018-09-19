#pragma once
#include <QTWidgets>
#include <QObject>
#include "Service.h"
class GUI :public QObject
{
	Q_OBJECT

private:
	Service & serv;
	Joc current_joc;

	QWidget * main = new QWidget;
	QFormLayout* mainLayout = new QFormLayout;

	QTableWidget* tabel = new QTableWidget(10, 4);
	QTableWidget* xo = new QTableWidget(3, 3);

	QLabel* tabla = new QLabel("Position: ");
	QLabel* juc = new QLabel("Next player");
	QLabel* stare = new QLabel("The state of the game:");

	QLabel* tablaU = new QLabel("New position:");
	QLabel* jucU = new QLabel("New player:");
	QLabel* stareU = new QLabel("New state of the game:");

	QLineEdit* Etabla = new QLineEdit;
	QLineEdit* Ejuc = new QLineEdit;
	QLineEdit* Estare = new QLineEdit;

	QLineEdit* EtablaU = new QLineEdit;
	QLineEdit* EjucU = new QLineEdit;
	QLineEdit* EstareU = new QLineEdit;

	QPushButton* buttonAdd = new QPushButton("Exe add");
	QPushButton* buttonUpd = new QPushButton("Exe update");
	QPushButton* buton11 = new QPushButton("-");
	QPushButton* buton12 = new QPushButton("-");
	QPushButton* buton13 = new QPushButton("-");

	QPushButton* buton21 = new QPushButton("-");
	QPushButton* buton22 = new QPushButton("-");
	QPushButton* buton23 = new QPushButton("-");

	QPushButton* buton31 = new QPushButton("-");
	QPushButton* buton32 = new QPushButton("-");
	QPushButton* buton33 = new QPushButton("-");

	QPushButton* buttonJoc= new QPushButton("Joc");
	QPushButton* buttonPlay = new QPushButton("play");

	QPushButton* buttonRefresh = new QPushButton("Refresh");

	QPushButton* buttonHelp = new QPushButton("Help");

public:
	GUI(Service& serv);
	private slots:
	void updateTabel();
	void clickExeAdd();
	void clickExeUpd();
	void manage();
	void play();
	std::pair<int,int> getRowColumn();
	bool isFull();
	std::string afisareXO();
	bool check_over();
	void refresh();
	void help();

};


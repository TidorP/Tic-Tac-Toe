#include "GUI.h"
//constructor
GUI::GUI(Service& serv) :serv{ serv }
{
	main->setLayout(mainLayout);

	mainLayout->addWidget(new QLabel("Table with many saved positions. They are also stored in a file. \n"));
	mainLayout->addWidget(tabel);

	tabel->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
	tabel->setHorizontalHeaderItem(1, new QTableWidgetItem("Position"));
	tabel->setHorizontalHeaderItem(2, new QTableWidgetItem("Next player"));
	tabel->setHorizontalHeaderItem(3, new QTableWidgetItem("State of the game"));

	connect(buttonAdd, &QPushButton::clicked, this, &GUI::clickExeAdd);
	connect(buttonUpd, &QPushButton::clicked, this, &GUI::clickExeUpd);
	connect(buttonJoc, &QPushButton::clicked, this, &GUI::manage);
	connect(buttonPlay, &QPushButton::clicked, this, &GUI::play);
	connect(buttonRefresh, &QPushButton::clicked, this, &GUI::refresh);
	connect(buttonHelp, &QPushButton::clicked, this, &GUI::help);
	
	mainLayout->addWidget(new QLabel("Add new positions!\n"));
	mainLayout->addRow(tabla, Etabla);
	mainLayout->addRow(juc, Ejuc);
	

	mainLayout->addWidget(buttonAdd);
	
	mainLayout->addWidget(new QLabel("Make an update to a position!\nChoose a line from the above table and enter the new data below:\n"));
	mainLayout->addRow(tablaU, EtablaU);
	mainLayout->addRow(jucU, EjucU);
	mainLayout->addRow(stareU, EstareU);
	mainLayout->addWidget(buttonUpd);
	updateTabel();
	main->setWindowTitle(QString::fromStdString("Ferestra principala"));
	
	mainLayout->addWidget(new QLabel("Play Tic Tac Toe:\n\nChoose a position and press JOC, press if you want na empty drawing board! "));
	mainLayout->addWidget(xo);
	mainLayout->addWidget(buttonRefresh);
	mainLayout->addWidget(buttonJoc);

	mainLayout->addWidget(new QLabel("Game strategies, learn how to become better!\n"));
	mainLayout->addWidget(buttonHelp);

	mainLayout->addWidget(new QLabel("Choose a free space and press play for drawing x or o:\n"));
	QPalette pal = buttonPlay->palette();
	pal.setColor(QPalette::Button, QColor(Qt::blue));
	buttonPlay->setAutoFillBackground(true);
	buttonPlay->setPalette(pal);
	mainLayout->addWidget(buttonPlay);
	
	main->show();
}
//updatam tabelul
void GUI::updateTabel()
{
	std::vector<Joc> jocuri = serv.sortare();
	int siz = static_cast<int>(jocuri.size());
	tabel->setRowCount(siz);
	for (int i = 0; i < tabel->rowCount(); i++)
		for (int j = 0; j < tabel->columnCount(); j++)
		{
			QTableWidgetItem *item = new QTableWidgetItem;
			if (j == 0)
			{
				QString it = QString::fromStdString(std::to_string(jocuri[i].getID()));
				item->setText(it);
				tabel->setItem(i, j, item);
			}
			if (j == 1)
			{
				QString it = QString::fromStdString(jocuri[i].getTabla());
				item->setText(it);
				tabel->setItem(i, j, item);
			}
			if (j == 2)
			{
				QString it = QString::fromStdString(jocuri[i].getJuc());
				item->setText(it);
				tabel->setItem(i, j, item);
			}
			if (j == 3)
			{
				QString it = QString::fromStdString(jocuri[i].getStare());
				item->setText(it);
				tabel->setItem(i, j, item);
			}

		}
}
//update
void GUI::clickExeUpd()
{
	QModelIndexList selection = tabel->selectionModel()->selectedRows();
	QModelIndex index = selection.at(0);
	std::vector<Joc> sortat = serv.sortare();
	int id = sortat[index.row()].getID();
	for (auto i : sortat)
	{
		if(i.getID()==id)
			serv.Supd(i,EtablaU->text().toStdString(), EjucU->text().toStdString(), EstareU->text().toStdString());
	}
	updateTabel();
}

void GUI::clickExeAdd()
{
	int id = serv.getRepo().getAll().size()+1;
	serv.Sadd(id, Etabla->text().toStdString(), Ejuc->text().toStdString(), "neinceput");
	updateTabel();
}
//facem update la tabel
void GUI::manage()
{
	QModelIndexList selection = tabel->selectionModel()->selectedRows();
	QModelIndex index = selection.at(0);
	std::vector<Joc> sortat = serv.sortare();
	current_joc = sortat[index.row()];
	serv.Supd(sortat[index.row()], sortat[index.row()].getTabla(), sortat[index.row()].getJuc(), "inderulare");
	updateTabel();
	current_joc.setStare("inderulare");
	std::string ta = sortat[index.row()].getTabla();

	for (int i = 0;i<3; i++)
	{

		QTableWidgetItem *item = new QTableWidgetItem;
		QString it = ta[i];
		item->setText(it);
		xo->setItem(0, i, item);

	}
	for (int i = 0;i<3; i++)
	{

		QTableWidgetItem *item = new QTableWidgetItem;
		QString it = ta[i+3];
		item->setText(it);
		xo->setItem(1, i, item);

	}
	for (int i = 0;i< 3; i++)
	{

		QTableWidgetItem *item = new QTableWidgetItem;
		QString it = ta[i+6];
		item->setText(it);
		xo->setItem(2, i, item);

	}
		
}
std::pair<int, int> GUI::getRowColumn()
{
	QMessageBox msgBox;
	QList<QTableWidgetItem *> list = xo->selectedItems();
	if (list.empty())
	{
		msgBox.setText("Alegeti un camp pentru a desena!!!");
		msgBox.exec();
		return std::pair<int, int>(-1, -1);
	}
	else
	{
		QTableWidgetItem *item = list.at(0);
		if (item->text().toStdString() == "-")
		{
			std::pair<int, int> pair;
			pair.first = item->row();
			pair.second = item->column();
			return pair;
		}
		else
		{
			msgBox.setText("Spatiul este deja ocupat! Alegeti un bloc liber");
			msgBox.exec();
			return std::pair<int, int>(-1, -1);
		}
	}
}
bool GUI::isFull()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			QString q= xo->item(i, j)->text();
			if (q=="-")
				return false;
		}
	}
	return true;
	
}
//functia de play unde jucam
void GUI::play()
{
	QMessageBox msgBox;
	QTableWidgetItem *item = new QTableWidgetItem;
	if (current_joc.getID() != -1)
	{
		std::pair<int, int> pair=getRowColumn();
		if (pair.first != -1)
		{
			QString it = QString::fromStdString(current_joc.getJuc());
			item->setText(it);
			xo->setItem(pair.first, pair.second, item);
			if (check_over())
			{
				refresh();
			}
			if (isFull())
			{
				msgBox.setText("S-a epuizat tot spatiul! Remiza");
				msgBox.exec();
				
			}
			else
			{
				if (current_joc.getJuc() == "x")
				{
					serv.Supd(current_joc, afisareXO(), "o", current_joc.getStare());
					current_joc.setJuc("o");
					updateTabel();

				}
				else
				{
					serv.Supd(current_joc, afisareXO(), "x", current_joc.getStare());
					current_joc.setJuc("x");
					updateTabel();
				}
			}
		
		}
	}
	else
	{
		msgBox.setText("Trebuie sa introduci o mapa de joc mai intai pentru a juca!");
		msgBox.exec();
	}


}
std::string GUI::afisareXO()
{
	std::string s;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			s = s + xo->item(i, j)->text().toStdString();
		}
	}
	
	return s;
}
bool GUI::check_over()
{
	QMessageBox msgBox;
	std::string s = afisareXO();
	for (int i = 0; i <= 6; i = i + 3)
	{
		if (s.substr(i, 3) == "ooo" || s.substr(i, 3) == "xxx")
		{
			QString q = QString::fromStdString("Congrats, jucatorul cu  " + current_joc.getJuc() + " a castigat!!");
			msgBox.setText(q);
			msgBox.exec();
			refresh();
			return true;
		}
		if (std::string(1,s.at(i/3)) + std::string(1,s.at(i/3+3)) + std::string(1,s.at(i/3+6)) == "ooo"|| std::string(1, s.at(i / 3)) + std::string(1, s.at(i / 3 + 3)) + std::string(1, s.at(i / 3 + 6)) == "xxx")
		{
			QString q = QString::fromStdString("Congrats, jucatorul cu " + current_joc.getJuc() + " a castigat!!");
			msgBox.setText(q);
			msgBox.exec();
			return true;
		}
	
	}
	if (std::string(1,s.at(0)) + std::string(1,s.at(4)) + std::string(1,s.at(8)) == "ooo" || std::string(1, s.at(0)) + std::string(1, s.at(4)) + std::string(1, s.at(8)) =="xxx")
	{
		QString q = QString::fromStdString("Congrats, jucatorul cu " + current_joc.getJuc() + " a castigat!!");
		msgBox.setText(q);
		msgBox.exec();
		return true;
	}
	if (std::string(1,s[2]) + std::string(1,s[4]) + std::string(1,s[6]) == "ooo" || std::string(1, s[2]) + std::string(1, s[4]) + std::string(1, s[6]) == "xxx")
	{
		QString q = QString::fromStdString("Congrats, jucatorul cu " + current_joc.getJuc() + " a castigat!!");
		msgBox.setText(q);
		msgBox.exec();
		return true;
	}
	return false;
}
void GUI::refresh()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			QTableWidgetItem *item = new QTableWidgetItem;
			QString it = QString::fromStdString("-");
			item->setText(it);
			xo->setItem(i,j, item);
		}
	}
}
void GUI::help()
{
	QMessageBox msgBox;
	QString q = QString::fromStdString("Tic tac toe este teoretic un joc rezolvat, la uun joc perfect se ajunge la remiza! Insa..exista mai multe reguli pe care trebuie sa le urmati daca vreti sa castigati!\n1. Ocuaptati centrul! \n\n2.Incercati sa amentitati pe diagonala mai intai \n\n3. Incercati sa creati 2 amenintari dintr-o singura mutare pe diagonala");
	msgBox.setText(q);
	msgBox.exec();
}
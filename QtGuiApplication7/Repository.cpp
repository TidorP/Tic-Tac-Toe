#include "Repository.h"

//construtor
Repository::Repository(std::string& fName) :fName{ fName }
{
	std::ifstream f(fName);
	int x;
	std::string y, z,t;
	while (f >> x >> y >> z >> t)
	{
		Joc game = Joc{ x,y,z,t };
		add(game);
	}
	f.close();
}
//fucntia de exportare intr un fisier
void Repository::exp()
{
	std::ofstream g(fName);
	for (auto i : jocuri)
	{
		g << i.getID() << " " << i.getTabla() << " " << i.getJuc() << " " << i.getStare();
		g << std::endl;
	}
	g.close();

}
//adaugam in repo
void Repository::add(Joc game)
{
	auto i = std::find_if(jocuri.begin(), jocuri.end(), [&game](Joc& m) {return m.getID() == game.getID(); });
	if (i == jocuri.end())
	{
		if (game.getTabla().size() == 9 && (game.getJuc() == "x" || game.getJuc() == "o") && (game.getStare() == "neinceput" || game.getStare() == "inderulare" || game.getStare() == "terminat"))
		{
			jocuri.push_back(game);
			exp();
		}
	}

}

//facem update in repo
void Repository::upd(Joc game1, Joc game2)
{
	if (game2.getTabla().size() == 9 && (game2.getJuc() == "x" || game2.getJuc() == "o") && (game2.getStare() == "neinceput" || game2.getStare() == "inderulare" || game2.getStare() == "terminat"))
	{
		auto i = std::find_if(jocuri.begin(), jocuri.end(), [&game1](Joc& m) {return m.getID() == game1.getID(); });
		if (i != jocuri.end())
		{
			for (int i = 0; i < jocuri.size(); i++)
				if (jocuri[i].getID() == game1.getID())
				{
					jocuri[i].getID() = game2.getID();
					jocuri[i].getTabla() = game2.getTabla();
					jocuri[i].getJuc() = game2.getJuc();
					jocuri[i].getStare() = game2.getStare();
				}
			exp();
		}
		else
		{
			game1.getID()= game2.getID();
			game1.getTabla() = game2.getTabla();
			game1.getJuc() = game2.getJuc();
			game1.getStare() = game2.getStare();
		}
	}
}
//retunram lista intreaga
std::vector<Joc>& Repository::getAll()
{
	return jocuri;
}


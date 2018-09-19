#include "Service.h"


//functia de adaugare, avem componentele , cosntruim jocul
void Service::Sadd(int id, std::string tabla, std::string juc, std::string stare)
{
	Joc game = Joc{ id,tabla,juc,stare };
	repo.add(game);
}
//sortarea elmentelor
std::vector<Joc> Service::sortare()
{
	std::vector<Joc> jocuri = repo.getAll();
	std::sort(jocuri.begin(), jocuri.end(), [](Joc& mel1, Joc& mel2) {return mel1.getStare() < mel2.getStare(); });
	return jocuri;
}
//bool Service::SDel(int id)
//{
//	std::vector<Melodie> vect = sortare();
//	if (vect[vect.size() - 1].getID() == id)
//		return false;
//	else
//	{
//		repo.del(id);
//		return true;
//	}
//
//}
void Service::Supd(Joc game, std::string tabla, std::string juc, std::string stare)
{
	Joc game2 = Joc{ game.getID(),tabla,juc,stare };
	repo.upd(game, game2);
}

//returnam repo ul
Repository& Service::getRepo()
{
	return repo;
}

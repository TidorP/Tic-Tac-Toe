#pragma once
#include "Repository.h"
class Service
{
private:
	Repository & repo;
public:
	Service(Repository & repo) :repo{ repo } {}

	void Sadd(int id, std::string tabla, std::string juc, std::string stare);
	std::vector<Joc> sortare();
	//bool SDel(int id);
	void Supd(Joc game, std::string tabla, std::string juc, std::string stare);
	Repository& Service::getRepo();
};



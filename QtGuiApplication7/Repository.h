#pragma once
#include "domain.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>
//repository
class Repository
{
private:
	std::vector<Joc> jocuri;
	std::string fName;
public:
	Repository(std::string& fName);
	void exp();
	void add(Joc game);
	void upd(Joc game1, Joc game2);
	std::vector<Joc>& getAll();
};
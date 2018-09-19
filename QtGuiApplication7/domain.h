#pragma once
#include <iostream>
#include <string>
//clasa naostra
class Joc
{
private:
	int id;
	std::string tabla;
	std::string juc;
	std::string stare;
public:
	Joc(int& id, std::string& tabla, std::string& juc, std::string& stare) :id{ id }, tabla{ tabla }, juc{ juc }, stare{ stare } {}
	Joc() :id{ -1 }, tabla{ "not_set" }, juc{ "not_set" }, stare{ "not_set" } {}
	int& getID();
	std::string& getTabla();
	std::string& getJuc();
	std::string& getStare();
	void operator=(Joc& ot);
	void setJuc(std::string juc);
	void setStare(std::string stare);
};


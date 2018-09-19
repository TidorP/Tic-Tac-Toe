#include "domain.h"



//functiile de get utlitare
int& Joc::getID()
{
	return id;
}
std::string& Joc::getTabla()
{
	return tabla;
}
std::string& Joc::getJuc()
{
	return juc;
}
std::string& Joc::getStare()
{
	return stare;
}
void Joc::operator=(Joc& ot)
{
	this->id = ot.getID();
	this->tabla = ot.getTabla();
	this->juc = ot.getJuc();
	this->stare = ot.getStare();
}
void Joc::setJuc(std::string juc)
{
	this->juc = juc;
}
void Joc::setStare(std::string stare)
{
	this->stare = stare;
}
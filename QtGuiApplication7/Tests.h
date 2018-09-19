#pragma once
#include "Service.h"
#include <cassert>
void testAll()
{
	std::string fName = "test.txt";
	Repository repo{ fName };
	Service serv{ repo };
	int i = 10;
	serv.Sadd(10, "x-oxo-xoo", "x", "inderulare");
	i++;
	assert(serv.getRepo().getAll()[3].getID(), 10);
	assert(serv.sortare()[3].getID(), "terminat");
}
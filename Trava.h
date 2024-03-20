#pragma once
#include <iostream>
using namespace std;
class Trava
{
	bool otkriven;
	char karakter;
public:
	Trava();
	virtual void print();
	virtual void otkri();
	bool getotkriveno();
	char& getkarakter() { return karakter; };
	virtual int getk() { return 0; };
};


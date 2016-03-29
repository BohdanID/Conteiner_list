#ifndef MYFUNCTOR_H
#define MYFUNCTOR_H
#include "Book.h"
#include <iostream>
using namespace std;

class MyFunctor
{
private:
	int a;
public:
	MyFunctor(int _a)
	{
		a= _a;
	}
	Book* operator()(Book* value)
	{
		value->setPages(value->getPages() + a);
		return value;
	}

};

class MyFunctor1
{
private:
	
public:
	
	
	ostream& operator()(Book* value,ostream& a=cout)
	{
		value->show1(a);
		return a;
	}

};



#endif
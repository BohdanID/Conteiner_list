#ifndef JANRBOOK_H
#define JANRBOOK_H
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class JanrBook :public Book
{
	friend istream& operator >>(istream & is, JanrBook& j)
	{
		string _name;
		string _avtor;
		int _pages;
		is >> _name >> _avtor >> _pages >> j.janr;
		j.setName(_name);
		j.setAvtor(_avtor);
		j.setPages(_pages);
		return is;
		
	}

	friend ostream& operator <<(ostream & os, const JanrBook & b)
	{
		os << b.getName() << " " << b.getAvtor() << " " << b.getPages() <<" "<<b.janr<< endl;
		return os;
	}

private:
	string janr;
public:
	JanrBook() :Book(), janr(""){};
	JanrBook(string _name, string _avtor, int _pages, string _janr) :Book(_name, _avtor, _pages), janr(_janr){};
	void setJanr(string _janr);
	string getJanr()const;
	virtual void show();
	virtual void show1(ostream& out);
	virtual void saveTo(ofstream & f);
};


#endif
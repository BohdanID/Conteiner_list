#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Book
{
	friend istream& operator >>(istream & is, Book & b)
	{
		is >> b.name >> b.avtor >> b.pages;
		return is;
	}
	
	friend ostream& operator <<(ostream & os, Book*  b)
	{
		//os << b.name<< " "<< b.avtor<<" "<< b.pages<<endl;
		b->show();
		return os;
	}

private:
	string name;
	string avtor;
	int pages;
public:
	Book() :name(""), avtor(""), pages(0){};
	Book(string _name, string _avtor, int _pages)throw(int) :name(_name), avtor(_avtor), pages(_pages){};
	void setName(string _name);
	string getName()const;
	void setAvtor(string _avtor);
	string getAvtor()const;
	void setPages(int _pages)throw(int);
	int getPages()const;
	virtual void show();
	virtual void show1(ostream& out);
	virtual void saveTo(ofstream& f);

};


#endif
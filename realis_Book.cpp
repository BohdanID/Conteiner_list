#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;




//Book::Book()
//{
//	name = "";
//	avtor = "";
//	pages = 0;
//}
//Book::Book(string _name, string _avtor, int _pages)throw(int)
//{
//	if (_pages <= 0)
//		throw(0);
//	name.assign(_name);
//	avtor.assign(_avtor);
//	pages = _pages;
//}
void Book::setName(string _name)
{
	name.assign(_name);
}
string Book::getName()const
{
	return name;
}
void Book::setAvtor(string _avtor)
{
	avtor.assign(_avtor);
}
string Book::getAvtor()const
{
	return avtor;
}
void Book::setPages(int _pages)throw(int)
{
	if (_pages <= 0)
		throw(0);
	pages = _pages;
}
int Book::getPages()const
{
	return pages;
}
void Book::show()
{
	cout << "Name: " << name << " Avtor: " << avtor << " pages: " << pages << endl;
}
void Book::show1(ostream& out)
{
	out << "Name: " << name << " Avtor: " << avtor << " pages: " << pages << endl;
}
void Book::saveTo(ofstream& f)
{
	f << name << " " << avtor << " " << pages << endl;
}
#include "JanrBook.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//JanrBook::JanrBook() :Book()
//{
//	janr = "";
//}
//JanrBook::JanrBook(string _name, string _avtor, int _pages, string _janr) : Book(_name, _avtor, _pages)
//{
//	janr.assign(_janr);
//}
void JanrBook::setJanr(string _janr)
{
	janr.assign(_janr);
}
string JanrBook::getJanr()const
{
	return janr;
}
void JanrBook::show() 
{
	cout << "Name: " << getName() << " Avtor: " << getAvtor() << " pages: " << getPages() <<" janr: "<<janr<< endl;
}
void JanrBook::show1(ostream& out)
{
	out << "Name: " << getName() << " Avtor: " << getAvtor() << " pages: " << getPages() << " janr: " << janr << endl;
}
void JanrBook::saveTo(ofstream & f)
{
	f << getName() << " " << getAvtor() << " " << getPages() <<" "<<janr<< endl;
}
#include "JanrBook.h"
#include "MyExeption.h"
#include "MyFunctor.h"
#include "Book.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

bool pred(Book *a, Book* b);
void printOut(list<Book*> l);
void printMenu();
void base_show(Book* a);


//void use_file(const char* name) 
//{
//	
//}


int main()
{
	/*vector <Book*> v;
	Book* b=new Book("a","b",10);
	v.push_back(b);
	MyFunctor1 mf1;
	ostream_iterator<Book*> output(cout, " ");
	copy(v.begin(), v.end(),output);*/

	ifstream f;
	list<Book*>l;
	string fileName;
	while (true)
	{
		try{
			bool b = false;

			cout << "Input fileName" << endl;
			cin >> fileName;
			f.open(fileName, ios::in);
			MyExeptionFile e("Error. Problem of acess to file " + fileName);
			if (!f)
				throw(e);
			b = true;
			break;
		}

		catch (MyExeptionFile& e)
		{
			e.printMessage();
		}
	}
	while (true)
	{
		try{
			printMenu();
			int m;
			cin >> m;
			switch (m)
			{
			case 1:
			{
					  while (!f.eof())
					  {
						  char c;
						  f >> c;
						  switch (c)
						  {
						  case 'b':
						  {
									  string _name;
									  string _avtor;
									  int _pages;
									  f >> _name >> _avtor >> _pages;
									  Book* t = new Book(_name, _avtor, _pages);
									  l.push_back(t);
						  }break;
						  case 'j':
						  {
									  string _name;
									  string _avtor;
									  int _pages;
									  string _janr;
									  f >> _name >> _avtor >> _pages >> _janr;
									  JanrBook* t = new JanrBook(_name, _avtor, _pages, _janr);
									  l.push_back(t);
						  }break;
						  }
					  }

					  f.close();
			}break;
			case 2:
			{
					  string _name;
					  string _avtor;
					  int _pages;
					  cout << "Input Information about Book" << endl;
					  cin >> _name >> _avtor >> _pages;
					  Book* t = new Book(_name, _avtor, _pages);
					  l.push_back(t);
			}break;
			case 3:
			{
					  string _name;
					  string _avtor;
					  int _pages;
					  string _janr;
					  cout << "information about JanrBook" << endl;
					  cin >> _name >> _avtor >> _pages >> _janr;
					  JanrBook* t = new JanrBook(_name, _avtor, _pages, _janr);
					  l.push_back(t);
			}break;
			case 4:
			{
					  printOut(l);
					 // copy(l.begin(), l.end(), base_show);
			}break;
			case 5:
			{
					  l.sort(pred);
			}break;
			case 6:
			{
					  cout << "input n" << endl;
					  int n;
					  cin >> n;
					  l.sort(pred);
					  list<Book*>::iterator it = l.begin();
					  for (int i = 0; i < n; ++i)
					  {
						  (**it).show();
						  it++;
					  }


			}break;
			case 7:
			{
					  ofstream o("result.txt");
					  list<Book*>::iterator it;

					  for (it = l.begin(); it != l.end(); it++)
					  {
						  (**it).saveTo(o);
					  }
					  o.close();
			}break;
			case 8:
			{
					  list<Book*>::iterator it;
					  int i = 0;


					  for (it = l.begin(); it != l.end(); it++)
					  {
						  if (dynamic_cast<JanrBook*>(*it))
							  cout << "Element number" << i << " is JanrBook" << endl;
						  else
							  cout << "Element number" << i << " is Book" << endl;
						  i++;
					  }
			}break;
			case 9:
			{
					 /* MyFunctor mf(2);
					  for_each(l.begin(), l.end(), mf);
					  printOut(l);*/

					  list<Book*>::iterator it;
					  it=min_element(l.begin(), l.end(), pred);
					  (*it)->show();

					 /* list<Book*> l1;
					  partial_sort_copy(l.begin(), l.end(), l1.begin(), l1.end(), pred);*/

			}break;
			case 10:
			{
					  return 0;
			}break;

			}
		}



		catch (int)
		{
			cout << "Error.Enter negative number of pages" << endl;
		}

	}


	system("pause");
	return 0;
}

bool pred(Book *a, Book* b)
{
	return a->getPages() < b->getPages();

}

void printOut(list<Book*> l)
{
	list<Book*>::iterator it;

	for (it = l.begin(); it != l.end(); it++)
	{
		(**it).show();
	}
}

void printMenu()
{
	cout << "Menu:" << endl;
	cout << "1. Read from file" << endl;
	cout << "2. Add Book" << endl;
	cout << "3. Add JanrBook" << endl;
	cout << "4. Print collections" << endl;
	cout << "5. Sort Collections" << endl;
	cout << "6. Choose the best" << endl;
	cout << "7. Save to file" << endl;
	cout << "8. Test of types" << endl;
	cout << "9. Change pages" << endl;
	cout << "10. Exit" << endl;
}
void base_show(Book* a)
{
	a->show1(cout);
}
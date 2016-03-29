#ifndef MYEXEPTION_H
#define MYEXEPTION_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;




class MyExeptionFile
{
private:
	string message;
public:
	MyExeptionFile(string _message);
	void printMessage();
};
#endif
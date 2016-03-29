#include "MyExeption.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


MyExeptionFile::MyExeptionFile(string _message)
{
	message.assign( _message);
}
void MyExeptionFile::printMessage()
{
	cout << message << endl;
}
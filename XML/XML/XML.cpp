// XML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "XMLParser.h"
#include <iostream>

using namespace std;

XMLParser *xml = new XMLParser();

int main()
{
	string file = xml->readfile();
	cout << file;
	//xml->compare(file, "MESSAGE");
}


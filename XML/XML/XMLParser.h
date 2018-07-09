#pragma once

#include "stdafx.h"
#include <string>
#include <fstream>

using namespace std;

class XMLParser
{

public:
	string line;
	string file;
	ifstream XMLFile;
	string readfile();

	void compare(string stringfile);
	void lang(string &file, string lang, int sepPos);

	XMLParser();
	~XMLParser();
};


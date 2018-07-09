#include "stdafx.h"
#include "XML.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string line;
ifstream XMLFile;

vector<string> XML::readfile()
{
	XMLFile.open("AppxManifest.xml");
	while (getline(XMLFile, line))
	{
		allTags.push_back(line);
	}
	return allTags;
}

XML::XML()
{}


XML::~XML()
{}




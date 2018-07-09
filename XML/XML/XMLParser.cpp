#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "XMLParser.h"

string line;
string file;
ifstream XMLFile;
string temp;
bool trigger = false;
using namespace std;

void  XMLParser::lang(string &file, string lang, int sepPos) {

	if (trigger) {
		temp = line.erase(line.find_first_of('<'), 6);
		temp = temp.substr(0, temp.find('<'));
		int find = temp.find("&#44");
		if (find >= 0)
			temp.replace(find,4 , ",");
		file.append(temp);
		file.append("\n");
		trigger = false;
	}
	else if (line.at(sepPos + 1) == 'D') {
		int found = line.find("ja");
		if (found >= 0 && (lang == "all" || lang == "ja")) {

			file.append(" In Japanese:");
			trigger = true;
		}
		found = line.find("en");
		if (found >= 0 && (lang == "all" || lang == "en")) {

			file.append(" In English:");
			trigger = true;
		}
		found = line.find("zhCN");
		if (found >= 0 && (lang == "all" || lang == "zhCN")) {

			file.append(" In Traditional Chinese:");
			trigger = true;
		}
		found = line.find("zhTW");
		if (found >= 0 && (lang == "all" || lang == "zhTW")) {

			file.append(" In Simplified characters:");
			trigger = true;
		}
		found = line.find("ko");
		if (found >= 0 && (lang == "all" || lang == "ko")) {

			file.append(" In Hangul:");
			trigger = true;
		}
		found = line.find("fr");
		if (found >= 0 && (lang == "all" || lang == "fr")) {

			file.append(" In French:");
			trigger = true;
		}
		found = line.find("it");
		if (found >= 0 && (lang == "all" || lang == "it")) {

			file.append(" In Italian:");
			trigger = true;
		}
		found = line.find("de");
		if (found >= 0 && (lang == "all" || lang == "de")) {

			file.append(" In German:");
			trigger = true;
		}
		found = line.find("es");
		if (found >= 0 && (lang == "all" || lang == "es")) {

			file.append(" In Spanish:");
			trigger = true;
		}
	}

}

string XMLParser::readfile()
{
	XMLFile.open("a.xml");
	while (getline(XMLFile, line))
	{
		int sepPos = line.find_first_of('<');
		if (line.at(sepPos + 1) == 'M') {
			
			file.append("Message : ");
			temp = line.erase(line.find_first_of('<'), 13);
			temp = temp.erase(line.find_first_of('"', 2));
			file.append(temp.substr(0, temp.find_first_of('"')));
			file.append("\n");

		}
		else {
			lang(file, "all", sepPos); // can choose a specific lang or all 
		}
	}
	return file;
}


	XMLParser::XMLParser()
	{
	}

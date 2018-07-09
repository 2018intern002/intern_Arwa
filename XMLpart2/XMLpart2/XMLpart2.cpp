// XMLpart2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "XML.h"
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;
XML *xml = new XML();
vector<string> allTags;
multimap<string, string> Tags;
string tagName;
bool trigger = true;
int main()
{
	allTags = xml->readfile();
	for (int i = 3; i < allTags.size(); i++) {
		int find = allTags[i].find('<');
		if (find >= 0 && trigger) {
			tagName = allTags[i].substr(find+1,allTags[i].length()-1);
			trigger = false;
		}
		else {
			int find = allTags[i].find("</"+tagName);
			if (find == -1) {
				Tags.insert(std::pair<string, string>(tagName, allTags[i]));
			}
			else {
				trigger = true;

			}
				
					

		}

	}
	//cout << Tags.size();

	for_each(Tags.begin(), Tags.end(),[](pair<string, string> element) {
		// Accessing KEY from element
		string tag = element.first;
		// Accessing VALUE from element.
		string child = element.second;

		//if(tag.compare("Applications") == 1)
		std::cout << tag << " :: " << child << std::endl;
	});

	return 0;
}


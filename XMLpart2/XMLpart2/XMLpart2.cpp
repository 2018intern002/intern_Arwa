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
#include "rapidxml.hpp"

using namespace rapidxml;

using namespace std;

int dataA;

bool trigger = true;

void processNode(xml_node<> *nodea)
{
	for (xml_node<> *childa = nodea->first_node(); childa; childa = childa->next_sibling())
	{
		//cout << childa->name() <<"\n";
		string line = childa->name();
		int pos;
		if ((pos = line.find("mx:SocketDescription")) == line.npos) {
			processNode(childa);
		}

		else {
			childa = childa->first_node();
			//cout << childa->name() << "\n";
			string attr = childa->first_attribute()->value();
			if ((pos = attr.find("WwiseDiscoverySocket")) != line.npos) {
				childa = childa->first_node()->first_node();
				while (childa != NULL) {
					cout << "TYPE :";
					cout << childa->first_attribute()->value() << "\n";
					childa = childa->next_sibling();
				}
			}
			break;
		}

	}
}
int i = 0;
void processAllNode(xml_node<> *node) {

	for (xml_node<> *child = node->first_node(); child; child = child->next_sibling())
	{
		cout << "Element Node:" << child->name() << "\n\n";

		for (xml_attribute<> *attr = child->first_attribute(); attr; attr = attr->next_attribute())
		{
			cout << "       Attribute Name: " << attr->name() << " ";
			cout << "       Value: " << attr->value() << "\n \n";
		}
		processAllNode(child);
	}
}

int main() {
	xml_document<> doc;
	xml_node<> * root_node;
	ifstream theFile("AppxManifest.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	doc.parse<0>(&buffer[0]);

	xml_node<> *node = doc.first_node();

	//processNode(node); //this option shows the example
	processAllNode(node); // this option shows all the elements and attribute
}


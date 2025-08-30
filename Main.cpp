//main.cpp

#include<iostream>
using namespace std :

	void scanDriectory(const string& path);
int main()
{
	string path;
	cout << "Enter path to scan: ";
	getline(cin, path);

	scanDirectory(path);

	return 0;

}
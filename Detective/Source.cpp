#include <iostream>
#include <fstream>
#include <string>
#include "gameheader.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////
//Title: Detective Raad Text adventure                                                  //
//Team members:Cody,Mariz, Joseph, Darian                                               //
//Repo: Github                                                                          //
//Cody:Trojanct    Joseph:JoeWieneke    Mariz:Magi12    Darian:darianpert97             //    
//Summary:                                                                              //
//This game is a text-based adventure game staring main character Detective Raad.       //
//Talk, Check, Search and more through three chapters.                                  //
//////////////////////////////////////////////////////////////////////////////////////////

const int m = 50;

void prolouge()
{
	ifstream file;
	int proarray[6][50] = { {0} };
	string pro = "pro";
	string text, choice;

	proarray[5][0] = 1;
	proarray[5][1] = 1;
	string proitems[3] = { "badge", "picture" };

	pro += "1.txt";
	//cout << pro << endl;
	file.open(pro.c_str());
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();

	while (proarray[0][0] != 1)
	{
		getline(cin, choice);
		menu(choice, proarray, proitems);
	}

	pro.erase(3, 5);
	pro += "2.txt";
	file.open(pro.c_str());
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	
	while (proarray[0][0] != 2)
	{
		getline(cin, choice);
		menu(choice, proarray, proitems);
	}

	pro.erase(3, 5);
	pro += "3.txt";
	file.open(pro.c_str());
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();

	while (proarray[0][0] != 3)
	{
		getline(cin, choice);
		menu(choice, proarray, proitems);
		if (proarray[4][0] == 1 && proarray[3][0] == 1 && proarray[3][1] == 1)
		{
			proarray[0][0] = 3;
		}
	}

	pro.erase(3, 5);
	pro += "4.txt";
	file.open(pro.c_str());
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();

	while (proarray[0][0] != 4)
	{
		getline(cin, choice);
		menu(choice, proarray, proitems);
	}
	
	pro.erase(3, 5);
	pro += "5.txt";
	file.open(pro.c_str());
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	
	//needs to be fixed because of a security flaw but using it for time being
	//system("CLS");
	pro.erase(3,5);
	cout << "End of prolouge." << endl << endl << endl;
}



void clearscreen()
{
	//relic of trying to get the screen to wipe
	//left here for further implementation.
	cout << string(50, '\n');
}

int main()
{
	//The start of the program
	prolouge();
	chapter1();
	chapter2();
	chapter3();
	chapter4();

	cout <<" THE END "<< endl;
}

void menu(string choice, int array[][50], string items[])
{
	int n = checkchoice(choice);

	switch (n)
	{
	case 1:
		showprolouge(choice, array);
		break;
	case 2:
		talkprolouge(choice, array);
		break;
	case 3:
		checkprolouge(choice, array);
		break;
	case 4:
		notes(choice, array);
		break;
	case 5:
		takeprolouge(choice, array,items);
		break;
	case 6:
		itemsprolouge(choice, array, items);
		break;
	case 7:
		useprolouge;
		break;
	case 8:
		cout << "Can't search right now." << endl;
		break;
	default:
		break;
	}
}

int checkchoice(string choice)
{
	if (choice.compare(0, 4, "show") == 0 || choice.compare(0, 4, "Show") == 0)
	{
		return 1;
	}
	if (choice.compare(0, 4, "talk") == 0 || choice.compare(0, 4, "Talk") == 0)
	{
		return 2;
	}
	if (choice.compare(0, 5, "check") == 0 || choice.compare(0, 5, "Check") == 0)
	{
		return 3;
	}
	if (choice.compare(0, 5, "notes") == 0 || choice.compare(0, 5, "Notes") == 0)
	{
		return 4;
	}
	if (choice.compare(0, 4, "take") == 0 || choice.compare(0, 4, "Take") == 0)
	{
		return 5;
	}
	if (choice.compare(0, 5, "items") == 0 || choice.compare(0, 5, "Items") == 0)
	{
		return 6;
	}
	if (choice.compare(0, 3, "use") == 0 || choice.compare(0, 3, "Use") == 0)
	{
		return 7;
	}
	if (choice.compare(0, 6, "search") == 0 || choice.compare(0, 6, "Search") == 0)
	{
		return 8;
	}
	else
	{
		cout << "I should not do that right now." << endl;
		return 0;
	}
}

void showprolouge(string item, int array[][50])
{
	string badge = "badge";

	if(item.length() < 5)
	{
		cout << "I don't have that item." << endl;
	}
	else if(item.compare(5, badge.length(), "badge") == 0 || item.compare(5, badge.length(), "Badge") == 0 && array[0][0] == 0)
	{
		array[0][0] = 1;
		cout << "I showed my badge to the officer." << endl;
	}
	else
	{
		cout << "I don't have that item." << endl;
	}
}

void talkprolouge(string item, int array[][50])
{
	string Harrison = "harrison";
	ifstream file;
	string text;
	
	if (item.length() < 5)
	{
		cout << "I can't talk to no one." << endl;
	}
	else if (item.compare(5, Harrison.length(), "harrison") == 0 || item.compare(5, Harrison.length(), "Harrison") == 0 && array[0][1] == 0)
	{
		array[0][0] = 2;
		array[0][1] = 1;
		file.open("harr.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
	}
	else
	{
		cout << "They are not here." << endl;
	}
}

void checkprolouge(string item, int array[][50])
{
	string Body = "body";
	string table = "table";
	ifstream file;
	string text;

	if (item.length() < 6)
	{
		cout << "Can't check that." << endl;
	}
	else if ((item.compare(6, Body.length(), "body") == 0 || item.compare(6, Body.length(), "Body") == 0) && array[3][0] == 0)
	{
		array[3][0] = 1;
		file.open("body.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else if (item.compare(6, table.length(), "table") == 0 || item.compare(6, table.length(), "Table") == 0 && array[3][1] == 0)
	{
		array[3][1] = 1;
		file.open("table.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else
	{
		cout << "Can't check that." << endl;
	}
}

void notes(string item, int array[][50])
{
	ifstream file;
	string text;

	file.open("notes.txt");
	getline(file, text);
	cout << text << endl;
	file.close();
}

void takeprolouge(string item, int array[][50],string items[])
{
	string folder = "folder";
	ifstream file;
	string text;

	if (item.length() < 5)
	{

		cout << "Can't take that." << endl;
	}
	else if ((item.compare(5, folder.length(), "folder") == 0 || item.compare(5, folder.length(), "Folder") == 0) && (array[4][0] == 0) && (array[3][1] == 1))
	{
		array[4][0] = 1;
		array[5][3] = 1;
		items[2] = "folder";
		cout << "I took the folder. I will look at it later." << endl;
	}
	else
	{
		cout << "Can't take that." << endl;
	}
}

void itemsprolouge(string item, int array[][50],string items[])
{
	//int itemnumber = sizeof(items) / sizeof(string);
	int itemnumber = 3;
	//cout << itemnumber << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << items[i] << endl;
	}
	if(itemnumber == 3)
	{
		array[0][0] = 4;
	}
}

void useprolouge()
{
	// give micheal the photo
	cout << "Nothing to use." << endl;
}


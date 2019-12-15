#include "gameheader.h"


void chapter3()
{
	cout << "hello" << endl;
}
void aprtmenu(string choice, int array[][50], string items[])
{

	int n = aprtcheckchoice(choice);

	switch (n)
	{
	case 1:
		showaprt(choice, array);
		break;
	case 2:
		talkaprt(choice, array);
		break;
	case 3:
		checkaprt(choice, array);
		break;
	case 4:
		notesaprt(choice, array);
		break;
	case 5:
		takeaprt(choice, array, items);
		break;
	case 6:
		itemaprt(choice, array, items);
		break;
	case 7:
		useaprt;
		break;
	default:
		break;
	}



}
int aprtcheckchoice(string choice)
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
	else
	{
		cout << "I should not do that right now" << endl;
		return 0;
	}


}
void showaprt(string item, int array[][50])
{
	string badge = "badge";
	string key = "key";

	if (item.length() < 5)
	{

		cout << "I don't have that item" << endl;
	}
	else if (item.compare(5, badge.length(), "badge") == 0 || item.compare(5, badge.length(), "Badge") == 0 )
	{
		

	}
	else
	{
		cout << "I don't have that item" << endl;

	}


}
void talkaprt(string item, int array[][50])
{
	

	if (item.length() < 5)
	{
		cout << "I can't talk to no one" << endl;
	}
	else
	{
		cout << "they are not here" << endl;

	}

}
void checkaprt(string item, int array[][50])
{
	string stand = "stand";
	string table = "table";
	string bed = "bed";
	string door = "door";
	string fridge = "fridge";
	ifstream file;
	string text;

	if (item.length() < 6)
	{

		cout << "can't check that" << endl;
	}
	else if (item.compare(6, fridge.length(), "body") == 0 || item.compare(6, Body.length(), "Body"))
	{
		cout << "nothing in here then a jar of pickles and a pizza box" << endl;

	}
	else if (item.compare(6, table.length(), "table") == 0 || item.compare(6, table.length(), "Table") == 0 && array[3][1] == 0)
	{
		array[3][1] = 1;
		file.open("aprttable.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else
	{
		cout << "can't check that" << endl;

	}

}
void notesaprt(string item, int array[][50])
{
	ifstream file;
	string text;

	file.open("notes.txt");
	getline(file, text);
	cout << text << endl;
	file.close();


}
void takeaprt(string item, int array[][50], string items[])
{
	string folder = "folder";
	ifstream file;
	string text;

	if (item.length() < 5)
	{

		cout << "can't take that" << endl;
	}
	else if (item.compare(5, folder.length(), "folder") == 0 || item.compare(5, folder.length(), "folder") == 0 && array[4][0] == 0)
	{
		array[4][0] = 1;
		array[5][3] = 1;
		items[2] = "folder";
		cout << "I took the folder i will look at it later" << endl;

	}
	else
	{
		cout << "can't take that" << endl;

	}

}
void itemaprt(string item, int array[][50], string items[])
{
	//int itemnumber = sizeof(items) / sizeof(string);
	int itemnumber = 3;
	//cout << itemnumber << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << items[i] << endl;
	}
	if (itemnumber == 3)
	{
		array[0][0] = 4;
	}




}
void useaprt()
{
	// give micheal the photo
	cout << "nothing to use" << endl;
}
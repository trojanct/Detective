#include "gameheader.h"
// 0 story
// 1 used
// 2 talked too
// 3 thing has been checked
// 4 item taken
// 5 items
void chapter3()
{
	ifstream file;
	int apartarray[6][50]= { {0} };
	string text, choice;

	apartarray[5][0] = 1;
	apartarray[5][1] = 1;
	apartarray[5][2] = 1;
	apartarray[5][3] = 1;
	string proitems[20] = { "badge", "picture","folder","key" };

	file.open("aprt.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();

	while (apartarray[0][0] != 1)
	{
		getline(cin, choice);
		aprtmenu(choice, apartarray, proitems);

	}



	
}
void aprtmenu(string choice, int array[][50], string items[])
{

	int n = aprtcheckchoice(choice);

	switch (n)
	{
	case 1:
		showaprt();
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
void showaprt()
{
	
	
		cout << "nothing to show right now" << endl;
	
		

}
void talkaprt(string item, int array[][50])
{
	

	if (item.length() < 5)
	{
		cout << "I can't talk to anyone" << endl;
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
	string game = "playboxswitch";
	string small = "smalldoor";
	string dvd = "dvd player";
	string couch = "couch";

	ifstream file;
	string text;

	if (item.length() < 6)
	{

		cout << "can't check that" << endl;
	}
	else if (item.compare(6, fridge.length(), "fridge") == 0 || item.compare(6, fridge.length(), "Fridge") == 0)
	{
		cout << "nothing in here then a jar of pickles and a pizza box" << endl;

	}
	else if (item.compare(6, table.length(), "table") == 0 || item.compare(6, table.length(), "Table") == 0)
	{
		
		file.open("aptable.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else if (item.compare(6, bed.length(), "bed") == 0 || item.compare(6, bed.length(), "Bed") == 0)
	{
		file.open("apbed.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else if (item.compare(6, door.length(), "door") == 0 || item.compare(6, door.length(), "Door") == 0)
	{
		
		cout << "the door is locked somehow i need a key to get int" << endl;
	}
	else if (item.compare(6, game.length(), "playboxswitch") == 0 || item.compare(6, game.length(), "Playboxswitch") == 0)
	{
		file.open("aptgame.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else if (item.compare(6, small.length(), "smalldoor") == 0 || item.compare(6, small.length(), "Smalldoor") == 0)
	{
		file.open("aptsmalldoor.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else if (item.compare(6, dvd.length(), "dvd player") == 0 || item.compare(6, dvd.length(), "DVD Player") == 0)
	{

		file.open("apdvd.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else if (item.compare(6, couch.length(), "couch") == 0 || item.compare(6, couch.length(), "Couch") == 0)
	{
		file.open("apcouch.txt");
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
	//5 is items up to 3 taken
	ifstream file;
	string text;
	string remote = "remote";
	string batteries = "batteries";
	string sim = "sim card";
	string bath = "bathkey";
	string money = "money";

	if (item.length() < 5)
	{

		cout << "can't take that" << endl;
	}
	else if (item.compare(5, batteries.length(), "batteries") == 0 || item.compare(5, batteries.length(), "Batteries") == 0 && array[4][0] == 0)
	{
		if (array[5][0] == 0)
		{
			cout << "I took some of the batteries." << endl;
			array[5][0] == 1;
			item[4] == 1;
		}
		else
		{
			cout << "I already took some of those i don't need more." << endl;
		}

	}
	else if (item.compare(5, remote.length(), "remote") == 0 || item.compare(5, remote.length(), "Remote") == 0 && array[4][0] == 0)
	{

		if (array[5][1] == 0)
		{
			cout << "I got the remote from the innards of the couch" << endl;
			array[5][1] == 1;
			item[5] == 1;
		}
		else
		{
			cout << "I already got that from the couch I am not going back" << endl;
		}

	}
	else if (item.compare(5, bath.length(), "bathkey") == 0 || item.compare(5, bath.length(), "Bathkey") == 0 && array[4][0] == 0)
	{

		if (array[5][3] == 1)
		{
			cout << "I took the bathkey off of the ground" << endl;
			array[5][3] == 1;
			item[6] == 1;
		}
		else
		{
			cout << "I already have that key" << endl;
		}
	}
	else if (item.compare(5, sim.length(), "sim card") == 0 || item.compare(5, sim.length(), "Sim card") == 0 )

{
		if (array[5][2] == 1)
		{
			cout << "I grabbed the sim card it could have information on it" << endl;
			array[5][2] == 1;
			item[7] == 1;
		}
		else
		{
			cout << "I already have that sim card" << endl;
		}

	}
	else if (item.compare(5, money.length(), "money") == 0 || item.compare(5, money.length(), "Money") == 0)
	{
		

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
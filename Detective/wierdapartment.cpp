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

	apartarray[5][16] = 1;
	apartarray[5][17] = 1;
	apartarray[5][18] = 1;
	apartarray[5][19] = 1;
	string items[20] = { "badge", "picture","folder","key" };

	file.open("aprt.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	while (apartarray[0][0] != 1)
	{
		getline(cin, choice);
		aprtmenu(choice, apartarray, items);

	}
	

	file.open("apbathroom.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();

	while (apartarray[0][1] != 1)
	{
		getline(cin, choice);
		aprtmenu(choice, apartarray, items);

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
		checkaprt(choice, array,items);
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
		useaprt( choice, array, items);
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
void checkaprt(string item, int array[][50],string items[])
{
	string stand = "stand";
	string table = "table";
	string bed = "bed";
	string door = "door";
	string fridge = "fridge";
	string game = "playboxswitch";
	string small = "small door";
	string dvd = "dvd player";
	string couch = "couch";
	string waste = "waste basket";
	string towel = "towel";

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
			if (array[3][0] == 0)
			{
				cout << "This is interesting I swipe one of the magazines with Claire’s name and the other address." << endl;
				items[8] = "magazine";
			}
			array[3][0] = 1;
		

	}
	else if (item.compare(6, stand.length(), "stand") == 0 || item.compare(6, stand.length(), "Stand") == 0)
	{
		file.open("apstand.txt");
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
		array[3][2] = 1;

	}
	else if (item.compare(6, door.length(), "door") == 0 || item.compare(6, door.length(), "Door") == 0)
	{
		if (array[0][0] == 0)
		{
		
			cout << "the door is locked somehow i need a key to get in" << endl;
		}
		else
		{
			cout << "door is unlocked now";
		}


	}
	else if (item.compare(6, game.length(), "playboxswitch") == 0 || item.compare(6, game.length(), "Playboxswitch") == 0)
	{
		file.open("aptgame.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		if (array[3][1] == 0)
		{
			cout << "Wait a moment what is this! It had a cracked spine and when I looked inside, I found a note. “Keep this as long as you like -Raad.” This was the game I lent Michael what is this doing here we’ll I’m taking this back but how did it get here." << endl;
			items[9] = "game";
		}
		array[3][1] = 1;

	}
	else if (item.compare(6, small.length(), "small door") == 0 || item.compare(6, small.length(), "Small door") == 0)
	{
		file.open("aptsmalldoor.txt");
		getline(file, text);
		cout << text << endl;
		file.close();

	}
	else if (item.compare(6, dvd.length(), "dvd player") == 0 || item.compare(6, dvd.length(), "DVD Player") == 0)
	{
		if (array[1][1] == 1 && array[5][3] == 0 )
		{
			file.open("apdvd2.txt");
			getline(file, text);
			cout << text << endl;
			file.close();
			array[3][6] = 1;
		}
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
			array[3][4] = 1;
			if (array[5][1] == 0)
			{
				cout << "There is also a remote no batteries though." << endl;
			}

	}

	else if ((item.compare(6, towel.length(), "towel") == 0 || item.compare(6, towel.length(), "Towel") == 0) && array[0][0] == 1)
	{
		file.open("aptowel.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		//33
	}
	else if ((item.compare(6, waste.length(), "waste basket") == 0 || item.compare(6, waste.length(), "Waste basket") == 0) && array[0][0] == 1)
	{
		file.open("apwaste.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][3] = 1;
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
	else if ((item.compare(5, batteries.length(), "batteries") == 0 || item.compare(5, batteries.length(), "Batteries") == 0) && array[3][2] == 1)
	{
		if (array[5][0] == 0)
		{
			cout << "I took some of the batteries." << endl;
			array[5][0] = 1;
			items[4] = batteries;
		}
		else
		{
			cout << "I already took some of those i don't need more." << endl;
		}

	}
	else if((item.compare(5, remote.length(), "remote") == 0 || item.compare(5, remote.length(), "Remote") == 0) && array[3][4] == 1)
	{

		if (array[5][1] == 0)
		{
			cout << "I got the remote from the innards of the couch it needs some batteris to \"use\" on it" << endl;
			array[5][1] = 1;
			items[5] = remote;
		}
		else
		{
			cout << "I already got that from the couch I am not going back" << endl;
		}

	}
	else if((item.compare(5, bath.length(), "bathkey") == 0 || item.compare(5, bath.length(), "Bathkey") == 0) && array[1][1] == 1)
	{

		if (array[5][3] == 0)
		{
			cout << "I took the bathkey off of the ground" << endl;
			array[5][3] = 1;
			items[6] = bath;
		}
		else
		{
			cout << "I already have that key" << endl;
		}
	}
	else if((item.compare(5, sim.length(), "sim card") == 0 || item.compare(5, sim.length(), "Sim card") == 0) && array[3][3] == 1)

	{
		if (array[5][2] == 0)
		{
			cout << "I grabbed the sim card it could have information on it" << endl;
			array[5][2] = 1;
			items[7] = sim;
		}
		else
		{
			cout << "I already have that sim card" << endl;
		}

	}
	else if (item.compare(5, money.length(), "money") == 0 || item.compare(5, money.length(), "Money") == 0)
	{
		
		cout << " i can't take that im a good cop" << endl;
	}
	else
	{
		cout << "can't take that" << endl;

	}
	

}
void itemaprt(string item, int array[][50], string items[])
{
	

	for (int i = 0; i < sizeof(items); i++)
	{
		cout << items[i] << endl;
	}
	




}
void useaprt(string item, int array[][50], string items[])
{
	ifstream file;
	string text;
	string remote = "remote";
	string batteries = "batteries";
	string sim = "sim card";
	string bath = "bathkey";


	if (item.length() < 4)
	{

		cout << "can't use that" << endl;
	}
	else if (item.compare(4, batteries.length(), "batteries") == 0 || item.compare(4, batteries.length(), "Batteries") == 0 && array[5][0] == 1)
	{
		if (array[5][0] == 1 && array[1][0] == 0)
		{
			cout << "I put the batteries into the remote. I could \"use\" this remote now that it has power" << endl;
			array[1][0] = 1;
		}
		else if (array[1][0] == 1)
		{
			cout << "The batteries are already in the remote" << endl;
		}
		else
		{
			cout << "don't have that" << endl;
		}
		


	}
	else if( (item.compare(4, remote.length(), "remote") == 0 || item.compare(4, remote.length(), "Remote") == 0 )&& array[5][1] == 1)
	{
		if (array[1][1] == 0 && array[1][0] == 1)
		{
			cout << "I click the on button on the remote and a loud clinking noise starts to come out of the dvd player i press open and it stops what was that sound" << endl;
			array[1][1] = 1;
		}
		else if (array[1][0] == 0)
		{
			cout << "The remote needs batteries" << endl;
		}
		else
		{
			cout << "not much use for this remote now" << endl;
		}

	}
	else if (item.compare(4, bath.length(), "bathkey") == 0 || item.compare(4, bath.length(), "Bathkey") == 0 && array[5][3] == 1)
	{
		if (array[0][0] == 0)
		{
			array[0][0] = 1;
		}
		else
		{
			cout << "already used that to open the door" << endl;
		}
	}
	else if ((item.compare(4, sim.length(), "sim card") == 0 || item.compare(4, sim.length(), "Sim Card") == 0) && array[5][2] == 1)
	{
		if (array[3][3] == 1)
		{
			file.open("sim.txt");
			getline(file, text);
			cout << text << endl;
			file.close();
			array[0][1] = 1;
		}
		else
		{
			cout << "cant use that yet" << endl;
		}
	}
	else
	{
		cout << "can't use that" << endl;
	}

}
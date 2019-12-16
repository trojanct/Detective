#include "gameheader.h"
//parts of the array that are being tracked
// 0 story
// 1 used
// 2 talked too
// 3 thing has been checked
// 4 item taken
// 5 items
void chapter3()
{
	ifstream file;
	//array used to keep track of certain events
	int apartarray[6][50]= { {0} };
	string text, choice;

	//initiating already gotten items 
	apartarray[5][16] = 1;
	apartarray[5][17] = 1;
	apartarray[5][18] = 1;
	apartarray[5][19] = 1;
	apartarray[5][15] = 1;
	//putting known items into array
	string items[20] = { "badge", "picture","folder","key","trophy" };

	
	//opening file to use as intro
	//used txt files due to large amount of text
	file.open("aprt.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	//while loop waitng for [0][0] which 0 contains story elements
	while (apartarray[0][0] != 1)
	{
		getline(cin, choice);
		aprtmenu(choice, apartarray, items);
	}
	//opens next story bit description
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
	//tells end of chapter
	cout << "End of chapter 3." << endl << endl << endl;
}

void aprtmenu(string choice, int array[][50], string items[])
{
	//checks to see if the players original action is valid
	int n = aprtcheckchoice(choice);

	//switch to use for multiple choices
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
		//show was not an option when coding for this section was done
	}
}

int aprtcheckchoice(string choice)
{
	//checking to make sure what the player typed is valid
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
		cout << "I should not do that right now." << endl;
		return 0;
	}
}

void showaprt()
{
	cout << "Nothing to show right now." << endl;
}

void talkaprt(string item, int array[][50])
{
	if (item.length() < 5)
	{
		cout << "I can't talk to anyone." << endl;
	}
	else
	{
		cout << "They are not here." << endl;
	}
}

void checkaprt(string item, int array[][50],string items[])
{
	//initialized strings that are also here for a reminder what is in this section of story
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
	//check to see if the place can be checked or it isn'ta valid item
	//checks to see if more that just the choice was put it
	if (item.length() < 6)
	{
		cout << "Can't check that." << endl;
	}
	else if (item.compare(6, fridge.length(), "fridge") == 0 || item.compare(6, fridge.length(), "Fridge") == 0)
	{
		cout << "Nothing in here other than a jar of pickles and a pizza box." << endl;
	}
	else if (item.compare(6, table.length(), "table") == 0 || item.compare(6, table.length(), "Table") == 0)
	{
		//opens appropriate text file and runs the text then closes the fle
		file.open("aptable.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		//makes sure that if something was taken from the scene is not there anymore
		if (array[3][0] == 0)
		{
			cout << "This is interesting. I swipe one of the magazines with Claire’s name and the other address." << endl;
			//puts new item into items array and can now be checked with items
			items[8] = "magazine";
		}
		//showing that this area has been checked
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
		
			cout << "The door is locked. I need a key to get in." << endl;
		}
		else
		{
			cout << "Door is unlocked now.";
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
			cout << "Wait a moment. What is this! It had a cracked spine and when I looked inside, I found a note. “Keep this as long as you like -Raad.” This was the game I lent Michael. What is this doing here? Well, I’m taking this back, but how did it get here?" << endl;
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
			cout << "There is also a remote. No batteries though." << endl;
		}
	}
	//this also checks to see if the right part of the story has been reached yet before continuing
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
		cout << "Can't check that." << endl;
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
	//initialized items to be used in checking and for reference that they are valid
	ifstream file;
	string text;
	string remote = "remote";
	string batteries = "batteries";
	string sim = "sim card";
	string bath = "bathkey";
	string money = "money";

	//checks to see if they put more than the choice
	if (item.length() < 5)
	{
		cout << "Can't take that." << endl;
	}
	// checks to see if the choice item is valid but also checks to see if the item has been found first before it can be interacted with
	else if ((item.compare(5, batteries.length(), "batteries") == 0 || item.compare(5, batteries.length(), "Batteries") == 0) && array[3][2] == 1)
	{
		if (array[5][0] == 0)
		{
			cout << "I took some of the batteries." << endl;
			array[5][0] = 1;
			//added to items
			items[10] = batteries;
		}
		else
		{
			cout << "I already took some of those, I don't need more." << endl;
		}
	}
	else if((item.compare(5, remote.length(), "remote") == 0 || item.compare(5, remote.length(), "Remote") == 0) && array[3][4] == 1)
	{
		if (array[5][1] == 0)
		{
			cout << "I got the remote from the innards of the couch. It needs some batteries to \"use\" on it" << endl;
			array[5][1] = 1;
			items[5] = "remote";
		}
		else
		{
			cout << "I already got that from the couch. I am not going back." << endl;
		}
	}
	else if((item.compare(5, bath.length(), "bathkey") == 0 || item.compare(5, bath.length(), "Bathkey") == 0) && array[1][1] == 1)
	{
		if (array[5][3] == 0)
		{
			cout << "I took the bathkey off of the ground." << endl;
			array[5][3] = 1;
			items[6] = bath;
		}
		else
		{
			cout << "I already have that key." << endl;
		}
	}
	else if((item.compare(5, sim.length(), "sim card") == 0 || item.compare(5, sim.length(), "Sim card") == 0) && array[3][2] == 1)
	{
		if (array[5][2] == 0)
		{
			cout << "I grabbed the sim card. It could have information on it." << endl;
			array[5][2] = 1;
			items[7] = sim;
		}
		else
		{
			cout << "I already have that sim card." << endl;
		}
	}
	else if (item.compare(5, money.length(), "money") == 0 || item.compare(5, money.length(), "Money") == 0)
	{
		
		cout << "I can't take that, I'm a good cop." << endl;
	}
	else
	{
		cout << "Can't take that." << endl;
	}
}

void itemaprt(string item, int array[][50], string items[])
{
	//making sure only the valid items are  shown
	for (int i = 0; i < 20; i++)
	{	
		if (items[i] != "")
		{
			cout << items[i] << endl;
		}
	}
}

void useaprt(string item, int array[][50], string items[])
{
	//initializes items for check and also reference that they are here
	ifstream file;
	string text;
	string remote = "remote";
	string batteries = "batteries";
	string sim = "sim card";
	string bath = "bathkey";
	//checking to see if they put more than the choice
	if (item.length() < 4)
	{
		cout << "Can't use that." << endl;
	}
	//checks to see if choice is valid but also to see if that item can be used yet
	else if (item.compare(4, batteries.length(), "batteries") == 0 || item.compare(4, batteries.length(), "Batteries") == 0 && array[5][0] == 1)
	{
		if (array[5][0] == 1 && array[1][0] == 0 && array[5][1] == 1)
		{
			cout << "I put the batteries into the remote. I could \"use\" this remote now that it has power." << endl;
			array[1][0] = 1;
		}
		else if (array[1][0] == 1)
		{
			cout << "The batteries are already in the remote" << endl;
		}
		else
		{
			cout << "Don't have that." << endl;
		}
	}
	else if( (item.compare(4, remote.length(), "remote") == 0 || item.compare(4, remote.length(), "Remote") == 0 )&& array[5][1] == 1)
	{
		if (array[1][1] == 0 && array[1][0] == 1)
		{
			cout << "I click the on button on the remote and a loud clinking noise starts to come out of the dvd player. I press open and it stops. What was that sound?" << endl;
			array[1][1] = 1;
		}
		else if (array[1][0] == 0)
		{
			cout << "The remote needs batteries." << endl;
		}
		else
		{
			cout << "Not much use for this remote now." << endl;
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
			cout << "Already used that to open the door." << endl;
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
			cout << "Cant use that yet." << endl;
		}
	}
	else
	{
		cout << "Can't use that." << endl;
	}
}
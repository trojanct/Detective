#include "gameheader.h"
// 0 story
// 1 items showed
// 2 items owned
// 3 people talked too

void chapter2()
{
	ifstream file;
	int outarray[4][50] = { {0} };
	string text, choice;

	outarray[2][0] = 1;
	outarray[2][1] = 1;
	outarray[2][2] = 1;
	outarray[2][3] = 1;
	string items[20] = { "badge", "picture","folder","key" };

	file.open("out1.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	while (outarray[0][0] != 1)
	{
		getline(cin, choice);
		outmenu(choice, outarray, items);
		if (outarray[3][0] == 1 && outarray[3][1] == 1 && outarray[3][2] == 1 && outarray[3][3] == 1 && outarray[3][4] == 1)
		{
			outarray[0][0] = 1;
		}

	}

	file.open("out2.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	
	cout << "End of chapter 2" << endl << endl << endl;

}
void outmenu(string choice, int array[][50], string items[])
{

	int n = checkchoice(choice);
	

	switch (n)
	{
	case 1:
		showout(choice,array);
		break;
	case 2:
		talkout(choice, array);
		break;
	case 3:
		checkout(choice, array, items);
		break;
	case 4:
		notesout(choice, array);
		break;
	case 5:
		takeout(choice, array, items);
		break;
	case 6:
		itemout(choice, array, items);
		break;
	case 7:
		useout(choice, array, items);
		break;
	case 8:
		cout << "nothing to search" << endl;

	default:
		break;
	}



}
void showout(string item, int array[][50])
{
	string badge = "badge";


	if (item.length() < 5)
	{
		cout << "I don't have that item" << endl;
	}
	else if (item.compare(5, badge.length(), "badge") == 0 || item.compare(5, badge.length(), "Badge") == 0)
	{
		if (array[1][0] == 0 && array[3][0] == 1)
		{
			array[1][0] = 1;
			cout << "I showed my badge to the nosey woman" << endl;
		}
		else
		{
			cout << "I don't need to do that right now" << endl;
		}
	}
	else
	{
		cout << "I don't have that item" << endl;
	}

}
void talkout(string item, int array[][50])
{
	string nosey = "nosey woman";
	string paparazzo = "paparazzo";
	string homeless = "homeless man";
	string excited = "excited woman";
	string angry = "angry man";
	ifstream file;
	string text;


	

	if (item.length() < 5)
	{
		cout << "I can't talk to no one" << endl;
	}
	else if (item.compare(5, nosey.length(), "nosey woman") == 0 || item.compare(5, nosey.length(), "Nosey woman") == 0)
	{
		if (array[1][0] == 1)
		{
			file.open("outnm.txt");
			getline(file, text);
			cout << text << endl;
			file.close();
		}
		else
		{
			cout << "I went up to her but she just told me to show her a badge or get out of her way." << endl;
			cout << "I guess i need to show her my badge if I need information." << endl;
			array[3][0] = 1;
		}
	}
	else if (item.compare(5, paparazzo.length(), "paparazzo") == 0 || item.compare(5, paparazzo.length(), "Paparazzo") == 0)
	{

		file.open("outpap.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][1] = 1;

	}
	else if (item.compare(5, homeless.length(), "homeless man") == 0 || item.compare(5, homeless.length(), "Homeless Man") == 0)
	{

		file.open("outhmlss.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][2] = 1;
	}
	else if (item.compare(5, excited.length(), "excited woman") == 0 || item.compare(5, excited.length(), "Excited Woman") == 0)
	{

		file.open("outew.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][3] = 1;
	}
	else if (item.compare(5, angry.length(), "angry man") == 0 || item.compare(5, angry.length(), "Angry Man") == 0)
	{
		
		file.open("outam.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][4] = 1;
	}
	else
	{
		cout << "they are not here" << endl;

	}

}
void checkout(string item, int array[][50], string items[])
{

	if (item.length() < 6)
	{

		cout << "can't check that out at the moment" << endl;
	}
	else
	{
		cout << "can't check that out at the moment" << endl;
	}
	

}
void notesout(string item, int array[][50])
{
	ifstream file;
	string text;

	file.open("notes.txt");
	getline(file, text);
	cout << text << endl;
	file.close();


}
void takeout(string item, int array[][50], string items[])
{

	if (item.length() < 5)
	{

		cout << "can't take that" << endl;
	}
	else
	{
		cout << "can't take that" << endl;

	}


}
void itemout(string item, int array[][50], string items[])
{


	for (int i = 0; i < sizeof(items); i++)
	{
		cout << items[i] << endl;
	}





}
void useout(string item, int array[][50], string items[])
{
	ifstream file;
	string text;
	


	if (item.length() < 4)
	{

		cout << "can't use that right now" << endl;
	}
	else
	{
		cout << "can't use that right now" << endl;
	}

}
#include "gameheader.h"
// 0 story
// 1 searched
// 2 talked too
// 3 thing has been checked
// 4 item taken
// 5 items
void chapter1()
{
	ifstream file;
	int harray[6][50] = { {0} };
	string text, choice;

	harray[5][0] = 1;
	harray[5][1] = 1;
	harray[5][2] = 1;
	string items[20] = { "badge", "picture","folder" };

	file.open("houseBegin.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	while (harray[0][0] != 1)
	{
		getline(cin, choice);
		hmenu(choice, harray, items);
		if (harray[4][0] == 1 && harray[4][1] == 1)
		{
			harray[0][0] = 1;
		}
	}

	cout << "That is all I'm going to find in here. I should go outside and get some witness testimony if able." << endl;
	cout << "End of chapter 1." << endl << endl << endl;
}

void hmenu(string choice, int array[][50], string items[])
{
	int n = checkchoice(choice);

	switch (n)
	{
	case 1:
		cout << "We are full on searching. Don't have time to show something." << endl;
		break;
	case 2:
		talkh(choice, array);
		break;
	case 3:
		checkh(choice, array);
		break;
	case 4:
		notes(choice, array);
		break;
	case 5:
		takeh(choice, array, items);
		break;
	case 6:
		itemh(choice, array, items);
		break;
	case 7:
		cout << "Nothing to use right now." << endl;
		break;
	case 8:
		searchh(choice, array);
		break;
	default:
		break;
	}
}

void searchh(string item, int array[][50])
{
	string study = "study";
	string kitchen = "kitchen";
	string brothers = "brothers-bedroom";
	string bedroom = "master-bedroom";
	string boxes = "boxes";
	string bookshelf = "bookshelf";
	string desk = "desk";

	ifstream file;
	string text;

	if (item.length() < 7)
	{
		cout << "Can't search that." << endl;
	}
	else if (item.compare(7, study.length(), "study") == 0 || item.compare(7, study.length(), "Study") == 0)
	{
		file.open("houseStudy.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[1][0] = 1;
	}
	else if (item.compare(7, kitchen.length(), "kitchen") == 0 || item.compare(7, kitchen.length(), "Kitchen") == 0)
	{
		file.open("houseKitchen.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[1][1] = 1;
	}
	else if (item.compare(7, brothers.length(), "brothers-bedroom") == 0 || item.compare(7, brothers.length(), "brothers-bedroom") == 0)
	{
		file.open("houseBrothersBedroom.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[1][2] = 1;
	}
	else if (item.compare(7, bedroom.length(), "master-bedroom") == 0 || item.compare(7, bedroom.length(), "master-bedroom") == 0)
	{
		file.open("houseVictimBedroom.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[1][3] = 1;
	}
	else if ((item.compare(7, boxes.length(), "boxes") == 0 || item.compare(7, boxes.length(), "boxes") == 0) && array[1][2] == 1)
	{
		file.open("houseBrothersBedroomBoxes.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[1][4] = 1;
	}
	else if (item.compare(7, bookshelf.length(), "bookshelf") == 0 || item.compare(7, bookshelf.length(), "Bookshelf") == 0 && array[1][3] == 1)
	{
		file.open("houseStudyBookshelf.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[1][5] = 1;
	}
	else if (item.compare(7, desk.length(), "desk") == 0 || item.compare(7, desk.length(), "Desk") == 0 && array[1][3] == 1)
	{
		file.open("houseStudyDesk.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[1][6] = 1;
	}
	else
	{
		cout << "Can't search that." << endl;
	}
}

void checkh(string item, int array[][50])
{
	string mail = "mail";
	string trash = "trash";
	string book = "book";
	string nightstand = "nightstand";
	string box = "box";

	ifstream file;
	string text;

	if (item.length() < 6)
	{
		cout << "Can't check that." << endl;
	}
	else if ((item.compare(6, mail.length(), "mail") == 0 || item.compare(6, mail.length(), "Mail") == 0) && array[1][1] == 1)
	{
		file.open("houseKitchenMail.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][1] = 1;
	}
	else if ((item.compare(6, trash.length(), "trash") == 0 || item.compare(6, trash.length(), "Trash") == 0) && array[3][1] == 1)
	{
		file.open("houseKitchenTrash.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][2] = 1;
	}
	else if ((item.compare(6, book.length(), "book") == 0 || item.compare(6, book.length(), "Book") == 0) && array[1][5] == 1)
	{
		file.open("HouseStudyBookshelfBook.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][3] = 1;
	}
	else if ((item.compare(6, nightstand.length(), "nightstand") == 0 || item.compare(6, nightstand.length(), "Nightstand") == 0) && array[1][3] == 1)
	{
		file.open("houseVictimsBedroomNightstand.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][4] = 1;
	}
	else if ((item.compare(6, box.length(), "box") == 0 || item.compare(6, box.length(), "Box") == 0) && array[1][3] == 1)
	{
		file.open("houseVictimsBedroomBox.txt");
		getline(file, text);
		cout << text << endl;
		file.close();
		array[3][5] = 1;
	}
	else
	{
		cout << "Can't check that." << endl;
	}
}

void takeh(string item, int array[][50], string items[])
{
	string key = "key";
	string trophy = "trophy";

	ifstream file;
	string text;

	if (item.length() < 5)
	{

		cout << "Can't take that." << endl;
	}
	else if ((item.compare(5, key.length(), "key") == 0 || item.compare(5, key.length(), "Key") == 0) && array[3][3] == 1)
	{
		if (array[4][0] == 0)
		{
			cout << "I took the key and on it, it said Mayfield" << endl;
			array[4][0] = 1;
		}
		else
		{
			cout << "Already took that." << endl;
		}
	}
	else if ((item.compare(5, trophy.length(), "trophy") == 0 || item.compare(5, trophy.length(), "trophy") == 0) && array[1][4] == 1)
	{
		if (array[4][1] == 0)
		{
			cout << "I took the trophy carefully." << endl;
			array[4][1] = 1;
		}
	}
	else
	{
		cout << "Can't take that." << endl;
	}
}

void itemh(string item, int array[][50], string items[])
{
	for (int i = 0; i < 20; i++)
	{
		cout << items[i] << endl;
	}
}

void talkh(string item, int array[][50])
{
	string Harrison = "harrison";
	ifstream file;
	string text;

	if (item.length() < 5)
	{
		cout << "I can't talk to no one." << endl;
	}
	else if (item.compare(5, Harrison.length(), "harrison") == 0 || item.compare(5, Harrison.length(), "Harrison") == 0)
	{
		cout << "I talk to Harrison." << endl;
		cout << "What you need to do is find the murder weapon. If you can see anything out of the ordinay" << endl;
	}
	else
	{
		cout << "They are not here." << endl;
	}
}

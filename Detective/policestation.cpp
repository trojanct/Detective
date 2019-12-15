#include "gameheader.h"
// 0 story
// 1 used
// 2 talked too
// 3 thing has been checked
// 4 item taken
// 5 items
void chapter4()
{
	ifstream file;
	int psarray[6][50] = { {0} };
	string text, choice;

	string items[20] = { "badge", "picture","folder","key","glass shards","gamedisc","burner phone" };

	file.open("ps1.txt");
	getline(file, text);
	cout << text << endl;
	text.clear();
	file.close();
	while (psarray[0][0] != 1)
	{
		cout << "Talk Michael" << endl;
		cout << "Talk Louie" << endl;
		cout << "Evidence" << endl;
		cout << "Choose culprit" << endl;
		getline(cin, choice);
		psmenu(choice, psarray, items);

	}


	


	cout << "End of chapter 4" << endl << endl << endl;

}
void psmenu(string choice, int array[][50], string items[])
{

	int n = pscheckchoice(choice);

	switch (n)
	{
	
	case 1:
		finaltalk(choice, array);
		break;
	case 2:
		evidence(choice);
		break;
	case 3:
		choose(choice);
		array[0][0] = 1;
		break;
	default:
		break;
	}



}
int pscheckchoice(string choice)
{


	if (choice.compare(0, 4, "talk") == 0 || choice.compare(0, 4, "Talk") == 0)
	{
		return 1;
	}
	if (choice.compare(0, 8, "evidence") == 0 || choice.compare(0, 8, "Evidence") == 0)
	{
		return 2;
	}
	if (choice.compare(0, 6, "choose") == 0 || choice.compare(0, 6, "Choose") == 0)
	{
		return 3;
	}
	else
	{
		cout << "I should not do that right now" << endl;
		return 0;
	}


}
void finaltalk(string item ,int array[][50])
{
	ifstream file;
	string text;
	string mike = "michael";
	string lou = "Louie";


	if (item.length() < 5)
	{
		cout << "that is not an option" << endl;
	}
	else if (item.compare(5, mike.length(), "michael") == 0 || item.compare(5, mike.length(), "Michael") == 0)
	{

		if (array[2][0] == 0)
		{
			file.open("psmichael.txt");
			getline(file, text);
			cout << text << endl;
			file.close();
			array[2][0] = 1;
		}
		else
		{
			cout << "i already talked to him" << endl;
		}

	}
	else if (item.compare(5, lou.length(), "louie") == 0 || item.compare(5, lou.length(), "Louie") == 0)
	{

		if (array[2][1] == 0)
		{
			file.open("pslouie.txt");
			getline(file, text);
			cout << text << endl;
			file.close();
			array[2][1] = 1;
		}
		else
		{
			cout << "i already talked to him" << endl;
		}

	}
	else
	{
		cout << "that is not an option" << endl;

	}

}
void evidence(string item)
{
	ifstream file;
	string text;

	file.open("evidence.txt");
	while (getline(file, text))
	{
		cout << text << endl;
	}
	file.close();
}
void choose(string item)
{
	ifstream file;
	string text;
	string mike = "michael";
	string lou = "Louie";


	if (item.length() < 7)
	{
		cout << "that is not an option" << endl;
	}
	else if (item.compare(7, mike.length(), "michael") == 0 || item.compare(7, mike.length(), "Michael") == 0)
	{

			file.open("choseMichael.txt");
			getline(file, text);
			cout << text << endl;
			file.close();
			
	}
	else if (item.compare(7, lou.length(), "louie") == 0 || item.compare(7, lou.length(), "Louie") == 0)
	{

		
			file.open("choseLouie.txt");
			getline(file, text);
			cout << text << endl;
			file.close();
	
	}
	else
	{
		cout << "that is not an option" << endl;

	}
}

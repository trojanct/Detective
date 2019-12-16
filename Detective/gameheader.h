#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//prolouge

//checks the choice of the player to see if it'scalid
int checkchoice(string choice);
//checks the notes of the crime
void notes(string item, int array[][50]);
//clears the screen not fully implemented due to old techniques and security
void clearscreen();
//if choice was valid goes to correct selection in menu
void menu(string choice, int array[][50], string items[]);
//all the items that can be shown by the player
void showprolouge(string item, int array[][50]);
//all the people they can talk too
void talkprolouge(string item, int array[][50]);
//all the places and things the player can check out
void checkprolouge(string item, int array[][50]);
//all the things the player can take in this section
void takeprolouge(string item, int array[][50], string items[]);
//calls function to list the items
void itemsprolouge(string item, int array[][50], string items[]);
//everthing the player can use
void useprolouge();

//chapter 3 wierd apartment
void chapter3();
void aprtmenu(string choice, int array[][50], string items[]);
int aprtcheckchoice(string choice);
void showaprt();
void talkaprt(string item, int array[][50]);
void checkaprt(string item, int array[][50],string items[]);
void notesaprt(string item, int array[][50]);
void takeaprt(string item, int array[][50], string items[]);
void itemaprt(string item, int array[][50], string items[]);
void useaprt(string item, int array[][50], string items[]);

//outside
void chapter2();
void outmenu(string choice, int array[][50], string items[]);
void showout(string item, int array[][50]);
void notesout(string item, int array[][50]);
void takeout(string item, int array[][50], string items[]);
void checkout(string item, int array[][50], string items[]);
void notesout(string item, int array[][50]);
void talkout(string item, int array[][50]);
void checkout(string item, int array[][50], string items[]);
void itemout(string item, int array[][50], string items[]);
void useout(string item, int array[][50], string items[]);

//police station
void chapter4();
//talking to victims husband and brother one last time
void finaltalk(string item, int array[][50]);
int pscheckchoice(string choice);
void psmenu(string choice, int array[][50], string items[]);
//list of all evidence found in the story
void evidence(string item);
//choosing who goes to jail
void choose(string item);

//house
void chapter1();
void hmenu(string choice, int array[][50], string items[]);
void searchh(string item, int array[][50]);
void checkh(string item, int array[][50]);
void takeh(string item, int array[][50], string items[]);
void itemh(string item, int array[][50], string items[]);
void talkh(string item, int array[][50]);
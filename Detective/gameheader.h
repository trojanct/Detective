#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int checkchoice(string choice);
void notes(string item, int array[][50]);


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
void finaltalk(string item, int array[][50]);
int pscheckchoice(string choice);
void psmenu(string choice, int array[][50], string items[]);
void evidence(string item);
void choose(string item);

void chapter1();
void hmenu(string choice, int array[][50], string items[]);
void searchh(string item, int array[][50]);
void checkh(string item, int array[][50]);
void takeh(string item, int array[][50], string items[]);
void itemh(string item, int array[][50], string items[]);
void talkh(string item, int array[][50]);



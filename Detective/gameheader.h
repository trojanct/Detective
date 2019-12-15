#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int checkchoice(string choice);

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




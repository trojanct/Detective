#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void chapter3();
void aprtmenu(string choice, int array[][50], string items[]);
int aprtcheckchoice(string choice);
void showaprt();
void talkaprt(string item, int array[][50]);
void checkaprt(string item, int array[][50]);
void notesaprt(string item, int array[][50]);
void takeaprt(string item, int array[][50], string items[]);
void itemaprt(string item, int array[][50], string items[]);
void useaprt();


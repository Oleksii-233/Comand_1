#pragma once

#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

extern fstream protocol;

extern char name[], bname[];

struct PeopleInformation {
	int Number = 0;
	char Name[100] = "\0";
	char Surname[100] = "\0";
	char Sex[50] = "\0";
	int Height = 0;
	int Weight = 0;
	int ClothesNumber = 0;
	int ShoesNumber = 0;
};

void IsOpen(fstream& file);
void p_Add(string text);
void p_Add(PeopleInformation p);
void p_Add();
void p_Add_Arr(PeopleInformation* p, int l);
void p_Read();

#endif

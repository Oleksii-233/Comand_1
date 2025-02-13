#include "Protocol.h"

#include <iomanip>

char name[] = "protocol.txt", bname[] = "PeopleInformation_1.dat";
fstream protocol;

void IsOpen(fstream& file) {
	if (!file.is_open()) {
		cout << "Not open." << endl;
		exit(1);;
	}
}

void p_Add() {
	IsOpen(protocol);
	protocol << setw(3) << "N" << setw(20) << "Surname" << setw(20) << "Name" << setw(10) << "Gender" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Clothes" << setw(10) << "Shoes" << endl;
}

void p_Add(string text) {
	IsOpen(protocol);
	protocol << text << endl;
}

void p_Add(PeopleInformation p) {
	IsOpen(protocol);
	protocol << setw(3) << p.Number << setw(20) << p.Surname << setw(20) << p.Name << setw(10) << p.Sex << setw(10) << p.Height << setw(10) << p.Weight << setw(10) << p.ClothesNumber << setw(10) << p.ShoesNumber << endl;
}

void p_Add_Arr(PeopleInformation* p, int l) {

	IsOpen(protocol);

	for (int i = 0; i < l; i++)
		p_Add(*(p + i));

}

void p_Read() {
	string line;

	protocol.open(name, ios::in);

	IsOpen(protocol);

	while (getline(protocol, line))
		cout << line << endl;

	protocol.close();
}
﻿#include "Dar`ev.h"

void Shapka() {
	cout << setw(3) << "N" << setw(20) << "Surname" << setw(20) << "Name" << setw(8) << "Gender" << setw(5) << "Height" << setw(5) << "Weight" << setw(7) << "Clothes" << setw(7) << "Shoes" << endl;
}

void ShowPeople(PeopleInformation inf) {
	cout << setw(3) << inf.Number << setw(20) << inf.Surname << setw(20) << inf.Name << setw(8) << inf.Sex << setw(5) << inf.Height << setw(5) << inf.Weight << setw(7) << inf.ClothesNumber << setw(8) << inf.ShoesNumber << endl;
}

void EnterPeople(PeopleInformation& People) {
	cout << "Write the people number: "; cin >> People.Number; cin.ignore();
	cout << "Write the people name: "; cin.getline(People.Name, 50);
	cout << "Write the people surname: "; cin.getline(People.Surname, 50);
	cout << "Write the people sex: "; cin.getline(People.Sex, 50);
	cout << "Write the people height: "; cin >> People.Height;
	cout << "Write the people weight: "; cin >> People.Weight;
	cout << "Write the people clothes number: "; cin >> People.ClothesNumber;
	cout << "Write the people shoes numbeer: " ; cin >> People.ShoesNumber;
}

void WriteInFile(fstream& File) {
	PeopleInformation People;
	int NumberPeople = 0;

	File.open(bname, ios::out | ios::binary);

	if (!File.is_open()) {
		cout << "File isn`t open!" << endl;
		exit(1);
	}

	p_Add("Creating File");
	p_Add();

	cout << "Enter count of people: "; TrueNum(NumberPeople);

	for (int i = 0; i < NumberPeople; i++) {
		EnterPeople(People);
		p_Add(People);
		File.write((char*)&People, sizeof People);

	}

	File.close();
}

void ShowSex(fstream& File) {
	PeopleInformation People;
	char SexIndex[15] = "\0";
	cout << "Input gender: "; cin.ignore(); cin.get(SexIndex, 15);
	int k = 0;

	File.open(bname, ios::in | ios::binary);

	if (!File.is_open()) {
		cout << "File isn`t open!" << endl;
		exit(1);
	}

	p_Add("People with needs gender.");

	Shapka();
	while (File.read((char*)&People, sizeof People)) {

		if (strcmp(People.Sex, SexIndex) == 0) {
			ShowPeople(People);
			k++;
		}
	}

	if (k == 0) {
		system("cls");
		cout << "People not find." << endl;
		p_Add("People not find.");
	}
	else {
		File.clear(); File.seekg(0);
		p_Add();
		while (File.read((char*)&People, sizeof People)) 
			if (strcmp(People.Sex, SexIndex) == 0) 
				p_Add(People);	
	}

	File.close();
}

void IndenticalHeightAndShoes(fstream& File) {
	PeopleInformation People[15], p;
	int counter = 0;
	File.open(bname, ios::in | ios::binary);

	if (!File.is_open()) {
		cout << "File dont opened" << endl;
		exit(1);
	}


	while (File.read((char*)&p, sizeof(p)))
		People[counter++] = p;


	p_Add("People from indentical weight and shoes number.");

	int k = 0;
	cout << setw(10) << "Surname" << setw(10) << "Weight" << setw(20) << "Shoes" << endl;
	for (int i = 0; i < counter - 1; i++) {

		for (int j = i + 1; j < counter; j++) {
			if (People[i].Weight < People[j].Weight) {
				swap(People[i], People[j]);
			}
			if (People[i].Weight == People[j].Weight && People[i].ShoesNumber == People[j].ShoesNumber)
				k++;
		}
	}

	if (k == 0) {
		cout << "People not find." << endl;
		p_Add("People not find.");

		File.close();

		int k = 0;
		for (int i = 0; i < counter - 1; i++)
			for (int j = i + 1; j < counter; j++)
				if (People[i].Weight == People[j].Weight && People[i].ShoesNumber == People[j].ShoesNumber)
					k++;

		p_Add("People with indentical weight and shoes");
		if (!k) {
			cout << "This people is mising" << endl;
			p_Add("Mising");

		}
		else {
			bool printed[15] = { false };

			cout << setw(10) << "Surname" << setw(20) << "Weight" << setw(20) << "Shoes" << endl;
			p_Add();
			for (int i = 0; i < counter - 1; i++)
				for (int j = i + 1; j < counter; j++)
					if (People[i].Weight == People[j].Weight && People[i].ShoesNumber == People[j].ShoesNumber) {
						if (!printed[i]) {
							p_Add(People[i]);
							cout << setw(10) << People[i].Surname << setw(20) << People[i].Weight << setw(20) << People[i].ShoesNumber << endl;
							printed[i] = true;
						}
						if (!printed[j]) {
							p_Add(People[j]);
							cout << setw(10) << People[j].Surname << setw(20) << People[j].Weight << setw(20) << People[j].ShoesNumber << endl;
							printed[j] = true;

						}
					}

		}

	}

}

void TrueNum(int& num) {
	do {
		cin >> num;
	} while (num <= 0 || num > 15);
}
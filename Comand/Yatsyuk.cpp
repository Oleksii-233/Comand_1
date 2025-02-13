#include "Yatsyuk.h"

void readfromfile(fstream& file) {

	PeopleInformation inf;

	file.open("PeopleInformation.dat", ios::in, ios::binary);

	if (!file.is_open()) {
		cout << "File isn`t open." << endl;
		exit(1);
	}

	p_Inic();

	p_Add("Reading the entire file to the screen.");

	Shapka();
	p_Add();
	while (file.read((char*)&inf, sizeof(inf))) {
		p_Add(inf);
		ShowPeople(inf);
	}

	file.close();
	p_Close();

}

void sortbysize(fstream& file) {
	PeopleInformation inf;
	int k = 0;
	file.open("PeopleInformation.dat", ios::in, ios::binary);

	if (!file.is_open()) {
		cout << "File isn`t open." << endl;
		exit(1);
	}
	p_Inic();
	p_Add("People with the right number of clothes and shoes.");

	cout << "Surnames of people whose clothing number is greater than 46 and shoe size is less than 41:\n";
	while (file.read((char*)&inf, sizeof(inf)))
	{
		if (inf.ClothesNumber > 46 && inf.ShoesNumber < 41) {
			cout << inf.Number << "\t" << inf.Surname << endl;
			k++;
		}
	}


	if (k == 0) {
		cout << "Missing..." << endl;
		p_Add("There are no such people.");
	}
	else {
		file.clear(); file.seekg(0);
		p_Add();
		while (file.read((char*)&inf, sizeof(inf)))
			if (inf.ClothesNumber > 46 && inf.ShoesNumber < 41) 
				p_Add(inf);
	}

	file.close();
	p_Close();

}

double avweight(fstream& file) {
	PeopleInformation inf;

	file.clear();
	file.seekg(0);

	double avweight = 0.;
	int count = 0;
	while (file.read((char*)&inf, sizeof inf))
	{
		avweight += inf.Weight;
		count++;
	}

	if (count == 0) {
		cout << "There are no entries in the file to calculate the average weight." << endl;
		return 0.;
	}
	else
		return avweight / count;
}

double avheight(fstream& file) {
	PeopleInformation inf;

	file.clear();
	file.seekg(0);

	double avheight = 0;
	int count = 0;
	while (file.read((char*)&inf, sizeof inf))
	{
		avheight += inf.Height;
		count++;
	}

	if (count == 0) {
		cout << "There are no entries in the file to calculate the average height." << endl;
		return 0.;
	}
	else
		return avheight / count;
}

void sortaverage(fstream& file) {
	PeopleInformation inf;
	file.open("PeopleInformation.dat", ios::in, ios::binary);

	if (!file.is_open()) {
		cout << "File isn`t open." << endl;
		exit(1);
	}

	p_Inic();

	double avhe = avheight(file);
	double avwe = avweight(file);

	file.clear();
	file.seekg(0);

	int k = 0;
	p_Add("People with months of average height and weight.");
	cout << "People with a difference of ±10% from the average height and weight ±5%: \n";
	Shapka();
	while (file.read((char*)&inf, sizeof inf))
		if (inf.Height < avhe * 1.1 && inf.Height>avhe * 0.9 && inf.Weight < avwe * 1.05 && inf.Weight > avwe * 0.95) {
			ShowPeople(inf);
			k++;
		}

	if (k == 0) {
		p_Add("There are no such people.");
		cout << "Missing." << endl;
	}
	else {
		file.clear(); file.seekg(0);
		p_Add();
		while (file.read((char*)&inf, sizeof inf))
			if (inf.Height < avhe * 1.1 && inf.Height>avhe * 0.9 && inf.Weight < avwe * 1.05 && inf.Weight > avwe * 0.95)
				p_Add(inf);
	}

	file.close();
	p_Close();

}
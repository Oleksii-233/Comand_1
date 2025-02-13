#include "Nikitiuk.h"

void addtofile() {

	PeopleInformation inf;
	ifstream f1(bname, ios::binary);
	ofstream f2("PeopleInformation1.dat", ios::binary);

	if (!f1.is_open() || !f2.is_open()) {
		char e[] = "File isn`t open.";
		cout << e << endl;
		exit(1);
	}

	p_Add();

	while (f1.read((char*)&inf, sizeof inf))
		f2.write((char*)&inf, sizeof inf);

	int num;
	cout << "Enter count of people: "; TrueNum(num); cin.get();
	for (int i = 0; i <= num - 1; i++)
	{
		EnterPeople(inf);
		p_Add(inf);
		f2.write((char*)&inf, sizeof inf);
	}

	f1.close();
	f2.close();

	remove(bname);
	rename("PeopleInformation1.dat", bname);

}

void My_Swap(PeopleInformation& p0, PeopleInformation& p1) {
	PeopleInformation t;
	t = p0;
	p0 = p1;
	p1 = t;
}

void My_Sort() {
	PeopleInformation peo, p[15];
	int len = 0;

	fstream file(bname, ios::in | ios::binary);

	if (!file.is_open()) {
		char e[] = "File isn`t open.";
		cout << e << endl;
		exit(1);
	} 

	while (file.read((char*)&peo, sizeof(peo)))
		p[len++] = peo; 

	file.close();

	int variant;
	char m[] = "Choose variant of sorting 0 - surname , another number - name. ";
	p_Add(m);
	cout << m << endl;
	cin >> variant;
	p_Add(to_string(variant));

	if (!variant) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++)
				if (strcmp(p[i].Surname, p[j].Surname) > 0)
					My_Swap(p[i], p[j]);
		}
	} 
	else {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++)
				if (strcmp(p[i].Name, p[j].Name) > 0)
					My_Swap(p[i], p[j]);
		}
	}

	p_Add("Append information from file.");
	p_Add();
	for (int i = 0; i < len; i++)
		p_Add(p[i]);

	fstream fbuf("bufer.dat", ios::out | ios::binary);
	if (!fbuf.is_open()) {
		char e[] = "File isn`t open.";
		cout << e << endl;
		exit(1);
	}
	fbuf.write((char*)&p, sizeof(p[0]) * len);
	fbuf.close();

	remove(bname);
	rename("bufer.dat", bname);

}

double My_Min(PeopleInformation* p, int len) {
	if (len == 0)
		exit(1);

	double min = p[0].ClothesNumber;

	for (int i = 1; i < len; i++)
		if (min > p[i].ClothesNumber)
			min = p[i].ClothesNumber;

	return min;
}

double My_Max(PeopleInformation* p, int len) {
	if (len == 0)
		exit(1);
	double max = p[0].ShoesNumber;

	for (int i = 1; i < len; i++)
		if (max < p[i].ShoesNumber)
			max = p[i].ShoesNumber;

	return max;
}

double Min_Height(PeopleInformation* p, int len) {
	if (len == 0)
		exit(1);

	double min = p[0].Height;
	for (int i = 0; i < len; i++) 
		if (min > p[i].Height)
			min = p[i].Height;
	
}

double Max_Weight(PeopleInformation* p, int len) {
	if (len == 0)
		exit(1);

	double max = p[0].Height;
	for (int i = 0; i < len; i++)
		if (max < p[i].Height)
			max = p[i].Height;
}

void ShowArr(PeopleInformation* p, int len) {
	Shapka();
	for (int i = 0; i < len; i++)
		ShowPeople(p[i]);
}

void ShowSmall() {
	PeopleInformation p[15], peo, pmin[15], pmax[15], p0[15], p1[15];
	double max, min;
	int len = 0, a = 0, b = 0;
	fstream file(bname, ios::in | ios::binary);

	if (!file.is_open()) {
		cout << "File isn`t open." << endl;
		exit(1);
	}

	while (file.read((char*)&peo, sizeof(peo)))
		p[len++] = peo;

	file.close();

	min = My_Min(p, len);
	max = My_Max(p, len);

	for (int i = 0; i < len; i++) {
		if (p[i].ClothesNumber == min)
			pmin[a++] = p[i];
		else if (p[i].ShoesNumber == max)
			pmax[b++] = p[i];
	}

	min = Min_Height(pmin, a);
	max = Max_Weight(pmax, b);
	
	p_Add("People with smallest clothes number and height");
	cout << "People with smallest clothes number and height: " << endl;
	Shapka();
	p_Add();
	for (int i = 0; i < a; i++) 
		if (pmin[i].Height == min) {
			ShowPeople(pmin[i]);
			p_Add(pmin[i]);
		}
	
	p_Add("Smallest shoes number and weight");
	cout << "People with biggest shoes number and weight: " << endl; 
	Shapka();
	p_Add();
	for (int i = 0; i < b; i++)
		if (pmax[i].Height == max) {
			ShowPeople(pmax[i]);
			p_Add(pmax[i]);
		}

}
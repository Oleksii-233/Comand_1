#include "Windows.h"

#include "Dar`ev.h"
#include "Nikitiuk.h"
#include "Yatsyuk.h"
#include "Protocol.h"

using namespace std;

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	fstream file;
	int ans;

	do {
		protocol.open(name, ios::out | ios::app);

		string text0 = "Choose what you want to do:\n0 - Create and write a file,\n1 - Read the file to the screen,\n2 - Show records of a specific gender,\n3 - Have the same weight and shoe number";
		string text1 = "4 - The clothing number is larger than 46 and the shoe size is smaller than 41,\n5 - People who are close to the average for weight and size";
		string text2 = "6 - People with the smallest shoe size and clothing number and people with the largest weight and shoe number,\n7 - Sort the file by last name or first name,\n8 - Add file";
		string text3 = "Enter another number to exit";
		
		p_Add(text0); p_Add(text1); p_Add(text2); p_Add(text3);

		cout << text0 << endl << text1 << endl <<text2 << endl << text3 << endl;

		cin >> ans;
		p_Add(to_string(ans));

		switch (ans) {
		case 0: {
			WriteInFile(file);
		}break;
		case 1: {
			readfromfile(file);
		}break;
		case 2: {
			ShowSex(file);
		}break;
		case 3: {
			IndenticalHeightAndShoes(file);
		}break;
		case 4: {
			sortbysize(file);
		}break;
		case 5: {
			sortaverage(file);
		}break;
		case 6: {
			ShowSmall();
		}break;
		case 7: {
			My_Sort();
		}break;
		case 8: {
			addtofile();
		}break;
		}

		protocol.close();

		if (ans == 111)
			p_Read();

		system("pause");

	} while (ans >= 0 && ans <= 8 || ans == 111);


}


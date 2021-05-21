#include<iostream>
#include<vector>
#include<string>
#include"part1.h"
#include<ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;
/*
void Linearfunc()
{
	srand(time(NULL));
	int age = 0;
	int hash;

	cout << "1. Ascii\n0. DJB2" << endl;
	cin >> hash;

	system("cls");
	
	Linear ltable(hash);

	for (int i = 0; i < 100; i++)
	{
		int randn = rand() % (1000 - 100) + 100;
		string name = to_string(randn);
		ltable.Add(name, age);
		age = i;
	}

	ltable.print();
	cout << "Size: " << ltable.getSize();
}*/

void Hopscotchfunc()
{
	srand(time(NULL));
	int age = 0;
	int hash;

	cout << "1. Ascii\n0. DJB2" << endl;
	cin >> hash;

	system("cls");

	Hopscotch htable(hash);

	for (int i = 0; i < 100; i++)
	{
		string extra = std::to_string(rand());
		string name = std::to_string(rand()) + extra;
		//int randn = rand() % (1000 - 100) + 100;
		//string name = to_string(randn);
		htable.Add(name, age);
		age = i;
	}

	htable.print();
	cout << "Size: " << htable.getSize();
}

int main()
{
	while (true)
	{
		int choice;

		cout << "1. Linear\n2. Hopscotch" << endl;
		cin >> choice;

		system("cls");

		if (choice == 1)
		{
			//Linearfunc();
		}
		else if (choice == 2)
		{
			Hopscotchfunc();
		}
	}
	
}
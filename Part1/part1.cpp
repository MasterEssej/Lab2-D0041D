#include<iostream>
#include<vector>
#include<string>
#include"part1.h"
#include<ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;

int main()
{
	srand(time(NULL));
	Linear ltable;
	int age = 0;
	
	for (int i = 0; i < 100; i++)
	{
		int randn = rand() % (1000 - 100) + 100;
		string name = to_string(randn);
		ltable.Add(name, age);
		age = i;
	}

	//cout << ltable.nextp(11);
	ltable.print();
	cout << "Size: " << ltable.getSize();
	/*
	ltable.Add("Mia", 80);
	ltable.Add("Tim", 80);
	ltable.Add("Bea", 80);*/
}
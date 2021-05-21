#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;
#include"part2.h"

int main()
{
	vector<int> x;
	srand(time(0));
	int size = rand() % (100) + 4;

	for (int i = 0; i <= size; i++)
	{
		int random = rand() % (1000 - 100) + 100;
		cout << random << "\n";
		x.push_back(random);
	}
	/*
	for (int i = size; i >= 0; i--)
	{
		x.push_back(i);
	}*/

	int n = Smallest(x, 3);
	cout << "\n\n4th smallest number: " << n << endl;
	cout << "comparisons = " << compare;

}
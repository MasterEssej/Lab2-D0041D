#pragma once
#include<string>
#include<vector>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;

int compare = 0;

int Smallest(vector<int> x, int look)
{
	if (x.size() <= 5)
	{
		for (int i = 0; i < x.size() - 1; i++)
		{
			if (x[i] > x[i + 1])
			{
				int temp = x[i];
				x[i] = x[i + 1];
				x[i + 1] = temp;
				i = -1;
				compare++;
			}
		}
		return(x[look]);
	}

	int div = x.size() / 5;

	int ele = 0;
	int mMedian = 0;
	vector<int> medians;

	for (int i = 0; i <= div - 1; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			if (x[k + ele] > x[k + ele + 1])
			{
				int temp = x[k + ele];
				x[k + ele] = x[k + ele + 1];
				x[k + ele + 1] = temp;
				k = -1;
				compare++;
			}
		}
		medians.push_back(x[2 + ele]);
		ele += 5;
	}

	int checkZero = medians.size();
	int h = 0;
	if (checkZero % 2 == 0)
	{
		int h = medians.size() / 2 + (medians.size() - 1) / 2;
	}
	else
	{
		int h = medians.size() / 2;
	}

	mMedian = medians[h];

	vector<int> left;
	vector<int> right;

	left.push_back(mMedian);

	for (int i = 0; i <= x.size() - 1; i++)
	{
		if (x[i] < mMedian)
		{
			left.push_back(x[i]);
		}
		else
		{
			right.push_back(x[i]);
		}
	}

	int lCap = left.size();

	if (lCap == look)
	{
		compare++;
		return mMedian;
	}
	else if (lCap >= 4)
	{
		compare++;
		return Smallest(left, 3);
	}
	else
	{
		compare++;
		return Smallest(right, 3 - lCap);
	}

}
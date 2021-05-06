#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Element
{
private:
	string name;
	int age;
public:
	Element(string n, int a)
	{
		name = n;
		age = a;
	}

	string getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	void setName(string n)
	{
		name = n;
	}

	void setAge(int a)
	{
		age = a;
	}
};

/*
class Linear
{
private:
	vector<Element*> dict;
	int cap = dict.capacity();
	int size = 0;
	int collisions;
public:
	Linear()
	{
		dict.resize(11);
		cap = dict.capacity();
		size;
		collisions = 0;
		for (int i = 0; i < cap; i++)
		{
			dict[i] = nullptr;
		}
	}

	int getSize()
	{
		return dict.capacity();
	}

	void Add(string n, int a)
	{
		if ((float)(size) / (float)(cap) >= 0.6)
		{
			reHash(n);
		}
		int namenum = 0;
		for (int i = 0; i < n.size(); i++)
		{
			namenum += int(n[i]);
		}
		int index = namenum % cap;

		if (dict[index] == nullptr)
		{
			Element* temp = new Element(n, a);
			dict[index] = temp;
			size++;
		}
		else
		{
			bool space = false;
			for (int i = index + 1; i < cap; i++)
			{
				if (dict[i] == nullptr)
				{
					Element* temp = new Element(n, a);
					dict[i] = temp;
					size++;
					space = true;
					break;
				}
				collisions++;
			}
			if (!space)
			{
				for (int i = 0; i < index; i++)
				{
					if (dict[i] == nullptr)
					{
						Element* temp = new Element(n, a);
						dict[i] = temp;
						size++;
						space = true;
						break;
					}
					collisions++;

				}
			}
		}
	}

	void print()
	{
		for (int i = 0; i < dict.capacity(); i++)
		{
			if (dict[i] != nullptr)
			{
				cout << dict[i]->getName() << " " << i << endl;
			}
		}
		cout << "Collisions: " << collisions << endl;
	}

	int nextp(int current)
	{
		current += current;
		bool prime = false;
		while (true)
		{
			for (int i = 2; i < current; i++)
			{
				if (current % i == 0)
				{
					break;
				}
				if (i == current - 1)
				{
					prime = true;
				}
				
			}
			if (prime)
			{
				return current;
			}
			current++;
		}
	}

	void reHash(string n)
	{
		vector<Element*> temp;
		for (int i = 0; i < cap; i++)
		{
			if (dict[i] != nullptr)
			{
				temp.push_back(dict[i]);
				dict[i] = nullptr;
			}
		}

		dict.resize(nextp(dict.capacity()));
		cap = dict.capacity();

		for (int i = 0; i < temp.size(); i++)
		{
			string name = temp[i]->getName();
			int age = temp[i]->getAge();

			int index = ascii(n);

			if (dict[index] == nullptr)
			{
				dict[index] = temp[i];
			}
			else
			{
				for (int k = index + 1; k < cap; k++)
				{
					if (dict[k] == nullptr)
					{
						dict[k] = temp[i];
						break;
					}
				}
			}
		}
	}

	int ascii(string n)
	{
		int temp = 0;
		for (int i = 0; i < n.size(); i++)
		{
			temp = temp + int(n[i]);
		}
		int index = (temp) % cap;
		return index;
	}
};
*/

class Bitmap
{
private:
	vector<bool> bitar;
public:
	Bitmap()
	{
		for (int i = 0; i < 4; i++)
		{
			bitar.push_back(0);
		}
	}

	void setBit(bool b, int i)
	{
		bitar[i] = b;
	}

	bool getBit(int i)
	{
		return bitar[i];
	}

	int getFirstTrue()
	{
		for (int i = 0; i < 4; i++)
		{
			if (bitar[i])
			{
				return i;
			}
		}
		return -1;
	}
};

class Node
{
private:
	Element* lmnt;
	Bitmap bmap;
public:
	Node()
	{
		lmnt = nullptr;
	}

	Element getElement()
	{
		return *lmnt;
	}
	
	Bitmap getBmap()
	{
		return bmap;
	}

	void setElement(Element* e)
	{
		*lmnt = *e;
	}

	void setBmap(Bitmap b)
	{
		bmap = b;
	}
};

class Hopscotch
{
private:
	vector<Node*> dict;
	Element* lmnt;
	Bitmap* bmap;
	int cap = dict.capacity();
	int size;
	int collision;
	int collisionChain;
	int h;
	bool ascii;
public:
	Hopscotch(int enc)
	{
		dict.resize(11);
		h = 4;
		size = 0;
		collision = 0;
		collisionChain = 0;
		cap = dict.capacity();
		ascii = enc;
		for (int i = 0; i < cap; i++)
		{
			Node* temp = new Node();
			dict[i] = temp;
		}
	}

	void update(Bitmap *bit, bool b, int p)
};
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
	int homeNode;
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

	int getHomeNode()
	{
		return homeNode;
	}

	void setHomeNode(int i)
	{
		homeNode = i;
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
	int collisionChain;
	bool ascii;
public:
	Linear(int h)
	{
		dict.resize(11);
		cap = dict.capacity();
		size;
		collisions = 0;
		collisionChain = 0;
		ascii = h;
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
		int chain = 0;
		int index = 0;
		if ((float)(size) / (float)(cap) >= 0.6)
		{
			reHash(n);
		}

		if (ascii)
		{
			index = asciiH(n);
		}
		else
		{
			index = djb2H(n);
		}

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
				chain++;
				if (chain > collisionChain)
				{
					collisionChain = chain;
				}
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
					chain++;
					if (chain > collisionChain)
					{
						collisionChain = chain;
					}
				}
			}
		}
	}

	int asciiH(string n)
	{
		int namenum = 0;
		for (int i = 0; i < n.size(); i++)
		{
			namenum += int(n[i]);
		}
		int index = namenum % cap;
		return index;
	}

	int djb2H(string n)
	{
		unsigned long hash = 5381;
		for (auto c : n)
		{
			hash = (hash << 5) + hash + c;
		}
		hash = hash % cap;
		return hash;
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
		cout << "Biggest collision chain: " << collisionChain << endl;
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

			int index = asciiH(n);

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
};*/


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
		bitar[i] = b; //out of range
	}

	bool getBit(int i)
	{
		return bitar[i];
	}

	int getTrue(int x)
	{
		for (int i = 0; i < x; i++)
		{
			if (bitar[i])
			{
				return i;
			}
		}
		return -1;
	}

	bool getAllTrue()
	{
		for (int i = 0; i < 4; i++)
		{
			if (bitar[i] == false)
			{
				return false;
			}
		}
		return true;
	}
};

class Node
{
private:
	Element* lmnt;
	Bitmap* bmap;
public:
	Node()
	{
		lmnt = nullptr;
		bmap = new Bitmap();
	}

	Element* getElement()
	{
		return lmnt;
	}
	
	Bitmap* getBmap()
	{
		return bmap;
	}

	void setElement(Element* e)
	{
		lmnt = e;
	}

	void setBmap(Bitmap* b)
	{
		bmap = b;
	}
};

class Hopscotch
{
private:
	vector<Node*> dict;
	int cap = dict.capacity();
	int size;
	int collisions;
	int collisionChain;
	int bmi;
	bool ascii;
public:
	Hopscotch(int h)
	{
		dict.resize(11);
		bmi = 4;
		size = 0;
		collisions = 0;
		collisionChain = 0;
		cap = dict.capacity();
		ascii = h;
		for (int i = 0; i < cap; i++)
		{
			Node* temp = new Node();
			dict[i] = temp;
		}
	}

	int getSize()
	{
		return size;
	}

	int getColl()
	{
		return collisions;
	}

	int getChain()
	{
		return collisionChain;
	}

	void update(Bitmap* bit, bool b, int p)
	{
		bit->setBit(b, p);
	}

	void Add(string n, int a)
	{
		Element* temp = new Element(n, a);
		int chain = 0;
		int index = 0;

		if ((float)(size) / (float)(cap) >= 0.6)
		{
			reHash(n, a);
		}

		if (ascii)
		{
			index = asciiH(n);
		}
		else
		{
			index = djb2H(n);
		}

		//cout << index << endl;

		if (dict[index]->getElement() == nullptr)
		{
			dict[index]->setElement(temp);
			temp->setHomeNode(index);
			dict[index]->getBmap()->setBit(1, chain);
			size++;
		}
		else
		{
			bool space = false;
			temp->setHomeNode(index);
			int tempindex;
			int temp2 = 0;

			for (int i = 0; i < bmi; i++)
			{
				if (index + i >= cap)
				{
					index = outOfBounds(index + i);
				}
				tempindex = index + i;
				/*if (tempindex >= cap)
				{
					tempindex = temp2;
					temp2++;
				}*/
				if (dict[tempindex]->getElement() == nullptr)
				{
					dict[tempindex]->setElement(temp);
					dict[index]->getBmap()->setBit(1, chain);
					size++;
					space = true;
					break;
				}
				collisions++;
				chain++;
				if (chain > collisionChain)
				{
					collisionChain = chain;
				}
			}
			if (!space)
			{
				int empty = findEmpty(index);
				Element* movable = nullptr;
				int dist = -1;

				int index2 = 0;

				for (int i = 3; i > 0; i--)
				{
					if (index - i < 0)
					{
						index2 = (cap)+(index - i);
					}
					else
					{
						index2 = index - i;
					}
					if (dict[index2] != nullptr)
					{
						dist = dict[index2]->getBmap()->getTrue(3 - i);
					}
					if (dist != -1)
					{
						movable = dict[index2]->getElement();
						dict[index2]->setElement(nullptr);
						dict[movable->getHomeNode()]->getBmap()->setBit(false, dist);
						break;
					}
				}

				if (dist == -1)
				{
					dict[empty]->setElement(temp);
					reHash(n, a);
				}
				else
				{
					int count = 0;
					for (int i = 0; i < 3; i++)
					{
						if (dict[index + i]->getElement() == temp)
						{
							break;
						}

						count += 1;
					}
					dict[index]->getBmap()->setBit(true, (count));
					Add(movable);
					Add(temp);
				}
			}

			/*
			if (!space)
			{
				int tempi;
				int tempi2 = cap - 1;

				int empty = findEmpty(index);
				Element* movable = nullptr;
				int dist = -1;

				for (int i = 3; i > 0; i--)
				{
					tempi = index - i;
					if (tempi < 0)
					{
						tempi = tempi2;
						tempi--;
					}

					if (dict[tempi] != nullptr)
					{
						dist = dict[tempi]->getBmap()->getTrue(3 - i);
					}

					if (dist != -1)
					{
						movable = dict[empty - i]->getElement();
						dict[empty - i]->setElement(nullptr);
						dict[movable->getHomeNode()]->getBmap()->setBit(0, empty - i);
						break;
					}

				}

				if (dist == -1)
				{
					dict[empty]->setElement(temp);
					//reHash();
				}
				else
				{
					int count = 0;
					for (int i = 0; i < 4; i++)
					{
						if (dict[temp->getHomeNode() + i]->getElement() == temp)
						{
							break;
						}
						count++;
					}
					dict[temp->getHomeNode()]->getBmap()->setBit(1, count);
					dict[empty]->setElement(movable);
					dict[index]->setElement(temp);
				}

			}*/
			
			/*
			if (!space)
			{
				for (int i = 0; i < bmi; i++)
				{
					tempindex = index + i;
					if (tempindex >= cap)
					{
						tempindex = temp2;
						temp2++;
					}
					if (dict[index]->getBmap().getBit(i) == true)
					{
						if (dict[tempindex]->getElement() == nullptr)
						{
							dict[tempindex]->setElement(temp);
							dict[index]->getBmap().setBit(1, chain);
							size++;
							break;
						}
						else
						{
							Add(dict[tempindex]->getElement()->getName(), dict[tempindex]->getElement()->getAge());
							Add(n, a);
						}
					}
				}
			}*/
		}
	}

	int outOfBounds(int i)
	{
		int reset = 0;
		reset = i - cap;
		return reset;
	}

	int nextPrime(int currentPrime) {
		currentPrime += currentPrime;
		bool isPrime = false;
		while (true) {
			for (int i = 2; i < currentPrime; i++) {
				if (currentPrime % i == 0)
					break;
				if (i == currentPrime - 1)
					isPrime = true;
			}
			if (isPrime == true)
				return currentPrime;
			currentPrime++;
		}
	}

	void reHash(string b, int a)
	{
		vector<Node*> tempArr;

		for (int i = 0; i < cap; i++)
		{
			if (dict[i]->getElement() != nullptr)
			{
				tempArr.push_back(dict[i]);
				dict[i] = nullptr;
			}
		}

		size = 0;
		dict.resize(nextPrime(dict.capacity()));
		cap = dict.capacity();

		for (int i = 0; i < cap; i++)
		{
			Node* tempo = new Node();
			dict[i] = tempo;
		}

		cout << "Rehash: " << dict.capacity() << endl;

		for (int i = 0; i < tempArr.size(); i++)
		{
			Add(tempArr[i]->getElement());
		}

	}

	Node* Add(Element* BRO)
	{
		int chain = 0;
		int index;
		if ((float(size) / float(cap)) >= float(0.6))
		{
			reHash(BRO->getName(), BRO->getAge());
		}
		if (ascii)
		{
			index = asciiH(BRO->getName());
		}
		else
		{
			index = asciiH(BRO->getName());
		}

		bool space = false;
		if (dict[index]->getElement() == nullptr)
		{
			dict[index]->setElement(BRO);
			BRO->setHomeNode(index);
			dict[index]->getBmap()->setBit(1, chain);
			size++;
		}
		else
		{
			BRO->setHomeNode(index);
			int tempindex;
			int temp2 = 0;

			for (int i = 0; i < bmi; i++)
			{
				tempindex = index + i;
				if (tempindex >= cap)
				{
					tempindex = temp2;
					temp2++;
				}

				if (dict[tempindex]->getElement() == nullptr)
				{
					dict[tempindex]->setElement(BRO);
					dict[index]->getBmap()->setBit(1, chain);
					size++;
					space = true;
					break;
				}
				collisions++;
				chain++;
				if (chain > collisionChain)
				{
					collisionChain = chain;
				}
			}

			if (!space)
			{
				if (dict[index]->getBmap()->getAllTrue() == true)
				{
					reHash(BRO->getName(), BRO->getAge());
				}
				for (int i = 0; i < bmi; i++)
				{
					if (index + i >= cap)
					{
						index = outOfBounds(index + i);
					}
					tempindex = index + i;
					/*if (tempindex >= cap)
					{
						tempindex = temp2;
						temp2++;
					}*/

					if (dict[index]->getBmap()->getBit(i) == true)
					{
						if (dict[tempindex] == nullptr)
						{
							dict[tempindex]->setElement(BRO);
							dict[index]->getBmap()->setBit(1, chain);
							size++;
							break;
						}
						else
						{
							Add(dict[tempindex]->getElement()->getName(), dict[tempindex]->getElement()->getAge());
							Add(BRO->getName(), BRO->getAge());
						}
					}
				}
			}
		}
		return dict[index];
	}

	int asciiH(string n)
	{
		int namenum = 0;
		for (int i = 0; i < n.size(); i++)
		{
			namenum += int(n[i]);
		}
		int index = namenum % cap;
		return index;
	}

	int djb2H(string n)
	{
		unsigned long hash = 5381;
		for (auto c : n)
		{
			hash = (hash << 5) + hash + c;
		}
		hash = hash % cap;
		return hash;
	}

	void print()
	{
		for (int i = 0; i < dict.capacity(); i++)
		{
			if (dict[i]->getElement() != nullptr)
			{
				cout << dict[i]->getElement() << " " << dict[i]->getElement()->getAge() << " " << i << endl;
			}
		}
	}

	int findEmpty(int x)
	{
		int i = x;
		while (dict[i]->getElement() != nullptr)
		{
			i++;
			if (i >= cap)
			{
				i = 0;
			}
		}
		return i;
	}
};
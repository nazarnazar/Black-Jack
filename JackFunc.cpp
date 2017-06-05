#include "JackHead.h"


///////////CARDS////////////////

Cards::Cards()
{
	for (int i=0; i<CARDS_NUM; i++)
	{
		if (i >= 0 && i <= 3)
			Arr[i] = 2;
		else if (i >= 4 && i <= 7)
			Arr[i] = 3;
		else if (i >= 8 && i <= 11)
			Arr[i] = 4;
		else if (i >= 12 && i <= 15)
			Arr[i] = 5;
		else if (i >= 16 && i <= 19)
			Arr[i] = 6;
		else if (i >= 20 && i <= 23)
			Arr[i] = 7;
		else if (i >= 24 && i <= 27)
			Arr[i] = 8;
		else if (i >= 28 && i <= 31)
			Arr[i] = 9;
		else if (i >= 32 && i <= 35)
			Arr[i] = 10;
		else if (i >= 36 && i <= 39)
			Arr[i] = J;
		else if (i >= 40 && i <= 43)
			Arr[i] = Q;
		else if (i >= 44 && i <= 47)
			Arr[i] = K;
		else Arr[i] = A;
	}
	for (int i=0; i<CARDS_NUM; i++)
		IsIn[i] = false;
	CardInd = 0;
}

int Cards::Give()
{
	for (int i = 0; i<CARDS_NUM; i++)
	{
		CardInd = rand() % 52;
		if (IsIn[CardInd] == false)
		{
			IsIn[CardInd] = true;
			break;
		}
	}
	if (Arr[CardInd] == J)
		cout << "J";
	else if (Arr[CardInd] == Q)
		cout << "Q";
	else if (Arr[CardInd] == K)
		cout << "K";
	else if (Arr[CardInd] == A)
		cout << "A";
	else cout << Arr[CardInd]; 
	CardType = (CardInd + 4) % 4;
	if (CardType == 0)
		cout << (char)3 << ". ";
	else if (CardType == 1)
		cout << char(6) << ". ";
	else if (CardType == 2)
		cout << char(4) << ". ";
	else cout << char(5) << ". ";
	return Arr[CardInd];
}

//////////////////PLAYER/////////////////////////

void Player::Init(int one, int two, string n)
{
	Name = n;
	cout << "- " << Name << endl;
	cards.push_back(one);
	cards.push_back(two);
}

void Player::AddCard(int add)
{
	cards.push_back(add);
	cout << "- " << Name << endl;
}

bool Player::Decide()
{
	cout << "Do you want to add another card? (y/n)\n";
	char ch;
	cin >> ch;
	while (ch != 'Y' && ch != 'y' && ch != 'n' && ch != 'N')
	{
		cout << "(y/n): ";
		cin >> ch;
	}
	if (ch == 'y' || ch == 'Y')
		return true;
	else return false;
}

int Player::Sum()
{
	int sum = 0;
	for (vector<int>::iterator iter = cards.begin(); iter != cards.end(); iter++)
	{
		if (*iter == J || *iter == Q || *iter == K)
			sum += 10;
		else if (*iter == A)
			if (sum + 11 > 21)
				sum += 1;
			else sum += 11;
		else sum += *iter;
	}
	return sum;
}

string Player::NameR()
{
	return Name;
}

/////////////////PC////////////////////

Pc::Pc(int o, int t, string n)
{
	Init(o, t, n);
}

bool Pc::Decide()
{
	if (this->Sum() <= 16)
		return true;
	else return false;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>


using namespace std;

enum {J = 11, Q, K, A};

class Cards
{
	static const int CARDS_NUM  = 52;
	int CardInd;
	char CardType;
	int Arr[CARDS_NUM];
	bool IsIn[CARDS_NUM];
public:
	Cards();
	int Give();
};

class Player
{
	string Name;
	vector<int> cards;
public:
	Player() {}
	void Init(int one, int two, string n = "player");
	void AddCard(int add);
	bool virtual Decide();
	int Sum();
	string NameR();
};

class Pc : public Player
{
public:
	Pc(int o, int t, string n = "PC");
	bool virtual Decide();
};
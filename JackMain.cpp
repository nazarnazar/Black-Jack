#include "JackHead.h"


int main()
{
	srand(time(NULL));
	cout << "\tWelcome to my Black Jack The Game!\n\n"; 
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		Cards C;
		cout << "Enter please the num of players (1 - 7): ";
		int pN = 0;
		cin >> pN;
		while (pN < 1 || pN > 7)
		{
			cout << "(1 - 7): ";
			cin >> pN;
		}
		Player *p = new Player[pN];
		string Name;
		bool decide = true;
		for (int i = 0; i < pN; i++)
		{
			cout << "\nPlayer" << i+1 << ", enter your nickName: ";
			cin >> Name;
			p[i].Init(C.Give(), C.Give(), Name);
			cout << "Sum = " << p[i].Sum() << endl;
			decide = true;
			while (decide)
			{
				if (p[i].Decide())
				{
					p[i].AddCard(C.Give());
					cout << "Sum = " << p[i].Sum() << endl;
				}
				else decide = false;
			}
			cout << "Sum = " << p[i].Sum() << endl;
			cout << "-------------------------\n";
		}
		cout << endl;
		Pc pc(C.Give(), C.Give());
		while (pc.Decide())
			pc.AddCard(C.Give());
		cout << "Sum = " << pc.Sum() << endl;
		int *arr = new int[pN+1];
		for (int i = 0; i<pN; i++)
		{
			arr[i] = p[i].Sum();
		}
		arr[pN] = pc.Sum();
		int Max = arr[0];
		int MaxInd = 0;
		bool win = true;
		bool win2 = false;
		if (Max > 21)
			for (int i = 1; i < pN+1; i++)
			{
				if (arr[i] <= 21)
				{
					Max = arr[i];
					MaxInd = i;
					win2 = true;
					break;
				}
			}
		else win2 = true;
		if (win2 == true)
		{
			for (int i = 1; i < pN+1; i++)
			{
				if (Max < arr[i] && arr[i] <= 21)
				{
					MaxInd = i;
					Max = arr[i];
					win = true;
				}
				else if (Max == arr[i] && i != MaxInd)
					win = false;
			}
		}
		if (win2 == true)
		{
			if (win)
				if (MaxInd == pN)
					cout << "\nWinner: PC!\n";
				else cout << "\nWinner: " << p[MaxInd].NameR() << '!' << endl;
			else cout << "\nNo winner\n";
		}
		else cout << "\nNo winner\n";
		cout << "\nAgain? (y/n)\n";
		cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
		{
			cout << "(y/n): ";
			cin >> ch;
		}
		delete []p;
	}

	return 0;
}
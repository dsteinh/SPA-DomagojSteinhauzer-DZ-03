#include "NajbrziPut.h"
#include <iostream>
#include<windows.h>
#include<string>
using namespace std;
NajbrziPut::NajbrziPut()
{
	int key = 0;
	for (unsigned i = 0; i < redci; i++)
	{
		for (unsigned j = 0; j < stupci; j++)
		{
			pocetna[i][j].first = key;
			key++;
		}
	}
}

void NajbrziPut::set_red_A(int red_A)
{
	this->red_A = red_A;
	
}

void NajbrziPut::set_stup_A(int stup_A)
{
	this->stup_A = stup_A;
}

void NajbrziPut::set_red_B(int red_B)
{
	this->red_B = red_B;
}

void NajbrziPut::set_stup_B(int stup_B)
{
	this->stup_B = stup_B;
}



void NajbrziPut::set_pocetna()
{
	for (unsigned i = 1; i <= redci; i++)
	{
		for (unsigned j = 1; j <= stupci; j++)
		{
			if (i == red_A && j == stup_A)
			{
				
				pocetna[i-1][j-1].second = 'A';
			}
			else if (i == red_B && j == stup_B)
			{
				
				pocetna[i-1][j-1].second = 'B';

			}
			
			else
			{
				
				pocetna[i-1][j-1].second = '-';

			}

		}
		cout << endl;
	}
	print();
}

void NajbrziPut::set_slijedeca()
{
	if (stup_A <= stup_B)
	{
		//povecava se
		for (unsigned i = stup_A; i < stup_B; i++)
		{
			pocetna[red_A-1][i].second = 'x';
			print();
			pocetna[red_A - 1][i].second = '-';
			Sleep(200);
		}
	}
	else 
	{
		for (int i = stup_A-2; i >= stup_B-1; i--)
		{
			pocetna[red_A-1][i].second = 'x';
			print();
			pocetna[red_A - 1][i].second = '-';
			Sleep(200);
		}
	}
	if (red_A <= red_B)
	{
		//povecava se
		for (unsigned i = red_A; i < red_B; i++)
		{
			pocetna[i][ stup_B-1].second = 'x';
			print();
			pocetna[i][stup_B - 1].second = '-';
			Sleep(200);
		}

	}
	else 
	{
		for (int i = red_A-2; i >= red_B-1; i--)
		{
			pocetna[i][stup_B - 1].second = 'x';
			print();
			pocetna[i][stup_B - 1].second = '-';
			Sleep(200);
		}
	}
	
	
}

void NajbrziPut::print()
{
	cout << string(50, '\n');
	for (unsigned i = 0; i < redci; i++)
	{
		for (unsigned j = 0; j < stupci; j++)
		{
			if (pocetna[i][j].second == 'A')
			{
				cout << 'A';
			}
			else if (pocetna[i][j].second == 'B')
			{
				cout << 'B';
			}

			else if (pocetna[i][j].second == 'x')
			{
				cout << 'x';
			}
			
			else
			{
				cout << '-';
			}

		}
		cout << endl;
	}
}

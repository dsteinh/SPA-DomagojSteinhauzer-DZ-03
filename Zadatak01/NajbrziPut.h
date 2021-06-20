#pragma once
#include<vector>

using namespace std;
class NajbrziPut
{
private:
	int red_A, stup_A, red_B, stup_B;
	int redci = 20;
	int stupci = 40;
	pair<int, char> pocetna[20][40];
	int sljedeca[20][40];
	

public:
	NajbrziPut();
	void set_red_A(int red_A);
	void set_stup_A(int stup_A);
	void set_red_B(int red_B);
	void set_stup_B(int stup_B);
	int susjedi(int i, int j);



	void set_pocetna();
	void set_slijedeca();

	void print();

};


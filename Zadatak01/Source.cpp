#include<iostream>
#include<vector>
#include"NajbrziPut.h"
using namespace std;

int main() {
	NajbrziPut p;
	int temp;
	
	

	cout << "A stupac: ";
	cin >> temp;
	p.set_stup_A(temp);
	cout << "A redak: ";
	cin >> temp;
	p.set_red_A(temp);
	
	cout << "B stupac: ";
	cin >> temp;
	p.set_stup_B(temp);
	cout << "B redak: ";
	cin >> temp;
	p.set_red_B(temp);
	
	p.set_pocetna();
	


	p.set_slijedeca();
	return 0;
}
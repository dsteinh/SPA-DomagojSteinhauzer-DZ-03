#include<iostream>
#include<vector>
#include"NajbrziPut.h"
using namespace std;

int main() {
	NajbrziPut p;
	int temp;
	
	

	cout << "A os-y: ";
	cin >> temp;
	p.set_stup_A(temp);
	cout << "A os-x: ";
	cin >> temp;
	p.set_red_A(temp);
	
	cout << "B os-y: ";
	cin >> temp;
	p.set_stup_B(temp);
	cout << "B os-x: ";
	cin >> temp;
	p.set_red_B(temp);
	
	p.print();
	p.print_sljedeci();
	



	
	return 0;
}
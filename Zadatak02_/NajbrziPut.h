#pragma once
#include<vector>

using namespace std;
class NajbrziPut
{
private:
	int red_A, stup_A, red_B, stup_B;
	int redci = 21;
	int stupci = 41;
	
	struct sNode
	{
		bool bObstacle = false;			
		bool bVisited = false;
		bool isPath = false;
		float fGlobalGoal;				
		float fLocalGoal;				
		int x;							
		int y;
		vector<sNode*> vecNeighbours;	
		sNode* parent;					
	};

	sNode* nodes = nullptr;
	int nMapWidth = 21;
	int nMapHeight = 41;

	sNode* nodeStart = nullptr;
	sNode* nodeEnd = nullptr;

public:
	NajbrziPut();
	~NajbrziPut();
	void AStar();
	void set_red_A(int red_A);
	void set_stup_A(int stup_A);
	void set_red_B(int red_B);
	void set_stup_B(int stup_B);

	void set_slijedeca();

	void print();
	void print_sljedeci();

};


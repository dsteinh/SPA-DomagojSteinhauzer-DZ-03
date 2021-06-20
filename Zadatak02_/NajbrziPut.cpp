#include "NajbrziPut.h"
#include <iostream>
#include<windows.h>
#include<string>
#include<list>
#include<stack>
using namespace std;
NajbrziPut::NajbrziPut()
{
	nodes = new sNode[redci * stupci];
	for (int x = 0; x < redci; x++)
	{
		for (int y = 0; y < stupci; y++)
		{
			nodes[y * nMapWidth + x].x = x; 
			nodes[y * nMapWidth + x].y = y;
			nodes[y * nMapWidth + x].bObstacle = false;
			nodes[y * nMapWidth + x].parent = nullptr;
			nodes[y * nMapWidth + x].bVisited = false;
		}
	}

	for (int x = 0; x < nMapWidth; x++)
		for (int y = 0; y < nMapHeight; y++)
		{
			if (y > 0)
				nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y - 1) * nMapWidth + (x + 0)]);
			if (y < nMapHeight - 1)
				nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y + 1) * nMapWidth + (x + 0)]);
			if (x > 0)
				nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y + 0) * nMapWidth + (x - 1)]);
			if (x < nMapWidth - 1)
				nodes[y * nMapWidth + x].vecNeighbours.push_back(&nodes[(y + 0) * nMapWidth + (x + 1)]);
		}
		
	for (int x = 0; x < redci; x++)
		for (int y = 0; y < stupci; y++)
		{
			if (x < 15 && y == 20 )
				nodes[y * nMapWidth + x].bObstacle = true;
			
		}

}
	NajbrziPut::~NajbrziPut() {
	delete[] nodes;
}
	void NajbrziPut::AStar()
	{
		

		for (int x = 0; x < nMapWidth; x++)
			for (int y = 0; y < nMapHeight; y++)
			{
				nodes[y * nMapWidth + x].bVisited = false;
				nodes[y * nMapWidth + x].fGlobalGoal = INFINITY;
				nodes[y * nMapWidth + x].fLocalGoal = INFINITY;
				nodes[y * nMapWidth + x].parent = nullptr;	// No parents
			}

		auto distance = [](sNode* a, sNode* b) // For convenience
		{
			return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
		};

		auto heuristic = [distance](sNode* a, sNode* b) // So we can experiment with heuristic
		{
			return distance(a, b);
		};

		sNode* nodeCurrent = nodeStart;
		nodeStart->fLocalGoal = 0.0f;
		nodeStart->fGlobalGoal = heuristic(nodeStart, nodeEnd);


		list<sNode*> listNotTestedNodes;
		listNotTestedNodes.push_back(nodeStart);

		while (!listNotTestedNodes.empty() && nodeCurrent != nodeEnd)
		{
			
			listNotTestedNodes.sort([](const sNode* lhs, const sNode* rhs) { return lhs->fGlobalGoal < rhs->fGlobalGoal; });

			while (!listNotTestedNodes.empty() && listNotTestedNodes.front()->bVisited)
				listNotTestedNodes.pop_front();


			if (listNotTestedNodes.empty())
				break;

			nodeCurrent = listNotTestedNodes.front();
			nodeCurrent->bVisited = true; 


			for (auto nodeNeighbour : nodeCurrent->vecNeighbours)
			{
				
				if (!nodeNeighbour->bVisited && nodeNeighbour->bObstacle == 0)
					listNotTestedNodes.push_back(nodeNeighbour);

			
				float fPossiblyLowerGoal = nodeCurrent->fLocalGoal + distance(nodeCurrent, nodeNeighbour);

				
				if (fPossiblyLowerGoal < nodeNeighbour->fLocalGoal)
				{
					nodeNeighbour->parent = nodeCurrent;
					nodeNeighbour->fLocalGoal = fPossiblyLowerGoal;

					
					nodeNeighbour->fGlobalGoal = nodeNeighbour->fLocalGoal + heuristic(nodeNeighbour, nodeEnd);
				}
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




void NajbrziPut::print()
{
	nodeStart = &nodes[red_A * nMapWidth + stup_A];
	nodeEnd = &nodes[red_B * nMapWidth + stup_B];

	cout << string(50, '\n');
	for (unsigned x = 0; x < redci; x++)
	{
		for (unsigned y = 0; y < stupci; y++)
		{
			if (nodes[y * nMapWidth + x].x == nodeStart->x && nodes[y * nMapWidth + x].y == nodeStart->y)
			{
				cout << 'A';
			}
			else if (nodes[y * nMapWidth + x].x == nodeEnd->x && nodes[y * nMapWidth + x].y == nodeEnd->y)
			{
				cout << 'B';
			}
		

			else if (nodes[y * nMapWidth + x].bObstacle == true)
			{
				cout << '#';
			}
			else
			{
				cout << '-';
			}

		}
		cout << endl;
	}
}

void NajbrziPut::print_sljedeci()
{
	stack<sNode*> put;
	AStar();
	if (nodeEnd != nullptr)
	{
		sNode* p = nodeEnd;
		while (p->parent != nullptr)
		{
			
			put.push(p);
			
			p = p->parent;
		}
	}

	while (!put.empty())
	{
		put.top()->isPath = true;
		cout << string(50, '\n');
		for (unsigned x = 0; x < redci; x++)
		{
			for (unsigned y = 0; y < stupci; y++)
			{
				if (nodes[y * nMapWidth + x].x == nodeStart->x && nodes[y * nMapWidth + x].y == nodeStart->y)
				{
					cout << 'A';
				}
				else if (nodes[y * nMapWidth + x].x == nodeEnd->x && nodes[y * nMapWidth + x].y == nodeEnd->y)
				{
					cout << 'B';
				}
				else if (nodes[y * nMapWidth + x].isPath == true)
				{
					cout << 'x';
					nodes[y * nMapWidth + x].isPath = false;

				}

				else if (nodes[y * nMapWidth + x].bObstacle == true)
				{
					cout << '#';
				}
				else
				{
					cout << '-';
				}

			}
			cout << endl;
		}
		put.pop();
		Sleep(100);
	
	
	}


	cout << string(50, '\n');
	for (unsigned x = 0; x < redci; x++)
	{
		for (unsigned y = 0; y < stupci; y++)
		{
			if (nodes[y * nMapWidth + x].x == nodeStart->x && nodes[y * nMapWidth + x].y == nodeStart->y)
			{
				cout << 'A';
			}
			else if (nodes[y * nMapWidth + x].x == nodeEnd->x && nodes[y * nMapWidth + x].y == nodeEnd->y)
			{
				cout << 'x';
			}
			
			else if (nodes[y * nMapWidth + x].bObstacle == true)
			{
				cout << '#';
			}
			else
			{
				cout << '-';
			}

		}
		cout << endl;
	}
	
}

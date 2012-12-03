/*
* 
* Author: RJ Marcus
* Course: CSE274
* Professor: Dr. Bo Brinkman
* Assignment: Traveling Salesman Problem (HW05)
* 
* This program satisfies requirements A, B, C, E
* 
* Citations: Brian Breitsch told me I should search for a "next_permutation" 
* algorithm in the c++ libraries to help me with my branch and bound.
* 
*/

#include "GraphAlgs.h"
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>


int factorial(int num_nodes){
	if(num_nodes == 1)
		return 1;
	else
		return num_nodes * factorial(num_nodes-1);
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){

	std::vector<NodeID> path;
	EdgeWeight distanceTraveled = 0;

	for(int i = 1; i < G->size(); i++)
		path.push_back(i);

	std::vector<NodeID> shortestPath;
	EdgeWeight shortestDistance = DBL_MAX;

	std::list<NWPair>::iterator iter;

	int num_nodes = G->size();
	
	for (int i = 0 ; i < factorial(num_nodes-1); i++){

		distanceTraveled = G->weight(0,path[0]);

		for(int j = 0; j < num_nodes - 1; j++){
			if(distanceTraveled > shortestDistance){
				break;
			}
			else{
				if(j == num_nodes - 2)
					distanceTraveled += G->weight(0,path[j]);
				else
					distanceTraveled += G->weight(path[j+1],path[j]);
			}
		}

		if(distanceTraveled < shortestDistance){
			shortestPath = path;
			shortestDistance = distanceTraveled;
		}

		next_permutation(path.begin(), path.end());
	}

 
	shortestPath.insert(shortestPath.begin(), 0);


	std::pair<std::vector<NodeID>,EdgeWeight> result(shortestPath,shortestDistance);

	return result;


}



/*
* 
* Author: RJ Marcus
* Course: CSE274
* Professor: Dr. Bo Brinkman
* Assignment: Traveling Salesman Problem (HW05)
* 
* 
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

	for(int i = 0; i < G->size(); i++)
		path.push_back(i);

	std::vector<NodeID> shortestPath;
	EdgeWeight shortestDistance = DBL_MAX;

	std::list<NWPair>::iterator iter;

	int num_nodes = G->size();

	for (int i = 0 ; i < factorial(num_nodes); i++){

		distanceTraveled = 0;
		for(int j = 0; j < num_nodes; j++){
			if(distanceTraveled > shortestDistance)
				break;
			else{
				if(j == num_nodes - 1)
					distanceTraveled += G->weight(path.at(0),path.at(j));
				else
					distanceTraveled += G->weight(path.at(j+1),path.at(j));
			}
		}

		if(distanceTraveled < shortestDistance){
			shortestPath = path;
			shortestDistance = distanceTraveled;
		}

		next_permutation(path.begin(), path.end());
	}

	std::pair<std::vector<NodeID>,EdgeWeight> result(shortestPath,shortestDistance);

	return result;






















	//EdgeWeight distanceTraveled = 0;
	//std::vector<NodeID>* path = new std::vector<NodeID>();
	//int nodesPassed = 0;
	//NWPair current;
	//double minInCol = DBL_MAX;
	//int* finished = new int[G->size()];
	//std::fill(finished,finished+ G->size()*sizeof(int), 0);
	//std::list<NWPair>::const_iterator iter;

	//std::list<NWPair> nearby = G->getAdj(0);
	//minInCol = (*(nearby.begin())).second;
	//for(iter = nearby.begin(); iter != nearby.end(); iter++){

	//	if((*iter).second != 0 && (*iter).second < minInCol)
	//		current = *iter;

	//}

	//finished[current.first] = 1;
	//distanceTraveled += current.second;
	//nodesPassed++;
	//path->push_back(current.first);

	//while(nodesPassed < G->size()){

	//	std::list<NWPair> nearby = G->getAdj(current.first);
	//	minInCol = (*(nearby.begin())).second;

	//	for(iter = nearby.begin(); iter != nearby.end(); iter++){
	//		if( (*iter).second != 0 && finished[(int)((*iter).second)] != 1 && (*iter).second < minInCol)
	//			current = *iter;
	//	}
	//	
	//	finished[current.first] = 1;
	//	distanceTraveled += current.second;
	//	nodesPassed++;
	//	path->push_back(current.first);
	//}


	//std::pair<std::vector<NodeID>,EdgeWeight> result(*path,distanceTraveled);
	//
	//return result;
}



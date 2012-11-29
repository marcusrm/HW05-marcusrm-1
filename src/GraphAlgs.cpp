

#include "GraphAlgs.h"



std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
































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



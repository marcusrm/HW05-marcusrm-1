
#include "MatrixGraph.h"




MatrixGraph::MatrixGraph(unsigned int num_nodes){

	this->num_edges = num_nodes * (num_nodes - 1) / 2;

	//create our matrix and zero it out
	for(int i = 0; i < num_nodes; i++){

		M.push_back(*(new std::vector<EdgeWeight>()));

		for(int j = 0; j < num_nodes; j++){
			this->M.at(i).push_back(0);
		}
	}

}

MatrixGraph::~MatrixGraph(){
	delete &M;
}

// Modifiers
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

	((this->M).at(u)).at(v) = weight;

}
  
// Inspectors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{

	return ((this->M).at(u)).at(v);

}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{

	std::list<NWPair>* nearby = new std::list<NWPair>;
	
	//NOTE!!! I don't know which node ID to use in the 
	//NWPair first parameter. Currently I'm using 'v',
	//since we're searching on 'u'. I feel like it lacks
	//information though.

	for(int i = 0; i < (M.at(u)).size(); i++){
		NWPair current(i,((this->M).at(u)).at(i));
		if(current.second != 0)
			nearby->push_back(current);
	}

	return *nearby;

}

unsigned MatrixGraph::degree(NodeID u) const{

	int degree = 0;

	for(int i = 0; i < (M.at(u)).size(); i++){
		if(((this->M).at(u)).at(i) != 0)
			degree++;
	}

	return degree;
}

unsigned MatrixGraph::size() const{

	unsigned max = 0;

	for(int i = 0; i < this->M.size(); i++){
		if((this->M.at(i)).size() > max)
			max = this->M.at(i).size();
	}

	return (this->M).size() * max;
}

unsigned MatrixGraph::numEdges() const{

	unsigned totalEdges = 0;

	for(int i = 0; i < this->M.size(); i++){
		for(int j = 0; j < this->M.at(i).size(); j++){
			if(this->M.at(i).at(j) != 0)
				totalEdges++;
		}
	}

	return totalEdges;

}





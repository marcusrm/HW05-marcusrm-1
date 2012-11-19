

#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int num_nodes){

	this->num_edges = num_nodes * (num_nodes - 1) / 2;

	this->edgeList = *(new std::vector<EList>());

	for(int i = 0; i < num_nodes; i++){
		this->edgeList.push_back(*(new std::list<NWPair>));
	}


}



  ListGraph::~ListGraph(){
	  for(int i = 0; i < this->edgeList.size(); i++)
		  this->edgeList.pop_back();
  }

  // Modifiers
  void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

	  this->edgeList.at(u).push_back(NWPair(v,weight));
	  this->edgeList.at(v).push_back(NWPair(u,weight));

  }
  
  // Inspectors
  EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{

	  std::list<NWPair> branch = this->edgeList.at(u);

	  std::list<NWPair>::const_iterator iter;

	  for(iter = branch.begin(); iter != (branch.end()); iter++){
		  if(((NWPair)(*iter)).first == v)
			  return ((NWPair)(*iter)).second;
	  }

	  return 0;

  }

  std::list<NWPair> ListGraph::getAdj(NodeID u) const{

	  return this->edgeList.at(u);

  }

  unsigned ListGraph::degree(NodeID u) const{

	  return (this->edgeList.at(u)).size();

  }

  unsigned ListGraph::size() const{

	  return this->edgeList.size();
  
  }

  unsigned ListGraph::numEdges() const{
	int size = 0;

	std::list<NWPair>::const_iterator iter;

	for(int i = 0; i < this->edgeList.size(); i++){
		for(iter = ((this->edgeList.at(i)).begin()); iter != (this->edgeList.at(i)).end(); iter++){
			if(((NWPair)(*iter)).first > i)
				size++;
		}
	}

	return size;


	//OR
	//return this->num_edges;
  }

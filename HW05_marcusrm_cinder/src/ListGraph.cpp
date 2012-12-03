

#include "ListGraph.h"

using namespace std;

ListGraph::ListGraph(int num_nodes){

	//Dr. Brinkman showed us the functionality of 'resize'
	this->edgeList.resize(num_nodes);

	this->num_edges = 0;

	//this->edgeList = *(new std::vector<EList>());

	//for(int i = 0; i < num_nodes; i++){
	//	this->edgeList.push_back(*(new std::list<NWPair>));
	//}


}

  ListGraph::~ListGraph(){
	  for(int i = 0; i < this->edgeList.size(); i++)
		  edgeList.pop_back();
  }

  // Modifiers
  void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

	  edgeList.at(u).push_back(NWPair(v,weight));
	  edgeList.at(v).push_back(NWPair(u,weight));

  }
  
  // Inspectors
  EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{

	 EList branch = edgeList.at(u);

	 EList::const_iterator iter;

	  for(iter = branch.begin(); iter != branch.end(); iter++){
		  if(((NWPair)(*iter)).first == v)
			  return ((NWPair)(*iter)).second;
	  }

	  return 0;

  }

  std::list<NWPair> ListGraph::getAdj(NodeID u) const{

	  return edgeList.at(u);

  }

  unsigned ListGraph::degree(NodeID u) const{

	  return (edgeList.at(u)).size();

  }

  unsigned ListGraph::size() const{

	  return edgeList.size();
  
  }

  unsigned ListGraph::numEdges() const{
	int size = 0;

	EList::const_iterator iter;

	for(int i = 0; i < edgeList.size(); i++){
		for(iter = ((edgeList.at(i)).begin()); iter != (edgeList.at(i)).end(); iter++){
			if(((NWPair)(*iter)).first > i)
				size++;
		}
	}

	return size;


	//OR
	//return this->num_edges;
  }

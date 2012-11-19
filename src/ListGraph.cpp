


#include "ListGraph.h"

ListGraph::ListGraph(int num_nodes){

	this->num_edges = num_nodes * (num_nodes - 1) / 2;

}



  ListGraph::~ListGraph(){
	  delete &edgeList;
  }

  // Modifiers
  void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

  }
  
  // Inspectors
  EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{

  }

  std::list<NWPair> ListGraph::getAdj(NodeID u) const{

  }

  unsigned ListGraph::degree(NodeID u) const{

  }

  unsigned ListGraph::size() const{

  }

  unsigned ListGraph::numEdges() const{

  }

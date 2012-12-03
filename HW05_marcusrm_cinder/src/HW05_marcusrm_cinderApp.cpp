// Author: RJ Marcus
// Course: CSE274
// Assignment: HW05 - Traveling Salesman
// Some code borrowed from the TSP testing files given to us by Dr. Bo Brinkman

// This program satisfies requirements A, B, C, E


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "StarbucksMap.h"
#include "Tester.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "GraphAlgs.h"
#include <assert.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <Windows.h>
#include <MMSystem.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW05_marcusrm_cinderApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	pair<int,int> testSpeedTSPMod(StarbucksMap& SB, double time_limit, bool use_matrix);

	int* nodeTimeMs;
	int num_nodes;

	//Width and height of the screen
	//taken from DR. BO BRINKMAN
	static const int kAppWidth=800;
	static const int kAppHeight=800;
	static const int kTextureSize=1024; //Must be the next power of 2 bigger or equal to app dimensions
};

void HW05_marcusrm_cinderApp::setup()
{
	
	//num_nodes = 5;
	nodeTimeMs = new int[100];

	nodeTimeMs[0] = 0;
	nodeTimeMs[1] = 0;

	StarbucksMap SB;

	pair<int,int> p = testSpeedTSPMod(SB, 2.0, false);

}

//TAKEN FROM DR. BO BRINKMAN
void HW05_marcusrm_cinderApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);
}

void HW05_marcusrm_cinderApp::mouseDown( MouseEvent event )
{
}

void HW05_marcusrm_cinderApp::update()
{
}

void HW05_marcusrm_cinderApp::draw()
{

	//gl::draw(*mySurface);
	// clear out the window with black
	//gl::clear( Color( 0, 0, 0 ) ); 
}



/*
*	PLEASE NOTE: the following code is all borrowed from the files provided for this assignment,
*	I do not claim to have written any of it except for some small modifications. 
* 
* 
* 
*/

Graph* createStarbucksGraphMod(vector<Store> storeList, bool use_matrix) {
  Graph* G;
  if (use_matrix)
    G = new MatrixGraph(storeList.size());
  else
    G = new ListGraph(storeList.size());

  for (NodeID u=0; u < G->size()-1; u++)
    for (NodeID v = u+1; v < G->size(); v++)
      G->addEdge(u, v, dist(storeList[u], storeList[v]));

  return G;
}


void deleteStarbucksGraphMod(Graph* G, bool use_matrix) {
  if (use_matrix)
    delete (MatrixGraph*)G;
  else
    delete (ListGraph*)G;
}

pair<int,int> HW05_marcusrm_cinderApp::testSpeedTSPMod(StarbucksMap& SB, double time_limit, bool use_matrix) {
	int n = 3;
	int totalTime = 0;

	while (true) {
		  vector<Store> R = SB.randomSet(n);
		  Graph* G = createStarbucksGraphMod(R, use_matrix);

		  int startTime = timeGetTime();
		  pair<vector<NodeID>, EdgeWeight> p = TSP(G);
		  int newTime = timeGetTime() - startTime;
		  cout << "TSP Speed: Finished " << n << " cities in " << newTime/1000.0 << " seconds." << endl;

		  nodeTimeMs[n-1] = newTime;

		  if (newTime/1000.0 > time_limit)
			  break;
		  totalTime = newTime;
		  n++;
		  
	}

	//I WROTE THIS PART
	int division = kAppWidth/n;
	int maxTime = totalTime;
	for(int i = 0; i < n; i++){
		//make a random color for each bar in our graph and plot it
		gl::color(((double)rand())/RAND_MAX,((double)rand())/RAND_MAX,((double)rand())/RAND_MAX);
		gl::drawSolidRect(Rectf(((double)i)/n,1.0-(nodeTimeMs[i]/(double)maxTime),((double)i+1)/n,1.0));


	}


	return make_pair(n,totalTime);
}

CINDER_APP_BASIC( HW05_marcusrm_cinderApp, RendererGl )
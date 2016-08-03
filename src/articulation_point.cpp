//Program to get Articulation Point and Bridges
#include "articulation_point.h"

//Get Bridges from bridge vector
void AP::getBridges(){
	dfs();
	for(auto x:bridge){
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}cout<<endl;
	
}
//Get Articulation Point from ap bool vector calculated by running dfs()
void AP::getArticulationPoints(){
	dfs();
	printLow();
	cout<<endl;
	for(int i=0;i<vertices.size();i++)
		if(ap[i])
			cout<<i+1<<" ";
	cout<<endl;
}

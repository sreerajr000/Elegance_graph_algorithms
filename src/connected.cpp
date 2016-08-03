#include "connected.h"
//Perform connected check
//Function counts no of connected components
int Connected::countConnected(){
	int count = 1;
	bfs_roots.clear();
	bfs_roots.push_back(1);
	for(size_t index=0;index<vertices.size();index++){
		if(vertices[index].color==WHITE){	//unvisited
			bfs(index+1);
			bfs_roots.push_back(index+1);	//push all the bfs source vertices
			count++;	//no of bfs calls
			
		}
	}
	return count;
}
//Check connectedness
bool Connected::isConnected(){
	bfs(1);
	//dfs();
	for(size_t index=0;index<vertices.size();index++){
		if(vertices[index].color==WHITE)
			return 0;
	}
	return 1;
}

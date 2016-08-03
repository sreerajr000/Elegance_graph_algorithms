#include "bipartite.h"
//Perform bipartite check using bfs
//For all components
bool Bipartite::isBipartite(bool connected_flag){
	bool return_value=true;
	int size=countConnected();
	for(size_t index=0;index<size;index++){	//for each component ...check bipartite
		return_value=return_value&&isBipartite(bfs_roots[index]);
	}
	return return_value;
}

//for a single component starting from source
bool Bipartite::isBipartite(int source){
	//int source=1;
	//initialisation
	for(size_t index=0;index<vertices.size();index++){
		vertices[index].color=WHITE;
		vertices[index].distance=INT_MAX;
		vertices[index].partition=0;
	}
	vertices[source-1].color=GRAY;
    vertices[source-1].distance=0;
    vertices[source-1].partition=1;	//Partition ->equivalent to coloring
    queue<Vertex *> Q;
    Q.push(&vertices[source-1]);
	while(!Q.empty()){
	Vertex *u=Q.front();
	//Q.pop();
	for(size_t index=0;index<adjacencyList[u->key].size();index++){
		if(adjacencyList[u->key][index]->partition==u->partition)	//Adjacent element in same partition ..Not Bipartite
			return 0;
	    else if(adjacencyList[u->key][index]->color==WHITE){	//not visitedS
	    	//cout<<adjacencyList[u.key][index]->key+1<<" ";
		adjacencyList[u->key][index]->color=GRAY;
		adjacencyList[u->key][index]->distance=u->distance+1;
		adjacencyList[u->key][index]->partition=3-u->partition;	//Set Partition
		Q.push(adjacencyList[u->key][index]);
	    }
	   
	}
	Q.pop();
	u->color=BLACK;	//Fully visited
    }
    return 1;
} 


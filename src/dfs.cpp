#include "dfs.h"

//Perform DFS
//FUnction to print parent of vertices in DFS tree
void DFS::printParent(bool dfs_flag){
	dfs();
	cout<<"Size : " << vertices.size()<<endl;
	for(auto x:vertices){
		if(x.parent!=NULL)
			cout<<x.key+1<<"->"<<x.parent->key+1<<" ";
	}
	cout<<endl;
}
//Print DFS o/[
void DFS::printDFS(){
	cout<<"DFS : ";
	for(auto x:dfs_op)	
		cout<<x<<" ";
	cout<<endl;
}
//Function dfs
void DFS::dfs(){
	ap=new bool[vertices.size()];	//articulation points
	memset(ap,0,sizeof(ap));	//set all false
	dfs_op.clear();			//clear current o/p
	dfs_op.push_back(1);
	low.clear();
	bridge.clear();
	low.resize(no_of_vertices);
	//initialisation
	for(size_t index=0;index<vertices.size();index++){
		vertices[index].color=WHITE;
		vertices[index].parent=NULL;
	}
	time=0;
	for(size_t index=0;index<vertices.size();index++){
		if(vertices[index].color==WHITE)
			dfs_visit(index);	//call dfs utility
	}
}

//Dfs utility function dfs_visit()...
void DFS::dfs_visit(int source){
	time++;
	vertices[source].distance=time;	//Distance refers discovery time
	low[source]=time;
	vertices[source].color=GRAY;
	int children=0;
	//bridge.clear();
	for(size_t index=0;index<adjacencyList[source].size();index++){
		if(adjacencyList[source][index]->color==WHITE){
			children++;
			dfs_op.push_back(adjacencyList[source][index]->key+1);
			//cout<<adjacencyList[source][index]->key+1<<" ";
			adjacencyList[source][index]->parent=&vertices[source];
			dfs_visit(adjacencyList[source][index]->key);
			low[source]=min(low[source],low[adjacencyList[source][index]->key]);	//set low value
			//Bridge Calculation
			
			if(low[adjacencyList[source][index]->key]>vertices[source].distance){
				vector<int> edge{source+1,adjacencyList[source][index]->key+1};
				bridge.push_back(edge);
			}
			
			//Articulation Point calculation
			if(vertices[source].parent==NULL&&children>1)
				ap[source]=true;
			if(vertices[source].parent!=NULL&&low[adjacencyList[source][index]->key]>=vertices[source].distance)
				ap[source]=true;
		}
		else if(adjacencyList[source][index]!=vertices[source].parent){
			low[source]=min(low[source],adjacencyList[source][index]->distance );	//set low value
		}
	}
	vertices[source].color=BLACK;
	time++;
	vertices[source].f=time;
}


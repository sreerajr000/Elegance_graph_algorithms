//Program to get Biconnected Components
#include "bcc.h"

//Get BCC
void BCC::bcc(){
	low.clear();
	low.resize(no_of_vertices);
	edge_stack=new list<Edge>[no_of_edges];		//Stack of edges to store current bcc
	for(size_t index=0;index<vertices.size();index++){	//Initialisation for dfs
		vertices[index].color=WHITE;
		vertices[index].parent=NULL;
		low[index]=-1;
		vertices[index].distance=-1;	//for dfs distance refers to discovery time
	}
	time=0;
	for(size_t index=0;index<vertices.size();index++){
		if(vertices[index].distance==-1)		//unvisited
			bcc_util(index);
		//Print biconnected component from the stack
		bool flag=false;
		while(edge_stack->size()>0){
			flag=true;
			cout<<edge_stack->back().u<<"--"<<edge_stack->back().v<<" ";
			edge_stack->pop_back();			
		}
		if(flag)
			cout<<endl;
	}
}
//BCC utility function bcc_util()...
void BCC::bcc_util(int source){
	time++;
	vertices[source].distance=time;	//Set discovery time of vertex
	low[source]=time;
	//vertices[source].color=GRAY;
	int children=0;		//initialise children count
	for(size_t index=0;index<adjacencyList[source].size();index++){
		if(adjacencyList[source][index]->distance==-1){
			children++;

			adjacencyList[source][index]->parent=&vertices[source];
			edge_stack->push_back(Edge(source+1,adjacencyList[source][index]->key+1));	//Push current edge onto stack
			bcc_util(adjacencyList[source][index]->key);	//Recursive call
			low[source]=min(low[source],low[adjacencyList[source][index]->key]);//Update low value
	
			//Ap check
			if((vertices[source].distance==1&&children>1)||(vertices[source].distance>1&&low[adjacencyList[source][index]->key]>=vertices[source].distance)){
				//Pop out current stack content
				while(edge_stack->back().u!=source+1||edge_stack->back().v!=adjacencyList[source][index]->key+1){
					cout<<edge_stack->back().u<<"--"<<edge_stack->back().v<<" ";
					edge_stack->pop_back();
				}
				cout<<edge_stack->back().u<<"--"<<edge_stack->back().v;
				edge_stack->pop_back();
				cout<<endl;
			}
			
		}//Not Ap
		else if(adjacencyList[source][index]!=vertices[source].parent&&adjacencyList[source][index]->distance</*low[source]*/vertices[source].distance){
			low[source]=min(low[source],adjacencyList[source][index]->distance );
			edge_stack->push_back(Edge(source+1,adjacencyList[source][index]->key+1));
		}
	}
	//vertices[source].color=BLACK;
	time++;
	//vertices[source].f=time;
}


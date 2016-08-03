#include "scc.h"
//Get Strongly Connected Components
//Dfs 1st
void SCC::fillOrder(int v,stack<int> &Stack){
	visited[v]=true;
	for(int i=0;i<adjacencyList[v].size();i++){
		if(!visited[adjacencyList[v][i]->key])
			fillOrder(adjacencyList[v][i]->key,Stack);
	}
	Stack.push(v);//push to stack
}
//2nd dfs scc utility

void SCC::scc_util(int v,bool visited[]){
	visited[v]=true;
	cout<<v+1<<" ";
	for(int i=0;i<adjacencyList[v].size();i++){
		if(!visited[adjacencyList[v][i]->key])
			scc_util(adjacencyList[v][i]->key,visited);
	}
	
}
//GET SCC
void SCC::getSCC(){
	stack<int> Stack;
	SCC graphT=getTranspose();	//find transpose
	graphT.vertices=vertices;
	visited=new bool[no_of_vertices];
	memset(visited,0,sizeof(visited));	//Set visited to false
	
	for(int index=0;index<no_of_vertices;index++)
		if(visited[index]==false)
			fillOrder(index,Stack);
	memset(visited,0,sizeof(visited));
	//output components
	while(Stack.empty()==false){
		int v=Stack.top();
		Stack.pop();
		if(visited[v]==false){
			graphT.scc_util(v,visited);
			cout<<endl;
		}
	}
}
//Find Transpose of directed graph
SCC SCC::getTranspose(){
	SCC trans;
	trans.adjacencyList.resize(no_of_vertices);
	for(int v=0;v<no_of_vertices;v++){
		for(int i=0;i<adjacencyList[v].size();i++)
			trans.adjacencyList[adjacencyList[v][i]->key].push_back(&vertices[v]);
	}
	/*cout<<"Transpose\n";
	for(auto x:trans.adjacencyList){
		for(auto y:x)
			cout<<y->key+1<<" ";
		cout<<endl;
	}*/
	return trans;	//return transpose
}


#include "ramsey.h"
//Check Ramsey theory
bool Ramsey::ramsey(){
	vector<vector<int>> edgeList={{1,2},{1,3},{1,4},{1,5},{1,6},
					{2,3},{2,4},{2,5},{2,6},
					{3,4},{3,5},{3,6},
					{4,5},{4,6},
					{5,6}};		//Static edge list
	vertices.clear();
	no_of_vertices=6;
	for(int i=0;i<6;i++){
		Vertex data(i);
		vertices.push_back(data);
	}		//vertices initialisation
	
	int count=0;
	for(int i=0;i<pow(2,15);i++){	//Run all graphs
		//cout<<endl;
		adjacencyList.clear();
		adjacencyList.resize(6);
	
		bitset<15> binary = bitset<15>(i);	//current bitstring
		invert:
		for(int j=0;j<15;j++){
			if(binary[j]){
				int u=edgeList[j][0];
				int v=edgeList[j][1];
				adjacencyList[u-1].push_back(&vertices[v-1]);
				adjacencyList[v-1].push_back(&vertices[u-1]);
			}				
		}
		//printAdjList();
		if(existC3())		//Check C3 friend
			count++;
		else{
			binary=~binary;		//Enemy (invert)
			goto invert;		//Rerun
		}
	}
	cout<<"Count="<<count<<endl;	
	if(count==32768)
		return true;
	else
		return false;
}


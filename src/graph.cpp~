#include "graph.h"
//Read Graph

//Read Graph Directed,Weighted
void Graph::readDirected(bool weighted){
	sum=0;
	directed=true;
	List.resize(no_of_vertices);
	indegree.resize(no_of_vertices,0);
	for(size_t index=0;index<no_of_edges;index++){
		cout<<"Enter the edge and weight : ";
		int vertex_a,vertex_b,wt;
		cin>>vertex_a>>vertex_b>>wt;
		adjacencyList[vertex_a-1].push_back(&vertices[vertex_b-1]);
		List[vertex_a-1].push_back(vertex_b-1);
		indegree[vertex_b-1]++;
		weight[vertex_a-1][vertex_b-1]=wt;
		sum+=wt;
  	}
}

void Graph::readDirected(){
	directed=true;
	List.resize(no_of_vertices);
	indegree.resize(no_of_vertices,0);
	for(size_t index=0;index<no_of_edges;index++){
		cout<<"Enter the edge : ";
		int vertex_a,vertex_b;
		cin>>vertex_a>>vertex_b;
		adjacencyList[vertex_a-1].push_back(&vertices[vertex_b-1]);
		List[vertex_a-1].push_back(vertex_b-1);
		indegree[vertex_b-1]++;
  	}
}

void Graph::readUndirected(bool weighted){
	sum=0;
	directed=false;
	List.resize(no_of_vertices);
	for(size_t index=0;index<no_of_edges;index++){
		cout<<"Enter the edge and weight : ";
		int vertex_a,vertex_b,wt;
		cin>>vertex_a>>vertex_b>>wt;
		adjacencyList[vertex_a-1].push_back(&vertices[vertex_b-1]);
		//adjacencyList[vertex_b-1].push_back(&vertices[vertex_a-1]);
		List[vertex_a-1].push_back(vertex_b-1);
		weight[vertex_a-1][vertex_b-1]=wt;
		weight[vertex_b-1][vertex_a-1]=wt;
		sum=sum+wt;
  	}

}


void Graph::readUndirected(){
		directed=false;
	for(size_t index=0;index<no_of_edges;index++){
		cout<<"Enter the edge : ";
		int vertex_a,vertex_b;
		cin>>vertex_a>>vertex_b;
		adjacencyList[vertex_a-1].push_back(&vertices[vertex_b-1]);
		adjacencyList[vertex_b-1].push_back(&vertices[vertex_a-1]);
  	}
}

void Graph::readAdjList(){
	vertices.clear();
	adjacencyList.clear();
    cout<<"Enter the no of vertices : ";
    cin>>no_of_vertices;
    cout<<"Enter the no of edges : ";
    cin>>no_of_edges;
    weight.resize(no_of_vertices,vector<int>(no_of_vertices,INT_MAX));
    		
    adjacencyList.resize(no_of_vertices);
    for(size_t index=0;index<no_of_vertices;index++){
	weight[index][index]=0;
	Vertex data(index);
	vertices.push_back(data);
    }
	cout<<"Directed/Undirected (1/0) : ";
	
	cin>>directed;
	cout<<"Weighted/Unweighted (1/0) : ";
	
	cin>>weighted;
	directed?(weighted?readDirected(true):readDirected()):(weighted?readUndirected(true):readUndirected());
	//Graph t=getTranspose();
}

//Print Adjacency List
void Graph::printAdjList(){
    for(auto x:adjacencyList){
	for(auto y:x)
	  cout<<(*y).key+1<<" ";
	cout<<endl;
    }
 }



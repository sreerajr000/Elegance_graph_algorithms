#include "cycle.h"
//All cycle check function
//Check cycle exist on graphs with connected componentsd
bool Cyclic::isCyclic(bool connected_flag){
	bool return_value=false	;
	int size=countConnected();
	for(size_t index=0;index<size;index++){
		return_value=return_value||isCyclic(bfs_roots[index]);
	}
	return return_value;
}

//check for connected ....
bool Cyclic::isCyclic(int source){
	//int source=1;
	//initialisation
	for(size_t index=0;index<vertices.size();index++){
		vertices[index].color=WHITE;
		vertices[index].distance=INT_MAX;
		vertices[index].parent=NULL;
	}
    vertices[source-1].color=GRAY;
    vertices[source-1].distance=0;
    vertices[source-1].parent=NULL;
    queue<Vertex *> Q;
    Q.push(&vertices[source-1]);
    while(!Q.empty()){
	Vertex *u=Q.front();
	Q.pop();
	for(size_t index=0;index<adjacencyList[u->key].size();index++){
		
		if(adjacencyList[u->key][index]->color==GRAY)//Back Edge  ...already visited vertex
			return 1;
	    if(adjacencyList[u->key][index]->color==WHITE){	//Unvisited
	    	//cout<<adjacencyList[u.key][index]->key+1<<" ";
		adjacencyList[u->key][index]->color=GRAY;	//set visited
		adjacencyList[u->key][index]->distance=u->distance+1;
		adjacencyList[u->key][index]->parent=u;
		Q.push(adjacencyList[u->key][index]);
	    }
	    else if(directed)	//Directed graph and black vertex  ..cycle exists
	    	return 1;
	}
	u->color=BLACK;		//Completely visited
    }
    return 0;
}


//Check whether C3 exists or connected components > = 3 for ramsey
bool Cyclic::existC3(){
	if(countConnected()>=3)		//for ramsey enemy case
		return true;
	vector<vector<bool>> nt=nontree;
	for(int i=0;i<adjacencyList.size();i++){
		for(int j=0;j<adjacencyList[i].size();j++){
			if(nt[i][adjacencyList[i][j]->key]){
				//cout<<"Non tree edge : "<<i+1<<","<<adjacencyList[i][j]->key+1<<endl;
				if(vertices[i].parent==vertices[adjacencyList[i][j]->key].parent)//non tree edge with sameparent C3 exists
					return true;
			}
		}
	}
	return false;	//No C3
}

//Current vertice set form a cycle or not ..bruteforece method
bool Cyclic::existEvenCycle(vector<int> &t){
	sort(t.begin(), t.end());
    	do {
		int i;
		for(i=0;i<t.size();i++){
			//i, i+1%t.size()
			int flag=0;
			for(int j=0;j<adjacencyList[t[i]].size();j++){
				if(adjacencyList[t[i]][j]->key==t[(i+1)%t.size()])
					flag=1;
			}
			if(flag==0)
				break;
		}
		if(i==t.size())
			return true;
	}while(next_permutation(t.begin(), t.end()));	
	return false;
}

//Check for even Cycle   (Bruteforce)
bool Cyclic::isEvenCyclic(){
	const int k=no_of_vertices;
	for(int i=1;i<=pow(2,no_of_vertices);i++){
		
		string binary = bitset<15>(i).to_string();	//Convert to binary
		int ct=0;
		vector<int> t;
		for(int j=0;j<no_of_vertices;j++){
			if(binary[j]=='1'){
				ct++;
				t.push_back(j);
			}
		}
		if(ct%2==0&&ct>2){	//take even vertices
			if(existEvenCycle(t))	//check even cycle
				return true;
		}
		t.clear();
	}
	return false;
	//return isCyclic(1)&&isBipartite(1);
}


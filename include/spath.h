#ifndef SPATH_H
#define SPATH_H
#include "bfs.h"

class Spath : virtual public BFS{
	private:
	
	protected:
		vector<vector<int>>newlist,undirected;
	public:
		void shortestPath(int,int);
		void allPairShortestPath();
		void longestPath();
		int shortestPathLength;
		void shortestPathWeighted(int,int);
		void makeAdjacencyList();
		void convert();
		void convertToUndirected();
};

#endif

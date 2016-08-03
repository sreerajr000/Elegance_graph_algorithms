#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include<cstring>
class DFS : virtual public Graph{
	private:
		vector<int> dfs_op;
	protected:
		int time;
		bool *ap;
		vector<int> low;
		vector<vector<int>>bridge;
	public:
		void dfs();
    		void dfs_visit(int);
		void printDFS();
		void printParent(bool);
};

#endif

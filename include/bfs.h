#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include<queue>
class BFS :  virtual public Graph{
	private:
		vector<int> bfs_op;
	protected:
		vector<vector<bool>>nontree;
	public:
		void bfs(int);
		void printBFS();
		void printParent();
};

#endif

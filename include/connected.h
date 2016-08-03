#ifndef CONNECTED_H
#define CONNECTED_H

#include "bfs.h"

class Connected : virtual public BFS {
	private:
	
	protected:
		vector<int> bfs_roots;
	public:
		bool isConnected();
		int countConnected();
};
#endif

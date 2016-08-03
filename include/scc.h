#ifndef SCC_H
#define	SCC_H

#include "dfs.h"
#include<stack>
class SCC : virtual public DFS{
	private:
		SCC getTranspose();
		bool *visited;
	protected:
		
	public:
		
		void getSCC();
		void scc_util(int,bool[]);
		void fillOrder(int,stack<int>&);
};
#endif

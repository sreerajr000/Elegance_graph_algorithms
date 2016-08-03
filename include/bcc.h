#ifndef BCC_H
#define BCC_H

#include "dfs.h"

class BCC : virtual public DFS{
	private:
		list<Edge> *edge_stack;
	protected:
	
	public:
		void bcc();
		void bcc_util(int);

};

#endif

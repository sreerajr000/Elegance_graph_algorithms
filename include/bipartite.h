#ifndef BIPARTITE_H
#define BIPARTITE_H
#include "connected.h"
class Bipartite : virtual public Connected {
	private:
	
	protected:
	
	public:
		bool isBipartite(int);	//Connected
		bool isBipartite(bool);	//Not Connected
};

#endif

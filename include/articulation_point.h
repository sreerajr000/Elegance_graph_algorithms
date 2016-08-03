#ifndef ARTICULATION_POINT_H
#define ARTICULATION_POINT_H
#include "dfs.h"

class AP : virtual public DFS{
	private:
		
	protected:
		
	public:
		void getArticulationPoints();
		void getBridges();
		void printLow(){
		    	dfs();
		    	cout<<"\nPrint low : ";
			for(auto x:low)
				cout<<x<<" ";
				cout<<endl;
			}
};

#endif

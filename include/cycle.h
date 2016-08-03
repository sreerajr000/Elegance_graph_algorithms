#ifndef CYCLE_H
#define CYCLE_H
#include "connected.h"
#include <algorithm>
#include <bitset>

class Cyclic : virtual public Connected{
	private:
	
	protected:
	
	public:
		bool isCyclic(int);		//Connected
		bool isCyclic(bool);	//Not Connected	
		bool isEvenCyclic();
		bool existEvenCycle(vector<int>&);
		bool existC3();
};
#endif

#include "tree.h"
//Check tree
bool Tree::isTree(){
	return (!isCyclic(1))&&isConnected();
}


#include "dfs.h"
#include "articulation_point.h"
#include "bcc.h"
#include "bfs.h"
#include "bipartite.h"
#include "connected.h"
#include "course_top.h"
#include "cycle.h"
#include "graph.h"
#include "ramsey.h"
#include "scc.h"
#include "spath.h"
#include "tree.h"

class Elegance : public AP,public BCC,public SCC,public Spath,public Ramsey,public Tree,public Bipartite,public TopologicalSort{
	private:
		int opt;
		char ch;
	public:
		int frame();
		void menu();
		
};

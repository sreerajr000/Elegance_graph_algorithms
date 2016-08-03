#include "course_top.h"

//Function topological Sort (Kahn's Algorithm)
int TopologicalSort::top_sort() {
      queue<int> tsort_queue;
      vector<int> sorted;	//Sorted List
     
      //If a node is not present in the graph , its indegree is -1.....
      for(int i = 0; i < (signed)indegree.size(); i++) {
            if(indegree[i] == -1)
                  continue;
            if(indegree[i] == 0)	//Push nodes with indegree 0
            tsort_queue.push(i);
      }
      int level=tsort_queue.size();
     int count=0;	//No of semesters
      while(!tsort_queue.empty()) {
            int front = tsort_queue.front();
            tsort_queue.pop();
            level--;
            sorted.push_back(front);
            vector<int>::iterator it;
            for(it = List[front].begin();
                        it != List[front].end(); it++) {
                  indegree[*it] -= 1;
                  if(indegree[*it] == 0)
                        tsort_queue.push(*it);
            }
            //Current level exhausted
            if(level==0){
            	level=tsort_queue.size();
            	count++;//One semester over
            }
      }
      cout<<"Top Sorted Order : ";
      for(int i = 0; i < (signed)sorted.size(); i++)
            cout<<sorted[i]+1<<" ";
      cout<<endl;
      return count;
}


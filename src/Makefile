IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)
OBJDIR=../obj/
OBJFLAG=-o $(OBJDIR)

OBJECTS=articulation_point.o bcc.o bfs.o bipartite.o connected.o course_top.o cycle.o dfs.o graph.o ramsey.o scc.o spath.o tree.o elegance.o

Elegance:$(OBJECTS)
	g++ -o ../Elegance $(OBJDIR)articulation_point.o $(OBJDIR)bcc.o $(OBJDIR)bfs.o $(OBJDIR)bipartite.o $(OBJDIR)connected.o $(OBJDIR)course_top.o $(OBJDIR)cycle.o $(OBJDIR)dfs.o $(OBJDIR)graph.o $(OBJDIR)ramsey.o $(OBJDIR)scc.o $(OBJDIR)spath.o $(OBJDIR)tree.o $(OBJDIR)elegance.o -std=c++11
	
.cpp.o:$*.cpp
	$(CC) $(OBJFLAG)$*.o -c $*.cpp $(CFLAGS) -std=c++11
	
clean:
	rm -f $(OBJDIR)*.o ../Elegance

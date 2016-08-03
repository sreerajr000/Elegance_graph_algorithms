#include<iostream>
#include<climits>
using namespace std;
enum Color{WHITE,GRAY,BLACK};

struct Vertex{
    Color color;
    int distance,f,partition;
    Vertex *parent;
    int key;
    Vertex(int k):color(WHITE),distance(INT_MAX),parent(NULL),key(k){};	
    Vertex():color(WHITE),distance(INT_MAX),parent(NULL){};//Constructor with default arguments try
};

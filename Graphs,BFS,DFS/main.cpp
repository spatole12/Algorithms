#include "graph.h"
#include <stdio.h>
#include <iostream>
int main()
{
	
	Graph g= Graph(12);
	/* g.set_edge(0,1,1);
	g.set_edge(1,0,1);
	g.set_edge(1,3,1);
	g.set_edge(3,1,1);
	g.set_edge(1,2,1);
	g.set_edge(2,1,1);
	g.set_edge(4,3,1);
	g.set_edge(4,2,1); */

	g.set_edge(0, 4, 1);
    g.set_edge(4, 0, 1);
    g.set_edge(4, 5, 1);
    g.set_edge(5, 4, 1);
    g.set_edge(4, 1, 1);
    g.set_edge(1, 4, 1);
    g.set_edge(1, 3, 1);
    g.set_edge(5, 3, 1);
    g.set_edge(5, 7, 1);
    g.set_edge(7, 8, 1);
    g.set_edge(8, 6, 1);
    g.set_edge(8, 9, 1);
	g.set_edge(6, 9, 1);
    g.set_edge(9, 6, 1);
    g.set_edge(11, 7, 1);
    g.set_edge(8, 11, 1);
    g.set_edge(11, 10, 1);
    g.set_edge(12, 11, 1);
    g.set_edge(10, 12, 1);
	
	cout<<" graph formed"<<endl;
    g.printmatrix();
	cout<<"Executing bfs"<<endl;
    g.bfs(0);
	cout<<"Executing dfs"<<endl;
	g.dfs(0);
    return 0;
}

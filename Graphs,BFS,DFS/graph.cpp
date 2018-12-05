#include "graph.h"
#include <iostream>	
#include <set>
#include <queue>
#include <stack>
using namespace std; 
Graph::Graph(int n){
	nodes=n;
	matrix=new int*[n];
	for(int i = 0; i < n; ++i){
		matrix[i] = new int[n];
	}
}
Graph::Graph(int** m, int n){
	nodes=n;
	matrix=m;
}
Graph::~Graph()
{ 
  //cout<<"deleting matrix";
  delete[] matrix;
  /* delete[] st1;
  delete[] st;
  delete q;
  delete stk;
  */
} 
bool Graph::set_edge(int a1, int a2, int value){
	matrix[a1][a2]=value;
	return true;
}
void Graph::printmatrix(){
	
	for (int i=0;i<nodes;i++){
		
		for (int j=0;j<nodes;j++){
		
			cout<<matrix[i][j];
		}
		cout<<endl;
	}
	//cout<<"end of print matrix";
}
void Graph::bfs(int start){
	//cout<<"print start"<<start;
	set<int> st; 
	bfs(start,&st);
}
void Graph::bfs(int start, set<int>* st){
	//cout<<"in bfs";
	queue <int> q;
	//st->insert(start);
	//enqueue(q,start)
	int u=start;
	q.push(start);
	st->insert(u);
	cout<<"Visited node in BFS:"<<endl;
	cout<<start<<endl;
	while(!q.empty()){
		//cout<<"in bfs while";
		u=q.front();
		q.pop();
		//cout<<"Visited node in BFS:"<<q.front()<<endl;
		for (int i=0;i<nodes;i++)
		{	//cout<<"matrix"<<u<<i<<matrix[u][i];
			if(matrix[u][i]==1){
				//cout<<"in if"<<endl;
				if(st->find(i)==st->end()){
					cout<<i<<endl;
					st->insert(i);
					q.push(i);
				}
			}
		}
	}
	//this->Graph::~Graph();
}

void Graph::dfs(int start){
	//cout<<"print start"<<start;
	set<int> st1; 
	for (int i = start; i < nodes; i++)
	{
		if (st1.find(i) == st1.end())
		{
		dfs(i,&st1);
		//dfs(start,&st1);
		}
	}
}	

void Graph::dfs(int start, set<int>* st1){
	int start_node = start;
    st1->insert(start_node); 
	cout<<start_node<<endl;

	for (int i=0;i<nodes;i++)
	{
		if(matrix[start_node][i]==1){
			if(st1->find(i)==st1->end())
			{
				dfs(i,st1);					
			}
		}
	}

}

/* 
	
 */
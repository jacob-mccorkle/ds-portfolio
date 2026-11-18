#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <limits>

using namespace std;

class Graph
{
 private:

  struct Edge {
    int destination;
    int weight;
  };

  std::vector<std::vector<Edge>> adjList;

 public:

  Graph();
  
  int addVertex();

  void addEdge(int u, int v, int weight);

  std::vector<int> bfs(int start);

  std::vector<int> dfs(int start);

  std::vector<int> dijkstra(int start);

  bool isConnected();

  void mergeSort(std::vector<int>& arr);
};

#endif
  

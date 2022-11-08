#ifndef __DIGRAPH_ADJ_LIST_H__
#define __DIGRAPH_ADJ_LIST_H__

#include "DiGraph.h"

using namespace std;

namespace ds {

/**
 * Directed graph implementation using **adjacent list**
 */
class DiGraphAdjList : public DiGraph {
private:
  int V;               // Number of vertices
  VList<int> *adjList; // Array of lists indexed by vertex id

public:
  /**
   * Create empty directed graph with V vertices
   *
   * @param _V number of vertices
   */
  explicit DiGraphAdjList(int _V) {
    V = _V;
    adjList = new VList<int>[V];
  }

  /**
   * Destroy the DiGraphAdjList object
   */
  ~DiGraphAdjList() { delete[] adjList; }

  /**
   * @return number of vertices
   */
  int v() const { return V; }

  /**
   * @return number of edges
   */
  int e() const {
    int sum = 0;
    for (int i = 0; i < v(); i++) {
      sum += adjList[i].size();
    }
    return sum;
  }

  /**
   * @param v node id
   * @return a list of nodes adjacent to v
   */
  VList<int> adj(int v) const {
    if (v >= V)
      return VList<int>();
    return adjList[v];
  }

  void addEdge(int v1, int v2);
  void delEdge(int v1, int v2);
  bool hasEdge(int v1, int v2) const;
  bool hasCycle() const;
};

} // namespace ds

#endif // __DIGRAPH_ADJ_LIST_H__
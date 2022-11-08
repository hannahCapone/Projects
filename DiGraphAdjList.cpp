#include "DiGraphAdjList.h"

using namespace std;

namespace ds {

/**
 * Determine if an edge is in graph
 *
 * @param s id of the source vertex
 * @param t id of the target vertex
 * @return true if the edge is in the graph
 */
bool DiGraphAdjList::hasEdge(int s, int t) const {
  // TODO:
  for (int &i : this->adj(s)) {
    if (i == t) {
      return true;
    }
  }
  return false;
}

/**
 * Add an edge to graph
 *
 * @param s id of the source vertex
 * @param t id of the target vertex
 */
void DiGraphAdjList::addEdge(int s, int t) {
  // TODO:
  if (hasEdge(s, t) == false) {
    adjList[s].addLast(t);
  }
}

/**
 * Remove an edge
 *
 * @param s id of the source vertex
 * @param t id of the target vertex
 */
void DiGraphAdjList::delEdge(int s, int t) {
  // TODO:
  int i;
  if (hasEdge(s, t) == true) {
    for (int j = 0; j < adj(s).size(); j++) {
      if (t == adjList[s].get(j)) {
        i = j;
      }
    }
    adjList[s].remove(i);
  }
}

/**
 * HELPER FUNCTION for hasCycle
 *
 * @return boolean
 */
bool hasCycleHelp(const DiGraphAdjList &g, int v, int *marked) {
  // TODO:

  // marked[v] = 0; // new
  // marked[v] = 1; // active
  // marked[v] = -1; // finished

  marked[v] = 1;
  for (int w = 0; w < g.adj(v).size(); w++) {
    if (marked[w] == 1) {
      return true;
    } 
    else if (marked[w] == 0) {
      if (hasCycleHelp(g, w, marked))
        return true;
    }
  }
  marked[v] = -1;
  return false;
}

/**
 * Check if the directed graph has cycles
 *
 * @return true if there are cycles
 */
bool DiGraphAdjList::hasCycle() const {
  // TODO:
  // create array called marked
  int marked [v()];

  for (int i = 0; i < v(); i++) {
    marked[i] = 0;
  }
  for (int i = 0; i < v(); i++) {
    if (marked[i] == 0)
      if (hasCycleHelp(*this, i, marked))
        return hasCycleHelp(*this, i, marked);
  }
  return false;

  // Not Visited (NEW)
  // Visited Once (ACTIVE)
  // Done with DFS (FINISHED)
}

} // namespace ds

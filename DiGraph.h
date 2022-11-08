#ifndef __DIGRAPH_H__
#define __DIGRAPH_H__

#include "VList.h"
#include <algorithm>
#include <ostream>

namespace ds {

/**
 * Directed graph ADT
 */
class DiGraph {
public:
  virtual void addEdge(int v1, int v2) = 0;
  virtual void delEdge(int v1, int v2) = 0;
  virtual bool hasEdge(int v1, int v2) const = 0;
  virtual VList<int> adj(int v) const = 0;
  virtual int v() const = 0;
  virtual int e() const = 0;

  /**
   * Print the graph to os
   *
   * @param os the output stream
   * @param g the graph
   * @return the updated output stream
   */
  friend std::ostream &operator<<(std::ostream &os, const DiGraph &g) {
    os << "{";
    for (int v = 0; v < g.v(); v += 1) {
      auto adjlist = g.adj(v);
      std::sort(adjlist.begin(), adjlist.end());
      if (v != 0)
        os << ",";
      os << v << ":" << adjlist;
    }
    os << "}";
    return os;
  }
};

} // namespace ds

#endif // __DIGRAPH_H__
#ifndef __VLIST_H__
#define __VLIST_H__

#include "List.h"
#include <vector>

namespace ds {

/** List based on vector */
template <typename ItemType> class VList : public List<ItemType> {
private:
  /** The underlying vector. */
  std::vector<ItemType> vec;

public:
  VList() {}
  VList(const VList &other) : vec(other.vec) {}
  int size() const override { return vec.size(); }
  ItemType &get(int i) override { return vec[i]; }
  const ItemType &get(int i) const override { return vec[i]; }
  void insert(const ItemType &x, int i) override {
    vec.insert(vec.begin() + i, x);
  }
  ItemType remove(int i) override {
    ItemType ret = vec[i];
    vec.erase(vec.begin() + i);
    return ret;
  }
  void addFirst(const ItemType &x) override { vec.insert(vec.begin(), x); }
  void addLast(const ItemType &x) override { vec.push_back(x); }
  ItemType &getFirst() override { return vec.front(); }
  ItemType &getLast() override { return vec.back(); }
  const ItemType &getFirst() const override { return vec.front(); }
  const ItemType &getLast() const override { return vec.back(); }
  ItemType removeFirst() override {
    ItemType first = vec.front();
    vec.erase(vec.begin());
    return first;
  }
  ItemType removeLast() override {
    ItemType last = vec.back();
    vec.pop_back();
    return last;
  }
  typename std::vector<ItemType>::iterator begin() { return vec.begin(); }
  typename std::vector<ItemType>::iterator end() { return vec.end(); }
};

} // namespace ds

#endif // __VLIST_H__

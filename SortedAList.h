#ifndef __SORTED_ALIST_H__
#define __SORTED_ALIST_H__

#include "SortedList.h"

// use factor 2
#define RFACTOR 2

namespace ds {

template <typename ItemType> class TestDriver; // for autograding; please ignore

/** Array-based sorted list. */
template <typename ItemType> class SortedAList : public SortedList<ItemType> {
  friend class TestDriver<ItemType>; // for autograding; please ignore

private:
  /** The underlying array. */
  ItemType *items;

  /** Stores the current size of the list. */
  int count;

  /** Max number of items allowed. */
  int maxCnt;

  /** Resize the underlying array to the target capacity. */
  void resize(int capacity) {
    maxCnt = capacity;
    ItemType *a = new ItemType[maxCnt];
    for (int i = 0; i < count; i++) {
      a[i] = items[i];
    }
    delete[] items;
    items = a;
  }

public:
  /**
   * Construct a new SortedAList object.
   *
   * @param initSize initial size of the underlying array; default 100
   */
  explicit SortedAList(int initSize = 100) {
    count = 0;
    maxCnt = initSize;
    items = new ItemType[maxCnt];
  }

  /** Destroy the SortedAList object. */
  ~SortedAList() { delete[] items; }

  /** Return the number of elements in the sorted list. */
  int size() const override { return count; }

  /** Return the i-th item in the sorted list .*/
  ItemType get(int i) const override { return items[i]; }

  /** Return the smallest item. */
  ItemType smallest() const override { return items[0]; }

  /** Return the greatest item. */
  ItemType greatest() const override { return items[count - 1]; }

  inline ItemType remove(int i) override;
  inline void put(const ItemType &it) override;
};

/**
 * Remove and return the i-th item from the sorted list.
 */
template <typename ItemType> ItemType SortedAList<ItemType>::remove(int i) {
  // TODO:
  // store the value of what is being removed
  ItemType value = items[i];
  
  // move the numbers above the index 'i' down
  for (int j = i; j < count -1; j++) {
    items[j] = items[j + 1];
  }
  // decrease count
  count--;
  // return what was removed
  return value;
}

/**
 * Put "it" into the "items" array while ensuring that "items" are sorted.
 */
template <typename ItemType>
void SortedAList<ItemType>::put(const ItemType &it) {
  // TODO:

  // resize if neccesary
  if (count == maxCnt) {
    resize(count * 2);
  }

  int i = 0;
  // see if the list is empty
  if (count == 0)
  {
    items[0] = it;
  }

  // see if it is the smallest (aka first)
  else if (it < items[i])
  {
    for (int h = count; h > 0; h--)
    {
    items[h] = items[h-1];
    }
    items[0] = it;
  }

  // see if it is the largest value
  else if (it > items[count - 1]) {
    items[count] = it;
  }

  // else, the value is somewhere in between
  else
  {
    // increment through to find where it belongs
    while (items[i] < it) 
    {
      i++;
    }
    // move the other items up one 
    for (int j = count; j > i; j--)
    {
      items[j] = items[j - 1];
    }
    // place it 
    items[i] = it;
  }
  // increment count
  count++;
}

} // namespace ds

#endif // __SORTED_ALIST_H__
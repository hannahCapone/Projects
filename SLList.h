#ifndef __SLLIST_H__
#define __SLLIST_H__

namespace ds {

template <typename ItemType> class Node {
public:
  ItemType item;
  Node *next;

  Node(ItemType i, Node *n = nullptr) {
    item = i;
    next = n;
  }
};

template <typename ItemType>
class TestDriver; // for autograding only; please ignore

/** Singly linked list. */
template <typename ItemType> class SLList {
  friend class TestDriver<ItemType>; // for autograding only; please ignore

private:
  /** Pointer pointing to the sentinel node. */
  Node<ItemType> *sentinel;

  /** Stores the current size of the list. */
  int count;

public:
  /** Construct a new SLList object. */
  SLList() {
    sentinel = new Node<ItemType>(ItemType(), nullptr);
    count = 0;
  }

  /** Destroy the SLList object. */
  ~SLList() {
    count = 0;
    while (sentinel != nullptr) {
      Node<ItemType> *curr = sentinel;
      sentinel = sentinel->next;
      delete curr;
    }
  }

  /** Add x at the beginning of the list. */
  void addFirst(ItemType x) {
    count += 1;
    sentinel->next = new Node<ItemType>(x, sentinel->next);
  }

  /** Return the first element. */
  ItemType &getFirst() const { return sentinel->next->item; }

  /** Return the number of elements in list. */
  int size() const { return count; }

  /** Append the list with x. */
  void addLast(ItemType x) {
    count += 1;
    Node<ItemType> *p = sentinel;
    while (p->next != nullptr) {
      p = p->next;
    }
    p->next = new Node<ItemType>(x, nullptr);
  }
  
  inline SLList(const SLList<ItemType> &other);
  inline ItemType &get(int i) const;
  inline ItemType removeFirst();
  inline ItemType removeLast();
};

/**
 * Copy-construct a new SLList<ItemType>::SLList object
 *
 * @param other some list
 */
template <typename ItemType>
SLList<ItemType>::SLList(const SLList<ItemType> &other) {
  // create a list that is identical to `other'
  
  sentinel = new Node<ItemType>(other.sentinel->next->item, nullptr);

  count = other.count;
  Node<ItemType> *p1 = other.sentinel->next;
  Node<ItemType> *p2 = sentinel;
  
  while (p1->next != nullptr) {
    p2->next = new Node<ItemType>(p1->item, p1->next);
    p1 = p1->next;
    p2 = p2->next;
  }
  p2->next = new Node<ItemType>(p1->item, nullptr);
}

/**
 *  Return the i-th item in list. Index starts from 0.
 *  For simplicity, assume the item always exists.
 *
 * @param i index of item
 * @return ItemType& the i-th item
 */
template <typename ItemType> ItemType &SLList<ItemType>::get(int i) const {
  Node<ItemType> *p = sentinel->next;
  for (int j = 0; j < i; j++) {
    p = p->next;  
  }
  return p->item;
}

/**
 * Remove and return the first item of the list.
 * For example, list [1,2,3] becomes [2,3] and 1 is returned.
 *
 * @return ItemType the first item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeFirst() {
  Node<ItemType> *p = sentinel->next;
  ItemType temp = p->item;
  
  sentinel->next = p->next;
  delete p;
  count--;
  return temp;
}

/**
 * Remove and return the last item of the list.
 * For example, list [1,2,3] becomes [1,2] and 3 is returned.
 *
 * @return ItemType the last item in the original list before removing
 */
template <typename ItemType> ItemType SLList<ItemType>::removeLast() {

  Node<ItemType> *p1 = sentinel;
  Node<ItemType> *p2 = sentinel;
  ItemType temp;
  p1 = p1->next;

  while (p1->next != nullptr)
  {
    p1 = p1->next;
    p2 = p2->next;
  }
  count = count - 1;
  temp = p1->item;
  delete p1;
  p2->next = nullptr;
  return temp;
}

} // namespace ds

#endif // __SLLIST_H__

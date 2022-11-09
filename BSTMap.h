#ifndef __BSTMAP_H__
#define __BSTMAP_H__

#include <ostream>
#include <sstream>
#include <string>

namespace ds {

template <typename Key, typename Value> class BSTMapNode {
public:
  Key key;
  Value value;
  BSTMapNode *left;
  BSTMapNode *right;

  BSTMapNode(const Key &k, const Value &v, BSTMapNode *l = nullptr,
             BSTMapNode *r = nullptr) {
    key = k;
    value = v;
    left = l;
    right = r;
  }
};

class BSTPrinter;

template <typename Key, typename Value> class BSTMap {
  friend class BSTPrinter;

private:
  BSTMapNode<Key, Value> *root; // Root of the BST

  BSTMapNode<Key, Value> *putHelp(BSTMapNode<Key, Value> *root, const Key &ik,
                                  const Value &val) {
    if (root == nullptr)
      return new BSTMapNode<Key, Value>(ik, val);
    if (ik < root->key)
      root->left = putHelp(root->left, ik, val);
    else if (ik > root->key)
      root->right = putHelp(root->right, ik, val);
    return root;
  }

  bool findHelp(const BSTMapNode<Key, Value> *root, const Key &sk) const {
    if (root == nullptr)
      return false;
    if (sk < root->key)
      return findHelp(root->left, sk);
    if (sk > root->key)
      return findHelp(root->right, sk);
    else
      return true;
  }

  // helper function removeHelp
  BSTMapNode<Key, Value> *removeHelp(BSTMapNode<Key, Value> *root,
                                     const Key &k) {
    // returns the root pointer of the resulting tree after the removal
    // is null
    if (root == nullptr) {
      return root;
    }
    // is greater than
    else if (root->key > k) {
      root->left = removeHelp(root->left, k);
    }
    // is less than
    else if (root->key < k) {
      root->right = removeHelp(root->right, k);
    }
    // is equal to
    else {
      // 3 scenarios
      // no children
      if (root->right == nullptr && root->left == nullptr) {
        delete root;
        return nullptr;
      }

      // one child
      else if (root->right == nullptr || root->left == nullptr) {
        BSTMapNode<Key, Value> *temp;
        if (root->right == nullptr)
          temp = root->left;
        else if (root->left == nullptr)
          temp = root->right;

        delete root;
        return temp;
      }

      // two children
      else if (!(root->right == nullptr || root->left == nullptr)) {
        BSTMapNode<Key, Value> *successor = root;
        successor = successor->right;
        while (successor->left != nullptr){
          successor = successor->left;
        }

        root->key = successor->key;
        root->value = successor->value;
        root->right = removeHelp(root->right, root->key);
        return root;
      }
    }
    // return for computer
    return root;
  }

public:
  BSTMap() { root = nullptr; }
  ~BSTMap() { clear(root); }

  /** Delete all nodes. */
  void clear(BSTMapNode<Key, Value> *root) {
    if (root == nullptr)
      return;
    clear(root->left);
    clear(root->right);
    delete root;
  }

  /**
   * Insert the key-value pair `ik` and `val` to the BSTMap.
   *
   * @param ik The key to insert
   * @param val The value corresponding to the key
   */
  void put(const Key &ik, const Value &val) { root = putHelp(root, ik, val); }

  /**
   * Search for given key in the BSTMap.
   *
   * @param sk The search key
   * @return true if `sk` is in the BSTMap
   */
  bool find(const Key &sk) const { return findHelp(root, sk); }

  Value get(const Key &sk) const;
  void remove(const Key &rk);
};

/**
 * Return the value of the given search key `sk` in the BSTMap.
 */
template <typename Key, typename Value>
Value BSTMap<Key, Value>::get(const Key &sk) const {
  //  assume that `sk` is in the BSTMap.
  // make variable set at root to move through BSTMap
  BSTMapNode<Key, Value> *holder = root;
  // move holder until matches with sk
  while (!(holder->key == sk)) {
    if (sk < holder->key)
      holder = holder->left;
    else if (sk > holder->key)
      holder = holder->right;
  }
  return holder->value;
}

/**
 * Remove `rk` and its corresponding value from the BST.
 */
template <typename Key, typename Value>
void BSTMap<Key, Value>::remove(const Key &rk) {
  // assume that `rk` is in the BSTMap.

  // set root to removeHelp
  root = removeHelp(root, rk);
}

} // namespace ds

#endif // __BSTMAP_H__

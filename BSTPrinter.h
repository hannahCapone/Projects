#ifndef __BSTPRINTER_H__
#define __BSTPRINTER_H__

#include "BSTMap.h"
#include <cmath>
#include <cstddef>
#include <ostream>
#include <string>
#include <vector>

using namespace std;

namespace ds {

class BSTPrinter {
public:
  /**
   * Print the BST level by level, from top to bottom and left to right.
   */
  template <typename Key, typename Value>
  static void print(const BSTMap<Key, Value> &bst, ostream &os) {
    vector<vector<string>> lines;
    vector<BSTMapNode<Key, Value> *> level;
    vector<BSTMapNode<Key, Value> *> next;
    level.push_back(bst.root);
    int nn = 1;
    size_t widest = 0;

    while (nn != 0) {
      vector<string> line;
      nn = 0;

      for (BSTMapNode<Key, Value> *n : level) {
        if (n == nullptr) {
          line.push_back("");

          next.push_back(nullptr);
          next.push_back(nullptr);
        } else {
          std::stringstream ss;
          ss << n->key << ":" << n->value;
          string aa = ss.str();
          line.push_back(aa);
          if (aa.length() > widest)
            widest = aa.length();

          next.push_back(n->left);
          next.push_back(n->right);

          if (n->left != nullptr)
            nn++;
          if (n->right != nullptr)
            nn++;
        }
      }

      if (widest % 2 == 1)
        widest++;

      lines.push_back(line);

      vector<BSTMapNode<Key, Value> *> tmp = level;
      level = next;
      next = tmp;
      next.clear();
    }

    int perpiece = lines.at(lines.size() - 1).size() * (widest + 4);
    for (size_t i = 0; i < lines.size(); i++) {
      vector<string> line = lines.at(i);
      int hpw = (int)floor(perpiece / 2.f) - 1;

      if (i > 0) {
        for (size_t j = 0; j < line.size(); j++) {
          // split node
          char c = ' ';
          if (j % 2 == 1) {
            if (line.at(j - 1) != "") {
              c = '+';
            } else if (j < line.size() && line.at(j) != "") {
              c = '+';
            }
          }
          os << c;

          // lines and spaces
          if (line.at(j) == "") {
            for (int k = 0; k < perpiece - 1; k++) {
              os << " ";
            }
          } else {
            for (int k = 0; k < hpw; k++) {
              os << (j % 2 == 0 ? " " : "─");
            }
            os << (j % 2 == 0 ? "┌" : "┐");
            for (int k = 0; k < hpw; k++) {
              os << (j % 2 == 0 ? "─" : " ");
            }
          }
        }
        // os << "\\n\"\n";
        os << "\n";
      }

      for (size_t j = 0; j < line.size(); j++) {
        string f = line.at(j);
        int gap1 = (int)ceil(perpiece / 2.f - f.length() / 2.f);
        int gap2 = (int)floor(perpiece / 2.f - f.length() / 2.f);
        for (int k = 0; k < gap1; k++) {
          os << " ";
        }
        os << f;
        for (int k = 0; k < gap2; k++) {
          os << " ";
        }
      }
      // os << "\\n\"\n";
      os << "\n";

      perpiece /= 2;
    }
  }
};

} // namespace ds

#endif // __BSTPRINTER_H__
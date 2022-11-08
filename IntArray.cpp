#include "IntArray.h"

namespace ds {

/**
 * Construct a new IntArray object
 *
 * @param len length of the IntArray
 */
IntArray::IntArray(int len) {
  // TODO: initialize data members
  length = len;
  storedArray = new int[len];
}

/**
 * Destroy the IntArray object
 */
IntArray::~IntArray() {
  // TODO: delete the internal array
  delete [] storedArray;
}

/**
 * Reverse the IntArray
 */
void IntArray::reverse() {
  // TODO: reverse `storedArray`
  int *temp = new int[length];
  for (int i = 0; i < length; i++)
  {
    temp[i] = storedArray[length - (i+1)];
  }
  int *oldArr = storedArray;
  storedArray = temp;
  delete [] oldArr;
}

} // namespace ds

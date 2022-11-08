#ifndef __INT_ARRAY_H__
#define __INT_ARRAY_H__

namespace ds {

/** Array of integers. */
class IntArray {
private:
  /** The internal array of integers. */
  int *storedArray;

public:
  /** Length of array. */
  int length;

  explicit IntArray(int len);
  ~IntArray();
  void reverse();

  /** Retrieve the i-th element in IntArray. */
  int &operator[](int i) { return storedArray[i]; }
};

} // namespace ds

#endif // __INT_ARRAY_H__

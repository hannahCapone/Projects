#ifndef __BIGINT_H__
#define __BIGINT_H__

#include "VList.h"
#include <iostream>
#include <string>

namespace ds {

class BigInt {
private:
  VList<int> digits; // stores the digits of the BigInt

public:
  /**
   * Construct a new BigInt object from string.
   *
   * @param val a string of unlimited digits; default is empty string
   */
  explicit BigInt(const std::string &val = "") {
    for (unsigned j = 0; j < val.length(); j++) {
      digits.addLast(val[j] - '0');
    }
  }

  /** Override `<<` to print all digits to os. */
  friend std::ostream &operator<<(std::ostream &os, const BigInt &bi) {
    for (int i = 0; i < bi.digits.size(); i++)
      os << bi.digits.get(i);
    return os;
  }
  // Overload < operator
  friend bool operator<(const BigInt &a, const BigInt &b) {
    if (a.digits.size() > b.digits.size())
      return false;

    else if (a.digits.size() < b.digits.size())
      return true;
   
    //a.digits.size() == b.digits.size();
    for (int i = 0; i < a.digits.size(); i++) {
      if (a.digits.get(i) < b.digits.get(i))
        return true;
      else if  (a.digits.get(i) > b.digits.get(i))
        return false;
    }
    // a == b
    return false;
  }

  inline BigInt operator+(const BigInt &other) const;
  inline BigInt operator-(const BigInt &other) const;
  inline BigInt operator*(const BigInt &other) const;
};

/** Return the *sum* of this BigInt and the `other` BigInt. */
BigInt BigInt::operator+(const BigInt &other) const {
  // Reference: https://en.wikipedia.org/wiki/Addition
  // Example: 456 + 1123 = 1579
  // TODO:
  int carry = 0, sum, d1, d2;
  BigInt res;

  // let i and j represent iterating through the numbers in each digits & other
  int i = digits.size() - 1;
  int j = other.digits.size() - 1;

  // while loop to move through the digits in each BigInt
  while (i >=0 || j >= 0)
  {
    // if i is negative, make d1 equal zero
    if (i < 0)
    {
      d1 = 0;
    }
    // if not, equal to the number in digits
    else
    {
      d1 = digits.get(i);
    }
    // if j is negative, make d2 equal zero
    if (j < 0)
    {  
      d2 = 0;
    }
    // if not, equal to the number in other
    else
    {
      d2 = other.digits.get(j);
    }

    // calculate sum
    sum = d1 + d2 + carry;

    // if sum is one digit, dont carry
    if (sum < 10)
    {
      carry = 0;
    }
    // if sum is two digits, carry and minus ten
    // i.e. sum = 11, carry = 1, sum = 1
    else
    {
      carry = 1;
      sum -= 10;
    }

    // append res with the sum
    res.digits.addFirst(sum);

    // reduce i & j
    i--;
    j--;
  }
  // add carry if neccessary
  if (carry == 1)
    res.digits.addFirst(1);
  
  // finally, return the BigInt result
  return res;
}

/** Return the *absolute difference* between this and the `other` BigInt. */
BigInt BigInt::operator-(const BigInt &other) const {
  // Reference: https://en.wikipedia.org/wiki/Absolute_difference
  // Example: 456 - 1123 = 667
  int dif, d1, d2, borrow = 0;
  BigInt res;
  
  // check if this is less than other
  if (*this < other)
  {
    return other - *this;
  }

  // let i and j represent iterating through the numbers in each digits & other
  int i = digits.size() - 1;
  int j = other.digits.size() - 1;
  
  // while loop to move through the digits in each BigInt
  while (i >=0 || j>=0)
  {
    // if i is negative, make d1 equal zero
    if (i < 0)
    {
      d1 = 0;
    }
    // if not, equal to the number in digits
    else
    {
      d1 = digits.get(i);
    }
    // if j is negative, make d2 equal zero
    if (j < 0)
    {  
      d2 = 0;
    }
    // if not, equal to the number in other
    else
    {
      d2 = other.digits.get(j);
    }

    // calculate difference
    dif = d1 - d2 - borrow;
    
    // if difference is positive 
    if (dif >= 0)
    {
      borrow = 0;
    }
    // if difference is positive
    else
    {
      borrow = 1;
      dif += 10;
    }

    // append res with the
    res.digits.addFirst(dif);

    // reduce i & j
    i--;
    j--;
  }
  // remove leading zeros using remove first
  while (res.digits.get(0) == 0)
  {
    if (res.digits.size() == 1)
    {
      break;
    }
    res.digits.removeFirst();
  }

  // finally, return the BigInt result
  return res;
}
BigInt BigInt::operator*(const BigInt &other) const { 
  int d1, d2;
  int i = digits.size() - 1;
  int j = other.digits.size() - 1;
  int carry = 0;
  int num;

  BigInt res;
  BigInt temp;
  // if bigger
  if (*this < other)
    return other * *this;

  // outside loop
  while (j >= 0)
  {
    // clears the temporary list
    for (int h = temp.digits.size(); h > 0; h--)
    {
      temp.digits.removeFirst();
    }
    // for loop to add zeros
    int y = j;
    while(y < (other.digits.size()-1)){
      temp.digits.addFirst(0);
      y++;
    }
    // inside loop
    while (i >= 0) 
    {
      // impliment digits
      d1 = digits.get(i); // this digit
      d2 = other.digits.get(j); // other digit

      // find num
      num = (d2 * d1) + carry;
      carry = num / 10;
      num = num % 10;

      // add to temp
      temp.digits.addFirst(num);

      // account for carry
      if (i == 0 && carry != 0)
      {
        temp.digits.addFirst(carry);
        carry = 0;
      }

      // final subtract i
      i--;
    }
    // make res add temp
    res = res + temp;
    i = digits.size() - 1;
    // final subtract j
    j--;
  }
  // remove leading zeros
  while (res.digits.get(0) == 0)
  {
    if (res.digits.size() == 1)
    {
      break;
    }
    res.digits.removeFirst();
  }
  // final return
  return res;
}

} // namespace ds

#endif // __BIGINT_H__

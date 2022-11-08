#include "IntArray.h"
#include <cstdlib>
#include <iostream>

int main() {
  // create an array of 10 ints (invoke the constructor)
  ds::IntArray nums(10);

  // randomly add 10 ints to the array
  srand(time(0)); // setting the seed for rand()
  for (int i = 0; i < 10; i++) {
    nums[i] = rand() % 10 + 1; // generating random numbers by rand()
  }

  // print the array
  std::cout << "Original:\t";
  for (int i = 0; i < nums.length; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  // test the reverse function
  nums.reverse();
  std::cout << "Reverse:\t";
  for (int i = 0; i < nums.length; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;

  // now the destructor is invoked

  return 0;
}

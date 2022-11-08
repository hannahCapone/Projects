#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SLList.h"
#include <cstdlib>
#include <doctest.h>

#define SIZE 10

TEST_CASE("SLList") {
  ds::SLList<int> L;

  // randomly add SIZE ints to the array
  int nums[SIZE];
  srand(time(0)); // setting the seed for rand()
  for (int i = SIZE - 1; i >= 0; i--) {
    nums[i] = rand() % 20 + 1; // generating random numbers by rand()
    L.addFirst(nums[i]);
  }

  SUBCASE("get") {
    CHECK(L.get(0) == nums[0]);
    CHECK(L.get(SIZE - 1) == nums[SIZE - 1]);
  }

  SUBCASE("copy constructor") {
    ds::SLList<int> *K = new ds::SLList<int>(L);
    CHECK(L.size() == K->size());
    CHECK(K->get(0) == nums[0]);
    CHECK(K->get(SIZE - 1) == nums[SIZE - 1]);
    delete K; // this should not also delete L
  }

  SUBCASE("removeFirst") {
    CHECK(nums[0] == L.removeFirst());
    CHECK((SIZE - 1) == L.size());
    CHECK(nums[5] == L.get(4));
  }

  SUBCASE("removeLast") {
    CHECK(nums[SIZE - 1] == L.removeLast());
    CHECK((SIZE - 1) == L.size());
    CHECK(nums[5] == L.get(5));
  }
}
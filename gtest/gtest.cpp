// gtest.cpp : Defines the entry point for the console application.
//
 
#include <gtest\gtest.h>


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  auto r = RUN_ALL_TESTS();
  getchar();
  return r;
}


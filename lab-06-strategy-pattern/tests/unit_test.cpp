#include "gtest/gtest.h"

#include "../tests/op_test.hpp"
#include "../tests/rand_test.hpp"
#include "../tests/mult_test.hpp"
#include "../tests/div_test.hpp"
#include "../tests/add_test.hpp"
#include "../tests/sub_test.hpp"
#include "../tests/pow_test.hpp"
#include "../tests/vector_container_test.hpp"
#include "../tests/bubble_sort_test.hpp"
#include "../tests/selection_sort_test.hpp"
#include "../tests/list_container_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

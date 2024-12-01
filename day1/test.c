#include "../subprojects/unity/src/unity.h"
#include "solution.h"
#include <stdbool.h>
#include <stdio.h>

void test_single_entry(void) {
  char *buf = "1 4";
  FILE *stream = fmemopen(buf, 4, "r");
  int expected = 3;
  int actual = process_list(stream);
  TEST_ASSERT_EQUAL(expected, actual);
}

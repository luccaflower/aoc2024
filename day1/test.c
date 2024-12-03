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
void test_three_entries_different_order(void) {
  char *buf = "1 4\n4 3\n2 2\0";
  FILE *stream = fmemopen(buf, 12, "r");
  int expected = 2;
  int actual = process_list(stream);
  TEST_ASSERT_EQUAL(expected, actual);
}

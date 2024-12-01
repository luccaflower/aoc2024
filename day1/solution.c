#include <stdio.h>
int process_list(FILE *input) {
  int nread = 0;
  char line[10] = {0};
  while ((nread = getline(line, 10, input))) {
  }
}

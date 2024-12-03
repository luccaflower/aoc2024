#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE *input = fopen(argv[1], "r");
  if (!input) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  int result = process_list(input);
  if (result == -1)
    exit(EXIT_FAILURE);
  printf("result: %d\n", result);
  return EXIT_SUCCESS;
}

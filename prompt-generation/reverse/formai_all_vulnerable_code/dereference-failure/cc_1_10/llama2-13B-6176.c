//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define MAX_STR_LEN 1024

void init_strings(char** strs, int num_strs) {
  int i;
  for (i = 0; i < num_strs; i++) {
    strs[i] = malloc(MAX_STR_LEN * sizeof(char));
    srand(time(NULL) * (i + 1));
    int len = rand() % MAX_STR_LEN;
    for (int j = 0; j < len; j++) {
      strs[i][j] = 'a' + (rand() % 26);
    }
    strs[i][len] = '\0';
  }
}

void print_strings(char** strs, int num_strs) {
  int i;
  for (i = 0; i < num_strs; i++) {
    printf("%s\n", strs[i]);
  }
}

void shuffle_strings(char** strs, int num_strs) {
  int i, j;
  for (i = 0; i < num_strs; i++) {
    for (j = i + 1; j < num_strs; j++) {
      char temp = strs[i][0];
      strs[i][0] = strs[j][0];
      strs[j][0] = temp;
    }
  }
}

int main() {
  int num_strs = 5;
  char** strs = malloc(num_strs * sizeof(char*));
  init_strings(strs, num_strs);

  shuffle_strings(strs, num_strs);

  print_strings(strs, num_strs);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void beautify(char **arr, int n) {
  int i, j, k, l, maxLen = 0;
  for (i = 0; i < n; i++) {
    l = strlen(arr[i]);
    if (l > maxLen) {
      maxLen = l;
    }
  }
  for (i = 0; i < n; i++) {
    j = strlen(arr[i]);
    k = maxLen - j;
    arr[i] = realloc(arr[i], maxLen);
    memset(arr[i] + j, ' ', k);
  }
}

int main() {
  char **arr = NULL;
  int n = 0;

  scanf("Enter the number of strings: ", &n);

  arr = malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    arr[i] = malloc(100);
  }

  for (int i = 0; i < n; i++) {
    scanf("Enter string %d: ", i + 1);
    getline(arr[i], 100, stdin);
  }

  beautify(arr, n);

  for (int i = 0; i < n; i++) {
    printf("String %d: %s\n", i + 1, arr[i]);
  }

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }

  free(arr);

  return 0;
}
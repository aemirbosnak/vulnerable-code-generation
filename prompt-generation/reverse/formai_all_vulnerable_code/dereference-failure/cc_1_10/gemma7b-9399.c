//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void translate(char **arr, int n) {
  for (int i = 0; i < n; i++) {
    switch (*arr[i]) {
      case 'a':
        *arr[i] = 'A';
        break;
      case 'e':
        *arr[i] = 'E';
        break;
      case 'i':
        *arr[i] = 'I';
        break;
      case 'o':
        *arr[i] = 'O';
        break;
      case 'u':
        *arr[i] = 'U';
        break;
    }
  }
}

int main() {
  char **arr = NULL;
  int n = 0;

  printf("Enter the number of words: ");
  scanf("%d", &n);

  arr = malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    arr[i] = malloc(20 * sizeof(char));
  }

  for (int i = 0; i < n; i++) {
    printf("Enter the word: ");
    scanf("%s", arr[i]);
  }

  translate(arr, n);

  for (int i = 0; i < n; i++) {
    printf("The translated word is: %s\n", arr[i]);
  }

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }

  free(arr);

  return 0;
}
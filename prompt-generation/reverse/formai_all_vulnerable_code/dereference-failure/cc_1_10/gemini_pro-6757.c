//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int enigma(int *arr, int n, int target);
char *obfuscate(char *str);
void swap(int *a, int *b);
void shuffle(int *arr, int n);

int main() {
  srand(time(NULL));

  int arr[] = {1, 3, 5, 7, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 5;

  char *enigma_str = "gorgonshred";
  char *obfuscated_str = obfuscate(enigma_str);

  printf("Original array: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  printf("Target element: %d\n", target);
  int result = enigma(arr, n, target);
  if (result == -1)
    printf("Target not found");
  else
    printf("Target found at index %d\n", result);

  printf("Original string: %s\n", enigma_str);
  printf("Obfuscated string: %s\n", obfuscated_str);

  return 0;
}

int enigma(int *arr, int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target)
      return i;
  }
  return -1;
}

char *obfuscate(char *str) {
  int len = strlen(str);

  char *obfuscated = malloc(len + 1);

  for (int i = 0; i < len; i++) {
    int index = rand() % len;
    obfuscated[i] = str[index];
  }

  obfuscated[len] = '\0';

  return obfuscated;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void shuffle(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int r = rand() % n;
    swap(&arr[i], &arr[r]);
  }
}
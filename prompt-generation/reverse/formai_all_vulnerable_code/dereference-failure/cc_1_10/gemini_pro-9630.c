//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom comparator function for strings
int compare_strings(const char *a, const char *b) {
  return strcmp(a, b);
}

// Define a custom comparator function for integers
int compare_integers(const int *a, const int *b) {
  return *a - *b;
}

// Define a custom comparator function for doubles
int compare_doubles(const double *a, const double *b) {
  return *a - *b;
}

// Define a generic sorting function that takes a comparator function as an argument
void sort(void *array, size_t n, size_t size, int (*comparator)(const void *, const void *)) {
  for (size_t i = 0; i < n - 1; i++) {
    for (size_t j = i + 1; j < n; j++) {
      if (comparator((char *)array + i * size, (char *)array + j * size) > 0) {
        void *temp = malloc(size);
        memcpy(temp, (char *)array + i * size, size);
        memcpy((char *)array + i * size, (char *)array + j * size, size);
        memcpy((char *)array + j * size, temp, size);
        free(temp);
      }
    }
  }
}

int main() {
  // Declare an array of strings
  char *strings[] = {"Hello", "World", "Brave", "New", "World"};

  // Sort the array of strings using the custom comparator function
  sort(strings, 5, sizeof(char *), compare_strings);

  // Print the sorted array of strings
  for (int i = 0; i < 5; i++) {
    printf("%s\n", strings[i]);
  }

  // Declare an array of integers
  int integers[] = {1, 3, 2, 5, 4};

  // Sort the array of integers using the custom comparator function
  sort(integers, 5, sizeof(int), compare_integers);

  // Print the sorted array of integers
  for (int i = 0; i < 5; i++) {
    printf("%d\n", integers[i]);
  }

  // Declare an array of doubles
  double doubles[] = {1.2, 3.4, 2.5, 5.6, 4.7};

  // Sort the array of doubles using the custom comparator function
  sort(doubles, 5, sizeof(double), compare_doubles);

  // Print the sorted array of doubles
  for (int i = 0; i < 5; i++) {
    printf("%f\n", doubles[i]);
  }

  return 0;
}
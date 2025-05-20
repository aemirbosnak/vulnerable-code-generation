//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a function to compare two strings.
int compare(const void *a, const void *b) {
  // Cast the void pointers to strings.
  char *s1 = (char *)a;
  char *s2 = (char *)b;

  // Compare the strings.
  return strcmp(s1, s2);
}

// Declare a function to print an array of strings.
void print_array(char **array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%s\n", array[i]);
  }
}

// Declare a function to sort an array of strings.
void sort_array(char **array, int size) {
  // Use the qsort function to sort the array.
  qsort(array, size, sizeof(char *), compare);
}

// Declare a function to generate a random string.
char *generate_random_string(int length) {
  // Allocate memory for the string.
  char *string = malloc(length + 1);

  // Generate a random string.
  for (int i = 0; i < length; i++) {
    string[i] = (char)(rand() % 26 + 97);
  }

  // Terminate the string with a null character.
  string[length] = '\0';

  // Return the string.
  return string;
}

// Declare a function to generate an array of random strings.
char **generate_array_of_random_strings(int size, int length) {
  // Allocate memory for the array.
  char **array = malloc(size * sizeof(char *));

  // Generate an array of random strings.
  for (int i = 0; i < size; i++) {
    array[i] = generate_random_string(length);
  }

  // Return the array.
  return array;
}

// Declare a function to free an array of strings.
void free_array_of_strings(char **array, int size) {
  // Free each string in the array.
  for (int i = 0; i < size; i++) {
    free(array[i]);
  }

  // Free the array itself.
  free(array);
}

// Declare a function to test the sorting algorithm.
void test_sorting_algorithm() {
  // Generate an array of random strings.
  char **array = generate_array_of_random_strings(10, 10);

  // Print the unsorted array.
  printf("Unsorted array:\n");
  print_array(array, 10);

  // Sort the array.
  sort_array(array, 10);

  // Print the sorted array.
  printf("Sorted array:\n");
  print_array(array, 10);

  // Free the array.
  free_array_of_strings(array, 10);
}

// Declare a function to main.
int main() {
  // Test the sorting algorithm.
  test_sorting_algorithm();

  return 0;
}
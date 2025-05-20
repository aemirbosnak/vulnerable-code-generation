//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ARRAY_SIZE 100
#define MAX_STR_LEN 50

// Declare a dynamic array to store the names
char **names;

// Declare a dynamic array to store the frequencies
int **frequencies;

// Function to check if the name exists in the list
int check_name(char *name) {
  int i;
  for (i = 0; i < MAX_ARRAY_SIZE; i++) {
    if (strcmp(names[i], name) == 0) {
      return 1;
    }
  }
  return 0;
}

// Function to add a name to the list
void add_name(char *name) {
  int i;
  for (i = 0; i < MAX_ARRAY_SIZE; i++) {
    if (names[i] == NULL) {
      break;
    }
  }
  if (i == MAX_ARRAY_SIZE) {
    // If the list is full, reallocate it
    char **new_names = realloc(names, (i + 1) * sizeof(char *));
    if (new_names == NULL) {
      printf("Error: unable to reallocate memory\n");
      exit(1);
    }
    names = new_names;
  }
  names[i] = strdup(name);
  frequencies = realloc(frequencies, (i + 1) * sizeof(int *));
  if (frequencies == NULL) {
    printf("Error: unable to reallocate memory\n");
    exit(1);
  }
  frequencies[i] = calloc(1, sizeof(int));
  if (frequencies[i] == NULL) {
    printf("Error: unable to allocate memory\n");
    exit(1);
  }
  frequencies[i][0] = 1;
}

// Function to print the list of names and their frequencies
void print_list() {
  int i;
  for (i = 0; i < MAX_ARRAY_SIZE; i++) {
    if (names[i] != NULL) {
      printf("%s (%d)\n", names[i], frequencies[i][0]);
    }
  }
}

int main() {
  srand(time(NULL));

  // Initialize the dynamic arrays
  names = calloc(MAX_ARRAY_SIZE, sizeof(char *));
  frequencies = calloc(MAX_ARRAY_SIZE, sizeof(int *));

  // Add some names to the list
  add_name("Alice");
  add_name("Bob");
  add_name("Charlie");
  add_name("David");
  add_name("Eve");

  // Search for a name in the list
  if (check_name("Alice")) {
    printf("Alice found\n");
  } else {
    printf("Alice not found\n");
  }

  // Print the list of names and their frequencies
  print_list();

  return 0;
}
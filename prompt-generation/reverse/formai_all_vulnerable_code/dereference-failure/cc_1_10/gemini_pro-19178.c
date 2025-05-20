//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the two lovers
typedef struct {
  char *name;
  int age;
} Lover;

// Create a new lover
Lover *create_lover(char *name, int age) {
  Lover *lover = malloc(sizeof(Lover));
  lover->name = strdup(name);
  lover->age = age;
  return lover;
}

// Free a lover
void free_lover(Lover *lover) {
  free(lover->name);
  free(lover);
}

// Print a lover
void print_lover(Lover *lover) {
  printf("Name: %s\n", lover->name);
  printf("Age: %d\n", lover->age);
}

// Compare two lovers
int compare_lovers(Lover *lover1, Lover *lover2) {
  int result = strcmp(lover1->name, lover2->name);
  if (result == 0) {
    result = lover1->age - lover2->age;
  }
  return result;
}

// Main function
int main() {
  // Create Romeo and Juliet
  Lover *romeo = create_lover("Romeo", 16);
  Lover *juliet = create_lover("Juliet", 14);

  // Print Romeo and Juliet
  print_lover(romeo);
  print_lover(juliet);

  // Compare Romeo and Juliet
  int result = compare_lovers(romeo, juliet);
  if (result == 0) {
    printf("Romeo and Juliet are the same person!\n");
  } else if (result < 0) {
    printf("Romeo is younger than Juliet!\n");
  } else {
    printf("Romeo is older than Juliet!\n");
  }

  // Free Romeo and Juliet
  free_lover(romeo);
  free_lover(juliet);

  return 0;
}
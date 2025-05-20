//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings to compare
#define MAX_STRING_LENGTH 100

// Define the cost of insertion, deletion, or substitution
#define COST_INSERT 1
#define COST_DELETE 1
#define COST_SUBSTITUTE 1

// Calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
  // Get the lengths of the strings
  int len1 = strlen(s1);
  int len2 = strlen(s2);

  // Create a matrix to store the distances
  int matrix[len1 + 1][len2 + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i * COST_DELETE;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j * COST_INSERT;
  }

  // Calculate the distances for the remaining cells
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      // Get the cost of the three operations
      int cost_insert = matrix[i][j - 1] + COST_INSERT;
      int cost_delete = matrix[i - 1][j] + COST_DELETE;
      int cost_substitute = matrix[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : COST_SUBSTITUTE);

      // Choose the operation with the lowest cost
      matrix[i][j] = fmin(cost_insert, fmin(cost_delete, cost_substitute));
    }
  }

  // Return the distance between the two strings
  return matrix[len1][len2];
}

// Print the usage of the program
void print_usage() {
  printf("Usage: levenshtein_distance <string1> <string2>\n");
  printf("Calculates the Levenshtein distance between two strings.\n");
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the number of arguments is correct
  if (argc != 3) {
    print_usage();
    return 1;
  }

  // Get the two strings from the command line
  char *s1 = argv[1];
  char *s2 = argv[2];

  // Calculate the Levenshtein distance between the two strings
  int distance = levenshtein_distance(s1, s2);

  // Print the distance to the console
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

  return 0;
}
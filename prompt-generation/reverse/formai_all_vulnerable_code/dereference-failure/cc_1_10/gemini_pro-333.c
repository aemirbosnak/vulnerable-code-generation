//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the cost of insertion, deletion, and substitution
#define INSERT_COST 1
#define DELETE_COST 1
#define SUBSTITUTE_COST 1

// Calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
  // Get the lengths of the two strings
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  // Create a matrix to store the Levenshtein distances
  int matrix[len1 + 1][len2 + 1];

  // Initialize the first row and column of the matrix to the lengths of the two strings
  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances for the rest of the matrix
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = fmin(fmin(matrix[i - 1][j] + DELETE_COST, matrix[i][j - 1] + INSERT_COST), matrix[i - 1][j - 1] + SUBSTITUTE_COST);
      }
    }
  }

  // Return the Levenshtein distance
  return matrix[len1][len2];
}

// Print the Levenshtein distance between two strings
void print_levenshtein_distance(const char *str1, const char *str2) {
  int distance = levenshtein_distance(str1, str2);
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);
}

// Get a string from the user
char *get_string(const char *prompt) {
  char *str = NULL;
  size_t len = 0;
  printf("%s", prompt);
  getline(&str, &len, stdin);
  return str;
}

// Main function
int main() {
  // Get two strings from the user
  char *str1 = get_string("Enter the first string: ");
  char *str2 = get_string("Enter the second string: ");

  // Print the Levenshtein distance between the two strings
  print_levenshtein_distance(str1, str2);

  // Free the memory allocated for the strings
  free(str1);
  free(str2);

  return 0;
}
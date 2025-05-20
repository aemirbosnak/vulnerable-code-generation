//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input strings
#define MAX_STRING_SIZE 100

// Calculate the Levenshtein distance between two strings
int levenshteinDistance(char *s1, char *s2) {
  // Create a matrix to store the Levenshtein distance between the prefixes of the two strings
  int matrix[MAX_STRING_SIZE + 1][MAX_STRING_SIZE + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= strlen(s1); i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= strlen(s2); j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distance between the prefixes of the two strings
  for (int i = 1; i <= strlen(s1); i++) {
    for (int j = 1; j <= strlen(s2); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = 1 + fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
      }
    }
  }

  // Return the Levenshtein distance between the two strings
  return matrix[strlen(s1)][strlen(s2)];
}

// Get the input strings from the user
char* getString(char* prompt) {
  char* input = malloc(MAX_STRING_SIZE + 1);
  printf("%s", prompt);
  scanf("%s", input);
  return input;
}

// Print the Levenshtein distance between the two strings
void printDistance(char* s1, char* s2, int distance) {
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);
}

// Main function
int main() {
  // Get the input strings from the user
  char* s1 = getString("Enter the first string: ");
  char* s2 = getString("Enter the second string: ");

  // Calculate the Levenshtein distance between the two strings
  int distance = levenshteinDistance(s1, s2);

  // Print the Levenshtein distance between the two strings
  printDistance(s1, s2, distance);

  // Free the allocated memory
  free(s1);
  free(s2);

  return 0;
}
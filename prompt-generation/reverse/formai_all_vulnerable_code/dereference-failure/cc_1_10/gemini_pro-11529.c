//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new string with the given length
char *createString(int length) {
  char *string = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = 'a';
  }
  string[length] = '\0';
  return string;
}

// Function to find the longest common substring of two strings
char *longestCommonSubstring(char *string1, char *string2) {
  int length1 = strlen(string1);
  int length2 = strlen(string2);

  // Create a matrix to store the lengths of the longest common substrings of the two strings
  int **matrix = malloc(length1 * sizeof(int *));
  for (int i = 0; i < length1; i++) {
    matrix[i] = malloc(length2 * sizeof(int));
  }

  // Initialize the first row and column of the matrix
  for (int i = 0; i < length1; i++) {
    matrix[i][0] = 0;
  }
  for (int j = 0; j < length2; j++) {
    matrix[0][j] = 0;
  }

  // Fill in the rest of the matrix
  for (int i = 1; i < length1; i++) {
    for (int j = 1; j < length2; j++) {
      if (string1[i] == string2[j]) {
        matrix[i][j] = matrix[i - 1][j - 1] + 1;
      } else {
        matrix[i][j] = 0;
      }
    }
  }

  // Find the longest common substring
  int max_length = 0;
  int max_i = 0;
  int max_j = 0;
  for (int i = 0; i < length1; i++) {
    for (int j = 0; j < length2; j++) {
      if (matrix[i][j] > max_length) {
        max_length = matrix[i][j];
        max_i = i;
        max_j = j;
      }
    }
  }

  // Create a new string to store the longest common substring
  char *substring = malloc(max_length + 1);
  for (int i = max_i - max_length + 1; i <= max_i; i++) {
    substring[i - (max_i - max_length + 1)] = string1[i];
  }
  substring[max_length] = '\0';

  // Free the matrix
  for (int i = 0; i < length1; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return substring;
}

int main() {
  // Create two strings
  char *string1 = createString(10);
  char *string2 = createString(15);

  // Find the longest common substring of the two strings
  char *substring = longestCommonSubstring(string1, string2);

  // Print the longest common substring
  printf("The longest common substring is: %s\n", substring);

  // Free the strings
  free(string1);
  free(string2);
  free(substring);

  return 0;
}
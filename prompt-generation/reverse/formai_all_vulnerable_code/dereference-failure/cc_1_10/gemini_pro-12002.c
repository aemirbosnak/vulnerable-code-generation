//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Generate a random string of a given length.
char *randomString(int length) {
  char *string = (char *)malloc(length + 1);
  for (int i = 0; i < length; i++) {
    string[i] = (rand() % 26) + 'a';
  }
  string[length] = '\0';
  return string;
}

// Calculate the Levenshtein distance between two strings.
int levenshteinDistance(char *string1, char *string2) {
  int length1 = strlen(string1);
  int length2 = strlen(string2);

  // Create a matrix to store the Levenshtein distances.
  int matrix[length1 + 1][length2 + 1];

  // Initialize the first row and column of the matrix.
  for (int i = 0; i <= length1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= length2; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distance for each cell in the matrix.
  for (int i = 1; i <= length1; i++) {
    for (int j = 1; j <= length2; j++) {
      int cost = (string1[i - 1] == string2[j - 1]) ? 0 : 1;
      matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
    }
  }

  // Return the Levenshtein distance between the two strings.
  return matrix[length1][length2];
}

// Find the minimum of three integers.
int min(int a, int b, int c) {
  int min = a;
  if (b < min) {
    min = b;
  }
  if (c < min) {
    min = c;
  }
  return min;
}

// Print a usage message and exit.
void usage() {
  printf("Usage: levenshtein <string1> <string2>\n");
  exit(1);
}

// Main function.
int main(int argc, char **argv) {
  // Check the number of arguments.
  if (argc != 3) {
    usage();
  }

  // Get the two strings from the command line.
  char *string1 = argv[1];
  char *string2 = argv[2];

  // Calculate the Levenshtein distance between the two strings.
  int distance = levenshteinDistance(string1, string2);

  // Print the Levenshtein distance.
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", string1, string2, distance);

  return 0;
}
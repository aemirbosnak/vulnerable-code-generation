//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

int main(int argc, char** argv) {
  if (argc < 3) {
    printf("Usage: %s <string1> <string2>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char word1[MAX_WORD_LEN];
  strcpy(word1, argv[1]);

  char word2[MAX_WORD_LEN];
  strcpy(word2, argv[2]);

  int len1 = strlen(word1);
  int len2 = strlen(word2);

  int** matrix = (int**) malloc(sizeof(int*) * (len1 + 1));
  for (int i = 0; i < len1 + 1; i++) {
    matrix[i] = (int*) malloc(sizeof(int) * (len2 + 1));
  }

  for (int i = 0; i < len1 + 1; i++) {
    matrix[i][0] = i;
  }

  for (int j = 0; j < len2 + 1; j++) {
    matrix[0][j] = j;
  }

  for (int i = 1; i < len1 + 1; i++) {
    for (int j = 1; j < len2 + 1; j++) {
      int cost = tolower(word1[i - 1]) == tolower(word2[j - 1]) ? 0 : 1;
      matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
    }
  }

  printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", word1, word2, matrix[len1][len2]);

  for (int i = 0; i < len1 + 1; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return EXIT_SUCCESS;
}
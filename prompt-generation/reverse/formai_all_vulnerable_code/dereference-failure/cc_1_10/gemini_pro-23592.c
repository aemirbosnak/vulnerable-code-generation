//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a word
typedef struct word {
  char *str;
  int count;
} word_t;

// Function to compare two words
int compare_words(const void *a, const void *b) {
  word_t *wa = (word_t *)a;
  word_t *wb = (word_t *)b;

  return strcmp(wa->str, wb->str);
}

// Function to count the occurrences of each word in a text file
int count_words(char *filename, word_t **words, int *nwords) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return -1;
  }

  // Allocate memory for the words array
  *words = malloc(sizeof(word_t) * 1000);
  if (*words == NULL) {
    fprintf(stderr, "Error allocating memory for words array\n");
    fclose(fp);
    return -1;
  }

  // Read the text file and count the occurrences of each word
  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    char *token = strtok(buffer, " ");
    while (token != NULL) {
      int found = 0;

      // Check if the word is already in the words array
      for (int i = 0; i < *nwords; i++) {
        if (strcmp((*words)[i].str, token) == 0) {
          (*words)[i].count++;
          found = 1;
          break;
        }
      }

      // If the word is not in the words array, add it
      if (!found) {
        (*words)[*nwords].str = strdup(token);
        (*words)[*nwords].count = 1;
        (*nwords)++;
      }

      token = strtok(NULL, " ");
    }
  }

  fclose(fp);

  return 0;
}

// Function to print the words and their counts
void print_words(word_t *words, int nwords) {
  // Sort the words in alphabetical order
  qsort(words, nwords, sizeof(word_t), compare_words);

  // Print the words and their counts
  for (int i = 0; i < nwords; i++) {
    printf("%s: %d\n", words[i].str, words[i].count);
  }
}

int main() {
  word_t *words = NULL;
  int nwords = 0;

  // Count the occurrences of each word in the text file
  if (count_words("text.txt", &words, &nwords) != 0) {
    return -1;
  }

  // Print the words and their counts
  print_words(words, nwords);

  // Free the memory allocated for the words array
  for (int i = 0; i < nwords; i++) {
    free(words[i].str);
  }
  free(words);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a macro for data mining
#define DM(x) printf("%d ", x);

// Function to find the maximum frequency of a word in a text
int findMaxFreq(char *text) {
  // Create a dictionary to store word frequencies
  int **dict = (int **)malloc(100 * sizeof(int *));
  for (int i = 0; i < 100; i++) {
    dict[i] = (int *)malloc(100 * sizeof(int));
  }

  // Split the text into words
  char *words = strtok(text, " ");

  // Iterate over the words and update the dictionary
  while (words) {
    int wordLen = strlen(words);
    for (int i = 0; i < wordLen; i++) {
      char word = words[i];
      if (dict[wordLen][word] == 0) {
        dict[wordLen][word] = 1;
      } else {
        dict[wordLen][word]++;
      }
    }
    words = strtok(NULL, " ");
  }

  // Find the maximum frequency
  int maxFreq = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (dict[i][j] > maxFreq) {
        maxFreq = dict[i][j];
      }
    }
  }

  // Free the memory
  for (int i = 0; i < 100; i++) {
    free(dict[i]);
  }
  free(dict);

  return maxFreq;
}

int main() {
  char *text = "This is a text with many words. The word 'is' is repeated twice. The word 'a' is also repeated twice.";

  int maxFreq = findMaxFreq(text);

  DM(maxFreq);

  return 0;
}
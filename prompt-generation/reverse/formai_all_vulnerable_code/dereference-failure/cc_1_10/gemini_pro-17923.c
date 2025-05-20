//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: medieval
// A Text Summarizer of Yesteryear

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bestow the Text upon us
char *ReceiveText() {
  printf("\nPray, good sir or lady, bestow upon me the text thou wishest summarized.\n");
  char *text = malloc(1024);
  fgets(text, 1024, stdin);
  return text;
}

// A Clerkly Function to Extract Meaningful Words
char **ExtractWords(char *text) {
  int length = strlen(text);
  char **words = malloc(length * sizeof(char *));
  char *word = strtok(text, " ,.-");
  int i = 0;
  while (word != NULL) {
    words[i++] = word;
    word = strtok(NULL, " ,.-");
  }
  words[i] = NULL;
  return words;
}

// A Tally of Words
int *CountWords(char **words) {
  int *counts = malloc(128 * sizeof(int));
  memset(counts, 0, 128 * sizeof(int));
  int i = 0;
  while (words[i] != NULL) {
    counts[words[i][0]]++;
    i++;
  }
  return counts;
}

// Present the Summary in Royal Style
void DisplaySummary(int *counts) {
  printf("\nHark! The Summary:\n");
  for (int i = 'a'; i <= 'z'; i++) {
    if (counts[i] > 0) {
      printf("%c: %d\n", i, counts[i]);
    }
  }
}

// The Grand Summarizer
int main() {
  char *text = ReceiveText();
  char **words = ExtractWords(text);
  int *counts = CountWords(words);
  DisplaySummary(counts);
  free(text);
  free(words);
  free(counts);
  return 0;
}
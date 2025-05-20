//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {
  // Get the input text from the user.
  char inputText[MAX_LENGTH];
  printf("Enter the text you want to summarize: ");
  fgets(inputText, MAX_LENGTH, stdin);

  // Tokenize the input text into an array of words.
  char *tokens[MAX_LENGTH];
  int numTokens = 0;
  char *token = strtok(inputText, " ");
  while (token != NULL) {
    tokens[numTokens++] = token;
    token = strtok(NULL, " ");
  }

  // Count the number of occurrences of each word in the input text.
  int wordCounts[MAX_LENGTH];
  for (int i = 0; i < numTokens; i++) {
    wordCounts[i] = 0;
    for (int j = 0; j < numTokens; j++) {
      if (strcmp(tokens[i], tokens[j]) == 0) {
        wordCounts[i]++;
      }
    }
  }

  // Find the most frequently occurring words in the input text.
  int maxCount = 0;
  int maxCountIndex = 0;
  for (int i = 0; i < numTokens; i++) {
    if (wordCounts[i] > maxCount) {
      maxCount = wordCounts[i];
      maxCountIndex = i;
    }
  }

  // Generate a summary of the input text.
  char summary[MAX_LENGTH];
  strcpy(summary, tokens[maxCountIndex]);
  for (int i = 0; i < numTokens; i++) {
    if (wordCounts[i] >= maxCount / 2) {
      strcat(summary, " ");
      strcat(summary, tokens[i]);
    }
  }

  // Print the summary to the user.
  printf("Summary: %s\n", summary);

  return 0;
}
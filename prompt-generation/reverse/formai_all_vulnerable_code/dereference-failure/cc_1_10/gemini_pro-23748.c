//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to summarize a text
char *summarizeText(char *text) {
  // Check if the text is valid
  if (text == NULL || strlen(text) == 0) {
    return NULL;
  }

  // Create an array to store the summary
  int summarySize = strlen(text) / 10;
  char *summary = malloc(summarySize + 1);
  if (summary == NULL) {
    return NULL;
  }

  // Tokenize the text into sentences
  char **sentences = malloc(strlen(text) * sizeof(char *));
  if (sentences == NULL) {
    free(summary);
    return NULL;
  }
  int numSentences = 0;
  char *token = strtok(text, ".?!");
  while (token != NULL) {
    sentences[numSentences++] = token;
    token = strtok(NULL, ".?!");
  }

  // Calculate the score of each sentence
  int *scores = malloc(numSentences * sizeof(int));
  if (scores == NULL) {
    for (int i = 0; i < numSentences; i++) {
      free(sentences[i]);
    }
    free(sentences);
    free(summary);
    return NULL;
  }
  for (int i = 0; i < numSentences; i++) {
    scores[i] = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      scores[i]++;
      word = strtok(NULL, " ");
    }
  }

  // Select the sentences with the highest scores
  int numSummarySentences = summarySize / 20;
  int *selectedSentences = malloc(numSummarySentences * sizeof(int));
  if (selectedSentences == NULL) {
    for (int i = 0; i < numSentences; i++) {
      free(sentences[i]);
    }
    free(sentences);
    free(summary);
    free(scores);
    return NULL;
  }
  for (int i = 0; i < numSummarySentences; i++) {
    int maxScore = -1;
    int maxSentenceIndex = -1;
    for (int j = 0; j < numSentences; j++) {
      if (scores[j] > maxScore && selectedSentences[j] == 0) {
        maxScore = scores[j];
        maxSentenceIndex = j;
      }
    }
    selectedSentences[maxSentenceIndex] = 1;
  }

  // Create the summary
  int summaryIndex = 0;
  for (int i = 0; i < numSentences; i++) {
    if (selectedSentences[i] == 1) {
      strcpy(summary + summaryIndex, sentences[i]);
      summaryIndex += strlen(sentences[i]);
      summary[summaryIndex++] = ' ';
    }
  }
  summary[summaryIndex - 1] = '\0';

  // Free the allocated memory
  for (int i = 0; i < numSentences; i++) {
    free(sentences[i]);
  }
  free(sentences);
  free(scores);
  free(selectedSentences);

  return summary;
}

// Function to print the summary
void printSummary(char *summary) {
  printf("Summary: %s\n", summary);
}

// Main function
int main() {
  // Get the text from the user
  printf("Enter the text to be summarized: ");
  char *text = malloc(1024);
  if (text == NULL) {
    printf("Error: Could not allocate memory for the text.\n");
    return 1;
  }
  gets(text);

  // Summarize the text
  char *summary = summarizeText(text);
  if (summary == NULL) {
    printf("Error: Could not summarize the text.\n");
    return 1;
  }

  // Print the summary
  printSummary(summary);

  // Free the allocated memory
  free(text);
  free(summary);

  return 0;
}
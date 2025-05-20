//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A surrealist text summarizer
int main() {
  // Declare variables
  char *text;
  int length;
  int sentences;
  char **summary;
  int i;

  // Get the text from the user
  printf("Enter the text you want to summarize: ");
  text = malloc(1000);
  gets(text);

  // Calculate the length of the text
  length = strlen(text);

  // Calculate the number of sentences in the text
  sentences = 0;
  for (i = 0; i < length; i++) {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
      sentences++;
    }
  }

  // Allocate memory for the summary
  summary = malloc(sentences * sizeof(char *));

  // Tokenize the text into sentences
  char *token = strtok(text, ".!?");
  while (token != NULL) {
    summary[i++] = token;
    token = strtok(NULL, ".!?");
  }

  // Print the summary
  printf("Summary:\n");
  for (i = 0; i < sentences; i++) {
    printf("%s\n", summary[i]);
  }

  // Free the memory
  free(text);
  free(summary);

  return 0;
}
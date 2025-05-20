//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configuration
#define MAX_INPUT_SIZE 512
#define MAX_OUTPUT_SIZE 256

// Function prototypes
void summarize(char *input, char *output);

int main() {
  char input[MAX_INPUT_SIZE];
  char output[MAX_OUTPUT_SIZE];

  // Prompt the user for input
  printf("Whoa! Enter some text to summarize: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Summarize the input
  summarize(input, output);

  // Print the output
  printf("Boom! Here's the summary: %s", output);

  return 0;
}

void summarize(char *input, char *output) {
  // Validate input
  if (!input || !output) {
    printf("Whoa there! Invalid input or output.");
    return;
  }

  // Initialize output
  output[0] = '\0';

  // Tokenize the input
  char *tokens[MAX_INPUT_SIZE];
  int num_tokens = 0;
  char *token = strtok(input, " ");
  while (token) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Remove stop words
  char *stop_words[] = {"the", "a", "an", "and", "of", "in", "to", "is", "are"};
  int num_stop_words = sizeof(stop_words) / sizeof(char *);
  for (int i = 0; i < num_tokens; i++) {
    for (int j = 0; j < num_stop_words; j++) {
      if (!strcmp(tokens[i], stop_words[j])) {
        tokens[i] = NULL;
        break;
      }
    }
  }

  // Stem the tokens
  for (int i = 0; i < num_tokens; i++) {
    if (tokens[i]) {
      // Stemming algorithm goes here
      // For this example, we'll just remove the last character
      int len = strlen(tokens[i]);
      tokens[i][len - 1] = '\0';
    }
  }

  // Generate the summary
  int num_summary_words = num_tokens / 2;
  for (int i = 0; i < num_summary_words; i++) {
    if (tokens[i]) {
      strcat(output, tokens[i]);
      strcat(output, " ");
    }
  }

  // Trim trailing whitespace
  int len = strlen(output);
  if (output[len - 1] == ' ') {
    output[len - 1] = '\0';
  }
}
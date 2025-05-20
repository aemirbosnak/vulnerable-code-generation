//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

void summarize(char input[], char output[], int summary_len);

int main(void)
{
  printf("Welcome to the multiplayer text summarizer!\n\n");

  while (1)
  {
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
    int summary_len;

    printf("Player 1, enter some text to summarize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    printf("Player 2, how many sentences should the summary contain? ");
    scanf("%d", &summary_len);
    getchar();  // Consume lingering newline character

    summarize(input, output, summary_len);

    printf("Player 1's text summary: %s\n", output);
    printf("--------------------------------------\n\n");
  }

  return 0;
}

void summarize(char input[], char output[], int summary_len)
{
  // Copy input for tokenizing
  char *input_copy = malloc(strlen(input));
  strcpy(input_copy, input);

  // Tokenize input into sentences
  char *sentence;
  sentence = strtok(input_copy, ".\n");

  // Initialize counter variable and summary string
  int sentence_count = 0;
  char summary[MAX_INPUT_LENGTH] = "";

  // Loop through sentences until the desired number have been added to summary
  while (sentence != NULL && sentence_count < summary_len)
  {
    // Concatenate sentence to summary
    strcat(summary, sentence);
    strcat(summary, ".");

    // Move to the next sentence
    sentence = strtok(NULL, ".\n");

    // Increment sentence count
    sentence_count++;
  }

  // Copy summary to output string
  strcpy(output, summary);

  // Free dynamically allocated memory
  free(input_copy);
}
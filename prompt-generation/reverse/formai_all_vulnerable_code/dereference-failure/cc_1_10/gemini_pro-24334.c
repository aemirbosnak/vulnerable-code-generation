//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_SUMMARY_LENGTH 500

typedef struct {
  char *word;
  int count;
} word_count;

int compare_word_counts(const void *a, const void *b) {
  return ((word_count *)a)->count - ((word_count *)b)->count;
}

char *summarize_text(char *text) {
  // Create an array to store the word counts.
  word_count word_counts[MAX_WORDS];
  int num_words = 0;

  // Tokenize the text and count the words.
  char *token = strtok(text, " ,.?\n");
  while (token != NULL) {
    // Convert the token to lowercase.
    char *lower_token = malloc(strlen(token) + 1);
    strcpy(lower_token, token);
    for (int i = 0; i < strlen(lower_token); i++) {
      lower_token[i] = tolower(lower_token[i]);
    }

    // Find the word count for the token.
    int index = -1;
    for (int i = 0; i < num_words; i++) {
      if (strcmp(word_counts[i].word, lower_token) == 0) {
        index = i;
        break;
      }
    }

    // If the word count does not exist, create it.
    if (index == -1) {
      word_counts[num_words].word = lower_token;
      word_counts[num_words].count = 1;
      num_words++;
    }
    // Otherwise, increment the word count.
    else {
      word_counts[index].count++;
    }

    // Get the next token.
    token = strtok(NULL, " ,.?\n");
  }

  // Sort the word counts in descending order.
  qsort(word_counts, num_words, sizeof(word_count), compare_word_counts);

  // Create the summary.
  char *summary = malloc(MAX_SUMMARY_LENGTH + 1);
  int summary_length = 0;
  for (int i = 0; i < num_words; i++) {
    // Add the word to the summary.
    strcat(summary, word_counts[i].word);
    strcat(summary, " ");
    summary_length += strlen(word_counts[i].word) + 1;

    // If the summary is too long, break.
    if (summary_length > MAX_SUMMARY_LENGTH) {
      break;
    }
  }

  // Remove the last space from the summary.
  summary[summary_length - 1] = '\0';

  // Return the summary.
  return summary;
}

int main() {
  // Get the text from the user.
  char *text = malloc(MAX_WORDS + 1);
  printf("Enter the text to be summarized:");
  fgets(text, MAX_WORDS + 1, stdin);

  // Summarize the text.
  char *summary = summarize_text(text);

  // Print the summary.
  printf("Summary:");
  printf("%s\n", summary);

  // Free the memory allocated for the text and the summary.
  free(text);
  free(summary);

  return 0;
}
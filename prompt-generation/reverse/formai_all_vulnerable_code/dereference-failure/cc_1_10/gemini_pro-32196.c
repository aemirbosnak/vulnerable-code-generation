//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the text to be summarized
#define MAX_TEXT_LENGTH 1024

// Define the maximum length of the summary
#define MAX_SUMMARY_LENGTH 256

// Declare the function to summarize the text
char *summarize_text(char *text);

int main() {
  // Get the text to be summarized from the user
  char text[MAX_TEXT_LENGTH];
  printf("Enter the text to be summarized:\n");
  scanf("%s", text);

  // Summarize the text
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary:\n%s", summary);

  return 0;
}

// Function to summarize the text
char *summarize_text(char *text) {
  // Allocate memory for the summary
  char *summary = malloc(MAX_SUMMARY_LENGTH);

  // Initialize the summary to an empty string
  summary[0] = '\0';

  // Tokenize the text into words
  char *words[MAX_TEXT_LENGTH / 2 + 1];
  int num_words = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Calculate the frequency of each word
  int word_frequencies[num_words];
  for (int i = 0; i < num_words; i++) {
    word_frequencies[i] = 0;
    for (int j = 0; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        word_frequencies[i]++;
      }
    }
  }

  // Sort the words by frequency in descending order
  for (int i = 0; i < num_words - 1; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (word_frequencies[i] < word_frequencies[j]) {
        int temp = word_frequencies[i];
        word_frequencies[i] = word_frequencies[j];
        word_frequencies[j] = temp;
        char *temp_word = words[i];
        words[i] = words[j];
        words[j] = temp_word;
      }
    }
  }

  // Add the most frequent words to the summary
  int num_summary_words = 0;
  for (int i = 0; i < num_words && num_summary_words < MAX_SUMMARY_LENGTH; i++) {
    strcat(summary, words[i]);
    strcat(summary, " ");
    num_summary_words += strlen(words[i]) + 1;
  }

  // Return the summary
  return summary;
}
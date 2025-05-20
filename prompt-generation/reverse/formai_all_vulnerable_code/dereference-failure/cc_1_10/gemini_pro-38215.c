//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the summary of a text
typedef struct {
  char *text;
  int length;
} Summary;

// Function to summarize a text
Summary summarize(char *text, int length) {
  // Remove all punctuation from the text
  for (int i = 0; i < length; i++) {
    if (text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?' || text[i] == ';' || text[i] == ':') {
      text[i] = ' ';
    }
  }

  // Tokenize the text into words
  char **words = malloc(length * sizeof(char *));
  int num_words = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Count the frequency of each word in the text
  int *counts = calloc(num_words, sizeof(int));
  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        counts[i]++;
      }
    }
  }

  // Sort the words by frequency
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (counts[i] < counts[j]) {
        int temp = counts[i];
        counts[i] = counts[j];
        counts[j] = temp;

        char *temp2 = words[i];
        words[i] = words[j];
        words[j] = temp2;
      }
    }
  }

  // Select the top 10 most frequent words as the summary
  Summary summary;
  summary.text = malloc(10 * sizeof(char *));
  summary.length = 10;
  for (int i = 0; i < 10; i++) {
    summary.text[i] = words[i];
  }

  // Free the memory allocated for the words and counts arrays
  free(words);
  free(counts);

  // Return the summary
  return summary;
}

// Function to print a summary
void print_summary(Summary summary) {
  for (int i = 0; i < summary.length; i++) {
    printf("%s ", summary.text[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Get the text to be summarized from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  fgets(text, 1000, stdin);

  // Summarize the text
  Summary summary = summarize(text, strlen(text));

  // Print the summary
  printf("Summary: ");
  print_summary(summary);

  // Free the memory allocated for the summary
  free(summary.text);

  return 0;
}
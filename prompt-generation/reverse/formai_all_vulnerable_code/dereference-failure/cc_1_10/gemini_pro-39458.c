//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum summary length
#define MAX_SUMMARY_LENGTH 100

// Define the number of sentences in the input text
#define NUM_SENTENCES 5

// Define the input text
char *input_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas eget lacus eget nunc tincidunt laoreet. Nunc eget orci eget nunc tincidunt laoreet. Maecenas eget lacus eget nunc tincidunt laoreet. Nunc eget orci eget nunc tincidunt laoreet.";

// Define the function to summarize the text
char *summarize_text(char *input_text) {
  // Allocate memory for the summary
  char *summary = malloc(MAX_SUMMARY_LENGTH);

  // Initialize the summary to an empty string
  strcpy(summary, "");

  // Split the input text into sentences
  char *sentences[NUM_SENTENCES];
  char *sentence = strtok(input_text, ".");
  int i = 0;
  while (sentence != NULL) {
    sentences[i] = sentence;
    i++;
    sentence = strtok(NULL, ".");
  }

  // Find the most important sentence in the text
  int most_important_sentence_index = 0;
  int highest_word_count = 0;
  for (i = 0; i < NUM_SENTENCES; i++) {
    int word_count = 0;
    char *word = strtok(sentences[i], " ");
    while (word != NULL) {
      word_count++;
      word = strtok(NULL, " ");
    }
    if (word_count > highest_word_count) {
      highest_word_count = word_count;
      most_important_sentence_index = i;
    }
  }

  // Add the most important sentence to the summary
  strcat(summary, sentences[most_important_sentence_index]);

  // Add a period to the end of the summary
  strcat(summary, ".");

  // Return the summary
  return summary;
}

// Print the summary to the console
int main() {
  char *summary = summarize_text(input_text);
  printf("Summary: %s\n", summary);
  return 0;
}
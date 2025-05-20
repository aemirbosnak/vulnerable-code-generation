//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove punctuation from a string
char *remove_punctuation(char *str) {
  char *new_str = malloc(strlen(str) + 1);
  int i, j;
  for (i = 0, j = 0; str[i] != '\0'; i++) {
    if (str[i] != '.' && str[i] != ',' && str[i] != '!' && str[i] != '?' && str[i] != ';' && str[i] != ':') {
      new_str[j++] = str[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to count the number of words in a string
int count_words(char *str) {
  int count = 0;
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      count++;
    }
  }
  return count + 1;
}

// Function to summarize a text
char *summarize_text(char *text, int num_sentences) {
  // Remove punctuation from the text
  char *new_text = remove_punctuation(text);

  // Count the number of words in the text
  int num_words = count_words(new_text);

  // Calculate the average number of words per sentence
  int avg_words_per_sentence = num_words / num_sentences;

  // Split the text into sentences
  char **sentences = malloc(num_sentences * sizeof(char *));
  char *sentence = strtok(new_text, ".");
  int i = 0;
  while (sentence != NULL) {
    sentences[i++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Create the summary
  char *summary = malloc(num_sentences * avg_words_per_sentence + 1);
  int j;
  for (j = 0; j < num_sentences; j++) {
    strcat(summary, sentences[j]);
    strcat(summary, " ");
  }

  // Free the allocated memory
  free(new_text);
  free(sentences);

  return summary;
}

// Main function
int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Get the number of sentences in the summary
  int num_sentences;
  printf("Enter the number of sentences in the summary: ");
  scanf("%d", &num_sentences);

  // Summarize the text
  char *summary = summarize_text(text, num_sentences);

  // Print the summary
  printf("Summary: %s\n", summary);

  // Free the allocated memory
  free(summary);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
  char *stop_words[] = {"a", "an", "the", "and", "or", "but", "is", "are", "was", "were", "be", "been", "being"};
  int num_stop_words = sizeof(stop_words) / sizeof(char *);

  char *new_str = malloc(strlen(str) + 1);
  int new_idx = 0;
  char *token = strtok(str, " ");
  while (token != NULL) {
    int is_stop_word = 0;
    for (int i = 0; i < num_stop_words; i++) {
      if (strcmp(token, stop_words[i]) == 0) {
        is_stop_word = 1;
        break;
      }
    }
    if (!is_stop_word) {
      strcpy(new_str + new_idx, token);
      new_idx += strlen(token);
      new_str[new_idx++] = ' ';
    }
    token = strtok(NULL, " ");
  }
  new_str[new_idx - 1] = '\0';
  return new_str;
}

// Function to summarize a text
char *summarize_text(char *text) {
  // Remove stop words from the text
  char *cleaned_text = remove_stop_words(text);

  // Split the text into sentences
  char **sentences = malloc(MAX_LEN * sizeof(char *));
  int num_sentences = 0;
  char *sentence = strtok(cleaned_text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Calculate the frequency of each word in the text
  int *word_freq = malloc(MAX_LEN * sizeof(int));
  for (int i = 0; i < MAX_LEN; i++) {
    word_freq[i] = 0;
  }
  for (int i = 0; i < num_sentences; i++) {
    char *token = strtok(sentences[i], " ");
    while (token != NULL) {
      word_freq[i]++;
      token = strtok(NULL, " ");
    }
  }

  // Find the most frequent words in the text
  int max_freq = 0;
  int max_idx = -1;
  for (int i = 0; i < MAX_LEN; i++) {
    if (word_freq[i] > max_freq) {
      max_freq = word_freq[i];
      max_idx = i;
    }
  }

  // Get the summary of the text
  char *summary = malloc(MAX_LEN);
  strcpy(summary, sentences[max_idx]);
  for (int i = 0; i < num_sentences; i++) {
    if (i == max_idx) {
      continue;
    }
    if (strstr(sentences[i], sentences[max_idx]) != NULL) {
      strcat(summary, " ");
      strcat(summary, sentences[i]);
    }
  }

  // Free the allocated memory
  free(cleaned_text);
  for (int i = 0; i < num_sentences; i++) {
    free(sentences[i]);
  }
  free(sentences);
  free(word_freq);

  return summary;
}

int main() {
  // Get the text from the user
  char *text = malloc(MAX_LEN);
  printf("Enter the text to summarize: ");
  fgets(text, MAX_LEN, stdin);

  // Summarize the text
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s", summary);

  // Free the allocated memory
  free(text);
  free(summary);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
  char *stop_words[] = {"a", "an", "the", "and", "or", "but", "for", "nor"};
  int num_stop_words = sizeof(stop_words) / sizeof(stop_words[0]);

  char *new_str = malloc(strlen(str) + 1);
  int j = 0;
  for (int i = 0; i < strlen(str); i++) {
    int is_stop_word = 0;
    for (int k = 0; k < num_stop_words; k++) {
      if (strcmp(str + i, stop_words[k]) == 0) {
        is_stop_word = 1;
        break;
      }
    }
    if (!is_stop_word) {
      new_str[j++] = str[i];
    }
  }
  new_str[j] = '\0';

  return new_str;
}

// Function to summarize a text
char *summarize_text(char *text, int num_sentences) {
  // Split the text into sentences
  char **sentences = malloc(sizeof(char *) * num_sentences);
  int num_sentences_found = 0;
  char *start = text;
  while (*start != '\0') {
    char *end = strchr(start, '.');
    if (end != NULL) {
      sentences[num_sentences_found++] = strndup(start, end - start);
      start = end + 1;
    } else {
      break;
    }
  }

  // Remove stop words from each sentence
  for (int i = 0; i < num_sentences_found; i++) {
    sentences[i] = remove_stop_words(sentences[i]);
  }

  // Sort the sentences by length
  qsort(sentences, num_sentences_found, sizeof(char *),
        (int (*)(const void *, const void *))strcmp);

  // Get the first num_sentences sentences
  char *summary = malloc(strlen(text) + 1);
  int j = 0;
  for (int i = 0; i < num_sentences_found && i < num_sentences; i++) {
    strcat(summary, sentences[i]);
    strcat(summary, " ");
    j += strlen(sentences[i]) + 1;
  }
  summary[j] = '\0';

  // Free the memory allocated for the sentences
  for (int i = 0; i < num_sentences_found; i++) {
    free(sentences[i]);
  }
  free(sentences);

  return summary;
}

int main() {
  // Get the text from the user
  char *text = malloc(1000);
  printf("Enter the text to be summarized: ");
  gets(text);

  // Get the number of sentences in the summary
  int num_sentences;
  printf("Enter the number of sentences in the summary: ");
  scanf("%d", &num_sentences);

  // Summarize the text
  char *summary = summarize_text(text, num_sentences);

  // Print the summary
  printf("Summary: %s", summary);

  // Free the memory allocated for the text and the summary
  free(text);
  free(summary);

  return 0;
}
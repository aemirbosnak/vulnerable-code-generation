//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove stop words from a string
char *remove_stop_words(char *str) {
  char *stop_words[] = {"a", "an", "the", "and", "or", "of", "in", "to", "from", "by"};
  int num_stop_words = sizeof(stop_words) / sizeof(char *);

  // Allocate memory for the new string
  char *new_str = malloc(strlen(str) + 1);

  // Copy the string to the new string
  strcpy(new_str, str);

  // Iterate over the stop words
  for (int i = 0; i < num_stop_words; i++) {
    // Find the stop word in the new string
    char *pos = strstr(new_str, stop_words[i]);

    // If the stop word is found, replace it with a space
    if (pos != NULL) {
      *pos = ' ';
    }
  }

  // Return the new string
  return new_str;
}

// Function to summarize a text
char *summarize_text(char *text) {
  // Remove stop words from the text
  char *new_text = remove_stop_words(text);

  // Split the text into sentences
  char **sentences = malloc(sizeof(char *) * 100);
  int num_sentences = 0;
  char *sentence = strtok(new_text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Calculate the frequency of each sentence
  int *sentence_frequencies = malloc(sizeof(int) * num_sentences);
  for (int i = 0; i < num_sentences; i++) {
    sentence_frequencies[i] = 0;
    for (int j = 0; j < num_sentences; j++) {
      if (strcmp(sentences[i], sentences[j]) == 0) {
        sentence_frequencies[i]++;
      }
    }
  }

  // Find the sentences with the highest frequency
  int max_frequency = 0;
  for (int i = 0; i < num_sentences; i++) {
    if (sentence_frequencies[i] > max_frequency) {
      max_frequency = sentence_frequencies[i];
    }
  }
  int num_max_sentences = 0;
  for (int i = 0; i < num_sentences; i++) {
    if (sentence_frequencies[i] == max_frequency) {
      num_max_sentences++;
    }
  }
  char **max_sentences = malloc(sizeof(char *) * num_max_sentences);
  int index = 0;
  for (int i = 0; i < num_sentences; i++) {
    if (sentence_frequencies[i] == max_frequency) {
      max_sentences[index++] = sentences[i];
    }
  }

  // Concatenate the max sentences into a summary
  char *summary = malloc(sizeof(char) * 1000);
  strcpy(summary, "");
  for (int i = 0; i < num_max_sentences; i++) {
    strcat(summary, max_sentences[i]);
    strcat(summary, ". ");
  }

  // Return the summary
  return summary;
}

int main() {
  // Get the text from the user
  char text[1000];
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s", summary);

  return 0;
}
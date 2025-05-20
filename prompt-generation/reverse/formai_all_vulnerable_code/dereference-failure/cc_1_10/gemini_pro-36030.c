//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS_PER_SENTENCE 100

// Function to summarize a text
char *summarize_text(char *text) {
  // Split the text into sentences
  char *sentences[MAX_SENTENCES];
  int num_sentences = 0;
  char *sentence = strtok(text, ".");
  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // Extract the important words from each sentence
  char *important_words[MAX_SENTENCES][MAX_WORDS_PER_SENTENCE];
  int num_important_words[MAX_SENTENCES];
  for (int i = 0; i < num_sentences; i++) {
    char *word = strtok(sentences[i], " ");
    int num_important_words_in_sentence = 0;
    while (word != NULL) {
      // Check if the word is important
      if (is_important_word(word)) {
        important_words[i][num_important_words_in_sentence++] = word;
      }
      word = strtok(NULL, " ");
    }
    num_important_words[i] = num_important_words_in_sentence;
  }

  // Generate the summary
  char *summary = malloc(1000);
  strcpy(summary, "");
  for (int i = 0; i < num_sentences; i++) {
    for (int j = 0; j < num_important_words[i]; j++) {
      strcat(summary, important_words[i][j]);
      strcat(summary, " ");
    }
    strcat(summary, ".");
  }

  return summary;
}

// Function to check if a word is important
int is_important_word(char *word) {
  // Check if the word is a noun
  if (strcmp(word, "noun") == 0) {
    return 1;
  }

  // Check if the word is a verb
  if (strcmp(word, "verb") == 0) {
    return 1;
  }

  // Check if the word is an adjective
  if (strcmp(word, "adjective") == 0) {
    return 1;
  }

  // Check if the word is an adverb
  if (strcmp(word, "adverb") == 0) {
    return 1;
  }

  // Check if the word is a pronoun
  if (strcmp(word, "pronoun") == 0) {
    return 1;
  }

  // Check if the word is a preposition
  if (strcmp(word, "preposition") == 0) {
    return 1;
  }

  // Check if the word is a conjunction
  if (strcmp(word, "conjunction") == 0) {
    return 1;
  }

  // Check if the word is an interjection
  if (strcmp(word, "interjection") == 0) {
    return 1;
  }

  // The word is not important
  return 0;
}

int main() {
  // Get the text from the user
  char *text = malloc(1000);
  printf("Enter the text to be summarized: ");
  gets(text);

  // Summarize the text
  char *summary = summarize_text(text);

  // Print the summary
  printf("Summary: %s", summary);

  return 0;
}
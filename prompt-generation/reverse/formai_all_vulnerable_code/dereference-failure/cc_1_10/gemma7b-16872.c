//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WORDS 1024
#define MAX_SENTENCES 1024

int main() {
  char text[MAX_WORDS];
  char sentences[MAX_SENTENCES][MAX_WORDS];
  int num_sentences = 0;
  int word_count = 0;
  int spam_score = 0;

  printf("Enter text: ");
  fgets(text, MAX_WORDS, stdin);

  // Split text into sentences
  char *sentence_start = text;
  while (sentence_start) {
    char *sentence_end = strchr(sentence_start, '.');
    if (sentence_end) {
      int sentence_length = sentence_end - sentence_start;
      strcpy(sentences[num_sentences], sentence_start);
      num_sentences++;
    }
    sentence_start = sentence_end + 1;
  }

  // Count words in each sentence
  for (int i = 0; i < num_sentences; i++) {
    char *word_start = sentences[i];
    while (word_start) {
      char *word_end = strchr(word_start, ' ');
      if (word_end) {
        int word_length = word_end - word_start;
        word_count++;
      }
      word_start = word_end + 1;
    }
  }

  // Calculate spam score based on word count
  for (int i = 0; i < num_sentences; i++) {
    int sentence_words = word_count;
    if (sentence_words > 20) {
      spam_score++;
    }
  }

  // Display spam score
  printf("Spam score: %d\n", spam_score);

  return 0;
}
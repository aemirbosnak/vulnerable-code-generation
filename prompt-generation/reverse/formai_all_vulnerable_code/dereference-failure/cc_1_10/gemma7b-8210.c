//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct SpamWord {
  char *word;
  int frequency;
} SpamWord;

SpamWord *words;

void analyze_sentence(char *sentence) {
  char *words_array[MAX_WORDS];
  int num_words = 0;
  char *word = strtok(sentence, " ");

  while (word) {
    words_array[num_words++] = word;
    word = strtok(NULL, " ");
  }

  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < MAX_WORDS; j++) {
      if (strcmp(words_array[i], words[j].word) == 0) {
        words[j].frequency++;
      }
    }
  }
}

int main() {
  words = (SpamWord *)malloc(MAX_WORDS * sizeof(SpamWord));

  for (int i = 0; i < MAX_WORDS; i++) {
    words[i].word = NULL;
    words[i].frequency = 0;
  }

  char *sentence = "This is a spam message with lots of words. The words are repeated many times.";

  analyze_sentence(sentence);

  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].frequency > 1) {
      printf("%s occurred %d times.\n", words[i].word, words[i].frequency);
    }
  }

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct SpamWord {
  char *word;
  int frequency;
} SpamWord;

SpamWord *loadSpamWords(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  SpamWord *words = malloc(MAX_WORDS * sizeof(SpamWord));
  int i = 0;

  char line[MAX_SENTENCE_LENGTH];
  while (fgets(line, MAX_SENTENCE_LENGTH, fp) != NULL) {
    char *word = strtok(line, " ");
    while (word) {
      SpamWord *wordEntry = &words[i++];
      wordEntry->word = strdup(word);
      wordEntry->frequency = 1;
      word = strtok(NULL, " ");
    }
  }

  fclose(fp);
  return words;
}

int main() {
  SpamWord *spamWords = loadSpamWords("spam_words.txt");

  char *sentence = "This is a spam message with many exclamation marks!!!";

  int spamScore = 0;
  for (int i = 0; i < MAX_WORDS; i++) {
    SpamWord *wordEntry = &spamWords[i];
    if (strstr(sentence, wordEntry->word) != NULL) {
      spamScore++;
    }
  }

  if (spamScore > 0) {
    printf("Spam score: %d\n", spamScore);
  } else {
    printf("No spam detected.\n");
  }

  return 0;
}
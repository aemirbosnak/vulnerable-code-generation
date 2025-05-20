//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 20

typedef struct SpamWord {
  char *word;
  int frequency;
} SpamWord;

SpamWord **loadWords(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  SpamWord **words = malloc(MAX_WORDS * sizeof(SpamWord));
  int i = 0;
  char line[256];
  while (fgets(line, 256, fp) != NULL) {
    char *word = strdup(line);
    words[i++] = malloc(sizeof(SpamWord));
    words[i - 1]->word = word;
    words[i - 1]->frequency = 1;
  }

  fclose(fp);
  return words;
}

int main() {
  SpamWord **words = loadWords("spam_words.txt");
  if (words == NULL) {
    return 1;
  }

  char *message = "This message contains a lot of spam words.";
  int score = 0;
  for (int i = 0; words[i] != NULL; i++) {
    if (strstr(message, words[i]->word) != NULL) {
      score++;
    }
  }

  if (score > 0) {
    printf("Message contains spam words. Score: %d\n", score);
  } else {
    printf("Message does not contain any spam words.\n");
  }

  return 0;
}
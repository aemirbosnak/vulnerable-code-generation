//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: sophisticated
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
  words[0].word = NULL;
  words[0].frequency = 0;

  char line[MAX_SENTENCE_LENGTH];
  int i = 0;
  while (fgets(line, MAX_SENTENCE_LENGTH, fp) != NULL) {
    char *word = strtok(line, " ");
    while (word) {
      int found = 0;
      for (int j = 0; j < i; j++) {
        if (strcmp(word, words[j].word) == 0) {
          words[j].frequency++;
          found = 1;
          break;
        }
      }

      if (!found) {
        words[i].word = strdup(word);
        words[i].frequency = 1;
        i++;
      }
    }

    word = NULL;
  }

  fclose(fp);
  return words;
}

int main() {
  SpamWord *words = loadSpamWords("spam_words.txt");

  for (int i = 0; words[i].word != NULL; i++) {
    printf("%s: %d\n", words[i].word, words[i].frequency);
  }

  free(words);

  return 0;
}
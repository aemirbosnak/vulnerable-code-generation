//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

typedef struct SpamWord {
  char *word;
  int frequency;
} SpamWord;

SpamWord *loadSpamWords(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  SpamWord *words = malloc(sizeof(SpamWord) * MAX_WORDS);
  words->word = NULL;
  words->frequency = 0;

  char line[MAX_SENTENCE_LENGTH];
  int i = 0;
  while (fgets(line, MAX_SENTENCE_LENGTH, fp) != NULL) {
    char *word = strtok(line, " \t\n");
    while (word) {
      int found = 0;
      for (int j = 0; j < words->frequency; j++) {
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
  }

  fclose(fp);
  return words;
}

int main() {
  char *filename = "spam.txt";
  SpamWord *words = loadSpamWords(filename);

  for (int i = 0; i < words->frequency; i++) {
    printf("%s: %d\n", words[i].word, words[i].frequency);
  }

  free(words);
  return 0;
}
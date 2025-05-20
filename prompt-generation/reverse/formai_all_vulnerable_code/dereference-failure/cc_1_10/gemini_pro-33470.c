//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDS 10000
#define MAXLEN 100

// word list
char *words[MAXWORDS];
int nwords;

// load word list from file
void load_words(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }
  while (fgets(words[nwords], MAXLEN, fp) != NULL) {
    nwords++;
  }
  fclose(fp);
}

// check if word is in list
int is_word(char *word) {
  for (int i = 0; i < nwords; i++) {
    if (strcmp(word, words[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

// check spelling of words in text
void check_spelling(char *text) {
  char *word = strtok(text, " ");
  while (word != NULL) {
    if (!is_word(word)) {
      printf("%s is not a valid word\n", word);
    }
    word = strtok(NULL, " ");
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <word list> <text>\n", argv[0]);
    exit(1);
  }
  load_words(argv[1]);
  check_spelling(argv[2]);
  return 0;
}
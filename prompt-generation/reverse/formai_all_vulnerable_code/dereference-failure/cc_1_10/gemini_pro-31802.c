//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LEN 1000
#define MAX_WORDS 100

typedef struct {
  char *word;
  int count;
} Word;

Word spamWords[MAX_WORDS];
int numSpamWords = 0;

void loadSpamWords() {
  FILE *f = fopen("spamwords.txt", "r");
  if (f == NULL) {
    perror("Error opening spamwords.txt");
    exit(1);
  }

  char line[MAX_LEN];
  while (fgets(line, MAX_LEN, f)) {
    char *word = strtok(line, "\n");
    spamWords[numSpamWords].word = malloc(strlen(word) + 1);
    strcpy(spamWords[numSpamWords].word, word);
    spamWords[numSpamWords].count = 0;
    numSpamWords++;
  }

  fclose(f);
}

int isSpam(char *text) {
  int score = 0;

  char *words[MAX_WORDS];
  int numWords = 0;

  char *word = strtok(text, " ");
  while (word != NULL) {
    words[numWords] = malloc(strlen(word) + 1);
    strcpy(words[numWords], word);
    numWords++;
    word = strtok(NULL, " ");
  }

  for (int i = 0; i < numWords; i++) {
    for (int j = 0; j < numSpamWords; j++) {
      if (strcmp(words[i], spamWords[j].word) == 0) {
        score += spamWords[j].count;
      }
    }
  }

  for (int i = 0; i < numWords; i++) {
    free(words[i]);
  }

  return score > 0;
}

int main() {
  loadSpamWords();

  char text[MAX_LEN];
  printf("Enter the text you want to check for spam: ");
  fgets(text, MAX_LEN, stdin);

  if (isSpam(text)) {
    printf("The text is spam!\n");
  } else {
    printf("The text is not spam.\n");
  }

  return 0;
}
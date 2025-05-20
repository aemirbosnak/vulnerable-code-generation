//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 2000

typedef struct SpamWord {
  char *word;
  int frequency;
} SpamWord;

SpamWord **loadSpamWords(char *file_path) {
  FILE *fp = fopen(file_path, "r");
  if (fp == NULL) {
    return NULL;
  }

  SpamWord **words = malloc(MAX_WORDS * sizeof(SpamWord));
  words[0] = NULL;

  char line[MAX_SENTENCE_LENGTH];
  int word_count = 0;
  while (fgets(line, MAX_SENTENCE_LENGTH, fp) != NULL) {
    char *word = strtok(line, " ");
    while (word) {
      SpamWord *newWord = malloc(sizeof(SpamWord));
      newWord->word = strdup(word);
      newWord->frequency = 1;
      words[word_count++] = newWord;
      word = strtok(NULL, " ");
    }
  }

  fclose(fp);
  return words;
}

int main() {
  SpamWord **spamWords = loadSpamWords("spam_words.txt");

  char *sentence = "This is a sample sentence that contains some spam words.";

  int score = 0;
  for (SpamWord *word = spamWords; word; word++) {
    if (strstr(sentence, word->word) != NULL) {
      score++;
    }
  }

  if (score > 0) {
    printf("Spam detected!\n");
  } else {
    printf("No spam detected.\n");
  }

  return 0;
}
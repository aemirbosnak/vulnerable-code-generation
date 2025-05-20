//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1024
#define MAX_SENTENCE_LENGTH 2048

typedef struct SpamWord {
  char *word;
  int frequency;
} SpamWord;

SpamWord **loadSpamWords(char *filename) {
  SpamWord **words = NULL;
  FILE *fp = fopen(filename, "r");
  if (fp) {
    words = malloc(MAX_WORDS * sizeof(SpamWord));
    char line[MAX_SENTENCE_LENGTH];
    int i = 0;
    while (fgets(line, MAX_SENTENCE_LENGTH, fp) != NULL) {
      char *word = strtok(line, ",");
      while (word) {
        SpamWord *newWord = malloc(sizeof(SpamWord));
        newWord->word = strdup(word);
        newWord->frequency = 1;
        words[i++] = newWord;
        word = strtok(NULL, ",");
      }
    }
    fclose(fp);
  }
  return words;
}

int classifySentence(char *sentence) {
  SpamWord **words = loadSpamWords("spam_words.txt");
  int score = 0;
  for (int i = 0; words[i] != NULL; i++) {
    if (strstr(sentence, words[i]->word) != NULL) {
      score += words[i]->frequency;
    }
  }
  free(words);
  return score;
}

int main() {
  char *sentence = "This is a spam email with lots of junk words, such as free, discount, and lottery.";
  int score = classifySentence(sentence);
  printf("The score is: %d", score);
  return 0;
}
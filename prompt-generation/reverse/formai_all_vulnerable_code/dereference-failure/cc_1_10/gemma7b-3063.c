//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1024

int main() {

  char text[MAX_WORDS];
  printf("Enter text: ");
  fgets(text, MAX_WORDS, stdin);

  char *words[MAX_WORDS];
  int num_words = tokenize(text, words);

  int sentiment = analyzeSentiment(words);

  switch (sentiment) {
    case 0:
      printf("Neutral\n");
      break;
    case 1:
      printf("Positive\n");
      break;
    case -1:
      printf("Negative\n");
      break;
  }

  return 0;
}

int tokenize(char *text, char **words) {
  int i = 0;
  words = malloc(MAX_WORDS * sizeof(char *));
  char *word = strtok(text, " ");
  while (word) {
    words[i++] = strdup(word);
    word = strtok(NULL, " ");
  }
  return i;
}

int analyzeSentiment(char **words) {
  int i, sentiment = 0;
  for (i = 0; words[i] != NULL; i++) {
    if (isPositiveWord(words[i])) {
      sentiment++;
    } else if (isNegativeWord(words[i])) {
      sentiment--;
    }
  }
  return sentiment;
}

int isPositiveWord(char *word) {
  // List of positive words
  char *positive_words[] = {"happy", "joy", "good", "great", "excellent", "wonderful"};
  int i = 0;
  for (i = 0; positive_words[i] != NULL; i++) {
    if (strcmp(word, positive_words[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int isNegativeWord(char *word) {
  // List of negative words
  char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful", "hate"};
  int i = 0;
  for (i = 0; negative_words[i] != NULL; i++) {
    if (strcmp(word, negative_words[i]) == 0) {
      return -1;
    }
  }
  return 0;
}
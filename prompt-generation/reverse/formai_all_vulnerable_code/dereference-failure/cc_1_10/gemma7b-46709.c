//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

int main() {
  char str[MAX_WORDS];
  printf("Enter a sentence: ");
  fgets(str, MAX_WORDS, stdin);

  char *words[MAX_WORDS];
  int num_words = tokenize(str, words);

  int sentiment = analyze_sentiment(words, num_words);

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

int tokenize(char *str, char **words) {
  char *ptr = str;
  int i = 0;

  words = malloc(MAX_WORDS * sizeof(char *));

  while (ptr) {
    char *word = malloc(MAX_WORDS * sizeof(char));

    word = strtok(ptr, " \t\n");

    if (word) {
      words[i++] = word;
    }

    ptr = strchr(ptr, ' ') + 1;
  }

  return i;
}

int analyze_sentiment(char **words, int num_words) {
  int sentiment = 0;
  for (int i = 0; i < num_words; i++) {
    if (is_positive(words[i])) {
      sentiment++;
    } else if (is_negative(words[i])) {
      sentiment--;
    }
  }

  return sentiment;
}

int is_positive(char *word) {
  char *positive_words[] = {"good", "great", "happy", "joyful", "wonderful"};

  for (int i = 0; i < 5; i++) {
    if (strcmp(word, positive_words[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int is_negative(char *word) {
  char *negative_words[] = {"bad", "awful", "sad", "angry", "terrible"};

  for (int i = 0; i < 5; i++) {
    if (strcmp(word, negative_words[i]) == 0) {
      return -1;
    }
  }

  return 0;
}
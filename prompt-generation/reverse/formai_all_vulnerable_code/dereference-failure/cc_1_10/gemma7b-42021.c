//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

int main() {
  char text[MAX_WORDS];
  printf("Enter text: ");
  fgets(text, MAX_WORDS, stdin);

  char **words = malloc(MAX_WORDS * sizeof(char *));
  int num_words = tokenize(text, words);

  int sentiment = analyzeSentiment(words, num_words);

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

  free(words);

  return 0;
}

int tokenize(char *text, char **words) {
  char *token = strtok(text, " ");
  int i = 0;

  while (token) {
    words[i++] = token;
    token = strtok(NULL, " ");
  }

  return i;
}

int analyzeSentiment(char **words, int num_words) {
  int sentiment = 0;
  for (int i = 0; i < num_words; i++) {
    if (words[i] == "good" || words[i] == "great" || words[i] == "excellent") {
      sentiment++;
    } else if (words[i] == "bad" || words[i] == "terrible" || words[i] == "awful") {
      sentiment--;
    }
  }

  return sentiment;
}
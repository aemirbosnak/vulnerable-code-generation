//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

int main() {

  char text[MAX_WORDS];
  printf("Enter a text: ");
  fgets(text, MAX_WORDS, stdin);

  char words[MAX_WORDS][MAX_WORDS];
  int num_words = tokenize(text, words);

  int sentiment = analyze_sentiment(words);

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
  char *ptr = text;
  int i = 0;

  words[0] = NULL;

  while (ptr) {
    char *word = strsep(ptr, " ");
    if (word) {
      words[i++] = word;
    }
    ptr = word ? NULL : ptr;
  }

  return i;
}

int analyze_sentiment(char **words) {
  int sentiment = 0;
  for (int i = 0; words[i]; i++) {
    if (words[i][0] == 'p' || words[i][0] == 'P') {
      sentiment++;
    } else if (words[i][0] == 'n' || words[i][0] == 'N') {
      sentiment--;
    }
  }

  return sentiment;
}
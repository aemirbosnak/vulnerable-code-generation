//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word words[MAX_WORDS];

void analyze_sentiment(char *text) {
  char *words_list = text;
  char word[MAX_WORDS];
  int i = 0;

  while (words_list) {
    word[i] = words_list;
    words_list = strchr(words_list, ' ') + 1;
    i++;
  }

  for (int j = 0; j < i; j++) {
    for (int k = 0; k < MAX_WORDS; k++) {
      if (strcmp(word[j], words[k].word) == 0) {
        words[k].frequency++;
      }
    }
  }

  // Calculate sentiment score
  int sentiment_score = 0;
  for (int l = 0; l < MAX_WORDS; l++) {
    if (words[l].word[0] == 'a' || words[l].word[0] == 'e' || words[l].word[0] == 'i') {
      sentiment_score++;
    } else if (words[l].word[0] == 'n' || words[l].word[0] == 'o' || words[l].word[0] == 's') {
      sentiment_score--;
    }
  }

  // Print sentiment score
  printf("Sentiment score: %d\n", sentiment_score);
}

int main() {
  analyze_sentiment("I am happy today.");
  analyze_sentiment("I am sad today.");
  analyze_sentiment("I am neutral today.");

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SENTIMENT_WORDS 50

typedef struct SentimentWord {
  char *word;
  int sentiment;
} SentimentWord;

SentimentWord *loadSentimentWords() {
  SentimentWord *words = malloc(MAX_SENTIMENT_WORDS * sizeof(SentimentWord));

  words[0].word = "happy";
  words[0].sentiment = 1;

  words[1].word = "sad";
  words[1].sentiment = -1;

  words[2].word = "angry";
  words[2].sentiment = -1;

  words[3].word = "fearful";
  words[3].sentiment = -1;

  words[4].word = "excited";
  words[4].sentiment = 1;

  words[5].word = "peaceful";
  words[5].sentiment = 1;

  return words;
}

int analyzeSentiment(char *text) {
  SentimentWord *words = loadSentimentWords();

  int sentiment = 0;
  for (int i = 0; i < MAX_SENTIMENT_WORDS; i++) {
    if (strstr(text, words[i].word) != NULL) {
      sentiment += words[i].sentiment;
    }
  }

  free(words);
  return sentiment;
}

int main() {
  char *text = "I am happy today.";

  int sentiment = analyzeSentiment(text);

  if (sentiment > 0) {
    printf("The text is positive.\n");
  } else if (sentiment < 0) {
    printf("The text is negative.\n");
  } else {
    printf("The text is neutral.\n");
  }

  return 0;
}
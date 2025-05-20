//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  int sentiment;
} Word;

Word *words;

void analyze_sentiment(char *sentence) {
  words = malloc(MAX_WORDS * sizeof(Word));
  int i = 0;

  // Tokenize the sentence into words
  char *word = strtok(sentence, " ");
  while (word) {
    words[i].word = strdup(word);
    words[i].sentiment = sentiment_score(word);
    i++;
    word = strtok(NULL, " ");
  }

  // Calculate the overall sentiment of the sentence
  int overall_sentiment = calculate_overall_sentiment();

  // Print the sentiment of each word and the overall sentiment
  for (i = 0; i < i; i++) {
    printf("%s: %d\n", words[i].word, words[i].sentiment);
  }
  printf("Overall sentiment: %d\n", overall_sentiment);

  free(words);
}

int sentiment_score(char *word) {
  // Sentiment score for each word
  int score = 0;
  if (strcmp(word, "happy") == 0) {
    score = 5;
  } else if (strcmp(word, "sad") == 0) {
    score = -5;
  } else if (strcmp(word, "angry") == 0) {
    score = -3;
  } else if (strcmp(word, "excited") == 0) {
    score = 3;
  }
  return score;
}

int calculate_overall_sentiment() {
  // Calculate the overall sentiment of the sentence by averaging the sentiment scores of each word
  int overall_sentiment = 0;
  for (int i = 0; i < MAX_WORDS; i++) {
    overall_sentiment += words[i].sentiment;
  }
  overall_sentiment /= MAX_WORDS;
  return overall_sentiment;
}

int main() {
  analyze_sentiment("I am happy today.");
  analyze_sentiment("I am sad today.");
  analyze_sentiment("I am angry today.");
  analyze_sentiment("I am excited today.");

  return 0;
}
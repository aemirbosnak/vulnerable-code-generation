//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTIMENT_LENGTH 256

typedef struct SentimentAnalysis {
  char sentiment[MAX_SENTIMENT_LENGTH];
  int sentiment_score;
} SentimentAnalysis;

SentimentAnalysis *allocate_sentiment_analysis() {
  return malloc(sizeof(SentimentAnalysis));
}

void free_sentiment_analysis(SentimentAnalysis *sa) {
  free(sa);
}

SentimentAnalysis *analyze_sentiment(char *sentence) {
  SentimentAnalysis *sa = allocate_sentiment_analysis();

  // Calculate sentiment score
  int score = calculate_sentiment_score(sentence);
  sa->sentiment_score = score;

  // Store sentiment
  strcpy(sa->sentiment, sentence);

  return sa;
}

int calculate_sentiment_score(char *sentence) {
  int score = 0;

  // Analyze words
  char *word = strtok(sentence, " ");
  while (word) {
    // Check for positive words
    if (strcmp(word, "happy") == 0 || strcmp(word, "joy") == 0 || strcmp(word, "good") == 0) {
      score++;
    }

    // Check for negative words
    else if (strcmp(word, "sad") == 0 || strcmp(word, "hate") == 0 || strcmp(word, "bad") == 0) {
      score--;
    }

    word = strtok(NULL, " ");
  }

  return score;
}

int main() {
  char *sentence = "I am happy that I am alive.";
  SentimentAnalysis *sa = analyze_sentiment(sentence);

  printf("Sentiment: %s\n", sa->sentiment);
  printf("Sentiment score: %d\n", sa->sentiment_score);

  free_sentiment_analysis(sa);

  return 0;
}
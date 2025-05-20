//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SENTENCE_LENGTH 500

typedef struct sentiment {
  int positive;
  int negative;
  int neutral;
} sentiment_analysis_result;

char *positive_words[] = {"good", "nice", "great", "awesome", "superb", "wonderful", "fantastic", "excellent", "perfect", "lovely"};
char *negative_words[] = {"bad", "terrible", "awful", "horrible", "dreadful", "disgusting", "repulsive", "nauseating", "sickening", "disgusting"};

sentiment_analysis_result analyze_sentiment(char *sentence) {
  sentiment_analysis_result result;
  result.positive = 0;
  result.negative = 0;
  result.neutral = 0;

  char *token;
  char *rest = sentence;
  while ((token = strtok_r(rest, " ", &rest))) {
    // Convert token to lowercase
    for (int i = 0; i < strlen(token); i++) {
      token[i] = tolower(token[i]);
    }

    // Check if token is a positive word
    for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        result.positive++;
        break;
      }
    }

    // Check if token is a negative word
    for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        result.negative++;
        break;
      }
    }

    // Otherwise, token is neutral
    result.neutral++;
  }

  return result;
}

int main() {
  char sentence[MAX_SENTENCE_LENGTH];
  sentiment_analysis_result result;

  printf("Enter a sentence to analyze: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  result = analyze_sentiment(sentence);

  printf("Sentiment analysis results:\n");
  printf("Positive: %d\n", result.positive);
  printf("Negative: %d\n", result.negative);
  printf("Neutral: %d\n", result.neutral);

  return 0;
}
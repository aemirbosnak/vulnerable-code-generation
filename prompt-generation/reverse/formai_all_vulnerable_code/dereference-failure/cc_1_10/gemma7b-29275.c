//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100

void analyze_sentiment(char *sentence) {
  int word_count = 0;
  char **words = (char **)malloc(MAX_WORDS * sizeof(char *));

  // Tokenize the sentence into words
  char *word = strtok(sentence, " ");
  while (word) {
    words[word_count++] = word;
    word = strtok(NULL, " ");
  }

  // Analyze the sentiment of each word
  for (int i = 0; i < word_count; i++) {
    int sentiment = analyze_word_sentiment(words[i]);
    words[i] = sentiment;
  }

  // Print the sentiment of the sentence
  printf("The sentiment of the sentence is: ");
  int overall_sentiment = 0;
  for (int i = 0; i < word_count; i++) {
    overall_sentiment += words[i];
  }
  printf("%d\n", overall_sentiment);
  free(words);
}

int analyze_word_sentiment(char *word) {
  // Create a dictionary of sentiment scores for each word
  int sentiment_score = 0;
  if (strcmp(word, "happy") == 0) {
    sentiment_score = 5;
  } else if (strcmp(word, "sad") == 0) {
    sentiment_score = -5;
  } else if (strcmp(word, "angry") == 0) {
    sentiment_score = -3;
  } else if (strcmp(word, "excited") == 0) {
    sentiment_score = 3;
  } else if (strcmp(word, "neutral") == 0) {
    sentiment_score = 0;
  }

  return sentiment_score;
}

int main() {
  analyze_sentiment("I am happy today.");
  analyze_sentiment("I am sad today.");
  analyze_sentiment("I am angry today.");
  analyze_sentiment("I am excited today.");
  analyze_sentiment("I am neutral today.");

  return 0;
}
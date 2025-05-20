//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 256

int main() {
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  int sentiment = analyze_sentiment(sentence);

  switch (sentiment) {
    case 0:
      printf("Neutral sentiment.\n");
      break;
    case 1:
      printf("Positive sentiment.\n");
      break;
    case -1:
      printf("Negative sentiment.\n");
      break;
  }

  return 0;
}

int analyze_sentiment(char *sentence) {
  // Calculate the sentiment score for the sentence.
  int score = calculate_sentiment_score(sentence);

  // Return the sentiment score.
  return score;
}

int calculate_sentiment_score(char *sentence) {
  // Count the number of positive and negative words in the sentence.
  int num_positive_words = count_positive_words(sentence);
  int num_negative_words = count_negative_words(sentence);

  // Calculate the sentiment score.
  int score = (num_positive_words - num_negative_words) / 2;

  // Return the sentiment score.
  return score;
}

int count_positive_words(char *sentence) {
  // Create an array of positive words.
  char *positive_words[] = {"happy", "joy", "good", "excellent", "wonderful"};

  // Iterate over the sentence and count the number of positive words.
  int num_positive_words = 0;
  for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
    if (sentence[i] != '\0' && strstr(positive_words, sentence[i]) != NULL) {
      num_positive_words++;
    }
  }

  // Return the number of positive words.
  return num_positive_words;
}

int count_negative_words(char *sentence) {
  // Create an array of negative words.
  char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful"};

  // Iterate over the sentence and count the number of negative words.
  int num_negative_words = 0;
  for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
    if (sentence[i] != '\0' && strstr(negative_words, sentence[i]) != NULL) {
      num_negative_words++;
    }
  }

  // Return the number of negative words.
  return num_negative_words;
}
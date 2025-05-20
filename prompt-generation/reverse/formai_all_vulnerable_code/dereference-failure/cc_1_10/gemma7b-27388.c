//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

int main() {
  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  int sentiment = sentiment_analysis(sentence);

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

int sentiment_analysis(char *sentence) {
  // Count the number of positive and negative words in the sentence
  int num_positive = count_positive_words(sentence);
  int num_negative = count_negative_words(sentence);

  // Calculate the sentiment score
  int sentiment = (num_positive - num_negative) / (num_positive + num_negative);

  // Return the sentiment score
  return sentiment;
}

int count_positive_words(char *sentence) {
  // Define a list of positive words
  char *positive_words[] = {"happy", "joy", "good", "excellent", "great", "wonderful"};

  // Iterate over the sentence and count the number of positive words
  int num_positive = 0;
  for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
    if (sentence[i] != '\0' && strstr(positive_words, sentence[i]) != NULL) {
      num_positive++;
    }
  }

  return num_positive;
}

int count_negative_words(char *sentence) {
  // Define a list of negative words
  char *negative_words[] = {"sad", "angry", "bad", "terrible", "awful", "hate"};

  // Iterate over the sentence and count the number of negative words
  int num_negative = 0;
  for (int i = 0; i < MAX_SENTENCE_LENGTH; i++) {
    if (sentence[i] != '\0' && strstr(negative_words, sentence[i]) != NULL) {
      num_negative++;
    }
  }

  return num_negative;
}
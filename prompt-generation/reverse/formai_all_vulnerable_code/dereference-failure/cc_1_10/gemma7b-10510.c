//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

void sentiment_analysis(char **review) {
  int i = 0, sentiment_score = 0, positive_words = 0, negative_words = 0;
  char **positive_words_array = {"happy", "joy", "love", "good", "excellent"};
  char **negative_words_array = {"sad", "hate", "bad", "terrible", "awful"};

  // Iterate over the review and count the number of positive and negative words
  for (i = 0; review[i] != NULL; i++) {
    if (strcmp(review[i], positive_words_array[0]) == 0 ||
        strcmp(review[i], positive_words_array[1]) == 0 ||
        strcmp(review[i], positive_words_array[2]) == 0 ||
        strcmp(review[i], positive_words_array[3]) == 0 ||
        strcmp(review[i], positive_words_array[4]) == 0) {
      positive_words++;
    } else if (strcmp(review[i], negative_words_array[0]) == 0 ||
        strcmp(review[i], negative_words_array[1]) == 0 ||
        strcmp(review[i], negative_words_array[2]) == 0 ||
        strcmp(review[i], negative_words_array[3]) == 0 ||
        strcmp(review[i], negative_words_array[4]) == 0) {
      negative_words++;
    }
  }

  // Calculate the sentiment score
  sentiment_score = (positive_words - negative_words) * 100 / MAX;

  // Print the sentiment score
  printf("Sentiment score: %d%%", sentiment_score);
}

int main() {
  char **review = NULL;

  // Allocate memory for the review
  review = (char **)malloc(MAX * sizeof(char *));

  // Get the review
  printf("Enter your review: ");
  getline(review, MAX, stdin);

  // Perform sentiment analysis
  sentiment_analysis(review);

  // Free the memory
  free(review);

  return 0;
}
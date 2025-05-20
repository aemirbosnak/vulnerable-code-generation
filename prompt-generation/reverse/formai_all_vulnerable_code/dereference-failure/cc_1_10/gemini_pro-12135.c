//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

// A struct to represent a sentiment analysis result
typedef struct {
  float positive_score;
  float negative_score;
} sentiment_result;

// A function to perform sentiment analysis on a sentence
sentiment_result analyze_sentiment(char *sentence) {
  // Initialize the sentiment result
  sentiment_result result = {0.0, 0.0};

  // Loop through each word in the sentence
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    // Check if the word is positive or negative
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "awesome") == 0) {
      result.positive_score += 1.0;
    } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "horrible") == 0) {
      result.negative_score += 1.0;
    }

    // Get the next word in the sentence
    word = strtok(NULL, " ");
  }

  // Return the sentiment result
  return result;
}

// A function to print the sentiment analysis result
void print_sentiment_result(sentiment_result result) {
  printf("Positive score: %.2f\n", result.positive_score);
  printf("Negative score: %.2f\n", result.negative_score);

  if (result.positive_score > result.negative_score) {
    printf("Overall sentiment: positive\n");
  } else if (result.positive_score < result.negative_score) {
    printf("Overall sentiment: negative\n");
  } else {
    printf("Overall sentiment: neutral\n");
  }
}

// A function to get a sentence from the user
char *get_sentence() {
  // Allocate memory for the sentence
  char *sentence = malloc(MAX_SENTENCE_LENGTH);

  // Get the sentence from the user
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  // Return the sentence
  return sentence;
}

// The main function
int main() {
  // Get a sentence from the user
  char *sentence = get_sentence();

  // Perform sentiment analysis on the sentence
  sentiment_result result = analyze_sentiment(sentence);

  // Print the sentiment analysis result
  print_sentiment_result(result);

  // Free the memory allocated for the sentence
  free(sentence);

  return 0;
}
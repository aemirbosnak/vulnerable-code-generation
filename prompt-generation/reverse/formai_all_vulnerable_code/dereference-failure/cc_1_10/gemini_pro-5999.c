//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 1024

// Define the number of sentiment categories
#define NUM_SENTIMENT_CATEGORIES 3

// Define the sentiment categories
char *sentiment_categories[] = {"positive", "negative", "neutral"};

// Define the sentiment scores for each word
int sentiment_scores[] = {1, -1, 0};

// Create a function to get the sentiment score of a sentence
int get_sentiment_score(char *sentence) {
  // Initialize the sentiment score to 0
  int sentiment_score = 0;

  // Tokenize the sentence into words
  char *words[MAX_SENTENCE_LENGTH];
  int num_words = 0;
  char *word = strtok(sentence, " ");
  while (word != NULL) {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the sentiment score for each word
  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < NUM_SENTIMENT_CATEGORIES; j++) {
      if (strcmp(words[i], sentiment_categories[j]) == 0) {
        sentiment_score += sentiment_scores[j];
      }
    }
  }

  // Return the sentiment score
  return sentiment_score;
}

// Create a function to get the sentiment category of a sentence
char *get_sentiment_category(int sentiment_score) {
  // Return the sentiment category based on the sentiment score
  if (sentiment_score > 0) {
    return sentiment_categories[0];
  } else if (sentiment_score < 0) {
    return sentiment_categories[1];
  } else {
    return sentiment_categories[2];
  }
}

// Create a function to test the sentiment analysis tool
void test_sentiment_analysis_tool() {
  // Define some test sentences
  char *sentences[] = {
    "I love this product!",
    "This product is terrible.",
    "This product is okay."
  };

  // Get the sentiment score and category for each sentence
  for (int i = 0; i < 3; i++) {
    int sentiment_score = get_sentiment_score(sentences[i]);
    char *sentiment_category = get_sentiment_category(sentiment_score);

    // Print the sentiment score and category for each sentence
    printf("Sentence: %s\n", sentences[i]);
    printf("Sentiment score: %d\n", sentiment_score);
    printf("Sentiment category: %s\n\n", sentiment_category);
  }
}

// Main function
int main() {
  // Test the sentiment analysis tool
  test_sentiment_analysis_tool();

  return 0;
}
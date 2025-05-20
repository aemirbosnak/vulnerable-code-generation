//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment analysis function
int sentiment_analysis(char *text) {
  // Create an array of positive and negative words
  char *positive_words[] = {"good", "great", "excellent", "awesome", "superb"};
  char *negative_words[] = {"bad", "terrible", "awful", "horrible", "disgusting"};

  // Initialize the positive and negative word counts
  int positive_count = 0;
  int negative_count = 0;

  // Tokenize the text
  char *token = strtok(text, " ");

  // Loop through the tokens
  while (token != NULL) {
    // Check if the token is a positive word
    for (int i = 0; i < sizeof(positive_words) / sizeof(char *); i++) {
      if (strcmp(token, positive_words[i]) == 0) {
        positive_count++;
        break;
      }
    }

    // Check if the token is a negative word
    for (int i = 0; i < sizeof(negative_words) / sizeof(char *); i++) {
      if (strcmp(token, negative_words[i]) == 0) {
        negative_count++;
        break;
      }
    }

    // Get the next token
    token = strtok(NULL, " ");
  }

  // Return the sentiment score
  return positive_count - negative_count;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a text to analyze
  if (argc < 2) {
    printf("Usage: %s <text>\n", argv[0]);
    return 1;
  }

  // Get the text from the user
  char *text = argv[1];

  // Perform sentiment analysis on the text
  int sentiment_score = sentiment_analysis(text);

  // Print the sentiment score
  printf("Sentiment score: %d\n", sentiment_score);

  // Return 0 to indicate success
  return 0;
}
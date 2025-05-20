//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A lexicon of positive and negative words
const char *positive[] = {
  "good", "great", "excellent", "wonderful", "amazing",
  "happy", "joyful", "cheerful", "optimistic", "hopeful",
  "love", "adore", "cherish", "treasure", "appreciate",
  "beautiful", "pretty", "handsome", "gorgeous", "stunning"
};

const char *negative[] = {
  "bad", "terrible", "horrible", "awful", "dreadful",
  "sad", "unhappy", "depressed", "pessimistic", "hopeless",
  "hate", "despise", "loathe", "abhor", "detest",
  "ugly", "unattractive", "hideous", "repulsive", "disgusting"
};

// Calculate the sentiment score of a given text
int sentiment_analysis(const char *text) {
  // Tokenize the text
  char *tokens[100];
  int num_tokens = tokenize(text, tokens);

  // Initialize the sentiment score
  int score = 0;

  // Iterate over the tokens and update the sentiment score
  for (int i = 0; i < num_tokens; i++) {
    // Check if the token is a positive word
    for (int j = 0; j < sizeof(positive) / sizeof(char *); j++) {
      if (strcmp(tokens[i], positive[j]) == 0) {
        score++;
        break;
      }
    }

    // Check if the token is a negative word
    for (int j = 0; j < sizeof(negative) / sizeof(char *); j++) {
      if (strcmp(tokens[i], negative[j]) == 0) {
        score--;
        break;
      }
    }
  }

  // Return the sentiment score
  return score;
}

// Tokenize a given text into an array of tokens
int tokenize(const char *text, char *tokens[]) {
  // Initialize the number of tokens
  int num_tokens = 0;

  // Iterate over the text and tokenize it
  char *token = strtok(text, " ");
  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  // Return the number of tokens
  return num_tokens;
}

// Print the sentiment score of a given text
void print_sentiment(const char *text) {
  // Calculate the sentiment score
  int score = sentiment_analysis(text);

  // Print the sentiment score
  printf("The sentiment score of '%s' is %d.\n", text, score);
}

// Main function
int main() {
  // Print the sentiment score of a few example texts
  print_sentiment("I love this movie!");
  print_sentiment("This movie is terrible.");
  print_sentiment("This movie is okay.");

  return 0;
}
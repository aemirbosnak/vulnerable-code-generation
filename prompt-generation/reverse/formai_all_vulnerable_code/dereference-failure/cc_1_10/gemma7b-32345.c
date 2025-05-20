//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main() {
  char **words = NULL;
  int num_words = 0;

  // Allocate memory for words
  words = malloc(MAX_WORDS * sizeof(char *));

  // Get the text to analyze
  char text[] = "I am a happy person. I love to eat pizza. The weather is beautiful today.";

  // Split the text into words
  char *token = strtok(text, " ");
  while (token) {
    // Add the word to the list
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Analyze the sentiment of each word
  for (int i = 0; i < num_words; i++) {
    int sentiment = analyze_sentiment(words[i]);
    printf("%s has a sentiment of %d\n", words[i], sentiment);
  }

  // Free the memory allocated for words
  free(words);

  return 0;
}

int analyze_sentiment(char *word) {
  // Sentiment dictionary
  int sentiment_dict[] = {
    -2, // Angry
    -1, // Sad
    0, // Neutral
    1, // Happy
    2 // Excited
  };

  // Check if the word is in the sentiment dictionary
  for (int i = 0; i < 5; i++) {
    if (strcmp(word, sentiment_dict[i]) == 0) {
      return sentiment_dict[i];
    }
  }

  // If the word is not in the dictionary, return neutral
  return 0;
}
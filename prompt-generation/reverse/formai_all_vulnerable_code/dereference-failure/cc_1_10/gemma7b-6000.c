//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main() {
  char text[MAX_WORDS];
  int i = 0;
  int word_count = 0;
  char words[MAX_WORDS][MAX_WORDS];

  printf("Enter text: ");
  fgets(text, MAX_WORDS, stdin);

  // Split text into words
  char *p = strtok(text, " ");
  while (p) {
    strcpy(words[word_count], p);
    word_count++;
    p = strtok(NULL, " ");
  }

  // Analyze sentiment of each word
  for (i = 0; i < word_count; i++) {
    int sentiment = analyze_sentiment(words[i]);
    printf("Word: %s, Sentiment: %d\n", words[i], sentiment);
  }

  return 0;
}

int analyze_sentiment(char *word) {
  // Sentiment dictionary
  int sentiment_dict[] = {
    -2, // Hate
    -1, // Dislike
    0, // Neutral
    1, // Like
    2, // Love
  };

  // Check if word is in the dictionary
  for (int i = 0; i < 5; i++) {
    if (strcmp(word, sentiment_dict[i]) == 0) {
      return sentiment_dict[i];
    }
  }

  // Return neutral sentiment
  return 0;
}
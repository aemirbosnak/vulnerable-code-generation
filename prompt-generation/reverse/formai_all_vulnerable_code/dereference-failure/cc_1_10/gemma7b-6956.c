//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main() {
  char text[MAX_WORDS];
  printf("Enter text: ");
  fgets(text, MAX_WORDS, stdin);

  // Tokenize the text
  char *words[MAX_WORDS];
  int num_words = tokenize(text, words);

  // Analyze the sentiment of each word
  int sentiment[MAX_WORDS];
  for (int i = 0; i < num_words; i++) {
    sentiment[i] = analyze_sentiment(words[i]);
  }

  // Print the sentiment of each word
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i], sentiment[i]);
  }

  return 0;
}

int tokenize(char *text, char **words) {
  // Split the text into words
  char *ptr = text;
  int num_words = 0;
  words = malloc(MAX_WORDS * sizeof(char *));
  while (ptr) {
    char *word = strchr(ptr, ' ');
    if (word) {
      words[num_words++] = strdup(ptr);
      ptr = word + 1;
    } else {
      words[num_words++] = strdup(ptr);
      ptr = NULL;
    }
  }
  return num_words;
}

int analyze_sentiment(char *word) {
  // Map words to their sentiment
  int sentiment = 0;
  if (strcmp(word, "happy") == 0) {
    sentiment = 1;
  } else if (strcmp(word, "sad") == 0) {
    sentiment = -1;
  } else if (strcmp(word, "neutral") == 0) {
    sentiment = 0;
  }
  return sentiment;
}
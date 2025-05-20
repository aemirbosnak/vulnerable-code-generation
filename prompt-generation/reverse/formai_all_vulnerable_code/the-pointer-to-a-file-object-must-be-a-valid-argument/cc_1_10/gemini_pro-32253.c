//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a word and its sentiment score
typedef struct {
  char *word;
  int score;
} Word;

// Define a function to compare two words based on their sentiment scores
int compare_words(const void *a, const void *b) {
  Word *word1 = (Word *)a;
  Word *word2 = (Word *)b;
  return word1->score - word2->score;
}

// Define a function to analyze the sentiment of a given text
int analyze_sentiment(char *text) {
  // Split the text into individual words
  char *token = strtok(text, " ");
  int word_count = 0;
  Word *words = malloc(sizeof(Word) * 100);
  while (token != NULL) {
    words[word_count].word = token;
    words[word_count].score = 0;
    word_count++;
    token = strtok(NULL, " ");
  }

  // Load a sentiment lexicon and assign scores to each word
  FILE *file = fopen("sentiment_lexicon.txt", "r");
  char line[256];
  while (fgets(line, sizeof(line), file)) {
    char *word = strtok(line, " ");
    char *score = strtok(NULL, " ");
    int i;
    for (i = 0; i < word_count; i++) {
      if (strcmp(words[i].word, word) == 0) {
        words[i].score += atoi(score);
      }
    }
  }
  fclose(file);

  // Sort the words based on their sentiment scores
  qsort(words, word_count, sizeof(Word), compare_words);

  // Calculate the overall sentiment score of the text
  int sentiment_score = 0;
  int i;
  for (i = 0; i < word_count; i++) {
    sentiment_score += words[i].score;
  }

  // Free the allocated memory
  for (i = 0; i < word_count; i++) {
    free(words[i].word);
  }
  free(words);

  return sentiment_score;
}

int main() {
  // Get the text to analyze from the user
  char text[256];
  printf("Enter the text to analyze: ");
  scanf("%s", text);

  // Analyze the sentiment of the text
  int sentiment_score = analyze_sentiment(text);

  // Print the result
  if (sentiment_score > 0) {
    printf("The text has a positive sentiment.\n");
  } else if (sentiment_score < 0) {
    printf("The text has a negative sentiment.\n");
  } else {
    printf("The text has a neutral sentiment.\n");
  }

  return 0;
}
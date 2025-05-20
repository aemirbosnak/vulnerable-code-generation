//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
  char *word;
  int score;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s text\n", argv[0]);
    return 1;
  }

  // Read the text from the file.
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: could not open file %s\n", argv[1]);
    return 1;
  }

  char *text = malloc(1000);
  if (text == NULL) {
    printf("Error: could not allocate memory for text\n");
    return 1;
  }

  fread(text, 1, 1000, fp);
  fclose(fp);

  // Tokenize the text into words.
  char *token = strtok(text, " ");
  while (token != NULL) {
    words[num_words].word = token;
    words[num_words].score = 0;
    num_words++;
    token = strtok(NULL, " ");
  }

  // Calculate the sentiment score for each word.
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i].word, "good") == 0) {
      words[i].score = 1;
    } else if (strcmp(words[i].word, "bad") == 0) {
      words[i].score = -1;
    }
  }

  // Calculate the overall sentiment score for the text.
  int sentiment_score = 0;
  for (int i = 0; i < num_words; i++) {
    sentiment_score += words[i].score;
  }

  // Print the sentiment score.
  printf("Sentiment score: %d\n", sentiment_score);

  return 0;
}
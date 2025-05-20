//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 200

typedef struct SentimentAnalysis {
  char **words;
  int numWords;
  int sentimentScore;
  char sentence[MAX_SENTENCE_LENGTH];
} SentimentAnalysis;

SentimentAnalysis *createSentimentAnalysis(char *sentence) {
  SentimentAnalysis *sa = malloc(sizeof(SentimentAnalysis));
  sa->words = malloc(MAX_WORDS * sizeof(char *));
  sa->numWords = 0;
  sa->sentimentScore = 0;
  strcpy(sa->sentence, sentence);

  return sa;
}

void analyzeSentiment(SentimentAnalysis *sa) {
  // Tokenize the sentence
  char *sentence = sa->sentence;
  char *word = strtok(sentence, " ");

  // Count the number of words in the sentence
  while (word) {
    sa->words[sa->numWords++] = word;
    word = strtok(NULL, " ");
  }

  // Calculate the sentiment score
  int score = 0;
  for (int i = 0; i < sa->numWords; i++) {
    char *word = sa->words[i];

    // Check if the word is a positive word
    if (isPositiveWord(word)) {
      score++;
    }

    // Check if the word is a negative word
    else if (isNegativeWord(word)) {
      score--;
    }
  }

  sa->sentimentScore = score;
}

int isPositiveWord(char *word) {
  // List of positive words
  char *positiveWords[] = {"happy", "joy", "good", "excellent", "great", "wonderful"};

  for (int i = 0; i < sizeof(positiveWords) / sizeof(char *); i++) {
    if (strcmp(word, positiveWords[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int isNegativeWord(char *word) {
  // List of negative words
  char *negativeWords[] = {"sad", "sad", "bad", "terrible", "awful", "horrible"};

  for (int i = 0; i < sizeof(negativeWords) / sizeof(char *); i++) {
    if (strcmp(word, negativeWords[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  char *sentence = "I am happy that I am alive.";
  SentimentAnalysis *sa = createSentimentAnalysis(sentence);
  analyzeSentiment(sa);

  printf("Sentiment score: %d\n", sa->sentimentScore);

  free(sa->words);
  free(sa);

  return 0;
}
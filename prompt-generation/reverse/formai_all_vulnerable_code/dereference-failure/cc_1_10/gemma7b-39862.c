//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTIMENT_WORDS 10

typedef struct SentimentWord {
  char *word;
  int sentiment;
} SentimentWord;

SentimentWord sentimentWords[MAX_SENTIMENT_WORDS] = {
  {"happy", 1},
  {"sad", -1},
  {"angry", -1},
  {"excited", 1},
  {"fearful", -1},
  {"curious", 0},
  {"proud", 1},
  {"ashamed", -1},
  {"grateful", 1},
  {"optimistic", 1}
};

int main() {
  char sentence[256];

  printf("Enter a sentence: ");
  fgets(sentence, 256, stdin);

  // Remove punctuation from the sentence
  char *word = sentence;
  char *word_without_punctuation = "";
  while (word) {
    word = strchr(word, '.');
    if (word) {
      *word = '\0';
      word_without_punctuation = strcat(word_without_punctuation, word_without_punctuation);
    } else {
      word_without_punctuation = strcat(word_without_punctuation, word);
    }
  }

  // Analyze the sentiment of the sentence
  int sentiment_score = 0;
  for (int i = 0; i < MAX_SENTIMENT_WORDS; i++) {
    if (strstr(word_without_punctuation, sentimentWords[i].word)) {
      sentiment_score += sentimentWords[i].sentiment;
    }
  }

  // Print the sentiment score
  printf("Sentiment score: %d\n", sentiment_score);

  return 0;
}
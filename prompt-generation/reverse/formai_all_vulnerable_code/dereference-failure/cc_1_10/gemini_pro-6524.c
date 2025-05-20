//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SPAM_THRESHOLD 0.5

typedef struct {
  char *word;
  int count;
} WordCount;

int compareWordCounts(const void *a, const void *b) {
  WordCount *wc1 = (WordCount *)a;
  WordCount *wc2 = (WordCount *)b;
  return strcmp(wc1->word, wc2->word);
}

double calculateSpamProbability(int wordCount, int spamWordCount) {
  return spamWordCount / (double)wordCount;
}

int main() {
  // Get the input text.
  char *text = malloc(10000);
  gets(text);

  // Tokenize the input text.
  char *words[1000];
  int numWords = 0;
  char *token = strtok(text, " ");
  while (token != NULL) {
    words[numWords++] = token;
    token = strtok(NULL, " ");
  }

  // Count the occurrences of each word.
  WordCount wordCounts[1000];
  int numWordCounts = 0;
  for (int i = 0; i < numWords; i++) {
    int found = 0;
    for (int j = 0; j < numWordCounts; j++) {
      if (strcmp(words[i], wordCounts[j].word) == 0) {
        wordCounts[j].count++;
        found = 1;
        break;
      }
    }
    if (!found) {
      wordCounts[numWordCounts].word = words[i];
      wordCounts[numWordCounts].count = 1;
      numWordCounts++;
    }
  }

  // Sort the word counts in descending order.
  qsort(wordCounts, numWordCounts, sizeof(WordCount), compareWordCounts);

  // Calculate the spam probability.
  int spamWordCount = 0;
  for (int i = 0; i < numWordCounts; i++) {
    if (wordCounts[i].count >= SPAM_THRESHOLD) {
      spamWordCount++;
    }
  }
  double spamProbability = calculateSpamProbability(numWords, spamWordCount);

  // Print the spam probability.
  printf("Spam probability: %.2f%%\n", spamProbability * 100);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTIMENTS 100

typedef struct {
  char *word;
  int sentiment;
} WordSentiment;

WordSentiment words[MAX_WORDS];
int numWords = 0;

typedef struct {
  char *sentence;
  int sentiment;
} SentenceSentiment;

SentenceSentiment sentences[MAX_SENTIMENTS];
int numSentences = 0;

int main() {
  // Load the word sentiments
  FILE *fp = fopen("sentiments.txt", "r");
  if (fp == NULL) {
    perror("Error opening sentiments.txt");
    return EXIT_FAILURE;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *word = strtok(line, "\t");
    int sentiment = atoi(strtok(NULL, "\n"));

    words[numWords].word = strdup(word);
    words[numWords].sentiment = sentiment;
    numWords++;
  }

  fclose(fp);

  // Load the sentences
  fp = fopen("sentences.txt", "r");
  if (fp == NULL) {
    perror("Error opening sentences.txt");
    return EXIT_FAILURE;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    char *sentence = strdup(line);

    sentences[numSentences].sentence = sentence;
    sentences[numSentences].sentiment = 0;
    numSentences++;
  }

  fclose(fp);

  // Calculate the sentiment of each sentence
  for (int i = 0; i < numSentences; i++) {
    char *sentence = sentences[i].sentence;
    char *token = strtok(sentence, " ");

    while (token != NULL) {
      for (int j = 0; j < numWords; j++) {
        if (strcmp(token, words[j].word) == 0) {
          sentences[i].sentiment += words[j].sentiment;
          break;
        }
      }

      token = strtok(NULL, " ");
    }
  }

  // Print the sentences and their sentiments
  for (int i = 0; i < numSentences; i++) {
    printf("%s: %d\n", sentences[i].sentence, sentences[i].sentiment);
  }

  return EXIT_SUCCESS;
}
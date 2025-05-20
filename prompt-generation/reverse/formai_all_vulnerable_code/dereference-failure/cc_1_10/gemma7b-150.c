//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
  char *word;
  int sentiment;
} Word;

Word *createWord(char *word, int sentiment) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->sentiment = sentiment;
  return newWord;
}

int main() {
  Word *words = NULL;
  char input[MAX_WORDS];

  printf("Enter a sentence: ");
  fgets(input, MAX_WORDS, stdin);

  // Tokenize the sentence and create a list of words
  char *token = strtok(input, " ");
  while (token) {
    words = createWord(token, getSentiment(token));
    token = strtok(NULL, " ");
  }

  // Calculate the overall sentiment of the sentence
  int totalSentiment = 0;
  for (Word *word = words; word; word++) {
    totalSentiment += word->sentiment;
  }

  // Print the sentiment of the sentence
  printf("The sentiment of the sentence is: ");
  switch (totalSentiment) {
    case 0:
      printf("Neutral\n");
      break;
    case 1:
      printf("Positive\n");
      break;
    case -1:
      printf("Negative\n");
      break;
  }

  return 0;
}

int getSentiment(char *word) {
  // Sentiment dictionary
  int sentimentDictionary[] = {
    -2, // Hate
    -1, // Dislike
    0, // Neutral
    1, // Like
    2, // Love
  };

  // Compare the word to the sentiment dictionary
  for (int i = 0; i < 5; i++) {
    if (strcmp(word, sentimentDictionary[i]) == 0) {
      return sentimentDictionary[i];
    }
  }

  // Return neutral sentiment if the word is not found in the dictionary
  return 0;
}
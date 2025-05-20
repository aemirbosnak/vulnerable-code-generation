//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word **createWordList(char **sentence, int sentenceLength) {
  Word **wordList = malloc(sizeof(Word *) * MAX_WORDS);
  int i = 0;
  for (char **wordPtr = sentence; i < sentenceLength; i++, wordPtr++) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(*wordPtr);
    newWord->frequency = 1;
    wordList[i] = newWord;
  }
  return wordList;
}

int calculateWordFrequency(Word **wordList, char *word) {
  int i = 0;
  for (Word *wordPtr = wordList; i < MAX_WORDS; i++) {
    if (strcmp(wordPtr->word, word) == 0) {
      wordPtr->frequency++;
      return wordPtr->frequency;
    }
  }
  return 0;
}

int detectSpam(char **sentence, int sentenceLength) {
  char **stopWords = {"the", "a", "of", "to", "in", "that", "it", "for", "about", "in", "with"};
  Word **wordList = createWordList(sentence, sentenceLength);
  int i = 0;
  for (Word *wordPtr = wordList; i < MAX_WORDS; i++) {
    if (wordPtr->frequency > 5 && isStopWord(stopWords, wordPtr->word) && isPunctuation(wordPtr->word)) {
      return 1;
    }
  }
  return 0;
}

int isStopWord(char **stopWords, char *word) {
  int i = 0;
  for (char **stopWord = stopWords; i < MAX_WORDS; i++) {
    if (strcmp(stopWord, word) == 0) {
      return 1;
    }
  }
  return 0;
}

int isPunctuation(char *word) {
  return word[0] >= 33 && word[0] <= 126;
}

int main() {
  char **sentence = {"This is a spam email with too many words and punctuation marks. It is a very long email that could be considered spam"};
  int sentenceLength = 100;
  int spamScore = detectSpam(sentence, sentenceLength);
  if (spamScore) {
    printf("This email is considered spam.");
  } else {
    printf("This email is not considered spam.");
  }
  return 0;
}
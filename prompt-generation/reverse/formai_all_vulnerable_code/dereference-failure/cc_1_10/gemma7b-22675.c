//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct Word
{
  char *word;
  int count;
  struct Word *next;
} Word;

Word *createWord(char *word)
{
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->count = 1;
  newWord->next = NULL;
  return newWord;
}

void addWord(Word *wordList, char *word)
{
  Word *newWord = createWord(word);
  if (wordList == NULL)
  {
    wordList = newWord;
  }
  else
  {
    Word *iter = wordList;
    while (iter->next)
    {
      iter = iter->next;
    }
    iter->next = newWord;
  }
}

int main()
{
  Word *wordList = NULL;
  char *sentence = "The quick brown fox jumps over the lazy dog.";

  // Split the sentence into words
  char *word = strtok(sentence, " ");
  while (word)
  {
    addWord(wordList, word);
    word = strtok(NULL, " ");
  }

  // Analyze the word count
  Word *iter = wordList;
  int totalWords = 0;
  while (iter)
  {
    totalWords += iter->count;
    iter = iter->next;
  }

  // Print the total number of words
  printf("Total number of words: %d\n", totalWords);

  return 0;
}
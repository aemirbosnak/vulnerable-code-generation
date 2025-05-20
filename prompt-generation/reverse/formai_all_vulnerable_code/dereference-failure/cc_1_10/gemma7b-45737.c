//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word {
  char *word;
  struct Word *next;
} Word;

Word *createWord(char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;
  return newWord;
}

void translate(Word *wordList) {
  char *translatedWord = NULL;
  switch (wordList->word[0]) {
    case 'a':
      translatedWord = "apple";
      break;
    case 'b':
      translatedWord = "banana";
      break;
    case 'c':
      translatedWord = "cherry";
      break;
    default:
      translatedWord = "Unknown fruit";
  }
  printf("%s is translated to %s\n", wordList->word, translatedWord);
}

int main() {
  Word *wordList = createWord("apple");
  translate(wordList);

  wordList = createWord("banana");
  translate(wordList);

  wordList = createWord("cherry");
  translate(wordList);

  wordList = createWord("orange");
  translate(wordList);

  return 0;
}
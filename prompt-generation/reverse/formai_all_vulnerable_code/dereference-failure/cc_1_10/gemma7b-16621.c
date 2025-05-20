//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
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

Word **createWordList(int *numWords) {
  Word **words = malloc(sizeof(Word *) * MAX_WORDS);
  *numWords = 0;
  return words;
}

void addWordToWordList(Word **words, int *numWords, char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = 0;
  words[*numWords] = newWord;
  (*numWords)++;
}

int main() {
  int numWords = 0;
  Word **words = createWordList(&numWords);

  char sentence[MAX_SENTENCE_LENGTH];
  printf("Enter a sentence: ");
  fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

  char *wordsInSentence = strtok(sentence, " ");

  while (wordsInSentence) {
    addWordToWordList(words, &numWords, wordsInSentence);
    wordsInSentence = strtok(NULL, " ");
  }

  int spamScore = 0;
  for (int i = 0; i < numWords; i++) {
    if (words[i]->word[0] == 'p' || words[i]->word[0] == 'P' ||
        words[i]->word[0] == 'a' || words[i]->word[0] == 'A' ||
        strcmp(words[i]->word, "free") == 0) {
      spamScore++;
    }
  }

  if (spamScore > 0) {
    printf("Your sentence contains suspicious words and may be spam.\n");
  } else {
    printf("Your sentence does not contain any suspicious words.\n");
  }

  return 0;
}
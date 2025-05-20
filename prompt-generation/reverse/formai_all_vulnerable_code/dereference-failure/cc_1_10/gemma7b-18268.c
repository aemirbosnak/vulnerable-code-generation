//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

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
  newWord->frequency = 1;
  words[*numWords] = newWord;
  (*numWords)++;
}

int calculateWordSimilarity(Word *word1, Word *word2) {
  int similarity = 0;
  int minLength = 0;
  if (strlen(word1->word) < strlen(word2->word)) {
    minLength = strlen(word1->word);
  } else {
    minLength = strlen(word2->word);
  }

  for (int i = 0; i < minLength; i++) {
    if (word1->word[i] == word2->word[i]) {
      similarity++;
    }
  }

  return similarity;
}

int main() {
  int numWords = 0;
  Word **words = createWordList(&numWords);

  addWordToWordList(words, &numWords, "apple");
  addWordToWordList(words, &numWords, "banana");
  addWordToWordList(words, &numWords, "orange");
  addWordToWordList(words, &numWords, "apricot");

  Word *word1 = words[0];
  Word *word2 = words[2];

  int similarity = calculateWordSimilarity(word1, word2);

  printf("Similarity: %d", similarity);

  return 0;
}
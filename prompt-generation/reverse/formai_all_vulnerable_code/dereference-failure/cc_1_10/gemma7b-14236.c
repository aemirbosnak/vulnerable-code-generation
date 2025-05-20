//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct WordCount {
  char **words;
  int word_count;
} WordCount;

WordCount *word_count_alloc(int words_num)
{
  WordCount *word_count = malloc(sizeof(WordCount));
  word_count->words = malloc(words_num * sizeof(char *));
  word_count->word_count = 0;
  return word_count;
}

void word_count_add(WordCount *word_count, char *word)
{
  int i = 0;
  for (; i < word_count->word_count && strcmp(word_count->words[i], word) != 0; i++) {}
  if (i == word_count->word_count) {
    word_count->words = realloc(word_count->words, (word_count->word_count + 1) * sizeof(char *));
    word_count->word_count++;
  }
  word_count->words[word_count->word_count - 1] = strdup(word);
}

void word_count_print(WordCount *word_count)
{
  int i = 0;
  printf("Word count: %d\n", word_count->word_count);
  for (; i < word_count->word_count; i++) {
    printf("%s, ", word_count->words[i]);
  }
  printf("\n");
}

int main()
{
  WordCount *word_count = word_count_alloc(MAX_WORDS);
  word_count_add(word_count, "Linux");
  word_count_add(word_count, "Torvalds");
  word_count_add(word_count, "C");
  word_count_add(word_count, "Programming");
  word_count_print(word_count);

  free(word_count->words);
  free(word_count);

  return 0;
}
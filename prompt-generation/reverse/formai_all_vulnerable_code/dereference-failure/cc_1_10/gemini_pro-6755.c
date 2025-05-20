//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

int main() {
  char *text;
  int num_words;
  int word_lengths[MAX_WORDS];
  char **words[MAX_WORDS];
  int i, j;

  printf("Enter some text (max 10,000 words, max 100 chars per word):\n");
  text = malloc(100000);
  gets(text);

  num_words = 0;
  words[num_words] = strtok(text, " ");
  while (words[num_words] != NULL) {
    num_words++;
    words[num_words] = strtok(NULL, " ");
  }

  for (i = 0; i < num_words; i++) {
    word_lengths[i] = strlen(words[i]);
  }

  // Sort the words by length
  for (i = 0; i < num_words - 1; i++) {
    for (j = i + 1; j < num_words; j++) {
      if (word_lengths[i] > word_lengths[j]) {
        int temp = word_lengths[i];
        word_lengths[i] = word_lengths[j];
        word_lengths[j] = temp;

        char *temp2 = words[i];
        words[i] = words[j];
        words[j] = temp2;
      }
    }
  }

  // Print the sorted words
  printf("The sorted words are:\n");
  for (i = 0; i < num_words; i++) {
    printf("%s\n", words[i]);
  }

  free(text);
  return 0;
}
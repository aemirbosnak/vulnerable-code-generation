//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
  char **words;
  int num_words;
} WordList;

WordList *generate_word_list(int num_words) {
  WordList *word_list = malloc(sizeof(WordList));
  word_list->words = malloc(sizeof(char *) * num_words);
  word_list->num_words = num_words;

  for (int i = 0; i < num_words; i++) {
    int word_length = rand() % 10 + 1;
    word_list->words[i] = malloc(sizeof(char) * word_length);
    for (int j = 0; j < word_length; j++) {
      word_list->words[i][j] = 'a' + rand() % 26;
    }
  }

  return word_list;
}

void free_word_list(WordList *word_list) {
  for (int i = 0; i < word_list->num_words; i++) {
    free(word_list->words[i]);
  }
  free(word_list->words);
  free(word_list);
}

void print_word_list(WordList *word_list) {
  for (int i = 0; i < word_list->num_words; i++) {
    printf("%s ", word_list->words[i]);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));

  int num_words = 100;
  WordList *word_list = generate_word_list(num_words);

  print_word_list(word_list);

  char input[1024];
  printf("Type the words as fast as you can: ");
  scanf("%s", input);

  int correct_words = 0;
  for (int i = 0; i < num_words; i++) {
    if (strcmp(input, word_list->words[i]) == 0) {
      correct_words++;
    }
  }

  printf("You typed %d words correctly!\n", correct_words);

  free_word_list(word_list);

  return 0;
}
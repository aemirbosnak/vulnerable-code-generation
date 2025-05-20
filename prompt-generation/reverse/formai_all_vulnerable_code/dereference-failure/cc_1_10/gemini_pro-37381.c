//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct word {
  char *str;
  int count;
};

struct word_list {
  struct word words[MAX_WORDS];
  int size;
};

struct word_list *create_word_list() {
  struct word_list *list = malloc(sizeof(struct word_list));
  list->size = 0;
  return list;
}

void free_word_list(struct word_list *list) {
  for (int i = 0; i < list->size; i++) {
    free(list->words[i].str);
  }
  free(list);
}

int add_word(struct word_list *list, char *word) {
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->words[i].str, word) == 0) {
      list->words[i].count++;
      return 0;
    }
  }
  if (list->size < MAX_WORDS) {
    list->words[list->size].str = strdup(word);
    list->words[list->size].count = 1;
    list->size++;
    return 1;
  }
  return -1;
}

void print_word_list(struct word_list *list) {
  for (int i = 0; i < list->size; i++) {
    printf("%s: %d\n", list->words[i].str, list->words[i].count);
  }
}

int main() {
  struct word_list *list = create_word_list();
  char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
  int num_words = sizeof(words) / sizeof(char *);
  for (int i = 0; i < num_words; i++) {
    add_word(list, words[i]);
  }
  print_word_list(list);
  free_word_list(list);
  return 0;
}
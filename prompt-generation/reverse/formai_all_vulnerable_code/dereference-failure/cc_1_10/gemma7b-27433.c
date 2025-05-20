//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: visionary
#include <stdio.h>
#include <string.h>

#define CAT_LANG_MAX_WORDS 10

typedef struct CatWord {
  char *word;
  struct CatWord *next;
} CatWord;

CatWord *cat_lang_add_word(CatWord **head, char *word) {
  CatWord *new_word = malloc(sizeof(CatWord));
  new_word->word = strdup(word);
  new_word->next = NULL;

  if (*head == NULL) {
    *head = new_word;
  } else {
    (*head)->next = new_word;
  }

  return new_word;
}

int cat_lang_translate(CatWord *head, char *input) {
  char *token = strtok(input, " ");
  int i = 0;

  while (token) {
    CatWord *word = head;

    while (word) {
      if (strcmp(token, word->word) == 0) {
        printf("%s ", word->word);
      } else {
        word = word->next;
      }
    }

    token = strtok(NULL, " ");
  }

  return 0;
}

int main() {
  CatWord *head = NULL;
  cat_lang_add_word(&head, "Meow");
  cat_lang_add_word(&head, "Purr");
  cat_lang_add_word(&head, "Woof");

  cat_lang_translate(head, "Meow Purr Woof");

  return 0;
}
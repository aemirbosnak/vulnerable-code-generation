//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

typedef struct CAT_WORD {
  char *word;
  int length;
  struct CAT_WORD *next;
} CatWord;

CatWord *cat_word_create(char *word)
{
  CatWord *new_word = malloc(sizeof(CatWord));
  new_word->word = strdup(word);
  new_word->length = strlen(word);
  new_word->next = NULL;

  return new_word;
}

void cat_word_add(CatWord *head, char *word)
{
  CatWord *new_word = cat_word_create(word);

  if (head == NULL) {
    head = new_word;
  } else {
    CatWord *curr = head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = new_word;
  }
}

void translate(CatWord *head)
{
  for (CatWord *curr = head; curr; curr = curr->next) {
    printf("%s ", curr->word);
  }
  printf("\n");
}

int main()
{
  CatWord *head = NULL;

  cat_word_add(head, "Meow");
  cat_word_add(head, "Woof");
  cat_word_add(head, "Chirp");
  cat_word_add(head, "Fluff");

  translate(head);

  return 0;
}
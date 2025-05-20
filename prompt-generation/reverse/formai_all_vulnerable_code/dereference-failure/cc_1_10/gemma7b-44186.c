//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define CAT_LANG_MAX_WORDS 10

typedef struct CatLangWord {
  char word[20];
  struct CatLangWord* next;
} CatLangWord;

CatLangWord* cat_lang_add_word(CatLangWord* head, char* word) {
  CatLangWord* new_word = malloc(sizeof(CatLangWord));
  strcpy(new_word->word, word);
  new_word->next = NULL;

  if (head == NULL) {
    head = new_word;
  } else {
    head->next = new_word;
  }

  return head;
}

int cat_lang_translate(CatLangWord* head, char* input) {
  char* words = strtok(input, " ");
  int i = 0;

  while (words[i] != NULL) {
    char* translated_word = NULL;

    for (CatLangWord* word = head; word != NULL; word++) {
      if (strcmp(words[i], word->word) == 0) {
        translated_word = word->word;
      }
    }

    if (translated_word == NULL) {
      translated_word = "UNKNOWN";
    }

    printf("%s ", translated_word);
    i++;
  }

  printf("\n");

  return 0;
}

int main() {
  CatLangWord* head = NULL;

  cat_lang_add_word(head, "Meow");
  cat_lang_add_word(head, "Woof");
  cat_lang_add_word(head, "Purr");
  cat_lang_add_word(head, "Hiss");

  cat_lang_translate(head, "I am a cat. Meow and woof.");

  return 0;
}
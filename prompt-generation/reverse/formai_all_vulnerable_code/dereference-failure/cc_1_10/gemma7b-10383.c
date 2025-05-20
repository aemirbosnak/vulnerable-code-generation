//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word {
  char word[20];
  struct Word* next;
} Word;

Word* insertWord(Word* head, char* word) {
  Word* newWord = malloc(sizeof(Word));
  strcpy(newWord->word, word);
  newWord->next = NULL;

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = newWord;
  }

  return head;
}

int translateCat(Word* head, char* source) {
  char* target = malloc(strlen(source) * 2);
  int i = 0;

  for (i = 0; source[i] != '\0'; i++) {
    switch (source[i]) {
      case 'a':
        target[i] = 'a';
        break;
      case 'e':
        target[i] = 'e';
        break;
      case 'i':
        target[i] = 'i';
        break;
      case 'o':
        target[i] = 'o';
        break;
      case 'u':
        target[i] = 'u';
        break;
      default:
        target[i] = source[i];
    }
  }

  target[i] = '\0';

  printf("%s\n", target);

  free(target);

  return 0;
}

int main() {
  Word* head = NULL;
  insertWord(head, "meow");
  insertWord(head, "purr");
  insertWord(head, "miaow");

  translateCat(head, "The cat jumps high.");

  return 0;
}
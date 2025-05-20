//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct Node {
  char word[MAX_WORDS];
  struct Node* next;
} Node;

void translate(Node* head) {
  while (head) {
    switch (head->word[0]) {
      case 'a':
        head->word[0] = 'a';
        break;
      case 'e':
        head->word[0] = 'e';
        break;
      case 'i':
        head->word[0] = 'i';
        break;
      case 'o':
        head->word[0] = 'o';
        break;
      case 'u':
        head->word[0] = 'u';
        break;
    }
    head = head->next;
  }
}

int main() {
  Node* head = NULL;
  head = malloc(sizeof(Node));
  head->word[0] = 'h';
  head->word[1] = 'a';
  head->word[2] = 'i';
  head->word[3] = '\0';
  head->next = malloc(sizeof(Node));
  head->next->word[0] = 'b';
  head->next->word[1] = 'e';
  head->next->word[2] = 'r';
  head->next->word[3] = '\0';
  head->next->next = malloc(sizeof(Node));
  head->next->next->word[0] = 'c';
  head->next->next->word[1] = 'a';
  head->next->next->word[2] = 't';
  head->next->next->word[3] = '\0';

  translate(head);

  while (head) {
    printf("%s ", head->word);
    head = head->next;
  }

  return 0;
}
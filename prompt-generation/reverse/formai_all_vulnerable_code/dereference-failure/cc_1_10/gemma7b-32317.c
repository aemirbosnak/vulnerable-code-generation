//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: shape shifting
#include <stdio.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
  char data;
  struct Node* next;
} Node;

Node* insert(Node* head, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int spellCheck(Node* head, char* word) {
  int i = 0;
  for (Node* current = head; current; current = current->next) {
    if (word[i] == current->data) {
      i++;
    }
  }

  return i == strlen(word);
}

int main() {
  Node* head = NULL;
  insert(head, 'a');
  insert(head, 'b');
  insert(head, 'c');
  insert(head, 'd');
  insert(head, 'e');

  char* word = "abc";
  if (spellCheck(head, word) == 1) {
    printf("Word found!\n");
  } else {
    printf("Word not found.\n");
  }

  return 0;
}
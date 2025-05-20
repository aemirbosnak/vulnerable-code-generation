//FormAI DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node* createNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void addNode(struct Node **head, int data) {
  if(*head == NULL) {
    *head = createNode(data);
  } else {
    struct Node *temp = *head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = createNode(data);
  }
}

void deleteNode(struct Node **head, int data) {
  if(*head == NULL) {
    return;
  }
  if((*head)->data == data) {
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
  } else {
    struct Node *current = *head;
    while(current->next != NULL && current->next->data != data) {
      current = current->next;
    }
    if(current->next != NULL) {
      struct Node *temp = current->next;
      current->next = current->next->next;
      free(temp);
    }
  }
}

void printList(struct Node *head) {
  struct Node *temp = head;
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  struct Node *head = NULL;
  addNode(&head, 5);
  addNode(&head, 10);
  addNode(&head, 15);
  printList(head);
  deleteNode(&head, 10);
  printList(head);
  return 0;
}
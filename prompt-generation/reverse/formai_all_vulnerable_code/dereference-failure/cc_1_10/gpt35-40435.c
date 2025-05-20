//FormAI DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* next;
};

// Function declarations 
void allocateMemory(struct node** head, int num);
void freeMemory(struct node** head);
void printList(struct node* head);

int main () {
  struct node* head = NULL;

  allocateMemory(&head, 10);
  printList(head);
  
  freeMemory(&head);
  
  return 0;
}

void allocateMemory(struct node** head, int num) {
  struct node* temp = NULL;
  struct node* current = NULL;
  
  for (int i = 0; i < num; i++) {
    temp = (struct node*) malloc(sizeof(struct node));
    if (*head == NULL) {
      *head = temp;
      current = *head;
    } else {
      current->next = temp;
      current = current->next;
    }
    current->value = i;
  }
}

void freeMemory(struct node** head) {
  struct node* current = *head;
  struct node* temp = *head;
  
  while (current != NULL) {
    temp = current;
    current = current->next;
    free(temp);
  }
  
  *head = NULL;
}

void printList(struct node* head) {
  struct node* current = head;

  while (current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}
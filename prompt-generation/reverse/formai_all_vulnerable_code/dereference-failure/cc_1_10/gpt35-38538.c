//FormAI DATASET v1.0 Category: Linked list operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void addElement(struct Node** headRef, int element) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode -> data = element;
  newNode -> next = (*headRef);
  (*headRef) = newNode;
}

void printList(struct Node* node) {
  while (node != NULL) {
    printf("%d ", node -> data);
    node = node -> next;
  }
}

int main() {
  struct Node* head = NULL;

  addElement(&head, 1);
  addElement(&head, 2);
  addElement(&head, 3);
  addElement(&head, 4);
  addElement(&head, 5);

  printf("Linked List: ");
  printList(head);
  
  struct Node* current = head;
  struct Node* prev = NULL;

  int deleteData = 5;

  while (current != NULL) {
    if (current -> data == deleteData) {
      if (prev == NULL) {
        head = current -> next;
        free(current);
        break;
      } else {
        prev -> next = current -> next;
        free(current);
        break;
      }
    }
    prev = current;
    current = current -> next;
  }

  printf("\nLinked List after deleting %d: ", deleteData);
  printList(head);

  return 0;
}
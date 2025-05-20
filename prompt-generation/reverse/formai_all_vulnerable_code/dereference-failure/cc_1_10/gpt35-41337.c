//FormAI DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *start = NULL;

void displayList() {
  struct node *ptr;
  ptr = start;

  if (ptr == NULL) {
    printf("List is empty\n");
    return;
  }

  printf("Linked list: ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

void insertAtBeginning(int item) {
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  
  temp->data = item;
  temp->next = start;
  
  start = temp;
}

void insertAtEnd(int item) {
  struct node *temp, *ptr;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = item;
  temp->next = NULL;

  if(start == NULL) {
    start = temp;
    return;
  }

  ptr = start;

  while(ptr->next != NULL) {
    ptr = ptr->next;
  }

  ptr->next = temp;
}

void insertAtPosition(int item, int pos) {
  struct node *temp, *ptr, *prev;
  temp = (struct node *)malloc(sizeof(struct node));
  
  temp->data = item;
  ptr = start;
  
  for (int i = 1; i < pos && ptr != NULL; i++) {
    prev = ptr;
    ptr = ptr->next;
  }
  
  prev->next = temp;
  temp->next = ptr;
}

void deleteAtBeginning() {
  struct node *ptr;

  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  ptr = start;
  start = start->next;
  free(ptr);
}

void deleteAtEnd() {
  struct node *ptr, *prev;

  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  if (start->next == NULL) {
    free(start);
    start = NULL;
    return;
  }

  ptr = start;

  while (ptr->next != NULL) {
    prev = ptr;
    ptr = ptr->next;
  }

  prev->next = NULL;
  free(ptr);
}

void deleteAtPosition(int pos) {
  struct node *ptr, *prev;

  if (start == NULL) {
    printf("List is empty\n");
    return;
  }

  ptr = start;
  
  for (int i = 1; i < pos && ptr != NULL; i++) {
    prev = ptr;
    ptr = ptr->next;
  }
  
  if (ptr == NULL) {
    printf("Position not found\n");
    return;
  }

  prev->next = ptr->next;
  free(ptr);
}

int main() {
  int choice, item, pos;
    
  while(1) {
    printf("1. Display List\n");
    printf("2. Insert at beginning\n");
    printf("3. Insert at end\n");
    printf("4. Insert at position\n");
    printf("5. Delete at beginning\n");
    printf("6. Delete at end\n");
    printf("7. Delete at position\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        displayList();
        break;
      case 2:
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        insertAtBeginning(item);
        break;
      case 3:
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        insertAtEnd(item);
        break;
      case 4:
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);
        printf("Enter the position: ");
        scanf("%d", &pos);
        insertAtPosition(item, pos);
        break;
      case 5:
        deleteAtBeginning();
        break;
      case 6:
        deleteAtEnd();
        break;
      case 7:
        printf("Enter the position: ");
        scanf("%d", &pos);
        deleteAtPosition(pos);
        break;
      case 8:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  
  return 0;
}
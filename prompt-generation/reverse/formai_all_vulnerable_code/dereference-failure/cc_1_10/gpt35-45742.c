//FormAI DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Defining the shape shifting structure
struct ShapeShifter {
  enum {
    NUMBER,
    STRING,
    FLOAT
  } type;
  union {
    int number;
    char* string;
    float floating;
  };
  struct ShapeShifter* next;
};

// Function to create a new node in the linked list
struct ShapeShifter* createNode(int number, char* string, float floating) {
  struct ShapeShifter* newNode = (struct ShapeShifter*)malloc(sizeof(struct ShapeShifter));
  if (newNode == NULL) {
    printf("Error: memory allocation unsuccessful!");
    return NULL;
  }
  newNode->type = NUMBER;
  newNode->number = number;
  newNode->next = NULL;

  if (string != NULL) {
    newNode->type = STRING;
    newNode->string = string;
  }

  if (floating != 0.0f) {
    newNode->type = FLOAT;
    newNode->floating = floating;
  }

  return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertNode(struct ShapeShifter** head, int number, char* string, float floating) {
  struct ShapeShifter* newNode = createNode(number, string, floating);
  newNode->next = *head;
  *head = newNode;
}

// Function to display the linked list
void displayList(struct ShapeShifter* head) {
  while (head != NULL) {
    switch (head->type) {
      case NUMBER:
        printf("%d ", head->number);
        break;
      case STRING:
        printf("%s ", head->string);
        break;
      case FLOAT:
        printf("%.2f ", head->floating);
        break;
    }
    head = head->next;
  }
  printf("\n");
}

// Driver function to demonstrate the shape shifting linked list operations
int main() {
  struct ShapeShifter* head = NULL;
  insertNode(&head, 10, NULL, 0.0f);
  insertNode(&head, 20, NULL, 0.0f);
  insertNode(&head, 30, NULL, 0.0f);
  insertNode(&head, 40, NULL, 0.0f);
  insertNode(&head, 50, "fifty", 0.0f);
  insertNode(&head, 60, "sixty", 1.23f);
  displayList(head);
  return 0;
}
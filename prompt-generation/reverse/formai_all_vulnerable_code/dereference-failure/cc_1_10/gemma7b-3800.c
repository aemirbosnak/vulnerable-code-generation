//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Color {
  int red;
  int green;
  int blue;
  struct Color* next;
} Color;

void insertNode(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void insertColor(Color** head, int red, int green, int blue) {
  Color* newNode = (Color*)malloc(sizeof(Color));
  newNode->red = red;
  newNode->green = green;
  newNode->blue = blue;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int main() {
  Node* head = NULL;
  insertNode(&head, 10);
  insertNode(&head, 20);
  insertNode(&head, 30);

  Color* colorHead = NULL;
  insertColor(&colorHead, 255, 0, 0);
  insertColor(&colorHead, 0, 255, 0);
  insertColor(&colorHead, 0, 0, 255);

  printf("Nodes:");
  for (Node* node = head; node; node = node->next) {
    printf(" %d", node->data);
  }

  printf("\nColors:");
  for (Color* color = colorHead; color; color = color->next) {
    printf(" Red: %d, Green: %d, Blue: %d", color->red, color->green, color->blue);
  }

  return 0;
}
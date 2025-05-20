//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 10

typedef struct Node {
  struct Node* next;
  void* data;
} Node;

Node* createNode(void* data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void deleteNode(Node* node) {
  free(node);
}

int main() {
  Node* head = NULL;
  void* memory = malloc(MAX_MEMORY);
  int memoryIndex = 0;

  // Simulate solving a mystery...

  // Scene 1: The Suspect's Room
  void* suspectData = malloc(10);
  suspectData = "Mr. Jones";
  head = createNode(suspectData);

  // Scene 2: The Drawing-Room
  void* witnessData = malloc(20);
  witnessData = "Miss Scarlet";
  Node* secondNode = createNode(witnessData);
  secondNode->next = head;

  // Scene 3: The Library
  void* bookData = malloc(30);
  bookData = "The Adventures of Sherlock Holmes";
  Node* thirdNode = createNode(bookData);
  thirdNode->next = secondNode;

  // Scene 4: The Conclusion
  printf("The mystery has been solved! The suspects are:\n");
  while (head) {
    printf("%s\n", (char*)head->data);
    deleteNode(head);
    head = NULL;
  }

  free(memory);
  return 0;
}
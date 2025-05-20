//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
  char name[20];
  struct Node* next;
  struct Node* dir;
  FILE* file;
} Node;

Node* head = NULL;

void createNode(char* name) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->dir = NULL;
  newNode->file = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void createDir(char* name) {
  createNode(name);
  Node* newNode = head;
  newNode->dir = (Node*)malloc(sizeof(Node));
  newNode->dir->name[0] = '\0';
  newNode->dir->next = NULL;
  newNode->dir->dir = NULL;
  newNode->dir->file = NULL;
}

void createFile(char* name) {
  createNode(name);
  Node* newNode = head;
  newNode->file = fopen(name, "w");
}

void listDir() {
  Node* current = head;
  while (current) {
    if (current->dir) {
      printf("%s\n", current->name);
    }
    current = current->next;
  }
}

int main() {
  createDir("home");
  createDir("home/Documents");
  createDir("home/Pictures");
  createFile("home/Documents/my_document.txt");
  createFile("home/Pictures/my_picture.jpg");

  listDir();

  return 0;
}
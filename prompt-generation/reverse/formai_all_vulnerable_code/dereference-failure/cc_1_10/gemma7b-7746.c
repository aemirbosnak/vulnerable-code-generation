//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_SIZE 10
#define MAX_FILE_SIZE 512

typedef struct Node {
  char name[256];
  struct Node* next;
  struct Node* dir;
  FILE* file;
} Node;

Node* newNode(char* name, Node* dir, FILE* file) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  newNode->dir = dir;
  newNode->file = file;
  return newNode;
}

void printDir(Node* dir) {
  printf("Directory: %s\n", dir->name);
  for (Node* node = dir->next; node; node = node->next) {
    printf("%s\n", node->name);
  }
}

void searchFile(Node* dir, char* filename) {
  for (Node* node = dir->next; node; node = node->next) {
    if (strcmp(node->name, filename) == 0) {
      printf("File found: %s\n", node->name);
      return;
    }
  }
  printf("File not found: %s\n", filename);
}

int main() {
  Node* root = newNode("Root", NULL, NULL);
  newNode("Dir1", root, NULL);
  newNode("Dir2", root, NULL);
  newNode("File1.txt", root->dir->dir, fopen("file1.txt", "w"));
  newNode("File2.txt", root->dir->dir, fopen("file2.txt", "w"));

  printDir(root);
  searchFile(root, "File1.txt");
  searchFile(root, "File3.txt");

  return 0;
}
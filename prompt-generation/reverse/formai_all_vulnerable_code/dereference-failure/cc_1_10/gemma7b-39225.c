//Gemma-7B DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileRecord {
  char name[256];
  int size;
  struct FileRecord* next;
};

void insertFile(struct FileRecord* head, char* name, int size) {
  struct FileRecord* newNode = malloc(sizeof(struct FileRecord));
  strcpy(newNode->name, name);
  newNode->size = size;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct FileRecord* traverse = head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }
}

int searchFile(struct FileRecord* head, char* name) {
  struct FileRecord* traverse = head;
  while (traverse) {
    if (strcmp(traverse->name, name) == 0) {
      return 1;
    }
    traverse = traverse->next;
  }
  return 0;
}

int main() {
  struct FileRecord* head = NULL;
  insertFile(head, "test.txt", 1024);
  insertFile(head, "image.jpg", 512);
  insertFile(head, "music.mp3", 2048);

  if (searchFile(head, "image.jpg") == 1) {
    printf("File found: image.jpg\n");
  } else {
    printf("File not found: image.jpg\n");
  }

  return 0;
}
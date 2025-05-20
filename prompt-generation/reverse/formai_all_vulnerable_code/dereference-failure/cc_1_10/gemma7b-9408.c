//Gemma-7B DATASET v1.0 Category: Cryptography Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define KEY_SIZE 32

typedef struct Node {
  char key[KEY_SIZE];
  struct Node* next;
} Node;

Node* insertKey(Node* head, char* key) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->key, key);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void encryptFile(Node* head, char* filename) {
  int fd = open(filename, O_RDWR);
  char buffer[1024];
  int readBytes, writtenBytes;

  while ((readBytes = read(fd, buffer, 1024)) > 0) {
    for (int i = 0; i < readBytes; i++) {
      char key = head->key[rand() % KEY_SIZE];
      buffer[i] ^= key;
    }

    writtenBytes = write(fd, buffer, readBytes);
  }

  close(fd);
}

int main() {
  Node* head = insertKey(NULL, "mysecretkey");
  encryptFile(head, "myfile.txt");

  return 0;
}
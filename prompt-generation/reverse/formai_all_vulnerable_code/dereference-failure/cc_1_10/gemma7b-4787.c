//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  struct Node* next;
  char data[MAX_BUFFER_SIZE];
} Node;

void compress(char* str) {
  Node* head = NULL;
  Node* tail = NULL;

  for (int i = 0; str[i] != '\0'; i++) {
    if (head == NULL) {
      head = tail = malloc(sizeof(Node));
      head->data[0] = str[i];
      head->next = NULL;
    } else if (tail->next == NULL) {
      tail->next = malloc(sizeof(Node));
      tail = tail->next;
      tail->data[0] = str[i];
      tail->next = NULL;
    } else {
      int flag = 0;
      for (Node* current = head; current; current = current->next) {
        if (str[i] == current->data[0]) {
          flag = 1;
          break;
        }
      }

      if (!flag) {
        tail->next = malloc(sizeof(Node));
        tail = tail->next;
        tail->data[0] = str[i];
        tail->next = NULL;
      }
    }
  }

  int compressed_size = 0;
  for (Node* current = head; current; current = current->next) {
    compressed_size++;
  }

  printf("Compressed size: %d\n", compressed_size);

  // Free memory
  for (Node* current = head; current; current = current->next) {
    free(current);
  }
}

int main() {
  char str[] = "aabbbbcccccaaa";
  compress(str);

  return 0;
}
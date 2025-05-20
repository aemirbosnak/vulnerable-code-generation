//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char character;
  struct Node* next;
} Node;

void compress(char* str) {
  Node* head = NULL;
  Node* tail = NULL;
  int i = 0;
  int character_count = 0;
  char current_character = str[0];

  for (; str[i] != '\0'; i++) {
    if (str[i] == current_character) {
      character_count++;
    } else {
      if (head == NULL) {
        head = tail = malloc(sizeof(Node));
        head->character = current_character;
        head->next = NULL;
      } else {
        tail->next = malloc(sizeof(Node));
        tail = tail->next;
        tail->character = current_character;
        tail->next = NULL;
      }
      current_character = str[i];
      character_count = 1;
    }
  }

  if (tail) {
    tail->next = NULL;
  }

  int compressed_size = 0;
  for (Node* node = head; node; node = node->next) {
    compressed_size++;
  }

  printf("Original string: %s\n", str);
  printf("Compressed string: ");
  for (Node* node = head; node; node = node->next) {
    printf("%c%d ", node->character, character_count);
  }
  printf("\n");
  printf("Number of characters compressed: %d\n", compressed_size - 1);
}

int main() {
  char str[] = "aabbbbcccc";
  compress(str);

  return 0;
}
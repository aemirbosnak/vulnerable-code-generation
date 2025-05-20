//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255
#define MAX_FILE_SIZE 1024

typedef struct Node {
  char dir_name[MAX_DIR_NAME_LEN];
  char file_name[MAX_FILE_NAME_LEN];
  int file_size;
  struct Node* next;
} Node;

void create_file_system(Node* head) {
  // Create a root directory
  head = malloc(sizeof(Node));
  head->dir_name[0] = '/';
  head->dir_name[1] = '\0';
  head->file_size = 0;
  head->next = NULL;

  // Add some sample files and directories
  Node* node = head;
  node->next = malloc(sizeof(Node));
  node = node->next;
  node->dir_name[0] = 'a';
  node->dir_name[1] = '\0';
  node->file_size = 0;
  node->next = NULL;

  node = head;
  node->next = malloc(sizeof(Node));
  node = node->next;
  node->file_name[0] = 'b';
  node->file_name[1] = '.txt';
  node->file_size = 1024;
  node->next = NULL;
}

int main() {
  Node* head = NULL;
  create_file_system(head);

  // List all files and directories
  Node* node = head;
  while (node) {
    printf("%s\n", node->dir_name);
    printf("%s\n", node->file_name);
    printf("%d\n", node->file_size);
    printf("\n");
    node = node->next;
  }

  return 0;
}
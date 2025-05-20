//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ_SIZE 1024

typedef struct Node {
  struct Node* next;
  char data[MAX_READ_SIZE];
} Node;

typedef struct Scanner {
  struct Node* head;
  struct Scanner* next;
  FILE* file;
} Scanner;

Scanner* scanner_new(FILE* file) {
  Scanner* scanner = malloc(sizeof(Scanner));
  scanner->head = NULL;
  scanner->next = NULL;
  scanner->file = file;
  return scanner;
}

void scanner_add_node(Scanner* scanner, char* data) {
  Node* node = malloc(sizeof(Node));
  node->next = scanner->head;
  scanner->head = node;
  strcpy(node->data, data);
}

void scanner_read(Scanner* scanner) {
  char line[MAX_READ_SIZE];
  while (fgets(line, MAX_READ_SIZE, scanner->file) != NULL) {
    scanner_add_node(scanner, line);
  }
}

int main() {
  FILE* qr_code_file = fopen("qrcode.txt", "r");
  Scanner* scanner = scanner_new(qr_code_file);
  scanner_read(scanner);

  // Process the scanned data
  for (Node* node = scanner->head; node; node = node->next) {
    printf("%s\n", node->data);
  }

  fclose(qr_code_file);
  return 0;
}
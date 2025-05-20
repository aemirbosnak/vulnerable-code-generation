//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
  char **data;
  struct CSV_Node *next;
} CSV_Node;

CSV_Node *CSV_Insert(CSV_Node *head, char **row) {
  CSV_Node *newNode = malloc(sizeof(CSV_Node));
  newNode->data = malloc(MAX_COLS * sizeof(char *));
  for (int i = 0; i < MAX_COLS; i++) {
    newNode->data[i] = malloc(MAX_LINES * sizeof(char));
  }

  memcpy(newNode->data, row, MAX_COLS * sizeof(char *));

  if (head) {
    newNode->next = head;
  }

  return newNode;
}

int main() {
  CSV_Node *head = NULL;

  char **row1 = malloc(MAX_COLS * sizeof(char *));
  row1[0] = "John Doe";
  row1[1] = "New York";

  CSV_Insert(head, row1);

  char **row2 = malloc(MAX_COLS * sizeof(char *));
  row2[0] = "Jane Doe";
  row2[1] = "Los Angeles";

  CSV_Insert(head, row2);

  for (CSV_Node *node = head; node; node = node->next) {
    for (int i = 0; i < MAX_COLS; i++) {
      printf("%s, ", node->data[i]);
    }
    printf("\n");
  }

  return 0;
}
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

CSV_Node *csv_insert(CSV_Node *head, char **row) {
  CSV_Node *newNode = malloc(sizeof(CSV_Node));
  newNode->data = malloc(MAX_COLS * sizeof(char *));
  for (int i = 0; i < MAX_COLS; i++) {
    newNode->data[i] = malloc(MAX_LINES * sizeof(char));
  }

  for (int i = 0; i < MAX_LINES; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      newNode->data[i][j] = row[i][j];
    }
  }

  newNode->next = head;
  return newNode;
}

int main() {
  CSV_Node *head = NULL;
  char **row = malloc(MAX_LINES * sizeof(char *));
  for (int i = 0; i < MAX_LINES; i++) {
    row[i] = malloc(MAX_COLS * sizeof(char));
  }

  row[0] = "John Doe,123 Main St,New York,NY 10001";
  row[1] = "Jane Doe,456 Oak Ave,Los Angeles,CA 90210";
  row[2] = "Bill Smith,789 Park Ave,Chicago,IL 60601";

  head = csv_insert(head, row);

  for (CSV_Node *node = head; node; node = node->next) {
    for (int i = 0; i < MAX_LINES; i++) {
      for (int j = 0; j < MAX_COLS; j++) {
        printf("%s ", node->data[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
  char **data;
  struct CSV_Node* next;
} CSV_Node;

CSV_Node* insert_node(CSV_Node* head, char** data) {
  CSV_Node* newNode = malloc(sizeof(CSV_Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  } else {
    head->next = newNode;
    return head;
  }
}

void print_csv(CSV_Node* head) {
  CSV_Node* current = head;
  while (current) {
    for (int i = 0; i < current->data[0] - 1; i++) {
      printf("%s,", current->data[i + 1]);
    }
    printf("\n");
    current = current->next;
  }
}

int main() {
  CSV_Node* head = NULL;
  char** data = NULL;

  data = malloc(MAX_LINES * MAX_COLS * sizeof(char*));
  for (int i = 0; i < MAX_LINES; i++) {
    data[i] = malloc(MAX_COLS * sizeof(char));
  }

  // Fill the data with sample CSV content
  data[0][0] = 3;
  data[0][1] = "John Doe";
  data[0][2] = "New York";

  data[1][0] = 2;
  data[1][1] = "Jane Doe";
  data[1][2] = "Los Angeles";

  insert_node(head, data);
  print_csv(head);

  free(data);
  return 0;
}
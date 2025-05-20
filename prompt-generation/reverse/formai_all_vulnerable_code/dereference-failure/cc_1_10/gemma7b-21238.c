//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
  char type;
  union {
    int number;
    double decimal;
    char *string;
    struct JSON_Node *array;
    struct JSON_Node *object;
  } data;
  struct JSON_Node *next;
} JSON_Node;

JSON_Node *JSON_Parser(char *json_str) {
  JSON_Node *head = NULL;
  JSON_Node *current = NULL;
  int i = 0;
  char buffer[MAX_BUFFER_SIZE];

  // Allocate memory for the first node
  if (head == NULL) {
    head = (JSON_Node *)malloc(sizeof(JSON_Node));
    current = head;
  }

  // Loop over the JSON string
  while (json_str[i] != '\0') {
    // Check for quotes, brackets, or commas
    if (json_str[i] == '"' || json_str[i] == '{' || json_str[i] == '}') {
      // Allocate memory for a new node
      current->next = (JSON_Node *)malloc(sizeof(JSON_Node));
      current = current->next;
    }

    // Store the character in the current node
    buffer[0] = json_str[i];
    current->data.string = buffer;

    // Increment the index
    i++;
  }

  // Return the head of the JSON tree
  return head;
}

int main() {
  char json_str[] = "{ 'name': 'John Doe', 'age': 30 }";
  JSON_Node *head = JSON_Parser(json_str);

  // Print the JSON data
  for (JSON_Node *node = head; node != NULL; node = node->next) {
    switch (node->type) {
      case 'o':
        printf("Object:\n");
        break;
      case 'a':
        printf("Array:\n");
        break;
      case 's':
        printf("String: %s\n", node->data.string);
        break;
      case 'n':
        printf("Number: %d\n", node->data.number);
        break;
      case 'd':
        printf("Decimal: %lf\n", node->data.decimal);
        break;
    }
  }

  return 0;
}
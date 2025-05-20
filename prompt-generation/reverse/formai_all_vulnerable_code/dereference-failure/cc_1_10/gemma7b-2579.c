//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <string.h>

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void parseJson(char *jsonStr) {
  // Convert JSON string into a linked list of nodes
  Node *head = NULL;
  Node *currNode = NULL;
  char *p = jsonStr;
  while (p) {
    // Check for quotes and curly braces
    if (*p == '"' || *p == '{' || *p == '}') {
      // Allocate a new node
      currNode = malloc(sizeof(Node));
      currNode->data = malloc(10);
      currNode->next = NULL;

      // Copy data from the JSON string
      memcpy(currNode->data, p, 10);

      // If the head is NULL, make it the head of the list
      if (head == NULL) {
        head = currNode;
      } else {
        currNode->next = head;
        head = currNode;
      }
    }
    // Increment the pointer
    p++;
  }

  // Print the nodes in the linked list
  Node *temp = head;
  while (temp) {
    printf("%s ", temp->data);
    temp = temp->next;
  }

  // Free the memory allocated for the nodes
  free(head);
}

int main() {
  char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
  parseJson(jsonStr);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONNode {
  char *key;
  char *value;
  struct JSONNode *next;
} JSONNode;

JSONNode *parseJSON(char *jsonString) {
  JSONNode *head = NULL;
  JSONNode *tail = NULL;

  // Allocate memory for the JSON node
  JSONNode *newNode = malloc(sizeof(JSONNode));
  newNode->key = NULL;
  newNode->value = NULL;
  newNode->next = NULL;

  // Parse the JSON string
  char *p = jsonString;
  while (*p) {
    // Check if the current character is a key-value separator
    if (*p == ':') {
      // Allocate memory for the key and value
      newNode->key = malloc(MAX_BUFFER_SIZE);
      newNode->value = malloc(MAX_BUFFER_SIZE);

      // Copy the key and value from the JSON string
      int i = 0;
      while (*p != ':') {
        newNode->key[i] = *p;
        p++;
        i++;
      }

      newNode->key[i] = '\0';

      i = 0;
      while (*p != '}') {
        newNode->value[i] = *p;
        p++;
        i++;
      }

      newNode->value[i] = '\0';

      // Add the node to the JSON list
      if (head == NULL) {
        head = tail = newNode;
      } else {
        tail->next = newNode;
        tail = newNode;
      }
    }

    // Move to the next character in the JSON string
    p++;
  }

  return head;
}

int main() {
  char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";

  JSONNode *head = parseJSON(jsonString);

  // Print the key-value pairs in the JSON document
  while (head) {
    printf("%s: %s\n", head->key, head->value);
    head = head->next;
  }

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
  char type;
  union {
    struct JSON_Node *child;
    int number;
    char *string;
  } data;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
  JSON_Node *root = NULL;
  char *buffer = NULL;
  int buffer_size = 0;
  int i = 0;

  // Allocate memory for the buffer.
  buffer = malloc(MAX_BUFFER_SIZE);

  // Copy the JSON string into the buffer.
  strcpy(buffer, json_string);

  // Iterate over the JSON string.
  while (buffer[i] != '\0') {
    // Check if the current character is the beginning of a key-value pair.
    if (buffer[i] == '"') {
      // Allocate memory for the key.
      JSON_Node *key = malloc(sizeof(JSON_Node));
      key->type = 's';
      key->data.string = malloc(MAX_BUFFER_SIZE);

      // Copy the key from the JSON string into the key node.
      int key_length = 0;
      while (buffer[i] != '"') {
        key->data.string[key_length] = buffer[i];
        key_length++;
        i++;
      }
      key->data.string[key_length] = '\0';

      // Check if the current character is the colon.
      if (buffer[i] == ':') {
        // Allocate memory for the value.
        JSON_Node *value = malloc(sizeof(JSON_Node));
        value->type = 'n';
        value->data.number = 0;

        // Iterate over the value.
        int value_length = 0;
        while (buffer[i] != ',') {
          value->data.number = value->data.number * 10 + buffer[i] - '0';
          value_length++;
          i++;
        }
        value->data.number = value->data.number / 10 * value_length;

        // Create a new node in the JSON tree.
        JSON_Node *node = malloc(sizeof(JSON_Node));
        node->type = 'o';
        node->data.child = key;
        node->data.child->data.child = value;

        // If the root node is null, make it the root node.
        if (root == NULL) {
          root = node;
        }
      }
    }

    // Increment the index.
    i++;
  }

  // Free the memory allocated for the buffer.
  free(buffer);

  // Return the root node of the JSON tree.
  return root;
}

int main() {
  char *json_string = "{ 'name': 'John Doe', 'age': 30 }";
  JSON_Node *root = parse_json(json_string);

  // Print the JSON data.
  printf("Name: %s\n", root->data.child->data.string);
  printf("Age: %d\n", root->data.child->data.child->data.number);

  // Free the memory allocated for the JSON node.
  free(root);

  return 0;
}
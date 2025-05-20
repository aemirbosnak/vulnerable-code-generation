//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONNode {
  char type;
  union {
    int number;
    char *string;
    struct JSONNode *object;
    struct JSONNode **array;
  } data;
  struct JSONNode *next;
} JSONNode;

JSONNode *parseJSON(char *jsonStr) {
  JSONNode *head = NULL;
  JSONNode *tail = NULL;
  char *buffer = NULL;
  int bufferSize = 0;

  // Allocate memory for the JSON node and buffer
  head = malloc(sizeof(JSONNode));
  tail = head;
  buffer = malloc(MAX_BUFFER_SIZE);

  // Parse the JSON string
  int i = 0;
  for (i = 0; jsonStr[i] != '\0'; i++) {
    switch (jsonStr[i]) {
      case '{' :
        tail->type = 'o';
        tail->data.object = malloc(sizeof(JSONNode));
        tail = tail->data.object;
        break;
      case '[' :
        tail->type = 'a';
        tail->data.array = malloc(sizeof(JSONNode *));
        tail = tail->data.array;
        break;
      case '"':
        tail->type = 's';
        tail->data.string = malloc(MAX_BUFFER_SIZE);
        int j = 0;
        for (j = i + 1; jsonStr[j] != '"' && jsonStr[j] != '\0'; j++) {
          tail->data.string[j - i - 1] = jsonStr[j];
        }
        tail->data.string[j - i - 1] = '\0';
        i = j - 1;
        break;
      case ' ':
      case ',':
      case ':':
      case ']':
      case '}':
        tail = tail->next = malloc(sizeof(JSONNode));
        break;
    }
  }

  return head;
}

int main() {
  char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
  JSONNode *head = parseJSON(jsonStr);

  // Print the JSON data
  JSONNode *node = head;
  while (node) {
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
    }
    node = node->next;
  }

  return 0;
}
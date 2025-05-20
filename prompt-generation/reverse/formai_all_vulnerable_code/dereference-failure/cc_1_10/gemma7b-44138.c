//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONNode {
  char type;
  union {
    int number;
    double decimal;
    char *string;
    struct JSONNode *object;
    struct JSONNode **array;
  } data;
  struct JSONNode *next;
} JSONNode;

JSONNode *parseJSON(char *jsonStr) {
  JSONNode *head = NULL;
  JSONNode *tail = NULL;

  // Allocate memory for the first node
  head = malloc(sizeof(JSONNode));
  tail = head;

  // Parse the JSON string
  char *ptr = jsonStr;
  while (*ptr) {
    // Handle quotes
    if (*ptr == '"') {
      tail->type = 's';
      tail->data.string = malloc(MAX_BUFFER_SIZE);
      ptr++;
      int i = 0;
      while (*ptr != '"' && *ptr) {
        tail->data.string[i] = *ptr;
        ptr++;
        i++;
      }
      tail->data.string[i] = '\0';
    }
    // Handle numbers
    else if (*ptr >= '0' && *ptr <= '9') {
      tail->type = 'n';
      tail->data.number = atoi(ptr);
      ptr += atoi(ptr);
    }
    // Handle objects and arrays
    else if (*ptr == '{' || *ptr == '[') {
      tail->type = 'o'  / 'a';
      tail->data.object = parseJSON(ptr);
      ptr += 1;
    }
    // Handle commas and colons
    else if (*ptr == ',' || *ptr == ':') {
      ptr++;
    }

    // Link the next node
    if (tail->next == NULL) {
      tail->next = malloc(sizeof(JSONNode));
      tail = tail->next;
    }
  }

  return head;
}

int main() {
  char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
  JSONNode *head = parseJSON(jsonStr);

  printf("Name: %s\n", head->data.object->data.string);
  printf("Age: %d\n", head->data.object->data.number);

  return 0;
}
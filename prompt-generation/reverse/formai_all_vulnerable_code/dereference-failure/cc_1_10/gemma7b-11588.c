//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data[MAX_BUFFER_SIZE];
  struct Node* next;
} Node;

Node* newNode(char* data) {
  Node* node = (Node*)malloc(sizeof(Node));
  strcpy(node->data, data);
  node->next = NULL;
  return node;
}

void parseJson(char* jsonStr) {
  Node* head = newNode(jsonStr);
  Node* current = head;
  char* key = NULL;
  char* value = NULL;
  int i = 0;

  while (current) {
    char* str = current->data;

    if (str[i] == '{') {
      key = malloc(MAX_BUFFER_SIZE);
      value = malloc(MAX_BUFFER_SIZE);
      i = 0;

      while (str[i] != ':') {
        key[i] = str[i];
        i++;
      }
      key[i] = '\0';

      while (str[i] != '}') {
        value[i] = str[i];
        i++;
      }
      value[i] = '\0';

      printf("Key: %s, Value: %s\n", key, value);

      free(key);
      free(value);
    }

    current = current->next;
  }
}

int main() {
  char* jsonStr = "{'name':'John Doe', 'age':30, 'interests':'music, movies' }";
  parseJson(jsonStr);

  return 0;
}
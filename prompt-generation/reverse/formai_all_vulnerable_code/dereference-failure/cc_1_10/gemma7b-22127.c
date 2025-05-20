//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void parseJson(char *jsonString) {
  Node *head = NULL;
  Node *tail = NULL;
  int i = 0;
  char currentChar = '\0';
  char key[MAX_BUFFER_SIZE] = "";
  char value[MAX_BUFFER_SIZE] = "";

  for (; i < strlen(jsonString); i++) {
    currentChar = jsonString[i];

    switch (currentChar) {
      case '"':
        if (tail) {
          tail->next = malloc(sizeof(Node));
          tail = tail->next;
        } else {
          head = tail = malloc(sizeof(Node));
          tail->next = NULL;
        }
        tail->data = malloc(MAX_BUFFER_SIZE);
        tail->data[0] = '\0';
        break;
      case ':':
        strcpy(value, key);
        tail->data = malloc(MAX_BUFFER_SIZE);
        tail->data[0] = '\0';
        break;
      case ',':
        tail->data[0] = '\0';
        break;
      default:
        strcat(key, &jsonString[i]);
    }
  }

  // Print the JSON data
  for (head = head; head; head = head->next) {
    printf("%s: %s\n", key, head->data);
  }
}

int main() {
  char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
  parseJson(jsonString);

  return 0;
}
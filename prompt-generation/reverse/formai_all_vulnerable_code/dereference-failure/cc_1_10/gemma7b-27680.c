//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

Node *parse_xml(char *xml_data) {
  Node *head = NULL;
  char *buffer = malloc(MAX_BUFFER_SIZE);
  char *p = xml_data;
  int state = 0;

  while (*p) {
    switch (state) {
      case 0:
        if (*p == '<') {
          state = 1;
          buffer = p;
        } else if (*p == '>') {
          state = 3;
          Node *newNode = malloc(sizeof(Node));
          newNode->data = strdup(buffer);
          newNode->next = head;
          head = newNode;
        } else {
          buffer = p;
        }
        break;
      case 1:
        if (*p == ' ') {
          state = 2;
          buffer = p;
        } else if (*p == '>') {
          state = 3;
          Node *newNode = malloc(sizeof(Node));
          newNode->data = strdup(buffer);
          newNode->next = head;
          head = newNode;
        } else {
          buffer = p;
        }
        break;
      case 2:
        if (*p == '>') {
          state = 3;
          Node *newNode = malloc(sizeof(Node));
          newNode->data = strdup(buffer);
          newNode->next = head;
          head = newNode;
        } else {
          buffer = p;
        }
        break;
      case 3:
        state = 0;
    }
    p++;
  }

  free(buffer);
  return head;
}

int main() {
  char *xml_data = "<foo>bar</foo>";
  Node *head = parse_xml(xml_data);

  for (Node *node = head; node; node = node->next) {
    printf("%s\n", node->data);
  }

  return 0;
}
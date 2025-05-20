//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char *data;
  struct Node *next;
} Node;

void parseXML(char *xmlStr) {
  Node *head = NULL;
  char *buffer = malloc(MAX_BUFFER_SIZE);
  char *p = xmlStr;
  char *start = NULL;
  int depth = 0;

  while (*p) {
    switch (*p) {
      case '<':
        start = p;
        depth++;
        break;
      case '>':
        if (start) {
          Node *newNode = malloc(sizeof(Node));
          newNode->data = strdup(start);
          newNode->next = head;
          head = newNode;
        }
        depth--;
        break;
      case '/':
        if (depth > 0) {
          depth--;
        }
        break;
      default:
        break;
    }

    p++;
  }

  free(buffer);
  free(head);
}

int main() {
  char xmlStr[] = "<foo><bar>Hello, world!</bar></foo>";
  parseXML(xmlStr);

  return 0;
}
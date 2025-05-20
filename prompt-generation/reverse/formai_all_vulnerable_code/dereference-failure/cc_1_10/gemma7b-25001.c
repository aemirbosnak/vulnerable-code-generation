//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: standalone
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
  char *buffer = NULL;
  char *token = NULL;
  int i = 0;

  buffer = malloc(MAX_BUFFER_SIZE);

  // Tokenize the XML string
  token = strtok(xmlStr, "<");

  // Loop over the tokens
  while (token) {
    Node *newNode = malloc(sizeof(Node));

    newNode->data = strdup(token);
    newNode->next = head;
    head = newNode;

    token = strtok(NULL, "<");
  }

  // Print the nodes
  for (i = 0; head; i++) {
    printf("%s\n", head->data);
    head = head->next;
  }

  free(buffer);
  free(head);
}

int main() {
  char xmlStr[] = "<foo><b>hello</b></foo>";

  parseXML(xmlStr);

  return 0;
}
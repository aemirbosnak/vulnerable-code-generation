//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct XMLNode {
  char *data;
  struct XMLNode *next;
} XMLNode;

XMLNode *parseXML(char *xmlStr) {
  XMLNode *head = NULL;
  XMLNode *newNode = NULL;
  int state = 0; // 0: outside, 1: inside tag, 2: inside attribute
  char buffer[MAX_BUFFER_SIZE] = "";
  char *p = xmlStr;

  while (*p) {
    switch (state) {
      case 0:
        if (*p == '<') {
          state = 1;
          buffer[0] = *p;
          newNode = malloc(sizeof(XMLNode));
          newNode->data = buffer;
          newNode->next = head;
          head = newNode;
        } else {
          buffer[0] = *p;
          buffer[1] = '\0';
          printf("Error: Unexpected character.\n");
          exit(1);
        }
        break;
      case 1:
        if (*p == '>' && buffer[0] != '/') {
          state = 0;
          buffer[0] = '\0';
          newNode = malloc(sizeof(XMLNode));
          newNode->data = buffer;
          newNode->next = head;
          head = newNode;
        } else if (*p == '/') {
          state = 0;
          buffer[0] = '\0';
        } else {
          buffer[0] = *p;
        }
        break;
      case 2:
        if (*p == '>' || *p == '/') {
          state = 0;
          buffer[0] = '\0';
          newNode = malloc(sizeof(XMLNode));
          newNode->data = buffer;
          newNode->next = head;
          head = newNode;
        } else {
          buffer[0] = *p;
        }
        break;
    }
    p++;
  }

  return head;
}

int main() {
  char xmlStr[] = "<root><child>Test</child></root>";
  XMLNode *head = parseXML(xmlStr);

  XMLNode *current = head;
  while (current) {
    printf("Data: %s\n", current->data);
    current = current->next;
  }

  return 0;
}
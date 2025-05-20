//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  struct Node* next;
  char* data;
} Node;

typedef struct XMLParser {
  Node* head;
  char* currentElement;
  int currentElementLength;
  int depth;
} XMLParser;

XMLParser* parser_init() {
  XMLParser* parser = (XMLParser*)malloc(sizeof(XMLParser));
  parser->head = NULL;
  parser->currentElement = NULL;
  parser->currentElementLength = 0;
  parser->depth = 0;
  return parser;
}

void parser_parse(XMLParser* parser, char* xml) {
  char* buffer = (char*)malloc(MAX_BUFFER_SIZE);
  int bufferIndex = 0;
  int i = 0;
  for (; xml[i] != '\0'; i++) {
    if (xml[i] == '<' && xml[i + 1] == ' ') {
      parser->currentElement = xml + i + 2;
      parser->currentElementLength = 0;
      parser->depth++;
    } else if (xml[i] == '>' && parser->currentElement) {
      parser->currentElementLength++;
      parser->depth--;
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->next = parser->head;
      parser->head = newNode;
      newNode->data = (char*)malloc(parser->currentElementLength);
      memcpy(newNode->data, parser->currentElement, parser->currentElementLength);
    } else {
      buffer[bufferIndex++] = xml[i];
    }
  }

  free(buffer);
}

int main() {
  XMLParser* parser = parser_init();
  parser_parse(parser, "<foo>bar</foo>");
  Node* node = parser->head;
  while (node) {
    printf("%s\n", node->data);
    node = node->next;
  }

  free(parser);

  return 0;
}
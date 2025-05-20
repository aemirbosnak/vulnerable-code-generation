//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data[MAX_BUFFER_SIZE];
  struct Node* next;
} Node;

typedef struct Parser {
  Node* root;
  char current_buffer[MAX_BUFFER_SIZE];
  int current_buffer_size;
  int state;
} Parser;

void initializeParser(Parser* parser) {
  parser->root = NULL;
  parser->current_buffer_size = 0;
  parser->state = 0;
}

void parseXML(Parser* parser, char* xml_data) {
  int i = 0;
  parser->current_buffer_size = 0;
  parser->current_buffer[0] = '\0';

  for (i = 0; xml_data[i] != '\0'; i++) {
    switch (parser->state) {
      case 0:
        if (xml_data[i] == '<') {
          parser->state = 1;
          strcpy(parser->current_buffer, xml_data + i);
          parser->current_buffer_size = 0;
        }
        break;
      case 1:
        if (xml_data[i] == '>') {
          Node* newNode = malloc(sizeof(Node));
          newNode->next = parser->root;
          parser->root = newNode;
          strcpy(newNode->data, parser->current_buffer);
          parser->state = 0;
        } else {
          parser->current_buffer[parser->current_buffer_size++] = xml_data[i];
        }
        break;
    }
  }
}

int main() {
  Parser* parser = malloc(sizeof(Parser));
  initializeParser(parser);

  char* xml_data = "<foo><bar>baz</bar></foo>";
  parseXML(parser, xml_data);

  Node* current_node = parser->root;
  while (current_node) {
    printf("%s\n", current_node->data);
    current_node = current_node->next;
  }

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
  char data[MAX_BUFFER_SIZE];
  struct Node* next;
} Node;

typedef struct JSONParser {
  Node* head;
  int currentPos;
  char currentChar;
  int parsingState;
} JSONParser;

void JSONParser_init(JSONParser* parser) {
  parser->head = NULL;
  parser->currentPos = 0;
  parser->currentChar = '\0';
  parser->parsingState = 0;
}

void JSONParser_parse(JSONParser* parser, char input) {
  switch (parser->parsingState) {
    case 0:
      if (input == '{') {
        parser->parsingState = 1;
      } else if (input == '"') {
        parser->parsingState = 2;
      } else if (input == ',') {
        parser->parsingState = 3;
      }
      break;
    case 1:
      if (input == '}') {
        parser->parsingState = 0;
      } else {
        Node* newNode = malloc(sizeof(Node));
        strcpy(newNode->data, &input);
        newNode->next = parser->head;
        parser->head = newNode;
      }
      break;
    case 2:
      if (input == '"') {
        parser->parsingState = 0;
      } else {
        parser->currentChar = input;
      }
      break;
    case 3:
      if (input == ',') {
        parser->parsingState = 0;
      } else if (input == '}') {
        parser->parsingState = 0;
      } else {
        parser->currentChar = input;
      }
      break;
  }
}

int main() {
  JSONParser* parser = malloc(sizeof(JSONParser));
  JSONParser_init(parser);

  char* jsonStr = "{ 'name': 'John Doe', 'age': 30 }";

  for (int i = 0; jsonStr[i] != '\0'; i++) {
    JSONParser_parse(parser, jsonStr[i]);
  }

  Node* node = parser->head;
  while (node) {
    printf("%s ", node->data);
    node = node->next;
  }

  free(parser);
  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
  char *buffer;
  int bufferSize;
  int position;
  struct JSONParser *next;
} JSONParser;

JSONParser *jsonStringParser(char *jsonString) {
  JSONParser *parser = (JSONParser *)malloc(sizeof(JSONParser));

  parser->buffer = (char *)malloc(MAX_BUFFER_SIZE);
  parser->bufferSize = MAX_BUFFER_SIZE;
  parser->position = 0;
  parser->next = NULL;

  strcpy(parser->buffer, jsonString);

  return parser;
}

void parseJSON(JSONParser *parser) {
  int i = 0;
  char currentChar = parser->buffer[parser->position];

  switch (currentChar) {
    case '"':
      parser->position++;
      break;
    case '(':
      parser->position++;
      break;
    case '{':
      parser->position++;
      break;
    case '}':
      parser->position++;
      break;
    case ',':
      parser->position++;
      break;
    default:
      i = parser->position;
      while (parser->buffer[i] != '"') {
        i++;
      }
      parser->position = i + 1;
      break;
  }
}

int main() {
  char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
  JSONParser *parser = jsonStringParser(jsonString);

  parseJSON(parser);

  printf("Name: %s", parser->buffer);
  printf("\nAge: %d", parser->buffer);

  return 0;
}
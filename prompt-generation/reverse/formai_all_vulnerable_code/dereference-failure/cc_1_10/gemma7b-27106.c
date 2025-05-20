//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
  char *buffer;
  int size;
  int position;
} JSONParser;

JSONParser *parser_init(int size) {
  JSONParser *parser = malloc(sizeof(JSONParser));
  parser->buffer = malloc(size * sizeof(char));
  parser->size = size;
  parser->position = 0;

  return parser;
}

void parser_append(JSONParser *parser, char character) {
  if (parser->position >= parser->size - 1) {
    parser->buffer = realloc(parser->buffer, (parser->size * 2) * sizeof(char));
    parser->size *= 2;
  }

  parser->buffer[parser->position++] = character;
}

int parser_get_string(JSONParser *parser, char **string) {
  int position = parser->position;

  while (parser->buffer[parser->position] != '"') {
    parser->position++;
  }

  *string = malloc((parser->position - position + 1) * sizeof(char));
  memcpy(*string, parser->buffer + position, parser->position - position);
  (*string)[parser->position - position] = '\0';

  return parser->position - position;
}

int main() {
  JSONParser *parser = parser_init(MAX_BUFFER_SIZE);

  parser_append(parser, '{');
  parser_append(parser, '"name":');
  parser_append(parser, "\"John Doe\"");
  parser_append(parser, ',');
  parser_append(parser, '"age":');
  parser_append(parser, 30);
  parser_append(parser, '}');

  char *string;
  int length = parser_get_string(parser, &string);

  printf("String: %s\n", string);
  printf("Length: %d\n", length);

  free(string);
  free(parser->buffer);
  free(parser);

  return 0;
}
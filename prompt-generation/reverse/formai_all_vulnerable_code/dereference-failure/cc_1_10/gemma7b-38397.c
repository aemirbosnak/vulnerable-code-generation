//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
  char **buffer;
  int size;
  int pos;
  struct JSONParser *next;
} JSONParser;

JSONParser *parser_init(int size) {
  JSONParser *parser = malloc(sizeof(JSONParser));
  parser->buffer = malloc(size * MAX_BUFFER_SIZE);
  parser->size = size;
  parser->pos = 0;
  parser->next = NULL;
  return parser;
}

void parser_free(JSONParser *parser) {
  free(parser->buffer);
  free(parser);
}

void parser_add(JSONParser *parser, char data) {
  if (parser->pos >= parser->size) {
    parser->buffer = realloc(parser->buffer, (parser->size + 1) * MAX_BUFFER_SIZE);
    parser->size++;
  }
  parser->buffer[parser->pos++] = data;
}

char parser_get(JSONParser *parser) {
  return parser->buffer[parser->pos - 1];
}

int main() {
  JSONParser *parser = parser_init(10);
  parser_add(parser, '{');
  parser_add(parser, '"');
  parser_add(parser, "name");
  parser_add(parser, ':');
  parser_add(parser, '"');
  parser_add(parser, "John Doe");
  parser_add(parser, '}');

  printf("%c", parser_get(parser));
  printf("%c", parser_get(parser));
  printf("%c", parser_get(parser));
  printf("%c", parser_get(parser));
  printf("%c", parser_get(parser));
  printf("%c", parser_get(parser));
  printf("%c", parser_get(parser));
  printf("%c", parser_get(parser));

  parser_free(parser);

  return 0;
}
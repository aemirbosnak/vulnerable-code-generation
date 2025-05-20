//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct JsonParser {
  char *buffer;
  int size;
  int position;
} JsonParser;

JsonParser *parser_init(int size) {
  JsonParser *parser = malloc(sizeof(JsonParser));
  parser->buffer = malloc(size * sizeof(char));
  parser->size = size;
  parser->position = 0;
  return parser;
}

void parser_free(JsonParser *parser) {
  free(parser->buffer);
  free(parser);
}

int parser_read(JsonParser *parser, int ch) {
  if (parser->position >= parser->size - 1) {
    return -1;
  }
  parser->buffer[parser->position++] = ch;
  return 0;
}

int parser_peek(JsonParser *parser) {
  if (parser->position == 0) {
    return -1;
  }
  return parser->buffer[parser->position - 1];
}

int main() {
  JsonParser *parser = parser_init(MAX_BUFFER_SIZE);
  parser_read(parser, '{');
  parser_read(parser, '"');
  parser_read(parser, "John Doe");
  parser_read(parser, '"');
  parser_read(parser, ':');
  parser_read(parser, 12);
  parser_read(parser, '}');

  int value = parser_peek(parser);
  if (value == -1) {
    printf("Error parsing JSON\n");
  } else {
    printf("Value: %d\n", value);
  }

  parser_free(parser);
  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
  char **buffer;
  int size;
  int position;
  int depth;
} JsonParser;

JsonParser *parser_init(int size) {
  JsonParser *parser = malloc(sizeof(JsonParser));
  parser->buffer = malloc(size * MAX_BUFFER_SIZE);
  parser->size = size;
  parser->position = 0;
  parser->depth = 0;
  return parser;
}

void parser_parse(JsonParser *parser, char **json_string) {
  parser->buffer[parser->position++] = *json_string;

  if (*json_string == '"') {
    parser->depth++;
  } else if (*json_string == '}') {
    parser->depth--;
  }

  if (parser->depth == 0) {
    parser->buffer[parser->position++] = '\0';
  }
}

void parser_finalize(JsonParser *parser) {
  free(parser->buffer);
  free(parser);
}

int main() {
  char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
  JsonParser *parser = parser_init(10);

  parser_parse(parser, json_string);

  parser_finalize(parser);

  return 0;
}
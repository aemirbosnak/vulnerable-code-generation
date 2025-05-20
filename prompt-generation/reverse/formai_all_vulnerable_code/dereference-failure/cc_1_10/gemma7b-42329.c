//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonParser {
  char *buffer;
  size_t size;
  size_t pos;
  int state;
  struct JsonParser *next;
} JsonParser;

JsonParser *parser_init(size_t size) {
  JsonParser *parser = malloc(sizeof(JsonParser));
  parser->buffer = malloc(size);
  parser->size = size;
  parser->pos = 0;
  parser->state = 0;
  parser->next = NULL;

  return parser;
}

void parser_free(JsonParser *parser) {
  free(parser->buffer);
  free(parser);
}

int parser_read(JsonParser *parser, int ch) {
  if (parser->pos >= parser->size - 1) {
    return -1;
  }

  parser->buffer[parser->pos++] = ch;
  return 0;
}

int parser_state(JsonParser *parser) {
  switch (parser->state) {
    case 0:
      if (parser_read(parser, '{') == 0) {
        parser->state = 1;
      }
      break;
    case 1:
      if (parser_read(parser, '}') == 0) {
        parser->state = 0;
      } else if (parser_read(parser, ':') == 0) {
        parser->state = 2;
      }
      break;
    case 2:
      if (parser_read(parser, '"') == 0) {
        parser->state = 3;
      } else if (parser_read(parser, ',') == 0) {
        parser->state = 1;
      }
      break;
    case 3:
      if (parser_read(parser, '"') == 0) {
        parser->state = 2;
      } else if (parser_read(parser, '}') == 0) {
        parser->state = 0;
      }
      break;
  }

  return 0;
}

int main() {
  JsonParser *parser = parser_init(MAX_BUFFER_SIZE);
  parser_read(parser, '{');
  parser_read(parser, "hello");
  parser_read(parser, ':');
  parser_read(parser, 12);
  parser_read(parser, '}');

  parser_free(parser);

  return 0;
}
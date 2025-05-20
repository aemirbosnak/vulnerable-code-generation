//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONParser {
  char *buffer;
  int bufferSize;
  int position;
  int endPosition;
  struct JSONParser *next;
} JSONParser;

void parser_init(JSONParser *parser) {
  parser->buffer = NULL;
  parser->bufferSize = MAX_BUFFER_SIZE;
  parser->position = 0;
  parser->endPosition = 0;
  parser->next = NULL;
}

void parser_append(JSONParser *parser, char data) {
  if (parser->endPosition - parser->position >= parser->bufferSize - 1) {
    parser->buffer = realloc(parser->buffer, parser->bufferSize * 2);
    parser->bufferSize *= 2;
  }
  parser->buffer[parser->position++] = data;
  parser->buffer[parser->position] = '\0';
  parser->endPosition++;
}

void parser_close(JSONParser *parser) {
  free(parser->buffer);
  parser->buffer = NULL;
  parser->position = 0;
  parser->endPosition = 0;
  parser->next = NULL;
}

int main() {
  JSONParser *parser = malloc(sizeof(JSONParser));
  parser_init(parser);

  parser_append(parser, '"');
  parser_append(parser, "John Doe");
  parser_append(parser, '"');
  parser_append(parser, ':');
  parser_append(parser, 30);
  parser_append(parser, ',');
  parser_append(parser, '"');
  parser_append(parser, "Jane Doe");
  parser_append(parser, '"');
  parser_append(parser, ':');
  parser_append(parser, 25);
  parser_append(parser, ']');

  parser_close(parser);

  printf("%s", parser->buffer);

  return 0;
}
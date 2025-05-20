//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct JsonParser {
  char *buffer;
  int bufferSize;
  int pos;
  int state;
} JsonParser;

void JsonParser_init(JsonParser *parser) {
  parser->buffer = malloc(MAX_BUFFER_SIZE);
  parser->bufferSize = MAX_BUFFER_SIZE;
  parser->pos = 0;
  parser->state = 0;
}

int JsonParser_parse(JsonParser *parser, char *jsonStr) {
  int i = 0;
  parser->state = 0;
  parser->buffer[0] = '\0';

  for (i = 0; jsonStr[i] != '\0'; i++) {
    switch (parser->state) {
      case 0:
        if (jsonStr[i] == '"') {
          parser->state = 1;
        } else if (jsonStr[i] == '{' || jsonStr[i] == '[') {
          parser->state = 2;
        } else if (jsonStr[i] == ',') {
          parser->state = 3;
        } else {
          parser->state = 4;
        }
        break;
      case 1:
        if (jsonStr[i] == '"') {
          parser->state = 5;
        } else if (jsonStr[i] == '\\') {
          parser->state = 6;
        } else {
          parser->buffer[parser->pos++] = jsonStr[i];
        }
        break;
      case 2:
        parser->buffer[parser->pos++] = jsonStr[i];
        if (jsonStr[i] == '}') {
          parser->state = 0;
        } else if (jsonStr[i] == ']') {
          parser->state = 0;
        }
        break;
      case 3:
        parser->buffer[parser->pos++] = jsonStr[i];
        if (jsonStr[i] == ',') {
          parser->state = 0;
        }
        break;
      case 4:
        parser->state = 0;
        break;
      case 5:
        parser->state = 0;
        break;
      case 6:
        parser->state = 1;
        break;
    }
  }

  return 0;
}

int main() {
  JsonParser parser;
  JsonParser_init(&parser);

  char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
  JsonParser_parse(&parser, jsonStr);

  printf("Name: %s\n", parser.buffer);
  printf("Age: %d\n", atoi(parser.buffer + 9));

  return 0;
}
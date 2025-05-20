//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
  struct Node* next;
  char* data;
} Node;

typedef struct JsonParser {
  Node* head;
  int current_position;
  char buffer[MAX_BUFFER_SIZE];
  int buffer_size;
  int state;
} JsonParser;

JsonParser* parser_init() {
  JsonParser* parser = malloc(sizeof(JsonParser));
  parser->head = NULL;
  parser->current_position = 0;
  parser->buffer_size = MAX_BUFFER_SIZE;
  parser->state = 0;
  return parser;
}

void parser_parse(JsonParser* parser, char* json_string) {
  parser->buffer[0] = '\0';
  strcpy(parser->buffer, json_string);

  while (parser->current_position < parser->buffer_size && parser->buffer[parser->current_position] != '\0') {
    switch (parser->state) {
      case 0:
        if (parser->buffer[parser->current_position] == '"') {
          parser->state = 1;
        } else if (parser->buffer[parser->current_position] == '{' || parser->buffer[parser->current_position] == '[') {
          parser->state = 2;
        } else {
          parser->state = 3;
        }
        break;
      case 1:
        if (parser->buffer[parser->current_position] == '"') {
          parser->state = 0;
          Node* new_node = malloc(sizeof(Node));
          new_node->data = strdup(parser->buffer);
          new_node->next = parser->head;
          parser->head = new_node;
        } else {
          parser->state = 0;
        }
        break;
      case 2:
        if (parser->buffer[parser->current_position] == '}') {
          parser->state = 0;
        } else if (parser->buffer[parser->current_position] == ']') {
          parser->state = 0;
        } else {
          parser->state = 3;
        }
        break;
      case 3:
        parser->state = 0;
        break;
    }

    parser->current_position++;
  }
}

int main() {
  JsonParser* parser = parser_init();
  parser_parse(parser, "{ \"name\": \"Donald Knuth\", \"age\": 90 }");

  Node* current_node = parser->head;
  while (current_node) {
    printf("%s\n", current_node->data);
    current_node = current_node->next;
  }

  return 0;
}
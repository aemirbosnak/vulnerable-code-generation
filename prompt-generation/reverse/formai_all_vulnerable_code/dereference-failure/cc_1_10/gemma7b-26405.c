//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
  char type;
  union {
    int number;
    double decimal;
    char *string;
    struct JsonNode *object;
    struct JsonNode *array;
  } data;
  struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonStr) {
  JsonNode *head = NULL;
  JsonNode *tail = NULL;
  char *buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;

  while (*jsonStr) {
    switch (*jsonStr) {
      case '"':
        buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
        tail = malloc(sizeof(JsonNode));
        tail->type = 's';
        tail->data.string = buffer;
        tail->next = NULL;
        if (head) {
          head->next = tail;
        } else {
          head = tail;
        }
        break;
      case '{' :
        tail = malloc(sizeof(JsonNode));
        tail->type = 'o';
        tail->data.object = NULL;
        tail->next = NULL;
        if (head) {
          head->next = tail;
        } else {
          head = tail;
        }
        break;
      case '[':
        tail = malloc(sizeof(JsonNode));
        tail->type = 'a';
        tail->data.array = NULL;
        tail->next = NULL;
        if (head) {
          head->next = tail;
        } else {
          head = tail;
        }
        break;
      case ',':
      case ':':
      case '}':
      case ']':
        break;
      default:
        buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
        buffer[i++] = *jsonStr;
    }

    jsonStr++;
  }

  free(buffer);
}

int main() {
  char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
  parseJson(jsonStr);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  char *value;
} json_pair;

typedef struct {
  int size;
  json_pair *pairs;
} json_object;

void json_parse(char *json, json_object *object) {
  char *start = json;
  char *end = json;
  char *key = NULL;
  char *value = NULL;
  int in_key = 1;

  while (*end != '\0') {
    if (*end == '"') {
      if (in_key) {
        key = start + 1;
      } else {
        value = start + 1;
      }
      in_key = !in_key;
      start = end + 1;
    } else if (*end == ':' && in_key) {
      *end = '\0';
      in_key = 0;
      start = end + 1;
    } else if (*end == ',' || *end == '}') {
      *end = '\0';
      if (key != NULL && value != NULL) {
        object->pairs = realloc(object->pairs, (object->size + 1) * sizeof(json_pair));
        object->pairs[object->size].key = strdup(key);
        object->pairs[object->size].value = strdup(value);
        object->size++;
      }
      key = NULL;
      value = NULL;
      in_key = 1;
      start = end + 1;
    }
    end++;
  }
}

void json_print(json_object *object) {
  for (int i = 0; i < object->size; i++) {
    printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
  }
}

void json_free(json_object *object) {
  for (int i = 0; i < object->size; i++) {
    free(object->pairs[i].key);
    free(object->pairs[i].value);
  }
  free(object->pairs);
}

int main() {
  char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\" }";
  json_object object;
  json_parse(json, &object);
  json_print(&object);
  json_free(&object);
  return 0;
}
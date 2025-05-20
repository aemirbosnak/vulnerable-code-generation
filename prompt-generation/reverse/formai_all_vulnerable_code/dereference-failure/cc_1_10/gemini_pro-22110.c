//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  char *value;
} JSONPair;

typedef struct {
  JSONPair *pairs;
  int num_pairs;
} JSONObject;

JSONObject *parse_json(const char *json) {
  JSONObject *object = malloc(sizeof(JSONObject));
  object->pairs = NULL;
  object->num_pairs = 0;

  int i = 0;
  while (json[i] != '\0') {
    if (json[i] == '{') {
      JSONObject *nested_object = parse_json(json + i + 1);
      JSONPair pair = {NULL, NULL};
      pair.key = malloc(strlen("nested_object") + 1);
      strcpy(pair.key, "nested_object");
      pair.value = malloc(sizeof(nested_object));
      memcpy(pair.value, &nested_object, sizeof(nested_object));

      object->pairs = realloc(object->pairs, (object->num_pairs + 1) * sizeof(JSONPair));
      object->pairs[object->num_pairs] = pair;
      object->num_pairs++;

      i += strlen("nested_object") + 2 + nested_object->num_pairs * 2 + 1;
    } else if (json[i] == '"') {
      int start = i + 1;
      while (json[i] != '"' && json[i] != '\0') {
        i++;
      }

      char *key = malloc(i - start + 2);
      strncpy(key, json + start, i - start);
      key[i - start + 1] = '\0';

      i += 2;
      if (json[i] == ':') {
        i++;
        int start = i;
        while (json[i] != ',' && json[i] != '}' && json[i] != '\0') {
          i++;
        }

        char *value = malloc(i - start + 2);
        strncpy(value, json + start, i - start);
        value[i - start + 1] = '\0';

        JSONPair pair = {NULL, NULL};
        pair.key = key;
        pair.value = value;

        object->pairs = realloc(object->pairs, (object->num_pairs + 1) * sizeof(JSONPair));
        object->pairs[object->num_pairs] = pair;
        object->num_pairs++;
      }
    }

    i++;
  }

  return object;
}

void free_json_object(JSONObject *object) {
  for (int i = 0; i < object->num_pairs; i++) {
    free(object->pairs[i].key);
    free(object->pairs[i].value);
  }

  free(object->pairs);
  free(object);
}

void print_json_object(JSONObject *object) {
  printf("{");

  for (int i = 0; i < object->num_pairs; i++) {
    printf("\"%s\": \"%s\"", object->pairs[i].key, object->pairs[i].value);

    if (i != object->num_pairs - 1) {
      printf(", ");
    }
  }

  printf("}");
}

int main() {
  const char *json = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";
  JSONObject *object = parse_json(json);

  print_json_object(object);

  free_json_object(object);

  return 0;
}
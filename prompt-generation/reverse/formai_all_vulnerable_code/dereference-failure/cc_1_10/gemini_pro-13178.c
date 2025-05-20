//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 1024

typedef struct {
  char *key;
  char *value;
} JSONPair;

typedef struct {
  JSONPair *pairs;
  int num_pairs;
} JSONObject;

JSONObject *parse_json(char *json) {
  JSONObject *object = malloc(sizeof(JSONObject));
  object->pairs = NULL;
  object->num_pairs = 0;

  char *start = json;
  char *end = start;

  while (*end != '\0') {
    // Skip whitespace
    while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') {
      end++;
    }

    // Check for start of object
    if (*end == '{') {
      start = end + 1;
      end++;

      // Parse pairs
      while (*end != '}') {
        // Skip whitespace
        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r') {
          end++;
        }

        // Check for end of object
        if (*end == '}') {
          break;
        }

        // Parse key
        char *key_start = end;
        end++;
        while (*end != ':' && *end != '\0') {
          end++;
        }
        char *key_end = end;

        // Parse value
        char *value_start = end + 1;
        end++;
        while (*end != ',' && *end != '}' && *end != '\0') {
          end++;
        }
        char *value_end = end;

        // Create pair
        JSONPair *pair = malloc(sizeof(JSONPair));
        pair->key = malloc(key_end - key_start + 1);
        strncpy(pair->key, key_start, key_end - key_start);
        pair->key[key_end - key_start] = '\0';
        pair->value = malloc(value_end - value_start + 1);
        strncpy(pair->value, value_start, value_end - value_start);
        pair->value[value_end - value_start] = '\0';

        // Add pair to object
        object->pairs = realloc(object->pairs, sizeof(JSONPair) * (object->num_pairs + 1));
        object->pairs[object->num_pairs] = *pair;
        object->num_pairs++;
      }
    } else {
      // Error: invalid JSON
      return NULL;
    }
  }

  return object;
}

void print_json_object(JSONObject *object) {
  printf("{\n");
  for (int i = 0; i < object->num_pairs; i++) {
    printf("  \"%s\": \"%s\",\n", object->pairs[i].key, object->pairs[i].value);
  }
  printf("}\n");
}

int main() {
  // Parse JSON
  char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\" }";
  JSONObject *object = parse_json(json);

  // Print JSON object
  print_json_object(object);

  // Free JSON object
  for (int i = 0; i < object->num_pairs; i++) {
    free(object->pairs[i].key);
    free(object->pairs[i].value);
  }
  free(object->pairs);
  free(object);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON object structure
typedef struct JSON {
  char *key;
  char *value;
  struct JSON *next;
} JSON;

// Initialize an empty JSON object
JSON *init_json() {
  return NULL;
}

// Parse a JSON string into an object
JSON *parse_json(char *json) {
  JSON *head = NULL;
  JSON *current = NULL;

  char *key = NULL;
  char *value = NULL;

  char *start = json;
  char *end = json;

  while (*end != '\0') {
    // Find the start of the next key
    while (*end != '\0' && *end != '"') {
      end++;
    }

    if (*end == '\0') {
      break;
    }

    // Copy the key
    key = malloc(end - start + 1);
    strncpy(key, start, end - start);
    key[end - start] = '\0';

    // Find the start of the next value
    start = end + 1;
    while (*start != '\0' && *start != '"') {
      start++;
    }

    if (*start == '\0') {
      break;
    }

    // Copy the value
    value = malloc(start - end + 1);
    strncpy(value, end, start - end);
    value[start - end] = '\0';

    // Create a new JSON object
    JSON *new_json = malloc(sizeof(JSON));
    new_json->key = key;
    new_json->value = value;
    new_json->next = NULL;

    // Add the new JSON object to the list
    if (head == NULL) {
      head = new_json;
    } else {
      current->next = new_json;
    }

    current = new_json;

    // Move to the next character
    start = start + 1;
    end = start;
  }

  return head;
}

// Free the memory allocated for a JSON object
void free_json(JSON *json) {
  while (json != NULL) {
    JSON *next = json->next;
    free(json->key);
    free(json->value);
    free(json);
    json = next;
  }
}

// Print a JSON object
void print_json(JSON *json) {
  while (json != NULL) {
    printf("%s: %s\n", json->key, json->value);
    json = json->next;
  }
}

int main() {
  // Parse a JSON string
  char *json = "{\"name\": \"John Doe\", \"age\": 30}";
  JSON *json_object = parse_json(json);

  // Print the JSON object
  print_json(json_object);

  // Free the memory allocated for the JSON object
  free_json(json_object);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON structure
typedef struct JSON {
  char *key;
  char *value;
} JSON;

// Parse a JSON string and return a JSON object
JSON *parseJSON(char *json) {
  // Allocate memory for the JSON object
  JSON *result = malloc(sizeof(JSON));

  // Initialize the JSON object
  result->key = NULL;
  result->value = NULL;

  // Parse the JSON string
  char *key = strtok(json, ":");
  char *value = strtok(NULL, ",");

  // Set the key and value of the JSON object
  result->key = malloc(strlen(key) + 1);
  strcpy(result->key, key);
  result->value = malloc(strlen(value) + 1);
  strcpy(result->value, value);

  // Return the JSON object
  return result;
}

// Free the memory allocated for the JSON object
void freeJSON(JSON *json) {
  // Free the key and value of the JSON object
  free(json->key);
  free(json->value);

  // Free the JSON object itself
  free(json);
}

// Print the JSON object
void printJSON(JSON *json) {
  // Print the key and value of the JSON object
  printf("Key: %s\n", json->key);
  printf("Value: %s\n", json->value);
}

// Main function
int main() {
  // Define the JSON string
  char *json = "{ \"key\": \"value\" }";

  // Parse the JSON string
  JSON *result = parseJSON(json);

  // Print the JSON object
  printJSON(result);

  // Free the memory allocated for the JSON object
  freeJSON(result);

  return 0;
}
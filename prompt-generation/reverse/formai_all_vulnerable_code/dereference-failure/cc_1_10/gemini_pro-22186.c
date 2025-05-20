//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List of metadata types
enum metadata_type {
  TYPE_UNKNOWN,
  TYPE_STRING,
  TYPE_NUMBER,
  TYPE_DATE,
  TYPE_BOOLEAN
};

// Structure to store metadata
struct metadata {
  enum metadata_type type;
  char *value;
};

// Function to extract metadata from a string
struct metadata *extract_metadata(char *str) {
  struct metadata *metadata = malloc(sizeof(struct metadata));
  if (metadata == NULL) {
    return NULL;
  }

  // Check for empty string
  if (strlen(str) == 0) {
    metadata->type = TYPE_UNKNOWN;
    metadata->value = NULL;
    return metadata;
  }

  // Check for string type
  if (str[0] == '"' && str[strlen(str) - 1] == '"') {
    metadata->type = TYPE_STRING;
    metadata->value = strndup(str + 1, strlen(str) - 2);
    return metadata;
  }

  // Check for number type
  if (str[0] >= '0' && str[0] <= '9') {
    metadata->type = TYPE_NUMBER;
    metadata->value = strndup(str, strlen(str));
    return metadata;
  }

  // Check for date type
  if (str[0] >= 'a' && str[0] <= 'z') {
    metadata->type = TYPE_DATE;
    metadata->value = strndup(str, strlen(str));
    return metadata;
  }

  // Check for boolean type
  if (strcmp(str, "true") == 0 || strcmp(str, "false") == 0) {
    metadata->type = TYPE_BOOLEAN;
    metadata->value = strndup(str, strlen(str));
    return metadata;
  }

  // Unknown type
  metadata->type = TYPE_UNKNOWN;
  metadata->value = NULL;
  return metadata;
}

// Function to print metadata
void print_metadata(struct metadata *metadata) {
  switch (metadata->type) {
    case TYPE_STRING:
      printf("String: %s\n", metadata->value);
      break;
    case TYPE_NUMBER:
      printf("Number: %s\n", metadata->value);
      break;
    case TYPE_DATE:
      printf("Date: %s\n", metadata->value);
      break;
    case TYPE_BOOLEAN:
      printf("Boolean: %s\n", metadata->value);
      break;
    default:
      printf("Unknown type\n");
      break;
  }
}

int main() {
  // Get input string
  char *str = "name=\"John\", age=30, dob=\"1990-01-01\", active=true";

  // Extract metadata from the string
  struct metadata *metadata = extract_metadata(str);

  // Print the metadata
  print_metadata(metadata);

  // Free the allocated memory
  free(metadata->value);
  free(metadata);

  return 0;
}
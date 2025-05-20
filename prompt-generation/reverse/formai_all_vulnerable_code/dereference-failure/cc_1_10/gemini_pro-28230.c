//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 4096

static int compare_strings(const char *a, const char *b) {
  if (a == NULL || b == NULL) { return -1; }
  return strcmp(a, b);
}

static int compare_integers(const void *a, const void *b) {
  if (a == NULL || b == NULL) { return -1; }
  const int *ia = (const int *)a;
  const int *ib = (const int *)b;
  return (*ia < *ib) ? -1 : (*ia > *ib);
}

static int compare_doubles(const void *a, const void *b) {
  if (a == NULL || b == NULL) { return -1; }
  const double *da = (const double *)a;
  const double *db = (const double *)b;
  return (*da < *db) ? -1 : (*da > *db);
}

static void print_json(const char *key, const char *value) {
  if (key == NULL || value == NULL) { return; }
  printf("{\"%s\": \"%s\"}\n", key, value);
}

static void print_json_integer(const char *key, int value) {
  if (key == NULL) { return; }
  printf("{\"%s\": %d}\n", key, value);
}

static void print_json_double(const char *key, double value) {
  if (key == NULL) { return; }
  printf("{\"%s\": %f}\n", key, value);
}

static void print_json_boolean(const char *key, int value) {
  if (key == NULL) { return; }
  printf("{\"%s\": %s}\n", key, value ? "true" : "false");
}

static void print_json_array(const char *key, const char **values, size_t count) {
  if (key == NULL || values == NULL || count == 0) { return; }
  printf("{\"%s\": [", key);
  for (size_t i = 0; i < count; i++) {
    printf("\"%s\"", values[i]);
    if (i < count - 1) { printf(", "); }
  }
  printf("]}\n");
}

static void print_json_object(const char *key, const char **keys, const char **values, size_t count) {
  if (key == NULL || keys == NULL || values == NULL || count == 0) { return; }
  printf("{\"%s\": {", key);
  for (size_t i = 0; i < count; i++) {
    printf("\"%s\": \"%s\"", keys[i], values[i]);
    if (i < count - 1) { printf(", "); }
  }
  printf("}}\n");
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <metadata file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *key = NULL;
    char *value = NULL;

    // Split the line into key and value
    char *delim = strchr(line, ':');
    if (delim != NULL) {
      key = strdup(strtok(line, ":"));
      value = strdup(strtok(NULL, "\n"));
    }

    // Check if the key is valid
    if (key == NULL || strlen(key) == 0) {
      fprintf(stderr, "Invalid metadata key: %s\n", line);
      continue;
    }

    // Check if the value is valid
    if (value == NULL || strlen(value) == 0) {
      fprintf(stderr, "Invalid metadata value: %s\n", line);
      continue;
    }

    // Trim spaces from the key and value
    key = strdup(strtok(key, " "));
    value = strdup(strtok(value, " "));

    // Convert the value to the appropriate type
    int integer_value = 0;
    double double_value = 0.0;
    int boolean_value = 0;

    if (strcmp(value, "true") == 0 || strcmp(value, "false") == 0) {
      boolean_value = (strcmp(value, "true") == 0);
    } else if (sscanf(value, "%d", &integer_value) == 1) {
      // Do nothing
    } else if (sscanf(value, "%lf", &double_value) == 1) {
      // Do nothing
    } else {
      fprintf(stderr, "Invalid metadata value: %s\n", line);
      continue;
    }

    // Print the metadata in JSON format
    print_json(key, value);
    print_json_integer("integer_value", integer_value);
    print_json_double("double_value", double_value);
    print_json_boolean("boolean_value", boolean_value);

    // Free the allocated memory
    free(key);
    free(value);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}
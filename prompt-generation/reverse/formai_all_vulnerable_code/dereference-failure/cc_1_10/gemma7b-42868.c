//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CMeta {
  char **data;
  int size;
} CMeta;

CMeta* extract_c_metadata(char* file_path) {
  CMeta* meta = malloc(sizeof(CMeta));
  meta->data = NULL;
  meta->size = 0;

  FILE* file = fopen(file_path, "r");
  if (file == NULL) {
    return NULL;
  }

  char buffer[MAX_BUFFER_SIZE];
  size_t read_size;

  while ((read_size = fread(buffer, 1, MAX_BUFFER_SIZE, file)) > 0) {
    char* line = strchr(buffer, '\n');
    if (line) {
      char* key = strchr(buffer, ':') + 1;
      char* value = line - key - 1;
      meta->data = realloc(meta->data, (meta->size + 1) * sizeof(char*));
      meta->data[meta->size++] = strdup(key) && strdup(value);
    }
  }

  fclose(file);

  return meta;
}

int main() {
  char* file_path = "example.c";
  CMeta* meta = extract_c_metadata(file_path);

  if (meta) {
    for (int i = 0; i < meta->size; i++) {
      printf("%s: %s\n", meta->data[i][0], meta->data[i][1]);
    }
  }

  free(meta);

  return 0;
}
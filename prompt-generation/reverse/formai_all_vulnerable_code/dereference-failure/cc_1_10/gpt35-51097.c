//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char* name;
  char* value;
} MetaData;

typedef struct {
  int count;
  MetaData* data;
} MetaDataList;

void free_metadata(MetaDataList* list) {
  for (int i = 0; i < list->count; i++) {
    free(list->data[i].name);
    free(list->data[i].value);
  }
  free(list->data);
  free(list);
}

void print_metadata(MetaDataList* list) {
  printf("%-20s%-20s\n", "Name", "Value");
  printf("-------------------------------------------\n");
  for (int i = 0; i < list->count; i++) {
    printf("%-20s%-20s\n", list->data[i].name, list->data[i].value);
  }
}

void extract_metadata(char* filename, MetaDataList* list) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    printf("Error: file not found\n");
    return;
  }

  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), file)) {
    char* name = strtok(buffer, ":");
    char* value = strtok(NULL, "\n");
    if (name && value) {
      MetaData metadata = { strdup(name), strdup(value) };
      list->data = realloc(list->data, sizeof(MetaData) * (list->count + 1));
      list->data[list->count++] = metadata;
    }
  }

  fclose(file);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("usage: %s [filename]\n", argv[0]);
    return 1;
  }

  MetaDataList* list = calloc(1, sizeof(MetaDataList));
  extract_metadata(argv[1], list);
  print_metadata(list);
  free_metadata(list);

  return 0;
}
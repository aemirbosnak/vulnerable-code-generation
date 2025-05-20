//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Metadata {
  char *name;
  char *description;
  int size;
  struct Metadata *next;
} Metadata;

Metadata *extract_metadata(char *filename) {
  FILE *fp;
  Metadata *head = NULL;
  char line[256];

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  while (fgets(line, 256, fp) != NULL) {
    char *key = strchr(line, ':');
    char *value = strchr(line, ';');

    if (key && value) {
      Metadata *new_metadata = malloc(sizeof(Metadata));
      new_metadata->name = strdup(key + 1);
      new_metadata->description = strdup(value);
      new_metadata->size = atoi(strchr(line, '#') - line);
      new_metadata->next = head;
      head = new_metadata;
    }
  }

  fclose(fp);
  return head;
}

int main() {
  Metadata *metadata = extract_metadata("my_file.txt");

  for (Metadata *current = metadata; current; current = current->next) {
    printf("Name: %s\n", current->name);
    printf("Description: %s\n", current->description);
    printf("Size: %d\n", current->size);
    printf("\n");
  }

  return 0;
}
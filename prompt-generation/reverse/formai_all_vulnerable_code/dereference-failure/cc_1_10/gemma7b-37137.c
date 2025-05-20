//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECOVERY_SIZE 1024

typedef struct DataRecord {
  char *name;
  int size;
  struct DataRecord *next;
} DataRecord;

void recoverData(DataRecord **head) {
  FILE *file = fopen("data.txt", "r");
  if (!file) {
    return;
  }

  DataRecord *newRecord = NULL;
  char buffer[MAX_RECOVERY_SIZE];
  int i = 0;

  while (fgets(buffer, MAX_RECOVERY_SIZE, file) != NULL) {
    char *name = strchr(buffer, ':');
    int size = atoi(strchr(name, ')') + 1);
    name = strchr(buffer, '"') + 1;

    if (newRecord == NULL) {
      newRecord = malloc(sizeof(DataRecord));
      *head = newRecord;
    }

    newRecord->name = strdup(name);
    newRecord->size = size;
    newRecord->next = NULL;

    newRecord = newRecord->next;
  }

  fclose(file);
}

int main() {
  DataRecord *head = NULL;
  recoverData(&head);

  DataRecord *current = head;
  while (current) {
    printf("Name: %s, Size: %d\n", current->name, current->size);
    current = current->next;
  }

  return 0;
}
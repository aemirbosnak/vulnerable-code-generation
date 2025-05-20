//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_FIELDS 16

typedef struct Record {
  char **fields;
  int num_fields;
} Record;

Record **read_csv(char *filename) {
  FILE *fp;
  Record **records = NULL;
  int num_records = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_LINES];
  char **fields = NULL;
  int num_fields = 0;

  while (fgets(line, MAX_LINES, fp) != NULL) {
    fields = malloc(MAX_FIELDS * sizeof(char *));
    num_fields = 0;

    char *p = line;
    char *field = strtok(p, ",");
    while (field) {
      fields[num_fields++] = strdup(field);
      field = strtok(NULL, ",");
    }

    Record *record = malloc(sizeof(Record));
    record->fields = fields;
    record->num_fields = num_fields;

    records = realloc(records, (num_records + 1) * sizeof(Record *));
    records[num_records++] = record;
  }

  fclose(fp);

  return records;
}

int main() {
  Record **records = read_csv("data.csv");

  for (int i = 0; records[i] != NULL; i++) {
    for (int j = 0; records[i]->fields[j] != NULL; j++) {
      printf("%s ", records[i]->fields[j]);
    }
    printf("\n");
  }

  return 0;
}
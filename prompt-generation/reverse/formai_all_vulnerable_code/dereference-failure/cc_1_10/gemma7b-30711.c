//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct CSV_Record {
  char **fields;
  int num_fields;
} CSV_Record;

CSV_Record **read_csv(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_LINES];
  int line_num = 0;
  CSV_Record **records = NULL;

  while (fgets(line, MAX_LINES, fp) != NULL) {
    line_num++;
    CSV_Record *record = malloc(sizeof(CSV_Record));
    record->fields = malloc(10 * sizeof(char *));
    record->num_fields = 0;

    char *field = strtok(line, ",");
    while (field) {
      record->fields[record->num_fields++] = strdup(field);
      field = strtok(NULL, ",");
    }

    records = realloc(records, (line_num) * sizeof(CSV_Record *));
    records[line_num - 1] = record;
  }

  fclose(fp);
  return records;
}

int main() {
  CSV_Record **records = read_csv("example.csv");

  for (int i = 0; records[i] != NULL; i++) {
    for (int j = 0; records[i]->fields[j] != NULL; j++) {
      printf("%s,", records[i]->fields[j]);
    }
    printf("\n");
  }

  return 0;
}
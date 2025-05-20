//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CsvRecord {
  char **data;
  int num_cols;
} CsvRecord;

CsvRecord *read_csv(char *filename) {
  FILE *fp;
  CsvRecord *record = malloc(sizeof(CsvRecord));
  record->data = NULL;
  record->num_cols = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    char *comma = strchr(line, ',');
    if (comma) {
      record->num_cols++;
      record->data = realloc(record->data, (record->num_cols) * sizeof(char *));
      record->data[record->num_cols - 1] = strdup(comma + 1);
    }
  }

  fclose(fp);
  return record;
}

int main() {
  CsvRecord *record = read_csv("data.csv");

  if (record) {
    for (int i = 0; i < record->num_cols; i++) {
      printf("%s ", record->data[i]);
    }
    printf("\n");
    free(record->data);
    free(record);
  }

  return 0;
}
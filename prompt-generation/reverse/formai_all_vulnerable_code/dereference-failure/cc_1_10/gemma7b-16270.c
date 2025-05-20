//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSV_Record {
  char **data;
  int num_cols;
} CSV_Record;

CSV_Record *read_csv(char *filename) {
  FILE *fp;
  CSV_Record *record = malloc(sizeof(CSV_Record));
  record->data = NULL;
  record->num_cols = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char line[MAX_LINES];
  char **cols = NULL;
  int num_cols = 0;

  while (fgets(line, MAX_LINES, fp) != NULL) {
    cols = realloc(cols, (num_cols + 1) * sizeof(char *));
    cols[num_cols++] = strdup(line);
  }

  record->data = cols;
  record->num_cols = num_cols;

  fclose(fp);

  return record;
}

int main() {
  CSV_Record *record = read_csv("example.csv");

  for (int i = 0; i < record->num_cols; i++) {
    printf("%s\n", record->data[0][i]);
  }

  free(record->data);
  free(record);

  return 0;
}
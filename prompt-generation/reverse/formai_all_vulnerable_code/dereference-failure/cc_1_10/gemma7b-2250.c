//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Record {
  char **data;
  int num_cols;
} CSV_Record;

CSV_Record *read_csv(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  CSV_Record *record = malloc(sizeof(CSV_Record));
  record->data = NULL;
  record->num_cols = 0;

  char line[MAX_ROWS];
  while (fgets(line, MAX_ROWS, fp) != NULL) {
    char *comma = strchr(line, ',');
    int num_cols = 0;
    char **data = malloc(MAX_COLS * sizeof(char *));
    while (comma) {
      data[num_cols++] = strdup(comma + 1);
      comma = strchr(comma + 1, ',');
    }
    data[num_cols] = NULL;
    record->data = data;
    record->num_cols = num_cols;
  }

  fclose(fp);
  return record;
}

int main() {
  CSV_Record *record = read_csv("example.csv");
  for (int i = 0; i < record->num_cols; i++) {
    printf("%s,", record->data[0][i]);
  }
  printf("\n");

  free(record->data);
  free(record);

  return 0;
}
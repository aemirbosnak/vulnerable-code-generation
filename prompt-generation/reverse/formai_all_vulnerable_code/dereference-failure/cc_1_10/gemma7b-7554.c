//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct Record {
  char **data;
  int num_cols;
} Record;

Record *read_csv(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char **lines = malloc(MAX_LINES * sizeof(char *));
  for (int i = 0; i < MAX_LINES; i++) {
    lines[i] = malloc(MAX_COLS * sizeof(char));
  }

  int num_lines = 0;
  char line[MAX_COLS];
  while (fgets(line, MAX_COLS, fp) != NULL) {
    lines[num_lines] = strdup(line);
    num_lines++;
  }

  fclose(fp);

  Record *record = malloc(sizeof(Record));
  record->data = lines;
  record->num_cols = num_lines;

  return record;
}

int main() {
  char *filename = "data.csv";
  Record *record = read_csv(filename);

  for (int i = 0; i < record->num_cols; i++) {
    printf("%s\n", record->data[0][i]);
  }

  free(record->data);
  free(record);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct Record {
  char **data;
  int num_cols;
} Record;

Record *read_csv(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  char **lines = NULL;
  int num_lines = 0;

  // Allocate memory for lines
  lines = malloc(MAX_LINES * sizeof(char *));
  if (lines == NULL) {
    fclose(fp);
    return NULL;
  }

  // Read lines from the file
  char line[MAX_COLS];
  while (fgets(line, MAX_COLS, fp) != NULL) {
    lines[num_lines++] = strdup(line);
  }

  fclose(fp);

  // Create a record
  Record *record = malloc(sizeof(Record));
  record->data = lines;
  record->num_cols = num_lines;

  return record;
}

int main() {
  Record *record = read_csv("data.csv");

  // Print the data
  for (int i = 0; i < record->num_cols; i++) {
    printf("%s\n", record->data[i]);
  }

  free(record->data);
  free(record);

  return 0;
}
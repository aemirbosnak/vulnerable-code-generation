//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
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

  char line[MAX_LINES];
  CSV_Record *record = malloc(sizeof(CSV_Record));
  record->num_cols = 0;
  record->data = NULL;

  while (fgets(line, MAX_LINES, fp) != NULL) {
    char **cols = malloc((record->num_cols + 1) * sizeof(char *));
    for (int i = 0; line[i] != '\0'; i++) {
      if (line[i] == ',') {
        cols[record->num_cols++] = strdup(line + i + 1);
      }
    }
    cols[record->num_cols] = NULL;
    record->data = cols;
  }

  fclose(fp);
  return record;
}

int main() {
  CSV_Record *record = read_csv("example.csv");
  for (int i = 0; record->data[i] != NULL; i++) {
    for (int j = 0; record->data[i][j] != NULL; j++) {
      printf("%s,", record->data[i][j]);
    }
    printf("\n");
  }

  free(record);
  return 0;
}
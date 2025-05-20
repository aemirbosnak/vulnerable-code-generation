//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Entry {
  char **data;
  int num_rows;
  int num_cols;
} CSV_Entry;

CSV_Entry *csv_reader(char *filename) {
  CSV_Entry *entry = malloc(sizeof(CSV_Entry));

  entry->data = malloc(MAX_LINES * MAX_COLS * sizeof(char *));
  entry->num_rows = 0;
  entry->num_cols = 0;

  FILE *fp = fopen(filename, "r");
  if (!fp) {
    return NULL;
  }

  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    char *data = strdup(line);
    entry->data[entry->num_rows] = data;
    entry->num_rows++;
  }

  fclose(fp);

  return entry;
}

int main() {
  char *filename = "data.csv";
  CSV_Entry *entry = csv_reader(filename);

  for (int i = 0; i < entry->num_rows; i++) {
    for (int j = 0; j < entry->num_cols; j++) {
      printf("%s,", entry->data[i][j]);
    }
    printf("\n");
  }

  free(entry->data);
  free(entry);

  return 0;
}
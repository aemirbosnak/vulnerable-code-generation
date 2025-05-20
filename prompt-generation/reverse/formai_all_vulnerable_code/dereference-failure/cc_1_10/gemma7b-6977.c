//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 10
#define MAX_ROWS 100

typedef struct CSV_Reader {
  char **data;
  int num_rows;
  int num_cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int num_rows, int num_cols) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->data = malloc(sizeof(char *) * num_rows);
  for (int r = 0; r < num_rows; r++) {
    reader->data[r] = malloc(sizeof(char *) * num_cols);
  }
  reader->num_rows = num_rows;
  reader->num_cols = num_cols;
  return reader;
}

void csv_reader_free(CSV_Reader *reader) {
  for (int r = 0; r < reader->num_rows; r++) {
    free(reader->data[r]);
  }
  free(reader->data);
  free(reader);
}

void csv_reader_read(CSV_Reader *reader, char **line) {
  int col = 0;
  for (int i = 0; i < reader->num_cols && line[i] != '\0'; i++) {
    reader->data[reader->num_rows - 1][col++] = line[i];
  }
  reader->num_rows++;
}

int main() {
  CSV_Reader *reader = csv_reader_init(MAX_ROWS, MAX_COLS);

  char line[MAX_COLS];
  printf("Enter a CSV line (separate columns with commas): ");
  scanf("%s", line);

  csv_reader_read(reader, line);

  printf("Data stored in CSV Reader:\n");
  for (int r = 0; r < reader->num_rows; r++) {
    for (int c = 0; c < reader->num_cols; c++) {
      printf("%s ", reader->data[r][c]);
    }
    printf("\n");
  }

  csv_reader_free(reader);

  return 0;
}
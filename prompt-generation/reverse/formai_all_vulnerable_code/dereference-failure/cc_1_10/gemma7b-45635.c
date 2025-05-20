//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
  char **data;
  int rows;
  int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->data = malloc(sizeof(char *) * rows);
  for (int r = 0; r < rows; r++) {
    reader->data[r] = malloc(sizeof(char) * cols);
  }
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_read(CSV_Reader *reader, char *csv_data) {
  char **lines = NULL;
  int lines_num = 0;
  char *line = strtok(csv_data, "\n");
  while (line) {
    lines = realloc(lines, (lines_num + 1) * sizeof(char *));
    lines[lines_num++] = line;
    line = strtok(NULL, "\n");
  }

  reader->rows = lines_num;
  reader->data = lines;
}

void csv_reader_print(CSV_Reader *reader) {
  for (int r = 0; r < reader->rows; r++) {
    for (int c = 0; c < reader->cols; c++) {
      printf("%s,", reader->data[r][c]);
    }
    printf("\n");
  }
}

int main() {
  CSV_Reader *reader = csv_reader_init(5, 3);
  csv_reader_read(reader, "a,b,c\nd,e,f\ng,h,i");
  csv_reader_print(reader);
  free(reader);

  return 0;
}
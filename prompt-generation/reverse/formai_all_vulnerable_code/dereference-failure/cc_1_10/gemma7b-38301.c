//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
  char **data;
  int rows;
  int cols;
} CSVReader;

CSVReader* csv_reader_init(int rows, int cols) {
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * rows);
  for (int i = 0; i < rows; i++) {
    reader->data[i] = malloc(sizeof(char) * cols);
  }
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_free(CSVReader* reader) {
  for (int i = 0; i < reader->rows; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

void csv_reader_read(CSVReader* reader, char* csv_data) {
  char* line = strtok(csv_data, "\n");
  int row = 0;
  while (line) {
    char* col = strtok(line, ",");
    int col_num = 0;
    while (col) {
      reader->data[row][col_num] = strdup(col);
      col = strtok(NULL, ",");
      col_num++;
    }
    row++;
    line = strtok(NULL, "\n");
  }
}

int main() {
  CSVReader* reader = csv_reader_init(5, 3);
  csv_reader_read(reader, "a,b,c\nd,e,f\ng,h,i");
  for (int r = 0; r < reader->rows; r++) {
    for (int c = 0; c < reader->cols; c++) {
      printf("%s ", reader->data[r][c]);
    }
    printf("\n");
  }
  csv_reader_free(reader);
  return 0;
}
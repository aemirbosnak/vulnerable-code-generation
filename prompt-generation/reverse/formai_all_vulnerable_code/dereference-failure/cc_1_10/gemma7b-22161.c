//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader {
  FILE *fp;
  char **data;
  int rows;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(char *filename) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fopen(filename, "r");
  reader->data = NULL;
  reader->rows = 0;
  reader->cols = 0;

  return reader;
}

void csv_reader_read(CSVReader *reader) {
  char line[MAX_ROWS][MAX_COLS];
  int i, j, k = 0;

  while (fgets(line[k], MAX_COLS, reader->fp) != NULL) {
    reader->rows++;
    k++;
  }

  reader->data = malloc(reader->rows * sizeof(char *) + 1);

  k = 0;
  while (fgets(line[k], MAX_COLS, reader->fp) != NULL) {
    reader->cols++;
    char **row = reader->data + k;
    row = malloc(reader->cols * sizeof(char *) + 1);

    j = 0;
    for (i = 0; line[k][i] != '\0'; i++) {
      row[j] = line[k][i];
      j++;
    }

    row[j] = NULL;
    k++;
  }

  fclose(reader->fp);
}

int main() {
  CSVReader *reader = csv_reader_init("data.csv");
  csv_reader_read(reader);

  // Print the data
  for (int i = 0; reader->data[i] != NULL; i++) {
    for (int j = 0; reader->data[i][j] != NULL; j++) {
      printf("%c ", reader->data[i][j]);
    }
    printf("\n");
  }

  free(reader);

  return 0;
}
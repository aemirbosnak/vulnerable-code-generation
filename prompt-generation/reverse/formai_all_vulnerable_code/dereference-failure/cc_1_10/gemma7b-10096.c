//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 20

typedef struct CSVReader {
  char **data;
  int rows;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(int rows, int cols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * rows);
  for (int i = 0; i < rows; i++) {
    reader->data[i] = malloc(sizeof(char *) * cols);
  }
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_free(CSVReader *reader) {
  for (int i = 0; i < reader->rows; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader *reader = csv_reader_init(10, 5);

  // Read data from CSV file or other source
  reader->data[0][0] = "John Doe";
  reader->data[0][1] = "jane.doe@example.com";
  reader->data[0][2] = "123 Main St";
  reader->data[0][3] = "New York";
  reader->data[0][4] = "12345";

  // Process data
  printf("Name: %s\n", reader->data[0][0]);
  printf("Email: %s\n", reader->data[0][1]);
  printf("Address: %s\n", reader->data[0][2]);
  printf("City: %s\n", reader->data[0][3]);
  printf("Zip Code: %s\n", reader->data[0][4]);

  // Free memory
  csv_reader_free(reader);

  return 0;
}
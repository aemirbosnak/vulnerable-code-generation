//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSVReader
{
  char **data;
  int rows;
  int cols;
} CSVReader;

CSVReader* csv_reader_init(int rows, int cols)
{
  CSVReader* reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * rows);
  for (int i = 0; i < rows; i++)
    reader->data[i] = malloc(sizeof(char) * cols);
  reader->rows = rows;
  reader->cols = cols;
  return reader;
}

void csv_reader_add_data(CSVReader* reader, char** data)
{
  for (int r = 0; r < reader->rows; r++)
  {
    for (int c = 0; c < reader->cols; c++)
    {
      reader->data[r][c] = data[r][c];
    }
  }
}

void csv_reader_print(CSVReader* reader)
{
  for (int r = 0; r < reader->rows; r++)
  {
    for (int c = 0; c < reader->cols; c++)
    {
      printf("%s,", reader->data[r][c]);
    }
    printf("\n");
  }
}

int main()
{
  CSVReader* reader = csv_reader_init(5, 3);
  char** data = malloc(sizeof(char *) * 5);
  for (int i = 0; i < 5; i++)
    data[i] = malloc(sizeof(char) * 3);

  data[0][0] = "John";
  data[0][1] = "Doe";
  data[0][2] = "New York";

  data[1][0] = "Jane";
  data[1][1] = "Doe";
  data[1][2] = "Los Angeles";

  csv_reader_add_data(reader, data);

  csv_reader_print(reader);

  free(data);
  free(reader);
  return 0;
}
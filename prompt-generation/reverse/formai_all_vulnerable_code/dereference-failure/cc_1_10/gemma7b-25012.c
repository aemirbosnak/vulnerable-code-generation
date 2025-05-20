//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSVReader
{
  char **data;
  int lines;
  int cols;
} CSVReader;

CSVReader *csv_reader_init(int lines, int cols)
{
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * lines);
  for (int i = 0; i < lines; i++)
    reader->data[i] = malloc(sizeof(char) * cols);
  reader->lines = lines;
  reader->cols = cols;
  return reader;
}

void csv_reader_free(CSVReader *reader)
{
  for (int i = 0; i < reader->lines; i++)
    free(reader->data[i]);
  free(reader->data);
  free(reader);
}

int csv_reader_read(CSVReader *reader, char *line)
{
  int pos = 0;
  for (int i = 0; i < reader->lines && pos < MAX_LINES; i++)
  {
    if (strcmp(line, reader->data[i]) == 0)
      return i;
    pos++;
  }
  return -1;
}

int main()
{
  CSVReader *reader = csv_reader_init(MAX_LINES, MAX_COLS);
  reader->data[0] = "John Doe,123 Main St,New York,NY 10001";
  reader->data[1] = "Jane Doe,456 Oak Ave,Los Angeles,CA 90210";
  reader->data[2] = "Bill Smith,789 Park Ave,Chicago,IL 60601";

  char *line = "John Doe,123 Main St,New York,NY 10001";
  int index = csv_reader_read(reader, line);

  if (index != -1)
    printf("Index of line: %d\n", index);

  csv_reader_free(reader);

  return 0;
}
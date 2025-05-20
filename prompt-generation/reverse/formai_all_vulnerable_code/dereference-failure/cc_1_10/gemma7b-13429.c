//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSVReader {
  char **data;
  int numLines;
  int numCols;
} CSVReader;

CSVReader *csvReader_init(int numLines, int numCols) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->data = malloc(sizeof(char *) * numLines);
  for (int i = 0; i < numLines; i++) {
    reader->data[i] = malloc(sizeof(char) * numCols);
  }
  reader->numLines = numLines;
  reader->numCols = numCols;
  return reader;
}

void csvReader_addEntry(CSVReader *reader, char **entry) {
  reader->data[reader->numLines] = entry;
  reader->numLines++;
}

void csvReader_free(CSVReader *reader) {
  for (int i = 0; i < reader->numLines; i++) {
    free(reader->data[i]);
  }
  free(reader->data);
  free(reader);
}

int main() {
  CSVReader *reader = csvReader_init(10, 5);
  char **entry = malloc(sizeof(char *) * 5);
  entry[0] = "John Doe";
  entry[1] = "New York";
  entry[2] = "USA";
  entry[3] = "engineer";
  entry[4] = "25";
  csvReader_addEntry(reader, entry);

  entry = malloc(sizeof(char *) * 5);
  entry[0] = "Jane Doe";
  entry[1] = "Los Angeles";
  entry[2] = "USA";
  entry[3] = "teacher";
  entry[4] = "30";
  csvReader_addEntry(reader, entry);

  for (int i = 0; i < reader->numLines; i++) {
    for (int j = 0; j < reader->numCols; j++) {
      printf("%s ", reader->data[i][j]);
    }
    printf("\n");
  }

  csvReader_free(reader);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSV_Reader {
  char **data;
  int lines;
  int cols;
  FILE *fp;
} CSV_Reader;

CSV_Reader *create_csv_reader(char *filename) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->data = NULL;
  reader->lines = 0;
  reader->cols = 0;
  reader->fp = fopen(filename, "r");

  return reader;
}

void read_csv(CSV_Reader *reader) {
  char line[MAX_LINES];
  char **cols = NULL;

  while (fgets(line, MAX_LINES, reader->fp) != NULL) {
    reader->lines++;
    cols = realloc(cols, reader->cols * sizeof(char *));

    // Split the line into columns
    char *ptr = line;
    int col = 0;
    while (ptr) {
      cols[col++] = strdup(ptr);
      ptr = strchr(ptr, ',') ? strchr(ptr, ',') + 1 : NULL;
    }

    reader->cols = col;
    reader->data = realloc(reader->data, reader->lines * sizeof(char **));
    reader->data[reader->lines - 1] = cols;
  }
}

int main() {
  CSV_Reader *reader = create_csv_reader("example.csv");
  read_csv(reader);

  // Print the data
  for (int i = 0; i < reader->lines; i++) {
    for (int j = 0; j < reader->cols; j++) {
      printf("%s, ", reader->data[i][j]);
    }
    printf("\n");
  }

  fclose(reader->fp);
  free(reader->data);
  free(reader);

  return 0;
}
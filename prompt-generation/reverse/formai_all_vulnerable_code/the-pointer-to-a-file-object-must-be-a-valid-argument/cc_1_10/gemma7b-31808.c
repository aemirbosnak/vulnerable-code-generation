//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Reader {
  char **buffer;
  int size;
  int pos;
  FILE *fp;
} CSV_Reader;

CSV_Reader *create_csv_reader(FILE *fp) {
  CSV_Reader *reader = malloc(sizeof(CSV_Reader));
  reader->buffer = NULL;
  reader->size = 0;
  reader->pos = 0;
  reader->fp = fp;
  return reader;
}

void read_csv_line(CSV_Reader *reader) {
  char line[MAX_BUFFER_SIZE];
  int len = 0;

  reader->buffer = realloc(reader->buffer, (reader->size + 1) * MAX_BUFFER_SIZE);

  // Read line from file
  fgets(line, MAX_BUFFER_SIZE, reader->fp);

  // Remove newline character
  line[strcspn(line, "\n")] = '\0';

  // Add line to buffer
  reader->buffer[reader->size++] = strdup(line);
}

void free_csv_reader(CSV_Reader *reader) {
  free(reader->buffer);
  free(reader);
}

int main() {
  FILE *fp = fopen("data.csv", "r");
  CSV_Reader *reader = create_csv_reader(fp);

  read_csv_line(reader);

  // Print line from buffer
  printf("%s\n", reader->buffer[0]);

  free_csv_reader(reader);
  fclose(fp);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 100

typedef struct {
  char *fields[MAX_FIELDS];
  int num_fields;
} CSVRow;

typedef struct {
  FILE *fp;
  char *line;
  size_t line_size;
  CSVRow *row;
} CSVReader;

CSVReader *csv_reader_new(FILE *fp) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->fp = fp;
  reader->line = NULL;
  reader->line_size = 0;
  reader->row = malloc(sizeof(CSVRow));
  reader->row->num_fields = 0;
  return reader;
}

void csv_reader_free(CSVReader *reader) {
  if (reader->line != NULL) {
    free(reader->line);
  }
  if (reader->row != NULL) {
    free(reader->row);
  }
  free(reader);
}

int csv_reader_next_row(CSVReader *reader) {
  ssize_t line_length;

  line_length = getline(&reader->line, &reader->line_size, reader->fp);
  if (line_length == -1) {
    return 0;
  }

  reader->row->num_fields = 0;

  char *field_start = reader->line;
  char *field_end;

  while ((field_end = strchr(field_start, ',')) != NULL) {
    *field_end = '\0';
    reader->row->fields[reader->row->num_fields] = field_start;
    reader->row->num_fields++;
    field_start = field_end + 1;
  }

  reader->row->fields[reader->row->num_fields] = field_start;
  reader->row->num_fields++;

  return 1;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  CSVReader *reader = csv_reader_new(fp);

  while (csv_reader_next_row(reader)) {
    for (int i = 0; i < reader->row->num_fields; i++) {
      printf("%s ", reader->row->fields[i]);
    }
    printf("\n");
  }

  csv_reader_free(reader);
  fclose(fp);

  return EXIT_SUCCESS;
}
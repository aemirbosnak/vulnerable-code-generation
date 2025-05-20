//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128
#define MAX_NUM_FIELDS 16

typedef struct {
  char *fields[MAX_NUM_FIELDS];
  int num_fields;
} CSVLine;

typedef struct {
  FILE *file;
  CSVLine current_line;
  int current_line_num;
} CSVReader;

CSVReader *csv_reader_init(const char *filename) {
  CSVReader *reader = (CSVReader*)malloc(sizeof(CSVReader));
  reader->file = fopen(filename, "r");
  reader->current_line.fields[0] = NULL;
  reader->current_line.num_fields = 0;
  reader->current_line_num = 0;
  return reader;
}

void csv_reader_close(CSVReader *reader) {
  fclose(reader->file);
  free(reader);
}

void csv_line_parse(CSVLine *line, char *buf) {
  char *pfield = strtok(buf, ",");
  while (pfield && line->num_fields < MAX_NUM_FIELDS) {
    line->fields[line->num_fields++] = strdup(pfield);
    pfield = strtok(NULL, ",");
  }
}

CSVLine *csv_reader_next(CSVReader *reader) {
  char buf[MAX_LINE_LENGTH];
  while (fgets(buf, MAX_LINE_LENGTH, reader->file)) {
    reader->current_line_num++;
    if (strlen(buf) > 0 && buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = '\0';
    }
    csv_line_parse(&reader->current_line, buf);
    return &reader->current_line;
  }
  return NULL;
}

void csv_print_line(CSVLine *line) {
  int i;
  for (i = 0; i < line->num_fields; i++) {
    printf("%s", line->fields[i]);
    if (i < line->num_fields - 1) {
      printf(",");
    }
  }
  printf("\n");
}

int main() {
  CSVReader *reader = csv_reader_init("data.csv");
  CSVLine *line;
  while ((line = csv_reader_next(reader)) != NULL) {
    csv_print_line(line);
  }
  csv_reader_close(reader);
  return 0;
}
//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 256
#define MAX_FIELDS 32

typedef struct {
  char fields[MAX_FIELDS][MAX_FIELD_LEN];
  int num_fields;
} CsvRow;

typedef struct {
  FILE *filep;
  int line_num;
  char line[MAX_LINE_LEN];
} CsvReader;

CsvRow *read_csv_row(CsvReader *reader);

CsvReader *open_csv_file(char *file_name) {
  CsvReader *reader = (CsvReader *) malloc(sizeof(CsvReader));
  reader->filep = fopen(file_name, "r");
  reader->line_num = 0;
  return reader;
}

CsvRow *read_csv_row(CsvReader *reader) {
  char *c;
  CsvRow *row = (CsvRow *) malloc(sizeof(CsvRow));
  row->num_fields = 0;

  if(fgets(reader->line, MAX_LINE_LEN, reader->filep) == NULL) {
    free(row);
    return NULL;
  }

  reader->line_num++;

  c = strtok(reader->line, ",");
  while(c != NULL) {
    strncpy(row->fields[row->num_fields], c, MAX_FIELD_LEN);
    row->num_fields++;
    c = strtok(NULL, ",");
  }

  return row;
}

void close_csv_file(CsvReader *reader) {
  fclose(reader->filep);
  free(reader);
}

void print_csv_row(CsvRow *row) {
  int i;
  for(i=0; i < row->num_fields; i++) {
    printf("%s ", row->fields[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Usage: %s filename.csv\n", argv[0]);
    exit(1);
  }

  CsvReader *reader = open_csv_file(argv[1]);

  CsvRow *row = read_csv_row(reader);
  while(row != NULL) {
    print_csv_row(row);
    free(row);
    row = read_csv_row(reader);
  }

  close_csv_file(reader);

  return 0;
}
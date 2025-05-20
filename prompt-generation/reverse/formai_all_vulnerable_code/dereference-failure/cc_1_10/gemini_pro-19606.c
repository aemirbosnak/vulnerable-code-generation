//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 100

typedef struct {
  char *data;
  int length;
} Field;

typedef struct {
  Field fields[MAX_NUM_FIELDS];
  int num_fields;
} Record;

typedef struct {
  FILE *file;
  char *line_buffer;
  int line_buffer_size;
  int line_buffer_length;
  int line_number;
} CSVReader;

CSVReader *csv_reader_new(FILE *file) {
  CSVReader *reader = malloc(sizeof(CSVReader));
  reader->file = file;
  reader->line_buffer = NULL;
  reader->line_buffer_size = 0;
  reader->line_buffer_length = 0;
  reader->line_number = 0;
  return reader;
}

void csv_reader_free(CSVReader *reader) {
  if (reader->line_buffer) {
    free(reader->line_buffer);
  }
  free(reader);
}

int csv_reader_read_line(CSVReader *reader) {
  if (reader->line_buffer_length == 0) {
    reader->line_buffer_length = getline(&reader->line_buffer, &reader->line_buffer_size, reader->file);
    if (reader->line_buffer_length == -1) {
      return -1;
    }
    reader->line_number++;
  }
  return reader->line_buffer_length;
}

int csv_reader_parse_line(CSVReader *reader, Record *record) {
  char *line = reader->line_buffer;
  int line_length = reader->line_buffer_length;
  int num_fields = 0;
  int field_start = 0;
  int field_length = 0;
  int in_quotes = 0;
  for (int i = 0; i < line_length; i++) {
    char c = line[i];
    if (c == '"') {
      in_quotes = !in_quotes;
    } else if (c == ',' && !in_quotes) {
      record->fields[num_fields].data = &line[field_start];
      record->fields[num_fields].length = field_length;
      num_fields++;
      field_start = i + 1;
      field_length = 0;
    } else {
      field_length++;
    }
  }
  record->fields[num_fields].data = &line[field_start];
  record->fields[num_fields].length = field_length;
  num_fields++;
  record->num_fields = num_fields;
  return num_fields;
}

int main() {
  FILE *file = fopen("data.csv", "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  CSVReader *reader = csv_reader_new(file);

  Record record;
  while (csv_reader_read_line(reader) != -1) {
    csv_reader_parse_line(reader, &record);
    for (int i = 0; i < record.num_fields; i++) {
      printf("%s\n", record.fields[i].data);
    }
  }

  csv_reader_free(reader);
  fclose(file);

  return 0;
}
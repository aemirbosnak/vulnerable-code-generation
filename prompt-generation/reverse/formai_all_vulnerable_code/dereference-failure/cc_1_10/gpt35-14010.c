//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

typedef struct csv_row_struct {
  char** columns;
  int num_cols;
} csv_row;

typedef struct csv_reader_struct {
  FILE* file;
  char* buffer;
  int buffer_size;
  int buffer_pos;
} csv_reader;

void csv_reader_init(csv_reader* reader, FILE* file) {
  reader->file = file;
  reader->buffer_size = MAX_BUFFER_SIZE;
  reader->buffer_pos = 0;
  reader->buffer = malloc(MAX_BUFFER_SIZE);
}

void csv_reader_cleanup(csv_reader* reader) {
  free(reader->buffer);
  reader->buffer = NULL;
  reader->buffer_size = 0;
  reader->buffer_pos = 0;
}

int csv_reader_read_line(csv_reader* reader, char* line_buffer, int line_buffer_size) {
  char c;
  int count = 0;

  while ((c = fgetc(reader->file)) != EOF) {
    if (c == '\n') {
      line_buffer[count] = '\0';
      break;
    } else if (count < line_buffer_size-1) {
      line_buffer[count] = c;
      count++;
    }
  }

  if (count == line_buffer_size-1) {
    line_buffer[count] = '\0';

    while ((c = fgetc(reader->file)) != EOF && c != '\n') {
      // Consume rest of line
    }

    return -1;
  } else {
    return count;
  }
}

int csv_reader_parse_row(char* row_buffer, csv_row* row) {
  int num_cols = 1;
  char* p = row_buffer;

  while (*p) {
    if (*p == ',') {
      num_cols++;
    }

    p++;
  }

  row->columns = malloc(sizeof(char*) * num_cols);
  row->num_cols = num_cols;

  p = strtok(row_buffer, ",");
  int i = 0;

  while (p) {
    row->columns[i] = strdup(p);
    i++;
    p = strtok(NULL, ",");
  }

  return num_cols;
}

csv_row* csv_reader_read_row(csv_reader* reader) {
  int line_size = csv_reader_read_line(reader, reader->buffer + reader->buffer_pos, reader->buffer_size - reader->buffer_pos);

  if (line_size == -1) {
    // Line was too long for buffer, try again with larger buffer
    reader->buffer_size *= 2;
    reader->buffer = realloc(reader->buffer, reader->buffer_size);
    reader->buffer_pos = line_size = csv_reader_read_line(reader, reader->buffer, reader->buffer_size);
  }

  if (line_size == 0) {
    // End of file reached
    return NULL;
  }

  csv_row* row = malloc(sizeof(csv_row));
  csv_reader_parse_row(reader->buffer + reader->buffer_pos, row);
  reader->buffer_pos += line_size;

  return row;
}

int main() {
  FILE* file = fopen("example.csv", "r");

  if (!file) {
    printf("Error: Could not open file\n");
    return -1;
  }

  csv_reader reader;
  csv_reader_init(&reader, file);

  csv_row* row;

  while ((row = csv_reader_read_row(&reader))) {
    for (int i = 0; i < row->num_cols; i++) {
      printf("%s", row->columns[i]);

      if (i < row->num_cols - 1) {
        printf(",");
      }
    }

    printf("\n");
  }

  csv_reader_cleanup(&reader);
  fclose(file);

  return 0;
}
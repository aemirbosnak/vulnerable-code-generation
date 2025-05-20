//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

struct csv_reader {
  FILE *file;
  char line[MAX_LINE_LENGTH];
  char *fields[MAX_NUM_FIELDS];
  int num_fields;
};

struct csv_reader *csv_reader_new(FILE *file) {
  struct csv_reader *reader = malloc(sizeof(*reader));
  if (!reader) {
    return NULL;
  }

  reader->file = file;
  return reader;
}

void csv_reader_free(struct csv_reader *reader) {
  free(reader);
}

int csv_reader_next(struct csv_reader *reader) {
  if (!fgets(reader->line, MAX_LINE_LENGTH, reader->file)) {
    return -1;
  }

  reader->num_fields = 0;
  char *p = reader->line;
  while (*p) {
    if (*p == ',') {
      *p++ = '\0';
      reader->fields[reader->num_fields++] = p;
    } else {
      p++;
    }
  }

  return reader->num_fields;
}

char *csv_reader_get_field(struct csv_reader *reader, int index) {
  if (index < 0 || index >= reader->num_fields) {
    return NULL;
  }

  return reader->fields[index];
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");
  if (!file) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  struct csv_reader *reader = csv_reader_new(file);
  if (!reader) {
    perror("csv_reader_new");
    return EXIT_FAILURE;
  }

  while (csv_reader_next(reader) != -1) {
    for (int i = 0; i < reader->num_fields; i++) {
      printf("%s ", csv_reader_get_field(reader, i));
    }
    printf("\n");
  }

  csv_reader_free(reader);
  fclose(file);

  return EXIT_SUCCESS;
}
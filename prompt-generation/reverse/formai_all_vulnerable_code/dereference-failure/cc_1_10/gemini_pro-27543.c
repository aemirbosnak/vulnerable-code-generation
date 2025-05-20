//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **data;
  size_t num_rows;
  size_t num_cols;
} csv_t;

csv_t *csv_read(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  csv_t *csv = malloc(sizeof(csv_t));
  if (csv == NULL) {
    fclose(fp);
    return NULL;
  }

  csv->num_rows = 0;
  csv->num_cols = 0;
  csv->data = NULL;

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    csv->num_rows++;

    char *token = strtok(line, ",");
    while (token) {
      csv->data = realloc(csv->data, sizeof(char *) * csv->num_rows * csv->num_cols + 1);
      csv->data[csv->num_rows * csv->num_cols] = strdup(token);
      csv->num_cols++;

      token = strtok(NULL, ",");
    }
  }

  fclose(fp);

  return csv;
}

void csv_free(csv_t *csv) {
  for (size_t i = 0; i < csv->num_rows; i++) {
    for (size_t j = 0; j < csv->num_cols; j++) {
      free(csv->data[i * csv->num_cols + j]);
    }
  }

  free(csv->data);
  free(csv);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  csv_t *csv = csv_read(argv[1]);
  if (csv == NULL) {
    fprintf(stderr, "Error: could not open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  for (size_t i = 0; i < csv->num_rows; i++) {
    for (size_t j = 0; j < csv->num_cols; j++) {
      printf("%s ", csv->data[i * csv->num_cols + j]);
    }
    putchar('\n');
  }

  csv_free(csv);

  return EXIT_SUCCESS;
}
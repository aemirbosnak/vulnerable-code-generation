//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
  char *line;
  int line_number;
} line_t;

typedef struct {
  line_t *lines;
  int num_lines;
} dataset_t;

dataset_t *load_dataset(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  dataset_t *dataset = malloc(sizeof(dataset_t));
  if (dataset == NULL) {
    perror("Error allocating memory for dataset");
    return NULL;
  }

  dataset->lines = malloc(sizeof(line_t) * MAX_NUM_LINES);
  if (dataset->lines == NULL) {
    perror("Error allocating memory for lines");
    return NULL;
  }

  int i = 0;
  while (1) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
      break;
    }

    dataset->lines[i].line = strdup(line);
    dataset->lines[i].line_number = i + 1;
    i++;
  }

  dataset->num_lines = i;

  fclose(fp);

  return dataset;
}

void free_dataset(dataset_t *dataset) {
  for (int i = 0; i < dataset->num_lines; i++) {
    free(dataset->lines[i].line);
  }

  free(dataset->lines);
  free(dataset);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  dataset_t *dataset = load_dataset(argv[1]);
  if (dataset == NULL) {
    return EXIT_FAILURE;
  }

  // Do some data mining here...

  free_dataset(dataset);

  return EXIT_SUCCESS;
}
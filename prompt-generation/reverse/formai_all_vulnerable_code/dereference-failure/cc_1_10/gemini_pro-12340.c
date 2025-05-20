//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_ATTRIBUTES 100
#define MAX_NUM_EXAMPLES 1000

typedef struct {
  char *name;
  double value;
} Attribute;

typedef struct {
  Attribute *attributes;
  int num_attributes;
  double *examples;
  int num_examples;
} Dataset;

Dataset *read_dataset(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  Dataset *dataset = malloc(sizeof(Dataset));
  if (dataset == NULL) {
    perror("Error allocating memory for dataset");
    exit(EXIT_FAILURE);
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    char *token = strtok(line, ",");
    if (token == NULL) {
      continue;
    }

    Attribute *attribute = malloc(sizeof(Attribute));
    if (attribute == NULL) {
      perror("Error allocating memory for attribute");
      exit(EXIT_FAILURE);
    }

    attribute->name = strdup(token);
    if (attribute->name == NULL) {
      perror("Error allocating memory for attribute name");
      exit(EXIT_FAILURE);
    }

    token = strtok(NULL, ",");
    if (token == NULL) {
      continue;
    }

    attribute->value = atof(token);

    dataset->attributes = realloc(dataset->attributes, (dataset->num_attributes + 1) * sizeof(Attribute));
    if (dataset->attributes == NULL) {
      perror("Error reallocating memory for attributes");
      exit(EXIT_FAILURE);
    }

    dataset->attributes[dataset->num_attributes] = *attribute;
    dataset->num_attributes++;
  }

  fclose(fp);

  return dataset;
}

void print_dataset(Dataset *dataset) {
  for (int i = 0; i < dataset->num_attributes; i++) {
    printf("%s: ", dataset->attributes[i].name);
    for (int j = 0; j < dataset->num_examples; j++) {
      printf("%f ", dataset->examples[j * dataset->num_attributes + i]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  Dataset *dataset = read_dataset(argv[1]);

  print_dataset(dataset);

  return EXIT_SUCCESS;
}
//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the maximum number of attributes and instances
#define MAX_ATTRIBUTES 100
#define MAX_INSTANCES 1000

// Define the data structure for an instance
typedef struct {
  double attributes[MAX_ATTRIBUTES];
  int label;
} Instance;

// Define the data structure for a dataset
typedef struct {
  Instance instances[MAX_INSTANCES];
  int num_attributes;
  int num_instances;
} Dataset;

// Load a dataset from a CSV file
Dataset* load_dataset(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  Dataset* dataset = malloc(sizeof(Dataset));
  if (dataset == NULL) {
    perror("Error allocating memory for dataset");
    return NULL;
  }

  // Read the header line
  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("Error reading header line");
    return NULL;
  }

  // Parse the header line to get the number of attributes
  char* token = strtok(line, ",");
  dataset->num_attributes = 0;
  while (token != NULL) {
    dataset->num_attributes++;
    token = strtok(NULL, ",");
  }

  // Read the data lines
  int i = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Parse the data line to get the attribute values
    token = strtok(line, ",");
    int j = 0;
    while (token != NULL) {
      dataset->instances[i].attributes[j] = atof(token);
      j++;
      token = strtok(NULL, ",");
    }

    // Parse the data line to get the label
    dataset->instances[i].label = atoi(token);

    i++;
  }

  dataset->num_instances = i;

  fclose(fp);

  return dataset;
}

// Free the memory allocated for a dataset
void free_dataset(Dataset* dataset) {
  free(dataset);
}

// Print a dataset to the console
void print_dataset(Dataset* dataset) {
  for (int i = 0; i < dataset->num_instances; i++) {
    for (int j = 0; j < dataset->num_attributes; j++) {
      printf("%f,", dataset->instances[i].attributes[j]);
    }
    printf("%d\n", dataset->instances[i].label);
  }
}

// Main function
int main() {
  // Load the dataset from a CSV file
  Dataset* dataset = load_dataset("data.csv");
  if (dataset == NULL) {
    return 1;
  }

  // Print the dataset to the console
  print_dataset(dataset);

  // Free the memory allocated for the dataset
  free_dataset(dataset);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of data points and attributes
#define MAX_DATA_POINTS 1000
#define MAX_ATTRIBUTES 10

// Define the data structure for a data point
typedef struct {
  float attributes[MAX_ATTRIBUTES];
  int label;
} DataPoint;

// Define the data structure for a dataset
typedef struct {
  DataPoint data_points[MAX_DATA_POINTS];
  int num_data_points;
  int num_attributes;
} Dataset;

// Load a dataset from a CSV file
Dataset* load_dataset(char* filename) {
  // Open the CSV file
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }

  // Create a new dataset
  Dataset* dataset = (Dataset*)malloc(sizeof(Dataset));
  if (dataset == NULL) {
    printf("Error allocating memory for dataset\n");
    fclose(fp);
    return NULL;
  }

  // Read the header line
  char line[1024];
  fgets(line, 1024, fp);

  // Parse the header line to get the number of attributes
  char* token = strtok(line, ",");
  dataset->num_attributes = 0;
  while (token != NULL) {
    dataset->num_attributes++;
    token = strtok(NULL, ",");
  }

  // Read the data points
  int num_data_points = 0;
  while (fgets(line, 1024, fp) != NULL) {
    // Parse the data point
    token = strtok(line, ",");
    int i = 0;
    while (token != NULL) {
      dataset->data_points[num_data_points].attributes[i++] = atof(token);
      token = strtok(NULL, ",");
    }
    dataset->data_points[num_data_points].label = atoi(token);
    num_data_points++;
  }

  // Close the CSV file
  fclose(fp);

  // Set the number of data points in the dataset
  dataset->num_data_points = num_data_points;

  // Return the dataset
  return dataset;
}

// Free the memory allocated for a dataset
void free_dataset(Dataset* dataset) {
  // Free the memory allocated for the data points
  free(dataset->data_points);

  // Free the memory allocated for the dataset
  free(dataset);
}

// Print a dataset
void print_dataset(Dataset* dataset) {
  // Print the header line
  printf("Attributes:");
  for (int i = 0; i < dataset->num_attributes; i++) {
    printf(" %d", i);
  }
  printf(" Label\n");

  // Print the data points
  for (int i = 0; i < dataset->num_data_points; i++) {
    printf("Data point %d:", i);
    for (int j = 0; j < dataset->num_attributes; j++) {
      printf(" %f", dataset->data_points[i].attributes[j]);
    }
    printf(" %d\n", dataset->data_points[i].label);
  }
}

// Main function
int main() {
  // Load the dataset
  Dataset* dataset = load_dataset("data.csv");
  if (dataset == NULL) {
    printf("Error loading dataset\n");
    return 1;
  }

  // Print the dataset
  print_dataset(dataset);

  // Free the memory allocated for the dataset
  free_dataset(dataset);

  return 0;
}
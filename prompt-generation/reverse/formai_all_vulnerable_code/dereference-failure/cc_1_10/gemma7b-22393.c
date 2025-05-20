//Gemma-7B DATASET v1.0 Category: Data mining ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a function to read data from a file
void read_data(char *filename, int **data, int *num_records) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return;
  }

  // Allocate memory for the data and number of records
  *data = malloc(100 * sizeof(int));
  *num_records = 0;

  // Read data from the file
  char line[100];
  while (fgets(line, 100, fp) != NULL) {
    (*num_records)++;
    int value = atoi(line);
    (*data)[*num_records - 1] = value;
  }

  fclose(fp);
}

// Define a function to find the mean of a set of numbers
double find_mean(int *data, int num_records) {
  int total = 0;
  for (int i = 0; i < num_records; i++) {
    total += data[i];
  }

  return (double)total / num_records;
}

int main() {
  // Read data from a file
  int *data;
  int num_records;
  read_data("data.txt", &data, &num_records);

  // Find the mean of the data
  double mean = find_mean(data, num_records);

  // Print the mean
  printf("The mean of the data is: %.2f", mean);

  return 0;
}
//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  int numRows = 6;
  int numCols = 4;

  int *data = (int *) malloc(numRows * numCols * sizeof(int));

  // Fill data with random numbers
  for (int i = 0; i < numRows * numCols; i++) {
    *(data + i) = rand() % 100;
  }

  // Print all data
  printf("Data:\n");
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      printf("%d\t", *(data + row * numCols + col));
    }
    printf("\n");
  }

  // Find the maximum value
  int maxVal = *data;
  for (int i = 1; i < numRows * numCols; i++) {
    if (*(data + i) > maxVal) {
      maxVal = *(data + i);
    }
  }
  printf("Maximum Value: %d\n", maxVal);

  // Find the minimum value
  int minVal = *data;
  for (int i = 1; i < numRows * numCols; i++) {
    if (*(data + i) < minVal) {
      minVal = *(data + i);
    }
  }
  printf("Minimum Value: %d\n", minVal);

  // Find the average value
  int sum = 0;
  for (int i = 0; i < numRows * numCols; i++) {
    sum += *(data + i);
  }
  double avgVal = (double) sum / (numRows * numCols);
  printf("Average Value: %.2f\n", avgVal);

  // Find the standard deviation
  double ss = 0;
  for (int i = 0; i < numRows * numCols; i++) {
    ss += (*(data + i) - avgVal) * (*(data + i) - avgVal);
  }
  double stdev = sqrt(ss / (numRows * numCols));
  printf("Standard Deviation: %.2f\n", stdev);

  free(data);
  return 0;
}
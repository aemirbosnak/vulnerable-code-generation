//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Initialize variables
  int n, i, j, k;
  float mean, median, mode, variance, standard_deviation;

  // Get input from the user
  printf("Enter the number of data points: ");
  scanf("%d", &n);

  // Get the data points
  float data[n];
  printf("Enter the data points: ");
  for (i = 0; i < n; i++) {
    scanf("%f", &data[i]);
  }

  // Calculate the mean
  mean = 0;
  for (i = 0; i < n; i++) {
    mean += data[i];
  }
  mean /= n;

  // Calculate the median
  median = 0;
  if (n % 2 == 0) {
    median = (data[n / 2] + data[n / 2 - 1]) / 2;
  } else {
    median = data[n / 2];
  }

  // Calculate the mode
  mode = 0;
  int count = 0;
  for (i = 0; i < n; i++) {
    int temp_count = 0;
    for (j = 0; j < n; j++) {
      if (data[i] == data[j]) {
        temp_count++;
      }
    }
    if (temp_count > count) {
      count = temp_count;
      mode = data[i];
    }
  }

  // Calculate the variance
  variance = 0;
  for (i = 0; i < n; i++) {
    variance += pow((data[i] - mean), 2);
  }
  variance /= n;

  // Calculate the standard deviation
  standard_deviation = sqrt(variance);

  // Print the results
  printf("The mean is: %f\n", mean);
  printf("The median is: %f\n", median);
  printf("The mode is: %f\n", mode);
  printf("The variance is: %f\n", variance);
  printf("The standard deviation is: %f\n", standard_deviation);

  return 0;
}
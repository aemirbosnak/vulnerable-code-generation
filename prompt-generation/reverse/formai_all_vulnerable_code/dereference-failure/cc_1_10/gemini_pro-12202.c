//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calculate the mean of an array of doubles
double mean(double *data, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += data[i];
  }
  return sum / n;
}

// Calculate the standard deviation of an array of doubles
double stddev(double *data, int n) {
  double mean_value = mean(data, n);
  double sum_of_squares = 0;
  for (int i = 0; i < n; i++) {
    sum_of_squares += (data[i] - mean_value) * (data[i] - mean_value);
  }
  return sqrt(sum_of_squares / (n - 1));
}

// Calculate the kurtosis of an array of doubles
double kurtosis(double *data, int n) {
  double mean_value = mean(data, n);
  double stddev_value = stddev(data, n);
  double sum_of_fourth_powers = 0;
  for (int i = 0; i < n; i++) {
    sum_of_fourth_powers += pow((data[i] - mean_value) / stddev_value, 4);
  }
  return (sum_of_fourth_powers / (n - 1)) - 3;
}

// Calculate the skewness of an array of doubles
double skewness(double *data, int n) {
  double mean_value = mean(data, n);
  double stddev_value = stddev(data, n);
  double sum_of_third_powers = 0;
  for (int i = 0; i < n; i++) {
    sum_of_third_powers += pow((data[i] - mean_value) / stddev_value, 3);
  }
  return (sum_of_third_powers / (n - 1)) / pow(stddev_value, 3);
}

// Calculate the covariance of two arrays of doubles
double covariance(double *data1, double *data2, int n) {
  double mean1 = mean(data1, n);
  double mean2 = mean(data2, n);
  double sum_of_products = 0;
  for (int i = 0; i < n; i++) {
    sum_of_products += (data1[i] - mean1) * (data2[i] - mean2);
  }
  return sum_of_products / (n - 1);
}

// Calculate the correlation coefficient of two arrays of doubles
double correlation(double *data1, double *data2, int n) {
  double stddev1 = stddev(data1, n);
  double stddev2 = stddev(data2, n);
  return covariance(data1, data2, n) / (stddev1 * stddev2);
}

// Calculate the linear regression coefficients of two arrays of doubles
double *linear_regression(double *data1, double *data2, int n) {
  double mean1 = mean(data1, n);
  double mean2 = mean(data2, n);
  double sum_of_products = 0;
  double sum_of_squares1 = 0;
  for (int i = 0; i < n; i++) {
    sum_of_products += (data1[i] - mean1) * (data2[i] - mean2);
    sum_of_squares1 += pow((data1[i] - mean1), 2);
  }
  double slope = sum_of_products / sum_of_squares1;
  double intercept = mean2 - (slope * mean1);
  double *coefficients = malloc(2 * sizeof(double));
  coefficients[0] = slope;
  coefficients[1] = intercept;
  return coefficients;
}

int main() {
  // Generate some random data
  int n = 100;
  double *data1 = malloc(n * sizeof(double));
  double *data2 = malloc(n * sizeof(double));
  for (int i = 0; i < n; i++) {
    data1[i] = rand() / (double)RAND_MAX;
    data2[i] = rand() / (double)RAND_MAX;
  }

  // Calculate the statistical measures
  printf("Mean of data1: %f\n", mean(data1, n));
  printf("Standard deviation of data1: %f\n", stddev(data1, n));
  printf("Kurtosis of data1: %f\n", kurtosis(data1, n));
  printf("Skewness of data1: %f\n", skewness(data1, n));

  printf("Mean of data2: %f\n", mean(data2, n));
  printf("Standard deviation of data2: %f\n", stddev(data2, n));
  printf("Kurtosis of data2: %f\n", kurtosis(data2, n));
  printf("Skewness of data2: %f\n", skewness(data2, n));

  printf("Covariance of data1 and data2: %f\n", covariance(data1, data2, n));
  printf("Correlation coefficient of data1 and data2: %f\n", correlation(data1, data2, n));

  // Calculate the linear regression coefficients
  double *coefficients = linear_regression(data1, data2, n);
  printf("Slope of the linear regression line: %f\n", coefficients[0]);
  printf("Intercept of the linear regression line: %f\n", coefficients[1]);

  // Free the allocated memory
  free(data1);
  free(data2);
  free(coefficients);

  return 0;
}
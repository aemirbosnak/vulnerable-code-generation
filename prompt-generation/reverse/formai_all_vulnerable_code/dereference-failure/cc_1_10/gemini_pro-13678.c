//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000

// Function to generate random numbers
int *generate_random_numbers(int n) {
  int *numbers = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    numbers[i] = rand() % 1000000;
  }
  return numbers;
}

// Function to find the maximum number
int find_max_number(int *numbers, int n) {
  int max_number = -1;
  for (int i = 0; i < n; i++) {
    if (numbers[i] > max_number) {
      max_number = numbers[i];
    }
  }
  return max_number;
}

// Function to find the minimum number
int find_min_number(int *numbers, int n) {
  int min_number = 1000000;
  for (int i = 0; i < n; i++) {
    if (numbers[i] < min_number) {
      min_number = numbers[i];
    }
  }
  return min_number;
}

// Function to find the average number
double find_avg_number(int *numbers, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += numbers[i];
  }
  return sum / n;
}

// Function to find the standard deviation
double find_std_dev(int *numbers, int n) {
  double avg = find_avg_number(numbers, n);
  double sum_of_squares = 0;
  for (int i = 0; i < n; i++) {
    sum_of_squares += (numbers[i] - avg) * (numbers[i] - avg);
  }
  return sqrt(sum_of_squares / n);
}

// Main function
int main() {
  int n;
  printf("Enter the number of random numbers to generate: ");
  scanf("%d", &n);

  // Generate random numbers
  int *numbers = generate_random_numbers(n);

  // Find the maximum number
  int max_number = find_max_number(numbers, n);

  // Find the minimum number
  int min_number = find_min_number(numbers, n);

  // Find the average number
  double avg_number = find_avg_number(numbers, n);

  // Find the standard deviation
  double std_dev = find_std_dev(numbers, n);

  // Print the results
  printf("Maximum number: %d\n", max_number);
  printf("Minimum number: %d\n", min_number);
  printf("Average number: %f\n", avg_number);
  printf("Standard deviation: %f\n", std_dev);

  // Free the allocated memory
  free(numbers);

  return 0;
}
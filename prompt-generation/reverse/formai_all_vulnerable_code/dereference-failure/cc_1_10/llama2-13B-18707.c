//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_COEFFICIENTS 10
#define MIN_VALUE -100
#define MAX_VALUE 100

// Function to generate a random number between two values
int random_between(int min, int max) {
  return min + (rand() % (max - min + 1));
}

// Function to generate a random string of given length
char* random_string(int length) {
  char* str = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    str[i] = 'A' + random_between(0, 25);
  }
  str[length] = '\0';
  return str;
}

// Function to calculate the polynomial equation
void calculate_polynomial(float coefficients[MAX_COEFFICIENTS], int degree) {
  for (int i = 0; i < degree; i++) {
    float sum = 0;
    for (int j = 0; j < MAX_COEFFICIENTS; j++) {
      sum += coefficients[j] * pow(i, j);
    }
    coefficients[i] = sum;
  }
}

// Function to evaluate the polynomial equation
float evaluate_polynomial(float coefficients[MAX_COEFFICIENTS], int degree, float x) {
  float sum = 0;
  for (int i = 0; i < degree; i++) {
    sum += coefficients[i] * pow(x, i);
  }
  return sum;
}

int main() {
  int length;
  char* str = NULL;
  float coefficients[MAX_COEFFICIENTS];
  int degree;

  // Get the length of the polynomial from the user
  printf("Enter the length of the polynomial (min: 2, max: %d): ", MAX_COEFFICIENTS);
  scanf("%d", &length);

  // Generate a random string of the given length
  str = random_string(length);

  // Generate the coefficients of the polynomial randomly
  for (int i = 0; i < MAX_COEFFICIENTS; i++) {
    coefficients[i] = (float)random_between(MIN_VALUE, MAX_VALUE);
  }

  // Calculate the degree of the polynomial
  degree = length - 1;

  // Evaluate the polynomial at a random point
  float x = random_between(MIN_VALUE, MAX_VALUE);
  float result = evaluate_polynomial(coefficients, degree, x);

  // Print the result
  printf("The result of evaluating the polynomial at %f is %f\n", x, result);

  // Free the memory allocated for the string
  free(str);

  return 0;
}
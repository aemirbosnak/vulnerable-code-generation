//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <integer1> <integer2>\n", argv[0]);
    return 1;
  }

  int input1 = atoi(argv[1]);
  int input2 = atoi(argv[2]);

  if (input1 < 2 || input1 % 2 == 0) {
    printf("Error: Input1 must be a positive integer greater than 1\n");
    return 2;
  }

  if (input2 < 2 || input2 % 2 == 0) {
    printf("Error: Input2 must be a positive integer greater than 1\n");
    return 2;
  }

  if (input1 > input2) {
    printf("Error: Input1 must be less than or equal to Input2\n");
    return 2;
  }

  // Check if either input is a prime number
  if (isPrime(input1) == 0 || isPrime(input2) == 0) {
    printf("Error: One or both inputs are not prime numbers\n");
    return 2;
  }

  // Both inputs are prime, so print the result
  printf("The product of %d and %d is %d\n", input1, input2, input1 * input2);

  return 0;
}

// Function to check if an integer is prime
int isPrime(int n) {
  if (n < 2) {
    return 1; // Not prime (less than 2)
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0; // Not prime (divisible by i)
    }
  }

  return 1; // Prime (not divisible by any integer less than or equal to sqrt(n))
}
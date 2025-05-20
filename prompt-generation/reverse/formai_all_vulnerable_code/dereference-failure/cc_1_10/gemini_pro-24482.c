//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of primes to generate
#define NUM_PRIMES 100

// Define the maximum number to check for primality
#define MAX_NUM 1000000

// Function to check if a number is prime
int is_prime(int n) {
  if (n <= 1) {
    return 0;
  }
  if (n <= 3) {
    return 1;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return 0;
  }
  int i = 5;
  while (i * i <= n) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return 0;
    }
    i += 6;
  }
  return 1;
}

// Function to generate a list of prime numbers
int* generate_primes(int n) {
  int* primes = malloc(sizeof(int) * n);
  int count = 0;
  int num = 2;
  while (count < n) {
    if (is_prime(num)) {
      primes[count] = num;
      count++;
    }
    num++;
  }
  return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", primes[i]);
  }
}

int main() {
  // Generate a list of prime numbers
  int* primes = generate_primes(NUM_PRIMES);

  // Print the list of prime numbers
  print_primes(primes, NUM_PRIMES);

  // Free the memory allocated for the list of primes
  free(primes);

  return 0;
}
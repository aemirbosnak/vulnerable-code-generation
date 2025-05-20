//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
  // If n is 1, it is not prime
  if (n == 1) {
    return false;
  }

  // Iterate over all numbers from 2 to the square root of n
  for (int i = 2; i <= n / 2; i++) {
    // If n is divisible by any number from 2 to its square root, it is not prime
    if (n % i == 0) {
      return false;
    }
  }

  // If n is divisible by no number from 2 to its square root, it is prime
  return true;
}

// Function to generate a list of prime numbers up to a given limit
int* generate_primes(int limit) {
  // Allocate memory for the list of prime numbers
  int* primes = malloc(sizeof(int) * limit);

  // Initialize the list of prime numbers
  int num_primes = 0;
  primes[num_primes++] = 2;

  // Iterate over all numbers from 3 to the given limit
  for (int i = 3; i <= limit; i++) {
    // If the number is prime, add it to the list of prime numbers
    if (is_prime(i)) {
      primes[num_primes++] = i;
    }
  }

  // Return the list of prime numbers
  return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int num_primes) {
  // Print the list of prime numbers
  for (int i = 0; i < num_primes; i++) {
    printf("%d ", primes[i]);
  }

  // Print a newline
  printf("\n");
}

// Main function
int main() {
  // Generate a list of prime numbers up to 100
  int* primes = generate_primes(100);

  // Print the list of prime numbers
  print_primes(primes, 100);

  // Free the memory allocated for the list of prime numbers
  free(primes);

  return 0;
}
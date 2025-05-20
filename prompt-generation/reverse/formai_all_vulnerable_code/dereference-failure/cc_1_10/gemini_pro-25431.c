//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A simple sieve of Eratosthenes function
int* sieve_of_eratosthenes(int n) {
  // Create an array of boolean values, all set to true initially
  bool* is_prime = calloc(n + 1, sizeof(bool));
  for (int i = 0; i <= n; i++) {
    is_prime[i] = true;
  }

  // Iterate over all numbers from 2 to n
  for (int i = 2; i * i <= n; i++) {
    // If the number is prime, mark all multiples of it as non-prime
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }

  // Count the number of prime numbers
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      count++;
    }
  }

  // Create an array of prime numbers and populate it
  int* primes = malloc(count * sizeof(int));
  int index = 0;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes[index++] = i;
    }
  }

  // Free the boolean array
  free(is_prime);

  // Return the array of prime numbers
  return primes;
}

int main() {
  // Get the input from the user
  int n;
  printf("Enter the value of n: ");
  scanf("%d", &n);

  // Generate the prime numbers using the sieve of Eratosthenes function
  int* primes = sieve_of_eratosthenes(n);

  // Print the prime numbers
  printf("The prime numbers up to %d are:\n", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", primes[i]);
  }

  // Free the array of prime numbers
  free(primes);

  return 0;
}
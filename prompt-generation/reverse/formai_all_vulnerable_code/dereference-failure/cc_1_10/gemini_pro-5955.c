//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Sieve of Eratosthenes
void sieve(int n, int *primes) {
  // Initialize all values to true (1)
  for (int i = 0; i < n; i++) {
    primes[i] = 1;
  }

  // Mark non-prime numbers
  for (int i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = 0;
      }
    }
  }
}

// Print prime numbers
void print_primes(int n, int *primes) {
  printf("Prime numbers up to %d:\n", n);
  for (int i = 2; i <= n; i++) {
    if (primes[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

int main() {
  // Get the upper limit from the user
  int n;
  printf("Enter the upper limit: ");
  scanf("%d", &n);

  // Create an array to store prime numbers
  int *primes = (int *)malloc(sizeof(int) * (n + 1));

  // Generate prime numbers using the Sieve of Eratosthenes
  sieve(n, primes);

  // Print the prime numbers
  print_primes(n, primes);

  // Free the allocated memory
  free(primes);

  return 0;
}
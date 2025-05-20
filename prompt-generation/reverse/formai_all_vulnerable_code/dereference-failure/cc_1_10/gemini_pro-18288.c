//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(const long long int num) {
  if (num <= 1) {
    return false;
  }
  if (num <= 3) {
    return true;
  }
  if (num % 2 == 0 || num % 3 == 0) {
    return false;
  }
  long long int i = 5;
  while (i * i <= num) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
    i += 6;
  }
  return true;
}

// Function to generate prime numbers
long long int* generate_primes(const long long int num) {
  long long int* primes = malloc(num * sizeof(long long int));
  long long int count = 0;
  long long int i = 2;
  while (count < num) {
    if (is_prime(i)) {
      primes[count] = i;
      count++;
    }
    i++;
  }
  return primes;
}

// Function to print an array of prime numbers
void print_primes(const long long int* primes, const long long int num) {
  for (long long int i = 0; i < num; i++) {
    printf("%lld ", primes[i]);
  }
  printf("\n");
}

int main() {
  // Get the number of prime numbers to generate
  long long int num;
  printf("Enter the number of prime numbers to generate: ");
  scanf("%lld", &num);

  // Generate prime numbers
  long long int* primes = generate_primes(num);

  // Print prime numbers
  print_primes(primes, num);

  // Free allocated memory
  free(primes);

  return 0;
}
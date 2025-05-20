//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if a number is prime
bool is_prime(int num) {
  if (num <= 1) {
    return false;
  }
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
  srand(time(NULL));
  return min + rand() % (max - min + 1);
}

// Function to generate a list of prime numbers
int main() {
  // Get the number of prime numbers to generate
  printf("How many prime numbers would you like to generate? ");
  int num_primes;
  scanf("%d", &num_primes);

  // Generate the list of prime numbers
  int *prime_numbers = malloc(sizeof(int) * num_primes);
  int prime_count = 0;
  int num = 2;
  while (prime_count < num_primes) {
    if (is_prime(num)) {
      prime_numbers[prime_count++] = num;
    }
    num++;
  }

  // Print the list of prime numbers
  printf("The first %d prime numbers are:\n", num_primes);
  for (int i = 0; i < num_primes; i++) {
    printf("%d ", prime_numbers[i]);
  }
  printf("\n");

  // Free the memory allocated for the list of prime numbers
  free(prime_numbers);

  return 0;
}
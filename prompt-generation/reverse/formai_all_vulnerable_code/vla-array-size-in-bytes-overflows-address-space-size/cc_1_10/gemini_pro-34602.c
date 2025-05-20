//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
  // Greet the user in a curious style
  printf("Greetings, curious reader!\n");
  printf("Prepare to witness the magical unveiling of prime numbers.\n");
  printf("Enter the number of prime numbers you wish to generate: ");

  // Read the user's input
  int n;
  scanf("%d", &n);

  // Initialize an array to store the prime numbers
  int primes[n];

  // Embark on the quest to find the prime numbers
  int count = 0;
  int candidate = 2;
  while (count < n) {
    // Assume the current candidate is prime
    bool is_prime = true;

    // Check for divisibility by all numbers up to the square root of the candidate
    for (int i = 2; i <= sqrt(candidate); i++) {
      if (candidate % i == 0) {
        // The candidate is not prime, as it is divisible by another number
        is_prime = false;
        break;
      }
    }

    // If the candidate passed the divisibility test, add it to the array and increment the count
    if (is_prime) {
      primes[count++] = candidate;
    }

    // Increment the candidate to continue the search
    candidate++;
  }

  // Display the prime numbers to the user
  printf("Behold, the prime numbers you sought:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");

  // Bid farewell to the user
  printf("May these prime numbers ignite your curiosity and inspire your imagination.\n");
  printf("Farewell, dear adventurer, until our paths cross again!\n");

  return 0;
}
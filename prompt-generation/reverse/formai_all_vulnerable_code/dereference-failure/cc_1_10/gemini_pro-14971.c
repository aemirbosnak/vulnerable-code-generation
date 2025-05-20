//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_primes(int limit) {
  int i, j, count = 1, is_prime;
  int *primes = (int *) malloc(limit * sizeof(int));

  primes[0] = 2;

  for (i = 3; i <= limit; i += 2) {
    is_prime = 1;
    for (j = 3; j <= sqrt(i); j += 2) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }

    if (is_prime == 1) {
      primes[count] = i;
      count++;
    }
  }

  return count;
}

int main() {
  int limit, num_primes;
  int *primes;

  printf("Hey there! Welcome to the Prime Number Generator Extravaganza!\n");
  printf("Gimme a number, my friend, and I'll generate all the prime numbers up to it.\n");
  printf("Type in your number: ");
  scanf("%d", &limit);

  num_primes = calculate_primes(limit);

  printf("Ta-da! Here are the prime numbers up to %d:\n", limit);
  for (int i = 0; i < num_primes; i++) {
    if (i % 10 == 0) {
      printf("\n");
    }
    printf("%d ", primes[i]);
  }

  printf("\n\nWow, that was fun! Thanks for playing with me.\n");
  printf("Remember, math is awesome, and prime numbers are the coolest!\n");

  return 0;
}
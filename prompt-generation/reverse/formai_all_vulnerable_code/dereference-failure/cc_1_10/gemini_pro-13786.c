//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A rosy hue for our numbers
#define COLOR_PRIME "\033[1;35m"

// A heart-shaped array to store our affections (prime numbers)
int heart[10000];

// Our beloved function to find the true loves of the number world
void find_primes(int n) {
  int i, j, is_prime;

  // Initialize our heart with zeros, like a blank canvas for our love story
  memset(heart, 0, sizeof(heart));

  // For each number in our quest for true love, from 2 to n
  for (i = 2; i <= n; i++) {
    is_prime = 1;  // Every number starts with the hope of being prime

    // Check if it's divisible by any of its predecessors
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        is_prime = 0;  // Alas, it's not meant to be
        break;
      }
    }

    // If it's still prime, let's add it to our heart
    if (is_prime) {
      heart[i] = 1;
    }
  }
}

// A poetic display of our prime numbers, like stars in the night sky
void show_heart(int n) {
  int i;

  // For each number in our heart
  for (i = 2; i <= n; i++) {
    // If it's prime, let's paint it in a rosy hue
    if (heart[i]) {
      printf(COLOR_PRIME "%d ", i);
    }
  }
}

int main(int argc, char **argv) {
  int n;

  // If the user has provided a number, let's use it as our limit
  if (argc > 1) {
    n = atoi(argv[1]);
  } else {
    // Otherwise, let's limit our search to 1000, a nice round number
    n = 1000;
  }

  // Let's find the prime numbers within our limit
  find_primes(n);

  // And finally, let's display our heart of prime numbers
  printf("Behold, my beloved primes from 1 to %d:\n", n);
  show_heart(n);
  puts("\n");

  return 0;
}
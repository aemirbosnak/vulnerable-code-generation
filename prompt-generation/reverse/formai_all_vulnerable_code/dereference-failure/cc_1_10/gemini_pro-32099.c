//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i <= num / 2; ++i) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to generate a list of prime numbers
int* generatePrimes(int n) {
  int* primes = (int*)malloc(sizeof(int) * n);
  int count = 0;
  int num = 2;
  while (count < n) {
    if (isPrime(num)) {
      primes[count] = num;
      count++;
    }
    num++;
  }
  return primes;
}

// Function to print a list of numbers
void printList(int* list, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", list[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the number of prime numbers to generate: ");
  scanf("%d", &n);

  int* primes = generatePrimes(n);

  printf("The first %d prime numbers are: ", n);
  printList(primes, n);

  free(primes);

  return 0;
}
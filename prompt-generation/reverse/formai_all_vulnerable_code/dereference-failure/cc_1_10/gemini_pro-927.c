//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
  srand(time(NULL));
  return (rand() % (max - min + 1)) + min;
}

// Function to generate a list of prime numbers
int* generatePrimeNumbers(int count) {
  int* primeNumbers = (int*)malloc(sizeof(int) * count);
  int primeCount = 0;
  int number = generateRandomNumber(2, 1000);
  while (primeCount < count) {
    if (isPrime(number)) {
      primeNumbers[primeCount++] = number;
    }
    number++;
  }
  return primeNumbers;
}

// Function to print a list of prime numbers
void printPrimeNumbers(int* primeNumbers, int count) {
  for (int i = 0; i < count; ++i) {
    printf("%d ", primeNumbers[i]);
  }
  printf("\n");
}

int main() {
  // Get the number of prime numbers to generate
  int count;
  printf("How many prime numbers do you want to generate? ");
  scanf("%d", &count);

  // Generate a list of prime numbers
  int* primeNumbers = generatePrimeNumbers(count);

  // Print the list of prime numbers
  printf("The first %d prime numbers are: ", count);
  printPrimeNumbers(primeNumbers, count);

  // Free the memory allocated for the list of prime numbers
  free(primeNumbers);

  return 0;
}
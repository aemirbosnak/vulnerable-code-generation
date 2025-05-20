//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare the isPrime function that checks if a number is prime
bool isPrime(int num);

int main() {
  // Welcome the user to the immersive prime number generator
  printf("Welcome to the Immersive Prime Number Generator!\n");
  printf("This program will generate a list of prime numbers for you to explore.\n");

  // Get the user's input on how many prime numbers they want to generate
  int numPrimes;
  printf("How many prime numbers would you like to generate? ");
  scanf("%d", &numPrimes);

  // Check if the user entered a valid number
  if (numPrimes <= 0) {
    printf("Invalid input. Please enter a positive number.\n");
    return 1;
  }

  // Initialize the list of prime numbers
  int *primeNumbers = malloc(sizeof(int) * numPrimes);

  // Generate the prime numbers using the isPrime function
  int count = 0;
  int currentNumber = 2;
  while (count < numPrimes) {
    if (isPrime(currentNumber)) {
      primeNumbers[count] = currentNumber;
      count++;
    }
    currentNumber++;
  }

  // Print the list of prime numbers
  printf("Here are the prime numbers you requested:\n");
  for (int i = 0; i < numPrimes; i++) {
    printf("%d ", primeNumbers[i]);
  }
  printf("\n");

  // Free the memory allocated for the list of prime numbers
  free(primeNumbers);

  return 0;
}

// The isPrime function checks if a number is prime
bool isPrime(int num) {
  if (num <= 1) {
    return false;
  } else if (num <= 3) {
    return true;
  } else if (num % 2 == 0 || num % 3 == 0) {
    return false;
  } else {
    int i = 5;
    while (i * i <= num) {
      if (num % i == 0 || num % (i + 2) == 0) {
        return false;
      }
      i += 6;
    }
    return true;
  }
}
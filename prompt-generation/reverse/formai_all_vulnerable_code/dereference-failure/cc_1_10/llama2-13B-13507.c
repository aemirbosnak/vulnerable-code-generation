//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LEN 1024
#define MAX_ERROR_LEN 256

// Define some error messages with a bit of humor
#define ERR_INVALID_INPUT "Invalid input? Oh no, that's like a unicorn with a cold! 🐴🤧"
#define ERR_DIVISION_BY_ZERO " division by zero? Well, at least you're not dividing by nothing! 😜"
#define ERR_NULL_POINTER "Null pointer? That's like a chicken with no head! 🐔😳"

// Function to check if a string is empty
int is_empty(char *str) {
  return strlen(str) == 0;
}

// Function to check if a number is negative
int is_negative(int num) {
  return num < 0;
}

// Function to check if a number is even
int is_even(int num) {
  return num % 2 == 0;
}

// Function to check if a number is prime
int is_prime(int num) {
  if (num <= 1) return 0; // 0 and 1 are not prime
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return 0; // not prime
  }
  return 1; // prime
}

// Function to calculate the factorial of a number
int factorial(int num) {
  if (num == 0) return 1; // base case
  else if (is_negative(num)) {
    printf("Error: negative numbers are not allowed! 😡");
    return -1;
  } else if (is_even(num)) {
    return num * factorial(num - 2); // even numbers are easy
  } else {
    return num * factorial(num - 1); // odd numbers are a bit harder
  }
}

int main() {
  // Ask the user for a number
  printf("Enter a number: ");
  int num;
  scanf("%d", &num);

  // Check if the input is valid
  if (is_empty(num)) {
    printf("Error: no number was entered! 😔");
    return 1;
  }

  // Calculate the factorial and print the result
  int result = factorial(num);
  if (result == -1) {
    printf("Error: %s 😠", ERR_INVALID_INPUT);
  } else {
    printf("The factorial of %d is %d 🎉\n", num, result);
  }

  return 0;
}
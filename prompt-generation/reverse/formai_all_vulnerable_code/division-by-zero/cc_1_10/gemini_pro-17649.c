//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of digits in a number
#define MAX_DIGITS 100

// Define the base of the number system
#define BASE 10

// Function to convert a number from base 10 to any other base
int convert_to_base(int number, int base) {
  int converted_number = 0;
  int power = 1;

  while (number > 0) {
    // Get the last digit of the number
    int digit = number % base;

    // Add the digit to the converted number
    converted_number += digit * power;

    // Increment the power by the base
    power *= base;

    // Remove the last digit from the number
    number /= base;
  }

  return converted_number;
}

// Function to print a number in any base
void print_in_base(int number, int base) {
  // If the number is 0, print 0
  if (number == 0) {
    printf("0");
    return;
  }

  // Create a stack to store the digits of the number
  int stack[MAX_DIGITS];
  int top = -1;

  // Convert the number to the given base
  while (number > 0) {
    // Get the last digit of the number
    int digit = number % base;

    // Push the digit onto the stack
    stack[++top] = digit;

    // Remove the last digit from the number
    number /= base;
  }

  // Print the digits of the number from the stack
  while (top >= 0) {
    printf("%d", stack[top--]);
  }
}

int main() {
  // Get the number from the user
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  // Get the base from the user
  int base;
  printf("Enter the base: ");
  scanf("%d", &base);

  // Convert the number to the given base
  int converted_number = convert_to_base(number, base);

  // Print the converted number
  printf("The converted number is: ");
  print_in_base(converted_number, base);
  printf("\n");

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the sum of the digits of a number
int sumOfDigits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n % 10 + sumOfDigits(n / 10);
  }
}

// Function to reverse a string
char *reverseString(char *str) {
  if (*str == '\0') {
    return str;
  } else {
    char *rest = reverseString(str + 1);
    *str = rest[0];
    rest[0] = '\0';
    return str;
  }
}

// Function to check if a number is prime
int isPrime(int n) {
  if (n <= 1) {
    return 0;
  } else {
    for (int i = 2; i <= n / 2; i++) {
      if (n % i == 0) {
        return 0;
      }
    }
    return 1;
  }
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Function to find the least common multiple of two numbers
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

// Function to find the sum of the first n natural numbers
int sumOfNaturals(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n + sumOfNaturals(n - 1);
  }
}

// Function to find the average of the first n natural numbers
float averageOfNaturals(int n) {
  return (float)sumOfNaturals(n) / n;
}

int main() {
  // Print the first 10 Fibonacci numbers
  printf("The first 10 Fibonacci numbers are: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", fibonacci(i));
  }
  printf("\n");

  // Print the factorial of 10
  printf("The factorial of 10 is: %d\n", factorial(10));

  // Print the sum of the digits of 12345
  printf("The sum of the digits of 12345 is: %d\n", sumOfDigits(12345));

  // Print the reverse of the string "hello"
  printf("The reverse of the string \"hello\" is: %s\n", reverseString("hello"));

  // Check if 17 is prime
  printf("Is 17 prime? %d\n", isPrime(17));

  // Find the greatest common divisor of 12 and 18
  printf("The greatest common divisor of 12 and 18 is: %d\n", gcd(12, 18));

  // Find the least common multiple of 12 and 18
  printf("The least common multiple of 12 and 18 is: %d\n", lcm(12, 18));

  // Find the sum of the first 10 natural numbers
  printf("The sum of the first 10 natural numbers is: %d\n", sumOfNaturals(10));

  // Find the average of the first 10 natural numbers
  printf("The average of the first 10 natural numbers is: %.2f\n", averageOfNaturals(10));

  return 0;
}
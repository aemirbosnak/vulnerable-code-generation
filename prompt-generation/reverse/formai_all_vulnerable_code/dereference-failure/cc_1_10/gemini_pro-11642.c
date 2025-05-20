//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number using recursion
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the sum of the digits of a number using recursion
int sumOfDigits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n % 10) + sumOfDigits(n / 10);
  }
}

// Function to check if a number is a palindrome using recursion
int isPalindrome(int n) {
  if (n < 0) {
    return 0;
  } else if (n < 10) {
    return 1;
  } else {
    int firstDigit = n / 10;
    int lastDigit = n % 10;
    if (firstDigit == lastDigit) {
      return isPalindrome(n / 100);
    } else {
      return 0;
    }
  }
}

// Function to calculate the length of a string using recursion
int strlen(char *str) {
  if (*str == '\0') {
    return 0;
  } else {
    return 1 + strlen(str + 1);
  }
}

// Function to reverse a string using recursion
char *reverseString(char *str) {
  if (*str == '\0') {
    return str;
  } else {
    char *rest = reverseString(str + 1);
    *str = rest[0];
    rest[0] = *str;
    return rest;
  }
}

// Function to calculate the number of set bits in a binary number using recursion
int countSetBits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n & 1) + countSetBits(n >> 1);
  }
}

// Function to calculate the greatest common divisor (GCD) of two numbers using recursion
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Function to calculate the sum of two numbers using recursion
int sum(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return sum(a + 1, b - 1);
  }
}

// Main function
int main() {
  // Calculate the factorial of a number
  int n = 5;
  int factorialResult = factorial(n);
  printf("The factorial of %d is %d\n", n, factorialResult);

  // Calculate the sum of the digits of a number
  n = 1234;
  int sumOfDigitsResult = sumOfDigits(n);
  printf("The sum of the digits of %d is %d\n", n, sumOfDigitsResult);

  // Check if a number is a palindrome
  n = 121;
  int isPalindromeResult = isPalindrome(n);
  printf("Is %d a palindrome? %s\n", n, isPalindromeResult ? "Yes" : "No");

  // Calculate the length of a string
  char *str = "Hello";
  int strlenResult = strlen(str);
  printf("The length of the string \"%s\" is %d\n", str, strlenResult);

  // Reverse a string
  str = "Hello";
  char *reverseStringResult = reverseString(str);
  printf("The reversed string is \"%s\"\n", reverseStringResult);

  // Calculate the number of set bits in a binary number
  n = 11;
  int countSetBitsResult = countSetBits(n);
  printf("The number of set bits in %d is %d\n", n, countSetBitsResult);

  // Calculate the GCD of two numbers
  int a = 12, b = 18;
  int gcdResult = gcd(a, b);
  printf("The GCD of %d and %d is %d\n", a, b, gcdResult);

  // Calculate the sum of two numbers using recursion
  a = 5, b = 7;
  int sumResult = sum(a, b);
  printf("The sum of %d and %d is %d\n", a, b, sumResult);

  return 0;
}
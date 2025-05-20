//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate the factorial of a non-negative integer
int factorial(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Recursive function to calculate the greatest common divisor of two non-negative integers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Recursive function to calculate the binary representation of a non-negative integer
char *binary(int n) {
  if (n == 0) {
    return "0";
  } else if (n == 1) {
    return "1";
  } else {
    char *result = binary(n / 2);
    char *temp = malloc(strlen(result) + 2);
    sprintf(temp, "%s%d", result, n % 2);
    free(result);
    return temp;
  }
}

// Recursive function to calculate the sum of the digits of a non-negative integer
int sum_digits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return n % 10 + sum_digits(n / 10);
  }
}

// Recursive function to calculate the product of the digits of a non-negative integer
int product_digits(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n % 10 * product_digits(n / 10);
  }
}

// Recursive function to calculate the number of bits set to 1 in the binary representation of a non-negative integer
int count_bits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n & 1) + count_bits(n >> 1);
  }
}

// Recursive function to reverse the bits in the binary representation of a non-negative integer
int reverse_bits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n & 1) << 31 | reverse_bits(n >> 1);
  }
}

// Recursive function to calculate the hamming weight of a non-negative integer
int hamming_weight(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n & 1) + hamming_weight(n >> 1);
  }
}

// Recursive function to calculate the parity of a non-negative integer
int parity(int n) {
  if (n == 0) {
    return 0;
  } else {
    return (n & 1) ^ parity(n >> 1);
  }
}

// Recursive function to calculate the number of trailing zeros in the binary representation of a non-negative integer
int trailing_zeros(int n) {
  if (n == 0) {
    return 0;
  } else if (n % 2 == 0) {
    return 1 + trailing_zeros(n >> 1);
  } else {
    return trailing_zeros(n >> 1);
  }
}

int main() {
  int n = 10;
  printf("Factorial of %d: %d\n", n, factorial(n));
  printf("GCD of 12 and 18: %d\n", gcd(12, 18));
  printf("Binary representation of %d: %s\n", n, binary(n));
  printf("Sum of digits of %d: %d\n", n, sum_digits(n));
  printf("Product of digits of %d: %d\n", n, product_digits(n));
  printf("Number of bits set to 1 in the binary representation of %d: %d\n", n, count_bits(n));
  printf("Reversed bits of %d: %d\n", n, reverse_bits(n));
  printf("Hamming weight of %d: %d\n", n, hamming_weight(n));
  printf("Parity of %d: %d\n", n, parity(n));
  printf("Number of trailing zeros in the binary representation of %d: %d\n", n, trailing_zeros(n));
  return 0;
}
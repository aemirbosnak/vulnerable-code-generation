//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: dynamic
#include <stdio.h>

int main() {
  // Initialize variables
  int a = 5, b = 3, c = 0;

  // Perform bitwise operations
  c = a & b;  // Bitwise AND
  printf("a & b = %d\n", c);
  c = a | b;  // Bitwise OR
  printf("a | b = %d\n", c);
  c = a ^ b;  // Bitwise XOR
  printf("a ^ b = %d\n", c);
  c = ~a;     // Bitwise NOT
  printf("~a = %d\n", c);
  c = a << 2;  // Bitwise left shift
  printf("a << 2 = %d\n", c);
  c = a >> 1;  // Bitwise right shift
  printf("a >> 1 = %d\n", c);

  // Dynamically create a variable using a pointer
  int *p = NULL;
  p = malloc(sizeof(int));
  *p = 20;

  // Perform bitwise operations on the dynamically created variable
  c = *p & a;
  printf("*p & a = %d\n", c);
  c = *p | b;
  printf("*p | b = %d\n", c);
  c = *p ^ a;
  printf("*p ^ a = %d\n", c);
  c = ~*p;
  printf("~*p = %d\n", c);
  c = *p << 2;
  printf("*p << 2 = %d\n", c);
  c = *p >> 1;
  printf("*p >> 1 = %d\n", c);

  // Free the dynamically allocated memory
  free(p);

  // Use bitwise operations to check the parity of a number
  int n = 15;
  if (n & 1) {
    printf("n is odd\n");
  } else {
    printf("n is even\n");
  }

  // Use bitwise operations to swap two numbers without using a temporary variable
  a = 10;
  b = 15;
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  printf("a = %d, b = %d\n", a, b);

  // Use bitwise operations to find the maximum and minimum of two numbers
  a = 12;
  b = 18;
  c = a | b;
  printf("Maximum of a and b: %d\n", c);
  c = a & b;
  printf("Minimum of a and b: %d\n", c);

  return 0;
}
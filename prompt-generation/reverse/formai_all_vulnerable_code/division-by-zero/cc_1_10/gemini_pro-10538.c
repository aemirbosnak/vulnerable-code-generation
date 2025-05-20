//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Prototypes
int fib(int n);
int fact(int n);
int pow(int x, int y);
int gcd(int a, int b);
int lcm(int a, int b);

// Main Function
int main() {
  // Set the stage with a captivating introduction
  printf("\n🌌 Welcome to the Recursive Odyssey, where code transcends time and space. 🌌\n");

  // Embark on a Fibonacci adventure
  printf("\n🚀 Fibonacci Sequence: A Journey into the Unknown\n");
  printf("Enter a number, intrepid traveler: ");
  int n;
  scanf(" %d", &n);
  printf("Prepare to witness the magic of recursion: %d\n", fib(n));

  // Ascend to the heights of factorial
  printf("\n🌠 Factorial Frenzy: The Sky's the Limit\n");
  printf("Enter a number, celestial explorer: ");
  int f;
  scanf(" %d", &f);
  printf("Behold the wonders of recursion: %d\n", fact(f));

  // Conquer the realm of exponentiation
  printf("\n⚡️ Power Play: Conquering the Exponents\n");
  printf("Enter a base and an exponent, mighty warrior: ");
  int x, y;
  scanf(" %d %d", &x, &y);
  printf("Witness the triumph of recursion: %d\n", pow(x, y));

  // Forge the greatest common divisor
  printf("\n🤝 Greatest Common Divisor: Uniting the Fractions\n");
  printf("Enter two numbers, enigmatic sage: ");
  int a, b;
  scanf(" %d %d", &a, &b);
  printf("Behold the power of recursion: %d\n", gcd(a, b));

  // Discover the least common multiple
  printf("\n🌐 Least Common Multiple: Transcending Differences\n");
  printf("Enter two numbers, cosmic scribe: ");
  scanf(" %d %d", &a, &b);
  printf("Witness the wonders of recursion: %d\n", lcm(a, b));

  // End with a message from the stars
  printf("\n🌟 Farewell, traveler. May the stars guide your recursive adventures. 🌟\n");

  return 0;
}

// Recursive Fibonacci function
int fib(int n) {
  if (n <= 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

// Recursive factorial function
int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return n * fact(n - 1);
}

// Recursive power function
int pow(int x, int y) {
  if (y == 0) {
    return 1;
  }
  return x * pow(x, y - 1);
}

// Recursive greatest common divisor function
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// Recursive least common multiple function
int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}
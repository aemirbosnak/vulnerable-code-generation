//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main() {
  // Declare variables
  int a = 10;
  int b = 20;
  int c;

  // Perform arithmetic operations
  c = a + b;
  printf("The sum of %d and %d is %d\n", a, b, c);

  c = a - b;
  printf("The difference of %d and %d is %d\n", a, b, c);

  c = a * b;
  printf("The product of %d and %d is %d\n", a, b, c);

  c = a / b;
  printf("The quotient of %d and %d is %d\n", a, b, c);

  c = a % b;
  printf("The remainder of %d divided by %d is %d\n", a, b, c);

  // Perform unary operations
  c++;
  printf("The value of c after increment is %d\n", c);

  c--;
  printf("The value of c after decrement is %d\n", c);

  c = -c;
  printf("The value of c after negation is %d\n", c);

  c = !c;
  printf("The value of c after logical not is %d\n", c);

  // Perform bitwise operations
  c = a & b;
  printf("The bitwise AND of %d and %d is %d\n", a, b, c);

  c = a | b;
  printf("The bitwise OR of %d and %d is %d\n", a, b, c);

  c = a ^ b;
  printf("The bitwise XOR of %d and %d is %d\n", a, b, c);

  c = ~a;
  printf("The bitwise NOT of %d is %d\n", a, c);

  // Perform relational operations
  bool d = (a == b);
  printf("Is %d equal to %d? %s\n", a, b, d ? "Yes" : "No");

  d = (a != b);
  printf("Is %d not equal to %d? %s\n", a, b, d ? "Yes" : "No");

  d = (a > b);
  printf("Is %d greater than %d? %s\n", a, b, d ? "Yes" : "No");

  d = (a >= b);
  printf("Is %d greater than or equal to %d? %s\n", a, b, d ? "Yes" : "No");

  d = (a < b);
  printf("Is %d less than %d? %s\n", a, b, d ? "Yes" : "No");

  d = (a <= b);
  printf("Is %d less than or equal to %d? %s\n", a, b, d ? "Yes" : "No");

  // Perform conditional operations
  c = (a > b) ? a : b;
  printf("The greater of %d and %d is %d\n", a, b, c);

  // Perform assignment operations
  c += a;
  printf("The value of c after += is %d\n", c);

  c -= a;
  printf("The value of c after -= is %d\n", c);

  c *= a;
  printf("The value of c after *= is %d\n", c);

  c /= a;
  printf("The value of c after /= is %d\n", c);

  c %= a;
  printf("The value of c after %= is %d\n", c);

  // Perform pointer operations
  int *p = &a;
  printf("The value of *p is %d\n", *p);

  *p = 15;
  printf("The value of a after *p = 15 is %d\n", a);

  p++;
  printf("The value of *p after p++ is %d\n", *p);

  // Perform array operations
  int arr[5] = {1, 2, 3, 4, 5};
  printf("The first element of the array is %d\n", arr[0]);
  printf("The last element of the array is %d\n", arr[4]);

  // Perform structure operations
  struct person {
    char name[20];
    int age;
  };

  struct person p1 = {"John Doe", 30};
  printf("The name of the person is %s\n", p1.name);
  printf("The age of the person is %d\n", p1.age);

  // Perform union operations
  union u {
    int i;
    float f;
  };

  union u v;
  v.i = 10;
  printf("The value of v.i is %d\n", v.i);
  printf("The value of v.f is %f\n", v.f);

  // Perform type casting operations
  int x = (int)1.5;
  printf("The value of x after type casting is %d\n", x);

  // Perform I/O operations
  printf("Enter a number: ");
  scanf("%d", &c);
  printf("You entered the number %d\n", c);

  return 0;
}
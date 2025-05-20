//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {
  printf("Hello there! Let's energize some arithmetic, shall we?\n");
  int x, y, sum, difference, product, quotient, remainder;
  
  printf("Enter two numbers to calculate\n");
  scanf("%d%d", &x, &y);
  
  sum = x + y;
  difference = x - y;
  product = x * y;
  quotient = x / y;
  remainder = x % y;
  
  printf("The sum of %d and %d is %d\n", x, y, sum);
  printf("The difference between %d and %d is %d\n", x, y, difference);
  printf("The product of %d and %d is %d\n", x, y, product);
  printf("The quotient of %d divided by %d is %d with a remainder of %d\n", x, y, quotient, remainder);
  
  printf("Now let's make things more interesting by using the power operator!\n");
  int base, exponent, result = 1;
  
  printf("Enter a base number: ");
  scanf("%d", &base);
  
  printf("Enter an exponent: ");
  scanf("%d", &exponent);
  
  for(int i = 0; i < exponent; i++) {
    result *= base;
  }
  
  printf("%d to the power of %d is %d\n", base, exponent, result);
  
  printf("Well that was fun! Let's do some modulus arithmetic now.\n");
  int num = 0;
  
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  
  if(num % 2 == 0) {
    printf("%d is an even number\n", num);
  } else {
    printf("%d is an odd number\n", num);
  }
  
  if(num % 3 == 0) {
    printf("%d is divisible by 3\n", num);
  } else {
    printf("%d is not divisible by 3\n", num);
  }
  
  printf("Thanks for energizing some arithmetic with me! Have a great day!\n");
  
  return 0;
}
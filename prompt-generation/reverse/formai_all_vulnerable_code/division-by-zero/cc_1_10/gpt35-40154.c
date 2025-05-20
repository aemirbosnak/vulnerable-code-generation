//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {
  printf("Hi! Let's do some energetic arithmetic!\n\n");

  int num1, num2;
  printf("Enter two positive integers, separated by a space: ");
  scanf("%d %d", &num1, &num2);
  
  int sum = num1 + num2;
  printf("\n%d + %d = %d\n", num1, num2, sum);

  int difference = num1 - num2;
  if (difference >= 0) {
    printf("%d - %d = %d\n", num1, num2, difference);
  } else {
    printf("%d - %d = %d (Negative woooooow!)\n", num1, num2, difference);
  }

  int product = num1 * num2;
  printf("%d x %d = %d\n", num1, num2, product);

  int quotient = num1 / num2;
  int remainder = num1 % num2;
  printf("%d divided by %d is %d with a remainder of %d\n", num1, num2, quotient, remainder);

  printf("\nHop ditty hop, let's do some more arithmetic!\n\n");

  printf("Enter two more positive integers, separated by a space: ");
  scanf("%d %d", &num1, &num2);

  int power = 1;
  for (int i = 0; i < num2; i++) {
    power *= num1;
  }
  printf("\n%d to the power of %d = %d\n", num1, num2, power);

  if (num1 > 0) {
    int remainder = 0;
    int reverse = 0;
    int originalNum = num1;

    while (num1 > 0) {
      remainder = num1 % 10;
      reverse = reverse * 10 + remainder;
      num1 /= 10;
    }
    printf("The reverse of %d is %d\n", originalNum, reverse);
  } else {
    printf("Sorry, we can't reverse a negative number! Let's dance instead!\n");
  }

  printf("\nWhoopee! That was some crazy arithmetic! Goodbye!\n");

  return 0;
}
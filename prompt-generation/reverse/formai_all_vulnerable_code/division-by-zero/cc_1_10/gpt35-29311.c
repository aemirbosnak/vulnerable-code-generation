//FormAI DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>

int main() {
  printf("Welcome to the Mind-Bending Arithmetic program!\n");
  printf("Please enter a number:\n");
  int num1;
  scanf("%d", &num1);
  printf("Please enter another number:\n");
  int num2;
  scanf("%d", &num2);
  
  // Adding numbers in a unique way
  int sum = 0;
  for (int i = 1; i <= num1; i++) {
    for (int j = 1; j <= num2; j++) {
      sum++;
    }
  }
  printf("%d + %d = %d\n", num1, num2, sum);

  // Subtracting numbers in a mind-bending way
  int difference = 0;
  for (int i = 1; i <= num1; i++) {
    for (int j = 1; j <= num2; j++) {
      difference--;
    }
  }
  printf("%d - %d = %d\n", num1, num2, difference);

  // Multiplying numbers in an eccentric manner
  int product = 1;
  for (int i = 1; i <= num1; i++) {
    product *= num2;
  }
  printf("%d * %d = %d\n", num1, num2, product);

  // Dividing numbers with a twist
  float quotient = num1 / num2;
  printf("%d / %d = %.2f\n", num1, num2, quotient);

  // Finding the remainder in a surreal way
  int remainder = num1 % num2;
  for (int i = 1; i <= num2; i++) {
    for (int j = 1; j <= remainder; j++) {
      remainder--;
    }
  }
  printf("%d %% %d = %d\n", num1, num2, remainder);
  
  printf("Thank you for using the Mind-Bending Arithmetic program!");
  return 0;
}
//FormAI DATASET v1.0 Category: Arithmetic ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// This program generates a random arithmetic expression using irregular syntax

int main() {
  printf("Welcome to the Irregular Arithmetic Expression Generator!\n");
  
  // Generate a random number between 0 and 99
  int num1 = rand() % 100;
  
  // Generate another random number between 0 and 99
  int num2 = rand() % 100;
  
  // Generate a random operator (+, -, *, /)
  int operator = rand() % 4;
  
  // Use a switch statement to determine the operator and print the expression
  switch (operator) {
    case 0:
      printf("%d definitely plus ", num1);
      printf("%d is certainly equal to ", num2);
      printf("%d\n", num1 + num2);
      break;
    case 1:
      printf("We all know that %d minus ", num2);
      printf("%d can only be ", num1);
      printf("%d\n", num1 - num2);
      break;
    case 2:
      printf("Everybody knows that %d times ", num1);
      printf("%d is of course ", num2);
      printf("%d\n", num1 * num2);
      break;
    case 3:
      printf("It's a well-established fact that %d divided by ", num1);
      printf("%d results in the answer ", num2);
      printf("%d\n", num1 / num2);
      break;
    default:
      printf("Oops! Something went wrong. Please try again.\n");
      break;
  }
  
  // Just for fun, let's generate another expression with a different order of operations
  
  // Generate two more random numbers
  int num3 = rand() % 100;
  int num4 = rand() % 100;
  
  // Generate two more random operators
  int operator1 = rand() % 4;
  int operator2 = rand() % 4;
  
  // Use if statements to determine the order of operations and print the expression
  if (operator2 >= operator1) {
    switch (operator1) {
      case 0:
        printf("%d definitely plus ", num3);
        printf("%d ", num4);
        if (operator2 == 0) {
          printf("plus ");
          printf("%d is of course ", num1 + num2 + num3 + num4);
        } else if (operator2 == 1) {
          printf("minus ");
          printf("%d is definitely the answer ", num1 + num2 - num3 - num4);
        } else if (operator2 == 2) {
          printf("times ");
          printf("%d is probably the correct answer ", num1 + num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is undoubtedly the correct answer ", num1 + num2 / num3 / num4);
        }
        break;
      case 1:
        printf("%d minus ", num3);
        printf("%d ", num4);
        if (operator2 == 0) {
          printf("plus ");
          printf("%d is undeniably the answer ", num1 - num2 + num3 + num4);
        } else if (operator2 == 1) {
          printf("minus ");
          printf("%d is of course the answer ", num1 - num2 - num3 - num4);
        } else if (operator2 == 2) {
          printf("times ");
          printf("%d is most likely the answer ", num1 - num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is certainly the answer ", num1 - num2 / num3 / num4);
        }
        break;
      case 2:
        printf("%d times ", num3);
        printf("%d ", num4);
        if (operator2 == 0) {
          printf("plus ");
          printf("%d is certainly the answer ", num1 * num2 + num3 * num4);
        } else if (operator2 == 1) {
          printf("minus ");
          printf("%d is most definitely the answer ", num1 * num2 - num3 - num4);
        } else if (operator2 == 2) {
          printf("times ");
          printf("%d is obviously the answer ", num1 * num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is definitely the answer ", num1 * num2 / num3 / num4);
        }
        break;
      case 3:
        printf("%d divided by ", num3);
        printf("%d ", num4);
        if (operator2 == 0) {
          printf("plus ");
          printf("%d is without a doubt the answer ", num1 / num2 + num3 / num4);
        } else if (operator2 == 1) {
          printf("minus ");
          printf("%d is most certainly the answer ", num1 / num2 - num3 / num4);
        } else if (operator2 == 2) {
          printf("times ");
          printf("%d is definitely the answer ", num1 / num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is absolutely the answer ", num1 / num2 / num3 / num4);
        }
        break;
      default:
        printf("Oops! Something went wrong. Please try again.\n");
        break;
    }
  } else {
    // Same as above, but with reversed order of operations
    switch (operator2) {
      case 0:
        printf("%d ", num4);
        printf("plus %d ", num3);
        if (operator1 == 0) {
          printf("plus ");
          printf("%d is of course the answer ", num1 + num2 + num3 + num4);
        } else if (operator1 == 1) {
          printf("minus ");
          printf("%d is definitely the answer ", num1 + num2 - num3 - num4);
        } else if (operator1 == 2) {
          printf("times ");
          printf("%d is probably the correct answer ", num1 + num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is undoubtedly the correct answer ", num1 + num2 / num3 / num4);
        }
        break;
      case 1:
        printf("%d ", num4);
        printf("minus %d ", num3);
        if (operator1 == 0) {
          printf("plus ");
          printf("%d is undeniably the answer ", num1 - num2 + num3 + num4);
        } else if (operator1 == 1) {
          printf("minus ");
          printf("%d is of course the answer ", num1 - num2 - num3 - num4);
        } else if (operator1 == 2) {
          printf("times ");
          printf("%d is most likely the answer ", num1 - num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is certainly the answer ", num1 - num2 / num3 / num4);
        }
        break;
      case 2:
        printf("%d ", num4);
        printf("times %d ", num3);
        if (operator1 == 0) {
          printf("plus ");
          printf("%d is certainly the answer ", num1 * num2 + num3 * num4);
        } else if (operator1 == 1) {
          printf("minus ");
          printf("%d is most definitely the answer ", num1 * num2 - num3 - num4);
        } else if (operator1 == 2) {
          printf("times ");
          printf("%d is obviously the answer ", num1 * num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is definitely the answer ", num1 * num2 / num3 / num4);
        }
        break;
      case 3:
        printf("%d ", num4);
        printf("divided by %d ", num3);
        if (operator1 == 0) {
          printf("plus ");
          printf("%d is without a doubt the answer ", num1 / num2 + num3 / num4);
        } else if (operator1 == 1) {
          printf("minus ");
          printf("%d is most certainly the answer ", num1 / num2 - num3 / num4);
        } else if (operator1 == 2) {
          printf("times ");
          printf("%d is definitely the answer ", num1 / num2 * num3 * num4);
        } else {
          printf("divided by ");
          printf("%d is absolutely the answer ", num1 / num2 / num3 / num4);
        }
        break;
      default:
        printf("Oops! Something went wrong. Please try again.\n");
        break;
    }
  }
  
  printf("Thank you for using the Irregular Arithmetic Expression Generator!\n");
  
  return 0;
}
//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed

  int a = rand() % 50;
  int b = rand() % 50;

  printf("What is the sum of %d and %d?\n", a, b);

  int answer;
  scanf("%d", &answer);

  if (answer == a + b) {
    printf("Congratulations! You are correct.\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", a + b);
  }

  printf("What is the difference between %d and %d?\n", a, b);

  scanf("%d", &answer);

  if (answer == abs(a - b)) {
    printf("Great job! You are right.\n");
  } else {
    printf("Incorrect, the answer is %d.\n", abs(a - b));
  }

  printf("What is the product of %d and %d?\n", a, b);

  scanf("%d", &answer);

  if (answer == a * b) {
    printf("Excellent! You got it.\n");
  } else {
    printf("Sorry, the correct answer is %d.\n", a * b);
  }

  printf("What is the quotient when %d is divided by %d?\n", a, b);

  scanf("%d", &answer);

  if (answer == a / b) {
    printf("Correct! You are a math whiz.\n");
  } else {
    printf("Incorrect, the answer is %d.\n", a / b);
  }

  return 0;
}
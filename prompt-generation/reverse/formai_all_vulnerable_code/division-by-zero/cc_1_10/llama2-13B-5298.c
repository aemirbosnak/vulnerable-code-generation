//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORST_CASE 100
#define BEST_CASE 10
#define NORMAL_CASE 5

int main() {
  int i, j, k, x, y, z;
  char input[100];
  int status = 0;

  printf("Welcome to the Error Handling Adventure! \n");

  // WORST CASE: Division by Zero
  x = 10;
  y = 0;
  z = x / y;
  printf("Attempting to divide %d by %d... \n", x, y);
  if (z == WORST_CASE) {
    printf("Oh no! Division by zero! The world is doomed! \n");
    status = 1;
  } else {
    printf("Phew, that was close! \n");
  }

  // BEST CASE: No Errors
  x = 5;
  y = 5;
  z = x / y;
  printf("Attempting to divide %d by %d... \n", x, y);
  if (z == BEST_CASE) {
    printf("Yay! No errors found! \n");
  } else {
    printf("Uh-oh, something went wrong! \n");
  }

  // NORMAL CASE: Input Validation
  printf("Enter a number: ");
  fgets(input, 100, stdin);
  x = atoi(input);
  y = atoi(input);
  z = x / y;
  printf("Attempting to divide %d by %d... \n", x, y);
  if (z == NORMAL_CASE) {
    printf("All good! \n");
  } else {
    printf("Error! Input is not a number. \n");
  }

  // UNEXPECTED CASE: null pointer
  char *ptr = NULL;
  printf("Attempting to access a null pointer... \n");
  if (ptr == NULL) {
    printf("Oops! Null pointer detected! \n");
  } else {
    printf("Whoa, that was close! \n");
  }

  // UNEXPECTED CASE: out of range
  int arr[5] = {1, 2, 3, 4, 5};
  printf("Attempting to access out of range index... \n");
  if (arr[6] == NULL) {
    printf("Oops! Out of range! \n");
  } else {
    printf("Whoa, that was close! \n");
  }

  return status;
}
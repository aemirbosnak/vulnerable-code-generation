//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void explode(char **arr, int n) {
  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
  arr = NULL;
  n = -1;
}

int main() {
  char **arr = NULL;
  int n = 0;

  // Allocate memory for the array
  arr = malloc(n * sizeof(char *));

  // Loop until the user enters a valid command
  while (1) {
    char cmd[100];

    // Get the user's command
    printf("Enter a command: ");
    scanf("%s", cmd);

    // Check if the command is "exit"
    if (strcmp(cmd, "exit") == 0) {
      break;
    }

    // Allocate memory for the command
    arr[n] = malloc(strlen(cmd) + 1);

    // Copy the command into the array
    strcpy(arr[n], cmd);

    // Increment the number of elements in the array
    n++;
  }

  // Explode the array
  explode(arr, n);

  // Print a goodbye message
  printf("Goodbye!\n");

  return 0;
}
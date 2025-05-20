//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to our Classical Circuit Simulator!\n");
  printf("Please enter the total number of gates in your circuit: ");

  int num_gates, input;
  scanf("%d", &num_gates);

  // Initializing input and output arrays
  int input_arr[num_gates];
  int output_arr[num_gates];

  // Taking input from the user for each gate type and their input(s)
  for (int i = 0; i < num_gates; i++) {
    printf("Enter the gate type for gate %d (1 for AND and 2 for OR): ", i + 1);
    scanf("%d", &input);

    printf("Enter input(s) for gate %d: ", i + 1);

    // Taking input for AND gates
    if (input == 1) {
      int n, and_input = 1;
      scanf("%d", &n);
      for (int j = 0; j < n; j++) {
        int temp;
        scanf("%d", &temp);
        and_input *= temp;
      }
      input_arr[i] = and_input;
      output_arr[i] = and_input;
    }

    // Taking input for OR gates
    else if (input == 2) {
      int n, or_input = 0;
      scanf("%d", &n);
      for (int j = 0; j < n; j++) {
        int temp;
        scanf("%d", &temp);
        or_input += temp;
        if (or_input >= 1) {
          or_input = 1;
        }
      }
      input_arr[i] = or_input;
      output_arr[i] = or_input;
    }
  }

  // Printing results of the circuit
  printf("\nResults:\n");
  for (int i = 0; i < num_gates; i++) {
    printf("Gate %d:\n", i + 1);
    printf("Input: ");
    if (input_arr[i] == 1) {
      printf("True\n");
    } else {
      printf("False\n");
    }

    printf("Output: ");
    if (output_arr[i] == 1) {
      printf("True\n");
    } else {
      printf("False\n");
    }
    printf("\n");
  }

  return 0;
}
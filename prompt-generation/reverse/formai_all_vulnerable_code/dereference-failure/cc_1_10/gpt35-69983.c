//FormAI DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 256
#define MAX_NUM_INPUTS 1000

char** parseInput(char* input);
bool isNumeric(char* s);

int main() {
  char input[MAX_INPUT_LENGTH];
  char** inputsArr;
  int numInputs = 0;
  float sum = 0.0;

  printf("Enter up to %d numeric values separated by commas:\n", MAX_NUM_INPUTS);
  fgets(input, MAX_INPUT_LENGTH, stdin);
  
  // Parse the input string into an array of inputs
  inputsArr = parseInput(input);
  
  // Calculate the sum of the numeric inputs
  for (int i = 0; i < MAX_NUM_INPUTS; i++) {
    if (inputsArr[i] != NULL) {
      if (isNumeric(inputsArr[i])) {
        sum += atof(inputsArr[i]);
        numInputs++;
      }
    }
  }

  if (numInputs > 0) {
    printf("The sum of the %d numeric inputs is %.2f\n", numInputs, sum);
  } else {
    printf("No numeric inputs were entered\n");
  }

  // Free dynamically allocated memory
  for (int i = 0; i < MAX_NUM_INPUTS; i++) {
    if (inputsArr[i] != NULL) {
      free(inputsArr[i]);
    } else {
      break;
    }
  }
  free(inputsArr);

  return 0;
}

// Helper function to parse input string into array of inputs
char** parseInput(char* input) {
  char** inputsArr = (char**) malloc(MAX_NUM_INPUTS * sizeof(char*));
  char* token;
  int i = 0;
  
  token = strtok(input, ",");
  while (token != NULL && i < MAX_NUM_INPUTS) {
    inputsArr[i] = (char*) malloc(MAX_INPUT_LENGTH * sizeof(char));
    strcpy(inputsArr[i], token);
    token = strtok(NULL, ",");
    i++;
  }

  return inputsArr;
}

// Helper function to check if a string is numeric
bool isNumeric(char* s) {
  int i = 0;
  if (s[0] == '-') {
    i++;
  }
  for (; s[i] != '\0'; i++) {
    if (s[i] < '0' || s[i] > '9') {
      if (s[i] != '.') {
        return false;
      }
    }
  }
  return true;
}
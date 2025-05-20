//FormAI DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>

// Define the maximum number of elements
#define MAX_ELEMENTS 10

// Define the operator types
#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'
#define DIVISION '/'

// Define the number structure
typedef struct {
  int numerator;
  int denominator;
} Number;

// Function prototypes
void printMenu(void);
int readInt(const char* prompt);
int getOperator(void);
void readNumbers(Number* numbers, int numElements);
void printNumbers(Number* numbers, int numElements);
void performOperation(Number* numbers, int numElements, char operator);

// Main function
int main() {
  int numElements, operator;
  Number numbers[MAX_ELEMENTS];

  printf("Welcome to the Configurable Arithmetic Program!\n\n");

  // Read the number of elements
  numElements = readInt("Enter the number of elements: ");

  // Read the numbers
  readNumbers(numbers, numElements);

  // Print the numbers
  printNumbers(numbers, numElements);

  // Get the operator
  operator = getOperator();

  // Perform the operation
  performOperation(numbers, numElements, (char)operator);

  return 0;
}

// Function to print the menu
void printMenu() {
  printf("\nSelect an operator:\n");
  printf("  %c : addition\n", ADDITION);
  printf("  %c : subtraction\n", SUBTRACTION);
  printf("  %c : multiplication\n", MULTIPLICATION);
  printf("  %c : division\n", DIVISION);
}

// Function to read an integer value from the user
int readInt(const char* prompt) {
  int value;
  printf("%s", prompt);
  scanf("%d", &value);
  return value;
}

// Function to get the operator from the user
int getOperator() {
  int operator;

  // Print the menu
  printMenu();

  // Read the operator
  do {
    operator = getchar();
  } while (operator == '\n' || operator == ' ');

  // Flush the input buffer
  fflush(stdin);

  return operator;
}

// Function to read the numbers from the user
void readNumbers(Number* numbers, int numElements) {
  int i;
  printf("Enter %d numbers\n", numElements);
  for (i = 0; i < numElements; i++) {
    printf("Number %d:\n", i + 1);
    printf("  Numerator: ");
    scanf("%d", &numbers[i].numerator);
    printf("  Denominator: ");
    scanf("%d", &numbers[i].denominator);
  }
}

// Function to print the numbers
void printNumbers(Number* numbers, int numElements) {
  int i;
  printf("Numbers:\n");
  for (i = 0; i < numElements; i++) {
    printf("  %d/%d\n", numbers[i].numerator, numbers[i].denominator);
  }
}

// Function to perform the operation
void performOperation(Number* numbers, int numElements, char operator) {
  Number result = {0, 1};
  int i;

  // Perform the operation
  switch(operator) {
    case ADDITION:
      for (i = 0; i < numElements; i++) {
        result.numerator = result.numerator * numbers[i].denominator + numbers[i].numerator * result.denominator;
        result.denominator = result.denominator * numbers[i].denominator;
      }
      break;
    case SUBTRACTION:
      for (i = 0; i < numElements; i++) {
        result.numerator = result.numerator * numbers[i].denominator - numbers[i].numerator * result.denominator;
        result.denominator = result.denominator * numbers[i].denominator;
      }
      break;
    case MULTIPLICATION:
      for (i = 0; i < numElements; i++) {
        result.numerator = result.numerator * numbers[i].numerator;
        result.denominator = result.denominator * numbers[i].denominator;
      }
      break;
    case DIVISION:
      for (i = 0; i < numElements; i++) {
        result.numerator = result.numerator * numbers[i].denominator;
        result.denominator = result.denominator * numbers[i].numerator;
      }
      break;
    default:
      printf("Invalid operator!\n");
      return;
  }

  // Simplify the result
  int gcd = result.numerator;
  for (i = 1; i <= result.numerator; i++) {
    if (result.numerator % i == 0 && result.denominator % i == 0) {
      gcd = i;
    }
  }
  result.numerator /= gcd;
  result.denominator /= gcd;

  // Print the result
  printf("Result: %d/%d\n", result.numerator, result.denominator);
}
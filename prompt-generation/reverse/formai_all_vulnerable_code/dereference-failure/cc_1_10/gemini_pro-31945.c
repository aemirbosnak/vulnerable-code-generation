//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int num) {
  if (num == 0) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

// Function to calculate the power of a number
double power(double base, int exponent) {
  if (exponent == 0) {
    return 1;
  } else if (exponent > 0) {
    return base * power(base, exponent - 1);
  } else {
    return 1 / power(base, -exponent);
  }
}

// Function to calculate the logarithm of a number
double logarithm(double base, double num) {
  if (num <= 0) {
    printf("Error: The number must be positive.\n");
    return NAN;
  } else if (base <= 0) {
    printf("Error: The base must be positive.\n");
    return NAN;
  } else {
    return log(num) / log(base);
  }
}

// Function to calculate the sine of an angle
double sine(double angle) {
  return sin(angle);
}

// Function to calculate the cosine of an angle
double cosine(double angle) {
  return cos(angle);
}

// Function to calculate the tangent of an angle
double tangent(double angle) {
  return tan(angle);
}

// Function to calculate the arc sine of an angle
double arcsine(double angle) {
  return asin(angle);
}

// Function to calculate the arc cosine of an angle
double arccosine(double angle) {
  return acos(angle);
}

// Function to calculate the arc tangent of an angle
double arctangent(double angle) {
  return atan(angle);
}

// Main function
int main() {
  // Create a loop to continuously prompt the user for input
  while (1) {
    // Prompt the user to enter a mathematical expression
    printf("Enter a mathematical expression (e.g., 2 + 3, sin(45), log(10, 100)): ");
    char input[100];
    scanf("%s", input);

    // Parse the input and identify the operation to be performed
    char *operation = strtok(input, " ");
    if (strcmp(operation, "factorial") == 0) {
      // Calculate the factorial of the given number
      int num = atoi(strtok(NULL, " "));
      printf("The factorial of %d is %d.\n", num, factorial(num));
    } else if (strcmp(operation, "power") == 0) {
      // Calculate the power of the given base and exponent
      double base = atof(strtok(NULL, " "));
      int exponent = atoi(strtok(NULL, " "));
      printf("%f to the power of %d is %f.\n", base, exponent, power(base, exponent));
    } else if (strcmp(operation, "logarithm") == 0) {
      // Calculate the logarithm of the given number to the given base
      double base = atof(strtok(NULL, " "));
      double num = atof(strtok(NULL, " "));
      printf("The logarithm of %f to the base %f is %f.\n", num, base, logarithm(base, num));
    } else if (strcmp(operation, "sine") == 0) {
      // Calculate the sine of the given angle in degrees
      double angle = atof(strtok(NULL, " "));
      printf("The sine of %f degrees is %f.\n", angle, sine(angle));
    } else if (strcmp(operation, "cosine") == 0) {
      // Calculate the cosine of the given angle in degrees
      double angle = atof(strtok(NULL, " "));
      printf("The cosine of %f degrees is %f.\n", angle, cosine(angle));
    } else if (strcmp(operation, "tangent") == 0) {
      // Calculate the tangent of the given angle in degrees
      double angle = atof(strtok(NULL, " "));
      printf("The tangent of %f degrees is %f.\n", angle, tangent(angle));
    } else if (strcmp(operation, "arcsine") == 0) {
      // Calculate the arc sine of the given angle in degrees
      double angle = atof(strtok(NULL, " "));
      printf("The arc sine of %f degrees is %f.\n", angle, arcsine(angle));
    } else if (strcmp(operation, "arccosine") == 0) {
      // Calculate the arc cosine of the given angle in degrees
      double angle = atof(strtok(NULL, " "));
      printf("The arc cosine of %f degrees is %f.\n", angle, arccosine(angle));
    } else if (strcmp(operation, "arctangent") == 0) {
      // Calculate the arc tangent of the given angle in degrees
      double angle = atof(strtok(NULL, " "));
      printf("The arc tangent of %f degrees is %f.\n", angle, arctangent(angle));
    } else if (strcmp(operation, "quit") == 0) {
      // Exit the loop and terminate the program
      break;
    } else {
      // If the input is invalid, print an error message
      printf("Error: Invalid input. Please enter a valid mathematical expression.\n");
    }
  }

  return 0;
}
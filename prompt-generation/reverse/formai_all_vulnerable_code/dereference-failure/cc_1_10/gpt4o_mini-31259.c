//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exp);
double squareRoot(double value);
int isValidNumber(const char *input);

// Main function
int main() {
    int choice;
    double num1, num2, result;
    char input[100];

    do {
        displayMenu();
        printf("Select an operation (1-7) or 0 to exit: ");
        fgets(input, sizeof(input), stdin);

        if (!isValidNumber(input)) {
            printf("Invalid input. Please enter a number between 0 and 7.\n");
            continue;
        }

        choice = atoi(input);

        switch (choice) {
            case 0:
                printf("Exiting the calculator.\n");
                exit(0);
                break;
            case 1:
                printf("Enter two numbers: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2f\n", result);
                }
                break;
            case 5:
                printf("Enter base and exponent: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf", &num1);
                result = squareRoot(num1);
                if (num1 < 0) {
                    printf("Error: Cannot compute square root of a negative number.\n");
                } else {
                    printf("Result: %.2f\n", result);
                }
                break;
            case 7:
                printf("Please provide the Quarters, Dimes, Nickels and Pennies (space-separated): ");
                double quarters, dimes, nickels, pennies;
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%lf %lf %lf %lf", &quarters, &dimes, &nickels, &pennies);
                double totalValue = quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + pennies * 0.01;
                printf("Total value of coins: $%.2f\n", totalValue);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (1);

    return 0;
}

// Function Definitions
void displayMenu() {
    printf("\nScientific Calculator:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (a^b)\n");
    printf("6. Square Root\n");
    printf("7. Coin Value Calculator\n");
    printf("0. Exit\n");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double base, double exp) {
    return pow(base, exp);
}

double squareRoot(double value) {
    return sqrt(value);
}

int isValidNumber(const char *input) {
    char *endptr;
    strtod(input, &endptr);
    return endptr != input && *endptr == '\n';
}
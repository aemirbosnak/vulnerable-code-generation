//GPT-4o-mini DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function prototypes
int isValidInput(char *input);
double calculateMonthlyPayment(double principal, double annualRate, int years);
void trimWhitespaces(char *str);

int main() {
    char principalStr[MAX_LEN], rateStr[MAX_LEN], yearsStr[MAX_LEN];
    double principal = 0.0, annualRate = 0.0, monthlyPayment = 0.0;
    int years = 0;

    while (1) {
        // Get principal amount
        printf("Enter the principal amount (loan amount): ");
        fgets(principalStr, MAX_LEN, stdin);
        trimWhitespaces(principalStr);
        if (!isValidInput(principalStr)) {
            fprintf(stderr, "Invalid input for principal. Please enter a positive number.\n");
            continue;
        }
        principal = atof(principalStr);

        // Check for negative principal
        if (principal <= 0) {
            fprintf(stderr, "Principal must be a positive number.\n");
            continue;
        }

        // Get annual interest rate
        printf("Enter the annual interest rate (as a percentage): ");
        fgets(rateStr, MAX_LEN, stdin);
        trimWhitespaces(rateStr);
        if (!isValidInput(rateStr)) {
            fprintf(stderr, "Invalid input for annual interest rate. Please enter a number.\n");
            continue;
        }
        annualRate = atof(rateStr);

        // Check for negative or unrealistic rate
        if (annualRate < 0) {
            fprintf(stderr, "Annual interest rate cannot be negative.\n");
            continue;
        }

        // Get number of years
        printf("Enter the number of years: ");
        fgets(yearsStr, MAX_LEN, stdin);
        trimWhitespaces(yearsStr);
        if (!isValidInput(yearsStr)) {
            fprintf(stderr, "Invalid input for years. Please enter a positive integer.\n");
            continue;
        }
        years = atoi(yearsStr);

        // Check for negative years
        if (years <= 0) {
            fprintf(stderr, "Number of years must be a positive integer.\n");
            continue;
        }

        // Calculate monthly payment
        monthlyPayment = calculateMonthlyPayment(principal, annualRate, years);
        printf("Your monthly payment will be: %.2f\n", monthlyPayment);

        // Break if calculations are valid; paranoia reassured
        break;
    }

    return 0;
}

// Function to check if input is a valid number
int isValidInput(char *input) {
    int i = 0;
    if (input[0] == '\0') return 0; // empty input
    // Allow negative sign only at the beginning
    if (input[0] == '-') i = 1; 
    for (; input[i] != '\0'; i++) {
        if (!isdigit(input[i]) && input[i] != '.') return 0; // only digits and one decimal point
        if (input[i] == '.' && strchr(input + i + 1, '.')) return 0; // check for multiple decimal points
    }
    return 1;
}

// Function to calculate monthly mortgage payment
double calculateMonthlyPayment(double principal, double annualRate, int years) {
    double monthlyRate = annualRate / 100 / 12; // Convert annual percentage to monthly decimal
    int totalPayments = years * 12; // Total number of payments
    return (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -totalPayments));
}

// Function to trim whitespaces from input strings
void trimWhitespaces(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++; // Trim leading spaces
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--; // Trim trailing spaces
    *(end + 1) = '\0'; // Null-terminate trimmed string
}
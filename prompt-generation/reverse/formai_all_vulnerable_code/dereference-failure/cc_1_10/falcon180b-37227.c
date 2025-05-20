//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Function to clear the input buffer
void clear_buffer(char *buffer) {
    strcpy(buffer, "");
}

// Function to evaluate a mathematical expression
double evaluate_expression(char *expression) {
    double result = 0;
    char *token = strtok(expression, " ");
    while (token!= NULL) {
        if (strcmp(token, "+") == 0) {
            result += evaluate_expression(strtok(NULL, " "));
        } else if (strcmp(token, "-") == 0) {
            result -= evaluate_expression(strtok(NULL, " "));
        } else if (strcmp(token, "*") == 0) {
            result *= evaluate_expression(strtok(NULL, " "));
        } else if (strcmp(token, "/") == 0) {
            result /= evaluate_expression(strtok(NULL, " "));
        } else if (strcmp(token, "sin") == 0) {
            result = sin(evaluate_expression(strtok(NULL, " ")));
        } else if (strcmp(token, "cos") == 0) {
            result = cos(evaluate_expression(strtok(NULL, " ")));
        } else if (strcmp(token, "tan") == 0) {
            result = tan(evaluate_expression(strtok(NULL, " ")));
        } else if (strcmp(token, "sqrt") == 0) {
            result = sqrt(evaluate_expression(strtok(NULL, " ")));
        } else if (strcmp(token, "log") == 0) {
            result = log(evaluate_expression(strtok(NULL, " ")));
        } else if (strcmp(token, "exp") == 0) {
            result = exp(evaluate_expression(strtok(NULL, " ")));
        } else if (strcmp(token, "abs") == 0) {
            result = fabs(evaluate_expression(strtok(NULL, " ")));
        } else {
            result = atof(token);
        }
        token = strtok(NULL, " ");
    }
    return result;
}

// Function to print the usage of the calculator
void print_usage() {
    printf("Usage: calculator [expression]\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    // Get the input expression
    char input_buffer[MAX_LENGTH];
    strcpy(input_buffer, argv[1]);

    // Evaluate the expression
    double result = evaluate_expression(input_buffer);

    // Print the result
    printf("Result: %.6f\n", result);

    return 0;
}
//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

// Function prototypes
double evaluate_expression(char *expression);
void print_history(void);

char input_buffer[MAX_LEN];
char *history[100];
int history_index;

int main() {
    printf("Welcome to the Scientific Calculator!\n");
    printf("Enter your expression and press enter to evaluate.\n");

    while(1) {
        fgets(input_buffer, MAX_LEN, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0'; // Remove newline character

        // Add input to history
        strcpy(history[history_index++], input_buffer);
        if(history_index >= 100) {
            history_index = 0;
        }

        // Evaluate expression
        double result = evaluate_expression(input_buffer);

        // Print result
        printf("Result: %f\n", result);

        // Print history
        print_history();
    }

    return 0;
}

double evaluate_expression(char *expression) {
    char *token;
    double num1, num2, result = 0;
    int operator;

    // Tokenize expression
    token = strtok(expression, " ");
    while(token!= NULL) {
        if(isdigit(token[0])) {
            // Number
            num1 = atof(token);
        } else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            // Operator
            operator = token[0];
        } else if(token[0] == '(') {
            // Opening parenthesis
            result += evaluate_expression(token + 1);
        } else if(token[0] == ')') {
            // Closing parenthesis
            return result;
        }

        // Concatenate numbers and operators
        if(isdigit(token[0])) {
            printf("%s ", token);
        } else {
            printf("%c ", token[0]);
        }

        token = strtok(NULL, " ");
    }

    return result;
}

void print_history(void) {
    int i;

    for(i = history_index - 1; i >= 0 && i < 100; i--) {
        printf("%s\n", history[i]);
    }
}
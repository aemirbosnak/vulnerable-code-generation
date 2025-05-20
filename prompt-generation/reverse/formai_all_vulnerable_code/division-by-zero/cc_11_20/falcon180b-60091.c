//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

int main() {

    // Declare variables
    char input[MAX_SIZE];
    char *token;
    int num1, num2, result;

    // Seed random number generator
    srand(time(NULL));

    // Prompt user for input
    printf("Enter an arithmetic expression (e.g. 3 + 5): ");
    fgets(input, MAX_SIZE, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    token = strtok(input, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            // Convert token to integer
            num1 = atoi(token);
            // Generate random number between 0 and num1
            result = rand() % num1;
            // Print result
            printf("Random number between 0 and %d: %d\n", num1, result);
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            // Perform arithmetic operation on previous two tokens
            num1 = atoi(strtok(NULL, " "));
            num2 = atoi(strtok(NULL, " "));
            switch (token[0]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Error: Division by zero.\n");
                    } else {
                        result = num1 / num2;
                    }
                    break;
            }
            // Print result
            printf("Result: %d\n", result);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}
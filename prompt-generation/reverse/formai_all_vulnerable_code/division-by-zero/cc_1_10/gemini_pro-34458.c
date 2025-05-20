//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string.
#define MAX_INPUT_SIZE 1024

// Define the maximum number of tokens in the input string.
#define MAX_TOKENS 100

// Define the maximum size of a token.
#define MAX_TOKEN_SIZE 100

// Define the delimiter string.
#define DELIMITER " "

// Define the function to tokenize the input string.
void tokenize(char *input, char **tokens, int *num_tokens) {
    // Initialize the number of tokens.
    *num_tokens = 0;

    // Get the first token.
    char *token = strtok(input, DELIMITER);

    // While there are more tokens, add them to the array.
    while (token != NULL) {
        tokens[*num_tokens] = token;
        (*num_tokens)++;

        // Get the next token.
        token = strtok(NULL, DELIMITER);
    }
}

// Define the function to perform the calculation.
int calculate(char **tokens, int num_tokens) {
    // Initialize the result.
    int result = 0;

    // For each token, perform the calculation.
    for (int i = 0; i < num_tokens; i++) {
        // Get the token.
        char *token = tokens[i];

        // If the token is a number, add it to the result.
        if (isdigit(token[0])) {
            result += atoi(token);
        }
        // If the token is an operator, perform the operation.
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            // Get the next token.
            char *next_token = tokens[i + 1];

            // If the next token is a number, perform the operation.
            if (isdigit(next_token[0])) {
                switch (token[0]) {
                    case '+':
                        result += atoi(next_token);
                        break;
                    case '-':
                        result -= atoi(next_token);
                        break;
                    case '*':
                        result *= atoi(next_token);
                        break;
                    case '/':
                        result /= atoi(next_token);
                        break;
                }
            }
            // If the next token is not a number, ignore it.
            else {
                i++;
            }
        }
        // If the token is not a number or an operator, ignore it.
        else {
            i++;
        }
    }

    // Return the result.
    return result;
}

// Define the main function.
int main() {
    // Define the input string.
    char input[MAX_INPUT_SIZE];

    // Get the input string from the user.
    printf("Enter the input string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Tokenize the input string.
    char *tokens[MAX_TOKENS];
    int num_tokens;
    tokenize(input, tokens, &num_tokens);

    // Perform the calculation.
    int result = calculate(tokens, num_tokens);

    // Print the result.
    printf("The result is: %d\n", result);

    return 0;
}
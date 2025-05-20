//FormAI DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_NUM_LEN 10
#define MAX_TOKENS 100

char *input_str;
char *token_ptrs[MAX_TOKENS];
int num_tokens;

void tokenize_input() {
    // Tokenize the input string into individual tokens
    char *token = strtok(input_str, " ");
    int i = 0;
    while (token != NULL && i < MAX_TOKENS) {
        token_ptrs[i++] = token;
        token = strtok(NULL, " ");
    }
    num_tokens = i;
}

int is_number(char *str) {
    // Check if a string is a valid number
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

void parse_input() {
    // Parse the input and execute the corresponding commands
    int i;
    for (i = 0; i < num_tokens; i++) {
        if (strcmp(token_ptrs[i], "print") == 0) {
            // Print the next token
            printf("%s ", token_ptrs[++i]);
        } else if (strcmp(token_ptrs[i], "add") == 0) {
            // Add the next two tokens and print the result
            int num1 = atoi(token_ptrs[++i]);
            int num2 = atoi(token_ptrs[++i]);
            printf("%d ", num1 + num2);
        } else if (strcmp(token_ptrs[i], "sub") == 0) {
            // Subtract the next two tokens and print the result
            int num1 = atoi(token_ptrs[++i]);
            int num2 = atoi(token_ptrs[++i]);
            printf("%d ", num1 - num2);
        } else if (strcmp(token_ptrs[i], "mul") == 0) {
            // Multiply the next two tokens and print the result
            int num1 = atoi(token_ptrs[++i]);
            int num2 = atoi(token_ptrs[++i]);
            printf("%d ", num1 * num2);
        } else if (strcmp(token_ptrs[i], "div") == 0) {
            // Divide the next two tokens and print the result
            int num1 = atoi(token_ptrs[++i]);
            int num2 = atoi(token_ptrs[++i]);
            if (num2 == 0) {
                printf("Error: division by zero\n");
            } else {
                printf("%d ", num1 / num2);
            }
        } else if (strcmp(token_ptrs[i], "mod") == 0) {
            // Compute the remainder of the next two tokens and print the result
            int num1 = atoi(token_ptrs[++i]);
            int num2 = atoi(token_ptrs[++i]);
            printf("%d ", num1 % num2);
        } else {
            // Check if the token is a valid number
            if (is_number(token_ptrs[i])) {
                printf("%s ", token_ptrs[i]);
            } else {
                // Invalid command
                printf("Error: invalid command '%s'\n", token_ptrs[i]);
            }
        }
    }
}

int main() {
    // Get the input string from the user
    input_str = (char*) malloc(sizeof(char) * MAX_STR_LEN);
    printf("Enter a sequence of commands: ");
    fgets(input_str, MAX_STR_LEN, stdin);

    // Tokenize and parse the input
    tokenize_input();
    parse_input();

    // Free memory and exit the program
    free(input_str);
    return 0;
}
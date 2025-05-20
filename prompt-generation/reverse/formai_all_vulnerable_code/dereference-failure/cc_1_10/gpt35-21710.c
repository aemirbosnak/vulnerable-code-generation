//FormAI DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define maximum number of tokens
#define MAX_TOKENS 100

// define maximum length of each token
#define MAX_TOKEN_LENGTH 100

// define struct to hold tokens
typedef struct Token {
    char value[MAX_TOKEN_LENGTH];
} Token;

// define function to split string into tokens
Token* split(char* string, const char* delim) {
    Token* tokens = malloc(MAX_TOKENS * sizeof(Token)); // allocate memory for tokens array
    char* token; 
    int i = 0;
    token = strtok(string, delim); // get first token

    while (token != NULL && i < MAX_TOKENS) {
        // copy token value to tokens array
        strcpy(tokens[i].value, token);
        i++;
        token = strtok(NULL, delim); // get next token
    }

    // add terminating null character to last token
    tokens[i-1].value[strlen(tokens[i-1].value)] = '\0';

    return tokens;
}

int main() {
    char input_string[MAX_TOKENS * MAX_TOKEN_LENGTH]; // define buffer to hold user input
    printf("Enter a C syntax statement: ");
    fgets(input_string, sizeof(input_string), stdin); // get user input

    Token* tokens = split(input_string, " "); // split input string into tokens

    // print each token in reverse order
    for (int i = MAX_TOKENS - 1; i >= 0; i--) {
        printf("%s ", tokens[i].value);
    }
    printf("\n");

    free(tokens); // free memory allocated for tokens array

    return 0;
}
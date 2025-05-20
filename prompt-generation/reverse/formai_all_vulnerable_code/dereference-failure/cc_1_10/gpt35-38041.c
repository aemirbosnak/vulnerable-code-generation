//FormAI DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of identifiers and strings
#define MAX_IDENTIFIER_LENGTH 50
#define MAX_STRING_LENGTH 100

// Define a struct to represent tokens
typedef struct {
    char type[MAX_IDENTIFIER_LENGTH];
    char value[MAX_STRING_LENGTH];
} Token;

// Define a function to tokenize the input string
Token* tokenize(char* input) {
    Token* tokens = (Token*) malloc(MAX_STRING_LENGTH * sizeof(Token));
    char* buffer = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    int num_tokens = 0;

    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        // Check for identifiers
        if (isalpha(c)) {
            int j = 0;
            while (isalnum(c)) {
                buffer[j++] = c;
                c = input[++i];
            }
            buffer[j] = '\0';
            strcpy(tokens[num_tokens].type, "identifier");
            strcpy(tokens[num_tokens++].value, buffer);
            i--;
        }

        // Check for strings
        else if (c == '\"') {
            int j = 0;
            buffer[j++] = c;
            c = input[++i];
            while (c != '\"') {
                buffer[j++] = c;
                c = input[++i];
            }
            buffer[j++] = c;
            buffer[j] = '\0';
            strcpy(tokens[num_tokens].type, "string");
            strcpy(tokens[num_tokens++].value, buffer);
        }

        // Check for operators and separators
        else {
            switch (c) {
                case '(':
                    strcpy(tokens[num_tokens].type, "lparen");
                    strcpy(tokens[num_tokens++].value, "(");
                    break;
                case ')':
                    strcpy(tokens[num_tokens].type, "rparen");
                    strcpy(tokens[num_tokens++].value, ")");
                    break;
                case '+':
                    strcpy(tokens[num_tokens].type, "plus");
                    strcpy(tokens[num_tokens++].value, "+");
                    break;
                case '-':
                    strcpy(tokens[num_tokens].type, "minus");
                    strcpy(tokens[num_tokens++].value, "-");
                    break;
                case '*':
                    strcpy(tokens[num_tokens].type, "mul");
                    strcpy(tokens[num_tokens++].value, "*");
                    break;
                case '/':
                    strcpy(tokens[num_tokens].type, "div");
                    strcpy(tokens[num_tokens++].value, "/");
                    break;
                case '=':
                    strcpy(tokens[num_tokens].type, "assign");
                    strcpy(tokens[num_tokens++].value, "=");
                    break;
                case ';':
                    strcpy(tokens[num_tokens].type, "semicolon");
                    strcpy(tokens[num_tokens++].value, ";");
                    break;
            }
        }
    }

    return tokens;
}

// Define a function to parse the input string
bool parse(char* input) {
    Token* tokens = tokenize(input);

    // Check for syntax errors
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];

        // Check for variable declaration
        if (strcmp(tokens[i].type, "identifier") == 0 && 
            strcmp(tokens[i+1].type, "assign") == 0) {
            i += 2;
            if (strcmp(tokens[i].type, "string") != 0)
                return false;
            if (strcmp(tokens[i+1].type, "semicolon") != 0)
                return false;
            i++;
        }

        // Check for addition
        else if (strcmp(tokens[i].type, "identifier") == 0 && 
                 strcmp(tokens[i+1].type, "assign") == 0) {
            i += 2;
            if (strcmp(tokens[i].type, "identifier") != 0)
                return false;
            if (strcmp(tokens[i+1].type, "plus") != 0)
                return false;
            i += 2;
            if (strcmp(tokens[i].type, "identifier") != 0)
                return false;
            if (strcmp(tokens[i+1].type, "semicolon") != 0)
                return false;
            i++;
        }
    }

    free(tokens);

    return true;
}

// Define the main function
int main() {
    char input[MAX_STRING_LENGTH];

    printf("Enter C source code to parse:\n");
    fgets(input, sizeof(input), stdin);

    if (parse(input))
        printf("Input is valid.\n");
    else
        printf("Input is not valid.\n");

    return 0;
}
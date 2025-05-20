//FormAI DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Define a struct to store each token along with its type
typedef struct {
    char* token;
    char* type;
} Token;

// Define a function to check if a string is a keyword
int is_keyword(char* str) {
    char* keywords[] = {"int", "char", "float", "double", "return", "void"};
    int num_keywords = 6;

    for (int i=0; i<num_keywords; i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }

    return 0;
}

// Define a function to check if a string is a valid identifier
int is_identifier(char* str) {
    if (!isalpha(str[0])) {
        return 0;
    }

    for (int i=1; i<strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }

    return 1;
}

// Define a function to tokenize a C program
Token* tokenize(char* program) {
    Token* tokens = malloc(sizeof(Token) * MAX_LENGTH);
    int num_tokens = 0;
    int i = 0;

    while (program[i] != '\0') {
        // Skip whitespace
        if (isspace(program[i])) {
            i++;
            continue;
        }

        // Handle single-character tokens
        switch (program[i]) {
            case ';':
                tokens[num_tokens].token = ";";
                tokens[num_tokens].type = "SEMICOLON";
                num_tokens++;
                i++;
                continue;
            case '(':
                tokens[num_tokens].token = "(";
                tokens[num_tokens].type = "LEFT_PAREN";
                num_tokens++;
                i++;
                continue;
            case ')':
                tokens[num_tokens].token = ")";
                tokens[num_tokens].type = "RIGHT_PAREN";
                num_tokens++;
                i++;
                continue;
            // Handle multi-character tokens
            case '/':
                if (program[i+1] == '/') {
                    // Handle comments
                    while (program[i] != '\n' && program[i] != '\0') {
                        i++;
                    }
                    continue;
                } else {
                    // Handle division operator
                    tokens[num_tokens].token = "/";
                    tokens[num_tokens].type = "DIVIDE";
                    num_tokens++;
                    i++;
                    continue;
                }
            case '+':
                // Handle addition operator
                tokens[num_tokens].token = "+";
                tokens[num_tokens].type = "ADD";
                num_tokens++;
                i++;
                continue;
            case '-':
                // Handle subtraction operator
                tokens[num_tokens].token = "-";
                tokens[num_tokens].type = "SUBTRACT";
                num_tokens++;
                i++;
                continue;
            case '*':
                // Handle multiplication operator
                tokens[num_tokens].token = "*";
                tokens[num_tokens].type = "MULTIPLY";
                num_tokens++;
                i++;
                continue;
            default:
                // Handle literals, keywords, and identifiers
                if (isdigit(program[i])) {
                    // Handle integer and float literals
                    char* str = malloc(sizeof(char) * MAX_LENGTH);
                    int j = 0;

                    while (isdigit(program[i]) || program[i] == '.') {
                        str[j] = program[i];
                        i++;
                        j++;
                    }

                    str[j] = '\0';
                    tokens[num_tokens].token = str;
                    tokens[num_tokens].type = "LITERAL";
                    num_tokens++;
                } else if (isalpha(program[i])) {
                    // Handle keywords and identifiers
                    char* str = malloc(sizeof(char) * MAX_LENGTH);
                    int j = 0;

                    while (isalnum(program[i]) || program[i] == '_') {
                        str[j] = program[i];
                        i++;
                        j++;
                    }

                    str[j] = '\0';

                    if (is_keyword(str)) {
                        tokens[num_tokens].token = str;
                        tokens[num_tokens].type = "KEYWORD";
                    } else if (is_identifier(str)) {
                        tokens[num_tokens].token = str;
                        tokens[num_tokens].type = "IDENTIFIER";
                    } else {
                        printf("Error: invalid token '%s'\n", str);
                        exit(1);
                    }

                    num_tokens++;
                } else {
                    printf("Error: invalid token '%c'\n", program[i]);
                    exit(1);
                }

                continue;
        }
    }

    // Add the end-of-file token
    tokens[num_tokens].token = "";
    tokens[num_tokens].type = "EOF";
    num_tokens++;

    return tokens;
}

// Define a main function to test the program
int main() {
    char* program = "int add(int x, int y) {\n  return x + y;\n}\n";
    Token* tokens = tokenize(program);

    for (int i=0; i<strlen(program); i++) {
        printf("%c", program[i]);
    }

    printf("\n\n");

    for (int i=0; strcmp(tokens[i].type, "EOF") != 0; i++) {
        printf("%s: %s\n", tokens[i].type, tokens[i].token);
    }

    return 0;
}
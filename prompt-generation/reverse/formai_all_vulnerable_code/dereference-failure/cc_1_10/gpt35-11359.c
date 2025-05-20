//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

// Structure to hold token information
struct token {
    char value[MAX_SIZE];
    int type; // 0: Identifier, 1: Keyword, 2: Operator, 3: Constant
};

// Function to determine if a character is an operator
bool isOperator(char c) {
    char operators[] = "+-/*%^()=!<>";
    for(int i=0; i<strlen(operators); i++) {
        if (operators[i] == c) {
            return true;
        }
    }
    return false;
}

// Function to determine if a token is a constant
bool isConstant(char* token) {
    for(int i=0; i<strlen(token); i++) {
        if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

// Function to determine if a token is a keyword
bool isKeyword(char* token) {
    char keywords[][25] = {"auto", "break", "case", "char", "const", 
                            "continue", "default", "do", "double", "else",
                            "enum", "extern", "float", "for", "goto", 
                            "if", "int", "long", "register", "return", 
                            "short", "signed", "sizeof", "static", 
                            "struct", "switch", "typedef", "union", 
                            "unsigned", "void", "volatile", "while"};
    for(int i=0; i<sizeof(keywords)/sizeof(keywords[0]); i++) {
        if (strcmp(keywords[i], token) == 0) {
            return true;
        }
    }
    return false;
}

// Function to parse a line of code into tokens
struct token* parseLine(char* line, int* numTokens) {
    int i = 0;
    char* token;
    struct token* tokens = (struct token*)malloc(sizeof(struct token)*MAX_SIZE);
    token = strtok(line, " ");
    while(token != NULL) {
        // Determine token type
        if (isKeyword(token)) {
            tokens[i].type = 1;
        }
        else if (isOperator(token[0])) {
            tokens[i].type = 2;
        }
        else if (isConstant(token)) {
            tokens[i].type = 3;
        }
        else {
            tokens[i].type = 0;
        }

        // Set token value
        strcpy(tokens[i].value, token);
        token = strtok(NULL, " ");
        i++;
    }
    *numTokens = i;
    return tokens;
}

// Function to print out all the tokens
void printTokens(struct token* tokens, int numTokens) {
    for (int i=0; i<numTokens; i++) {
        printf("Token %d: %s (Type %d)\n", i+1, tokens[i].value, tokens[i].type);
    }
}

int main() {
    char line[MAX_SIZE];
    int numTokens;
    struct token* tokens;

    printf("Enter a line of code to parse:\n");
    fgets(line, sizeof(line), stdin);
    tokens = parseLine(line, &numTokens);
    printTokens(tokens, numTokens);

    free(tokens);
    return 0;
}
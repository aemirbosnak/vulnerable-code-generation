//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure for holding tokens
typedef struct Token {
    char type[20];
    char value[20];
}Token;

// function for tokenizing the input string
Token* tokenize(char* input) {
    Token* tokens = calloc(20, sizeof(Token));
    if (tokens == NULL) {
        printf("Memory allocation error");
        exit(1);
    }

    int i = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        strcpy(tokens[i].value, token);
        if (strcmp(token, "int") == 0 || strcmp(token, "char") == 0 || strcmp(token, "float") == 0) {
            strcpy(tokens[i].type, "DATATYPE");
        }
        else if (strchr(token, '(') != NULL || strchr(token, ')') != NULL || strchr(token, ';') != NULL) {
            strcpy(tokens[i].type, "SYMBOL");
        }
        else {
            strcpy(tokens[i].type, "IDENTIFIER");
        }
        token = strtok(NULL, " ");
        i++;
    }
    strcpy(tokens[i].type, "END");
    strcpy(tokens[i].value, "\0");

    return tokens;
}

// function for parsing the tokens
void parse(Token* tokens) {
    int i = 0;
    while (strcmp(tokens[i].type, "END") != 0) {
        if (strcmp(tokens[i].type, "DATATYPE") == 0 && strcmp(tokens[i+1].type, "IDENTIFIER") == 0 && strcmp(tokens[i+2].type, "SYMBOL") == 0) {
            printf("%s declaration found: %s\n", tokens[i].value, tokens[i+1].value);
        }
        i++;
    }
}

int main() {
    char input[50];
    printf("Enter code snippet to parse: \n");
    fgets(input, 50, stdin);
    // remove new line character from input string
    input[strcspn(input, "\n")] = '\0';
    Token* tokens = tokenize(input);
    parse(tokens);

    return 0;
}
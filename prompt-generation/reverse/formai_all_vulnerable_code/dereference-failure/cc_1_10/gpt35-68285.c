//FormAI DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Data structure for a token
typedef struct {
    char type[20];
    char value[MAX_LEN];
} Token;

// Tokenize the input string
Token* tokenize(char* input) {
    Token* tokens = malloc(MAX_LEN * sizeof(Token));
    char* token;
    int count = 0;
    token = strtok(input, " ");
    while(token != NULL) {
        strcpy(tokens[count].value, token);
        if(strcmp(token, "if") == 0 || strcmp(token, "else") == 0) {
            strcpy(tokens[count].type, "IF_ELSE");
        } else if(strcmp(token, "for") == 0 || strcmp(token, "while") == 0) {
            strcpy(tokens[count].type, "LOOP");
        } else if(token[0] == '{' || token[0] == '}') {
            strcpy(tokens[count].type, "BRACE");
        } else if(token[0] == '(' || token[0] == ')') {
            strcpy(tokens[count].type, "PAREN");
        } else if(token[0] == ';' || token[strlen(token)-1] == ';') {
            strcpy(tokens[count].type, "SEMICOLON");
        } else if(token[0] == '+' || token[0] == '-' || 
                  token[0] == '*' || token[0] == '/') {
            strcpy(tokens[count].type, "OPERATOR");
        } else {
            strcpy(tokens[count].type, "VARIABLE");
        }
        token = strtok(NULL, " ");
        count++;
    }
    tokens[count].type[0] = '\0';
    tokens[count].value[0] = '\0';
    return tokens;
}

// Parse the tokens and determine the syntax
void parse(Token* tokens) {
    int i = 0;
    while(strcmp(tokens[i].type, "") != 0) {
        if(strcmp(tokens[i].type, "IF_ELSE") == 0) {
            printf("IF statement found starting at token %d\n", i);
            while(strcmp(tokens[i].value, ")") != 0) {
                i++;
            }
            while(strcmp(tokens[i].value, "{") != 0) {
                i++;
            }
            printf("IF statement body found starting at token %d\n", i+1);
            while(strcmp(tokens[i].value, "}") != 0) {
                i++;
            }
            printf("IF statement end at token %d\n", i);
        } else if(strcmp(tokens[i].type, "LOOP") == 0) {
            printf("Loop statement found starting at token %d\n", i);
            while(strcmp(tokens[i].value, ")") != 0) {
                i++;
            }
            while(strcmp(tokens[i].value, "{") != 0) {
                i++;
            }
            printf("Loop statement body found starting at token %d\n", i+1);
            while(strcmp(tokens[i].value, "}") != 0) {
                i++;
            }
            printf("Loop statement end at token %d\n", i);
        } else {
            i++;
        }
    }
}

int main() {
    char input[MAX_LEN];
    printf("Enter the code to parse:\n");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = 0;
    Token* tokens = tokenize(input);
    parse(tokens);
    free(tokens);
    return 0;
}
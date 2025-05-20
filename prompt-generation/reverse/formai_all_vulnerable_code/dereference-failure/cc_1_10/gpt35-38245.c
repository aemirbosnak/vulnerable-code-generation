//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 256

char* input; // pointer to input string
int i = 0; // global variable to track position in input string

// parsing recursive descent functions
void parseExpression();
void parseTerm();
void parseFactor();
void parseVariable();
void parseDigit();
void parseOperator();

int main() {
    input = malloc(sizeof(char) * MAX_LENGTH);  // allocate memory for input string
    printf("Enter expression to parse: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;  // remove newline character from input string
    
    parseExpression();  // start parsing
    
    if (i == strlen(input)) {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed at index %d\n", i);
    }
    
    free(input);  // free allocated memory
    return 0;
}

void parseExpression() {
    printf("Expression: ");
    parseTerm();
    while (input[i] == '+' || input[i] == '-') {
        parseOperator();
        parseTerm();
    }
}

void parseTerm() {
    printf("Term: ");
    parseFactor();
    while (input[i] == '*' || input[i] == '/') {
        parseOperator();
        parseFactor();
    }
}

void parseFactor() {
    printf("Factor: ");
    if (isdigit(input[i])) {
        parseDigit();
    } else {
        parseVariable();  // assume character is a variable
    }
}

void parseVariable() {
    printf("Variable: %c\n", input[i++]);
}

void parseDigit() {
    int num = 0;
    printf("Digit: ");
    while (isdigit(input[i])) {
        num = num * 10 + (input[i++] - '0');
    }
    printf("%d\n", num);
}

void parseOperator() {
    printf("Operator: %c\n", input[i++]);
}
//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void parseVariableType(char *variableType);
void parseIdentifier(char *identifier);
void parseAssignment(char *assignmentOperator);
void parseExpression(char *expression);

int main() {
    char input[100];
    char *token;
    const char delimiter[2] = " ";
    printf("Enter a C syntax statement: ");
    fgets(input, 100, stdin);

    /* Parse the variable type */
    token = strtok(input, delimiter);
    parseVariableType(token);

    /* Parse the identifier */
    token = strtok(NULL, delimiter);
    parseIdentifier(token);

    /* Parse the assignment operator */
    token = strtok(NULL, delimiter);
    parseAssignment(token);

    /* Parse the expression */
    token = strtok(NULL, delimiter);
    parseExpression(token);

    printf("Syntax is valid.\n");
    return 0;
}

void parseVariableType(char *variableType) {
    if (strcmp(variableType, "int") == 0 || strcmp(variableType, "char") == 0 || strcmp(variableType, "float") == 0 || strcmp(variableType, "double") == 0) {
        printf("Variable type '%s' is valid.\n", variableType);
    } else {
        printf("Invalid variable type '%s'.\n", variableType);
        exit(0);
    }
}

void parseIdentifier(char *identifier) {
    int i = 0;
    while (identifier[i] != '\0') {
        if (i == 0 && !isalpha(identifier[i])) {
            printf("Identifier '%s' is invalid.\n", identifier);
            exit(0);
        } else if (!isalnum(identifier[i])) {
            printf("Identifier '%s' is invalid.\n", identifier);
            exit(0);
        }
        i++;
    }
    printf("Identifier '%s' is valid.\n", identifier);
}

void parseAssignment(char *assignmentOperator) {
    if (strcmp(assignmentOperator, "=") != 0) {
        printf("Invalid assignment operator '%s'.\n", assignmentOperator);
        exit(0);
    } else {
        printf("Assignment operator '%s' is valid.\n", assignmentOperator);
    }
}

void parseExpression(char *expression) {
    int i = 0;
    int dotCount = 0;
    while (expression[i] != '\0') {
        if (!isdigit(expression[i])) {
            if (expression[i] == '.') {
                dotCount++;
                if (dotCount > 1) {
                    printf("Invalid expression '%s'.\n", expression);
                    exit(0);
                }
            } else {
                printf("Invalid expression '%s'.\n", expression);
                exit(0);
            }
        }
        i++;
    }
    printf("Expression '%s' is valid.\n", expression);
}
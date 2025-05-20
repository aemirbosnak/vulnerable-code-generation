//FormAI DATASET v1.0 Category: Syntax parsing ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isIdentifier(char *);
bool isNumber(char *);
bool isOperator(char *);
bool isEquals(char *);
bool isSemicolon(char *);
bool isLeftParen(char *);
bool isRightParen(char *);
void parseExpression(char **);
void parseStatement(char **);
void parseBlock(char **);
void parseProgram(char **);

int main() {
    char *program = "int main() {\n    int x = 5;\n    int y = 10;\n    int z = x + y;\n    printf(\"Value of z: %d\", z);\n    return 0;\n}\n";
    parseProgram(&program);
    return 0;
}

// Function to check if a given character is a valid identifier character
bool isIdentifierChar(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

// Function to check if a given string is a valid identifier
bool isIdentifier(char *str) {
    char *ptr = str;
    while (*ptr) {
        if (!isIdentifierChar(*ptr)) {
            return false;
        }
        ptr++;
    }
    return true;
}

// Function to check if a given string is a valid number
bool isNumber(char *str) {
    char *ptr = str;
    while (*ptr) {
        if (*ptr < '0' || *ptr > '9') {
            return false;
        }
        ptr++;
    }
    return true;
}

// Function to check if a given string is a valid operator
bool isOperator(char *str) {
    char *operators[] = {"+", "-", "*", "/", "%", "<", ">", "<=", ">=", "==", "!="};
    for (int i = 0; i < 11; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if a given string is an equals sign
bool isEquals(char *str) {
    return strcmp(str, "=") == 0;
}

// Function to check if a given string is a semicolon
bool isSemicolon(char *str) {
    return strcmp(str, ";") == 0;
}

// Function to check if a given string is a left parenthesis
bool isLeftParen(char *str) {
    return strcmp(str, "(") == 0;
}

// Function to check if a given string is a right parenthesis
bool isRightParen(char *str) {
    return strcmp(str, ")") == 0;
}

// Function to parse an expression
void parseExpression(char **ptr) {
    char *token = strtok(*ptr, " ");
    if (isIdentifier(token) || isNumber(token)) {
        token = strtok(NULL, " ");
        if (isOperator(token)) {
            parseExpression(ptr);
            parseExpression(ptr);
        }
    } else if (isLeftParen(token)) {
        parseExpression(ptr);
        token = strtok(NULL, " ");
        if (!isRightParen(token)) {
            printf("Syntax error: expected right parenthesis\n");
        }
    } else {
        printf("Syntax error: unexpected token: %s\n", token);
    }
}

// Function to parse a statement
void parseStatement(char **ptr) {
    char *token = strtok(*ptr, " ");
    if (isIdentifier(token)) {
        token = strtok(NULL, " ");
        if (!isEquals(token)) {
            printf("Syntax error: expected equals sign\n");
            return;
        }
        parseExpression(ptr);
        token = strtok(NULL, " ");
        if (!isSemicolon(token)) {
            printf("Syntax error: expected semicolon\n");
            return;
        }
    } else if (strcmp(token, "printf") == 0) {
        token = strtok(NULL, " ");
        if (!isLeftParen(token)) {
            printf("Syntax error: expected left parenthesis\n");
            return;
        }
        parseExpression(ptr);
        token = strtok(NULL, " ");
        if (!isRightParen(token)) {
            printf("Syntax error: expected right parenthesis\n");
            return;
        }
        token = strtok(NULL, " ");
        if (!isSemicolon(token)) {
            printf("Syntax error: expected semicolon\n");
            return;
        }
    } else {
        printf("Syntax error: unexpected token: %s\n", token);
    }
}

// Function to parse a block
void parseBlock(char **ptr) {
    char *token = strtok(*ptr, " ");
    while (strcmp(token, "}") != 0) {
        if (strcmp(token, "int") == 0) {
            token = strtok(NULL, " ");
            if (!isIdentifier(token)) {
                printf("Syntax error: expected identifier\n");
            }
            token = strtok(NULL, " ");
            if (!isSemicolon(token)) {
                printf("Syntax error: expected semicolon\n");
            }
        } else if (isIdentifier(token)) {
            parseStatement(ptr);
        } else {
            printf("Syntax error: unexpected token: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
}

// Function to parse a program
void parseProgram(char **ptr) {
    char *token = strtok(*ptr, " ");
    while (token != NULL) {
        if (strcmp(token, "int") == 0) {
            token = strtok(NULL, " ");
            if (!isIdentifier(token)) {
                printf("Syntax error: expected identifier\n");
            }
            token = strtok(NULL, " ");
            if (isEquals(token)) {
                parseExpression(ptr);
                token = strtok(NULL, " ");
            }
            if (!isSemicolon(token)) {
                printf("Syntax error: expected semicolon\n");
            }
        } else if (strcmp(token, "{") == 0) {
            parseBlock(ptr);
            token = strtok(NULL, " ");
        } else {
            printf("Syntax error: unexpected token: %s\n", token);
            token = strtok(NULL, " ");
        }
    }
}
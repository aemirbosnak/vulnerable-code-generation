//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_EXPR_LEN 512
#define MAX_NUM_TOKENS 64

typedef enum Token {
    T_NUMBER,
    T_OPERATOR,
    T_PAREN,
    T_FUNCTION,
    T_EOF
} Token;

typedef struct Tokenizer {
    char *expr;
    int pos;
    Token token;
    char value[MAX_EXPR_LEN];
} Tokenizer;

Tokenizer *tokenizer_new(char *expr) {
    Tokenizer *tokenizer = malloc(sizeof(Tokenizer));
    tokenizer->expr = expr;
    tokenizer->pos = 0;
    tokenizer->token = T_EOF;
    return tokenizer;
}

void tokenizer_free(Tokenizer *tokenizer) {
    free(tokenizer);
}

// Get next token
Token tokenizer_next(Tokenizer *tokenizer) {
    // Skip whitespace
    while (tokenizer->expr[tokenizer->pos] == ' ') {
        tokenizer->pos++;
    }

    // Check for end of expression
    if (tokenizer->expr[tokenizer->pos] == '\0') {
        tokenizer->token = T_EOF;
        return T_EOF;
    }

    // Check for number
    if (strchr("0123456789.", tokenizer->expr[tokenizer->pos]) != NULL) {
        int i = 0;
        while (strchr("0123456789.", tokenizer->expr[tokenizer->pos+i]) != NULL) {
            tokenizer->value[i] = tokenizer->expr[tokenizer->pos+i];
            i++;
        }
        tokenizer->value[i] = '\0';
        tokenizer->token = T_NUMBER;
        tokenizer->pos += i;
        return T_NUMBER;
    }

    // Check for operator
    if (strchr("+-*/%^", tokenizer->expr[tokenizer->pos]) != NULL) {
        tokenizer->value[0] = tokenizer->expr[tokenizer->pos];
        tokenizer->value[1] = '\0';
        tokenizer->token = T_OPERATOR;
        tokenizer->pos++;
        return T_OPERATOR;
    }

    // Check for parenthesis
    if (strchr("()", tokenizer->expr[tokenizer->pos]) != NULL) {
        tokenizer->value[0] = tokenizer->expr[tokenizer->pos];
        tokenizer->value[1] = '\0';
        tokenizer->token = T_PAREN;
        tokenizer->pos++;
        return T_PAREN;
    }

    // Check for function
    if (strchr("sincos", tokenizer->expr[tokenizer->pos]) != NULL) {
        int i = 0;
        while (strchr("sincos", tokenizer->expr[tokenizer->pos+i]) != NULL) {
            tokenizer->value[i] = tokenizer->expr[tokenizer->pos+i];
            i++;
        }
        tokenizer->value[i] = '\0';
        tokenizer->token = T_FUNCTION;
        tokenizer->pos += i;
        return T_FUNCTION;
    }

    // Error
    tokenizer->token = T_EOF;
    return T_EOF;
}

// Shunting-yard algorithm
double shunting_yard(Tokenizer *tokenizer) {
    double stack[MAX_NUM_TOKENS];
    int top = 0;
    while (tokenizer->token != T_EOF) {
        switch (tokenizer->token) {
            case T_NUMBER:
                stack[top++] = atof(tokenizer->value);
                break;
            case T_OPERATOR:
                if (top < 2) {
                    printf("Error: Not enough operands for operator %s\n", tokenizer->value);
                    return NAN;
                }
                double op2 = stack[--top];
                double op1 = stack[--top];
                switch (tokenizer->value[0]) {
                    case '+':
                        stack[top++] = op1 + op2;
                        break;
                    case '-':
                        stack[top++] = op1 - op2;
                        break;
                    case '*':
                        stack[top++] = op1 * op2;
                        break;
                    case '/':
                        if (op2 == 0) {
                            printf("Error: Division by zero\n");
                            return NAN;
                        }
                        stack[top++] = op1 / op2;
                        break;
                    case '%':
                        if (op2 == 0) {
                            printf("Error: Division by zero\n");
                            return NAN;
                        }
                        stack[top++] = fmod(op1, op2);
                        break;
                    case '^':
                        stack[top++] = pow(op1, op2);
                        break;
                }
                break;
            case T_PAREN:
                if (tokenizer->value[0] == '(') {
                    top++;
                } else {
                    if (top < 1) {
                        printf("Error: Mismatched parentheses\n");
                        return NAN;
                    }
                    top--;
                }
                break;
            case T_FUNCTION:
                if (top < 1) {
                    printf("Error: Not enough arguments for function %s\n", tokenizer->value);
                    return NAN;
                }
                double arg = stack[--top];
                double result;
                if (strcmp(tokenizer->value, "sin") == 0) {
                    result = sin(arg);
                } else if (strcmp(tokenizer->value, "cos") == 0) {
                    result = cos(arg);
                } else if (strcmp(tokenizer->value, "tan") == 0) {
                    result = tan(arg);
                }
                stack[top++] = result;
                break;
        }
        tokenizer_next(tokenizer);
    }
    if (top != 1) {
        printf("Error: Invalid expression\n");
        return NAN;
    }
    return stack[0];
}

// Read line from stdin
char *readline() {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, stdin);
    return line;
}

int main() {
    printf("Welcome to the Retro Scientific Calculator!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        char *expr = readline();
        if (strcmp(expr, "exit") == 0) {
            break;
        }

        Tokenizer *tokenizer = tokenizer_new(expr);
        double result = shunting_yard(tokenizer);
        tokenizer_free(tokenizer);
        free(expr);

        if (isnan(result)) {
            printf("Error: Invalid expression\n");
        } else {
            printf("%f\n", result);
        }
    }

    printf("Exiting...\n");
    return 0;
}
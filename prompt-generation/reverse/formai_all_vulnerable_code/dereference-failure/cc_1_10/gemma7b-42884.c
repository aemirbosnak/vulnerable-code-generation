//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 255

typedef struct Expression {
    char type;
    union {
        int number;
        struct Identifier {
            char identifier[MAX_IDENTIFIER_LENGTH];
            struct Expression* next;
        } identifier;
    } Union;
} Expression;

Expression* parseExpression(char* expression) {
    Expression* head = NULL;
    Expression* current = NULL;

    // Eat the first character
    expression++;

    // Loop over the remaining characters
    while (*expression) {
        // Check if it's an identifier
        if (isalnum(*expression)) {
            // Create a new identifier expression
            current = malloc(sizeof(Expression));
            current->type = 'i';
            current->Union.identifier.identifier[0] = '\0';
            current->Union.identifier.identifier[0] = *expression;

            // If there's already a current expression, link it to the new one
            if (current) {
                if (head) {
                    current->Union.identifier.next = head;
                }
                head = current;
            }
        }

        // Check if it's a number
        else if (isdigit(*expression)) {
            // Create a new number expression
            current = malloc(sizeof(Expression));
            current->type = 'n';
            current->Union.number = atoi(expression);

            // If there's already a current expression, link it to the new one
            if (current) {
                if (head) {
                    current->Union.identifier.next = head;
                }
                head = current;
            }
        }

        // Eat the current character
        expression++;
    }

    return head;
}

int main() {
    char* expression = "12 + abc";
    Expression* head = parseExpression(expression);

    printf("Expression: ");
    for (Expression* current = head; current; current = current->Union.identifier.next) {
        switch (current->type) {
            case 'n':
                printf("%d ", current->Union.number);
                break;
            case 'i':
                printf("%s ", current->Union.identifier.identifier);
                break;
        }
    }

    printf("\n");

    return 0;
}
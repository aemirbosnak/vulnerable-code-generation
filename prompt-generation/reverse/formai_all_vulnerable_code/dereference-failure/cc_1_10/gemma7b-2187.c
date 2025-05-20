//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IDENTIFIER_LENGTH 255
#define MAX_STATEMENT_LENGTH 1024

typedef struct Node {
    char *identifier;
    struct Node *next;
} Node;

typedef struct Statement {
    Node *variables;
    char *operator;
    Node *operands;
    struct Statement *next;
} Statement;

Statement *parse_statement(char *statement) {
    Statement *statement_node = malloc(sizeof(Statement));
    statement_node->variables = NULL;
    statement_node->operator = NULL;
    statement_node->operands = NULL;
    statement_node->next = NULL;

    // Identify variables
    char *variable_start = strchr(statement, 'a');
    if (variable_start) {
        variable_start = variable_start - 1;
        while (variable_start >= statement && variable_start[0] != ' ') {
            Node *variable_node = malloc(sizeof(Node));
            variable_node->identifier = strdup(variable_start);
            variable_node->next = statement_node->variables;
            statement_node->variables = variable_node;
            variable_start = strchr(variable_start, ' ') - 1;
        }
    }

    // Identify operator
    char *operator_start = strchr(statement, '+');
    if (operator_start) {
        statement_node->operator = strdup(operator_start);
    }

    // Identify operands
    char *operand_start = strchr(statement, '(');
    if (operand_start) {
        operand_start = operand_start - 1;
        while (operand_start >= statement && operand_start[0] != ' ') {
            Node *operand_node = malloc(sizeof(Node));
            operand_node->identifier = strdup(operand_start);
            operand_node->next = statement_node->operands;
            statement_node->operands = operand_node;
            operand_start = strchr(operand_start, ')') - 1;
        }
    }

    return statement_node;
}

int main() {
    char statement[] = "a + 5 (c - d) = 10";
    Statement *statement_node = parse_statement(statement);

    printf("Variables:");
    for (Node *variable = statement_node->variables; variable; variable = variable->next) {
        printf(" %s", variable->identifier);
    }

    printf("\nOperator:");
    printf(" %s", statement_node->operator);

    printf("\nOperands:");
    for (Node *operand = statement_node->operands; operand; operand = operand->next) {
        printf(" %s", operand->identifier);
    }

    printf("\n");

    return 0;
}
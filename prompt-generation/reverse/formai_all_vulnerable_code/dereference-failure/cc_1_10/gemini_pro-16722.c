//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int type;
    union {
        int value;
        struct {
            struct node *left;
            struct node *right;
        } binary;
    } data;
} node;

enum node_type {
    NT_NUMBER,
    NT_BINARY_PLUS,
    NT_BINARY_MINUS,
    NT_BINARY_MULTIPLY,
    NT_BINARY_DIVIDE,
};

node *parse_expression(char **input);

node *parse_number(char **input) {
    int value = 0;
    while (**input >= '0' && **input <= '9') {
        value = value * 10 + **input - '0';
        (*input)++;
    }
    return malloc(sizeof(node));
}

node *parse_binary_operator(char **input, int type) {
    node *left = parse_expression(input);
    node *right = parse_expression(input);
    node *result = malloc(sizeof(node));
    result->type = type;
    result->data.binary.left = left;
    result->data.binary.right = right;
    return result;
}

node *parse_expression(char **input) {
    while (**input == ' ') {
        (*input)++;
    }
    switch (**input) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return parse_number(input);
        case '+':
            return parse_binary_operator(input, NT_BINARY_PLUS);
        case '-':
            return parse_binary_operator(input, NT_BINARY_MINUS);
        case '*':
            return parse_binary_operator(input, NT_BINARY_MULTIPLY);
        case '/':
            return parse_binary_operator(input, NT_BINARY_DIVIDE);
        default:
            fprintf(stderr, "Invalid input: %c\n", **input);
            exit(1);
    }
}

void print_node(node *n) {
    switch (n->type) {
        case NT_NUMBER:
            printf("%d", n->data.value);
            break;
        case NT_BINARY_PLUS:
            print_node(n->data.binary.left);
            printf(" + ");
            print_node(n->data.binary.right);
            break;
        case NT_BINARY_MINUS:
            print_node(n->data.binary.left);
            printf(" - ");
            print_node(n->data.binary.right);
            break;
        case NT_BINARY_MULTIPLY:
            print_node(n->data.binary.left);
            printf(" * ");
            print_node(n->data.binary.right);
            break;
        case NT_BINARY_DIVIDE:
            print_node(n->data.binary.left);
            printf(" / ");
            print_node(n->data.binary.right);
            break;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s expression\n", argv[0]);
        return 1;
    }
    node *tree = parse_expression(&argv[1]);
    print_node(tree);
    printf("\n");
    return 0;
}
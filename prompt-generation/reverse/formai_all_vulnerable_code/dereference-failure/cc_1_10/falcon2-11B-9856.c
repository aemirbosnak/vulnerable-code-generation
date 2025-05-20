//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char *token;
    int precedence;
    struct node *left;
    struct node *right;
} node_t;

int parse(node_t *root, char *expression) {
    node_t *current = root;
    int i = 0;
    while (expression[i]!= '\0') {
        if (isdigit(expression[i])) {
            i++;
            char *num = malloc(i * sizeof(char));
            strncpy(num, expression + i - 1, i);
            current->token = num;
            current->left = NULL;
            current->right = NULL;
            current = current->left;
            i = 0;
        } else if (expression[i] == '(') {
            char *num = malloc(1 * sizeof(char));
            num[0] = '\0';
            current->left = parse(root, expression + i + 1);
            i = i + 1;
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            char *op = malloc(2 * sizeof(char));
            op[0] = expression[i];
            op[1] = '\0';
            current->token = op;
            current->precedence = expression[i] == '+'? 1 : 2;
            current->left = parse(root, expression + i + 1);
            i = i + 1;
        } else {
            fprintf(stderr, "Invalid character: %c\n", expression[i]);
            exit(1);
        }
    }
    if (current->token) {
        current->right = parse(root, expression + i + 1);
    }
    return current;
}

int main() {
    node_t *root = malloc(sizeof(node_t));
    root->token = NULL;
    root->left = NULL;
    root->right = NULL;
    char *expression = "1 + 2 * 3";
    node_t *current = parse(root, expression);
    printf("Parsed expression: %s\n", current->token);
    return 0;
}
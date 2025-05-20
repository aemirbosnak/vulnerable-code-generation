//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_TOKEN_LENGTH 1024
#define MAX_EXPR_DEPTH 10

typedef struct token_t {
    char *text;
    int type;
} token_t;

typedef struct expr_t {
    token_t *left;
    token_t *right;
    int op;
} expr_t;

void parse_expr(char *str, expr_t *expr) {
    int i = 0;
    token_t *token = NULL;

    while (i < strlen(str)) {
        if (str[i] == ' ' || str[i] == '\t') {
            i++;
            continue;
        }

        token = calloc(1, sizeof(token_t));
        token->text = &str[i];

        if (str[i] == '(') {
            expr->left = token;
            i++;
            parse_expr(str + i, &expr->right);
            i += strcspn(str + i, ")");
            expr->op = ')';
        } else if (str[i] == ')') {
            expr->right = token;
            i++;
        } else {
            expr->left = token;
            expr->right = NULL;
            expr->op = str[i];
        }

        break;
    }
}

int main() {
    char str[] = "3 + 4 * 5 - 2";
    expr_t expr;

    parse_expr(str, &expr);

    printf("Expr: %s\n", expr.left->text);
    printf("Op: %c\n", expr.op);
    printf("Right: %s\n", expr.right->text);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <sys/time.h>

#define INF 1000000000
#define MIN 1000000000
#define MAX 0

struct node {
    int val;
    char op;
    struct node *left, *right;
};

typedef struct node node_t;

node_t *parse(char *str) {
    node_t *root = NULL;
    char *p = str;
    char op;
    int val;

    while (*p) {
        if (isdigit(*p)) {
            val = *p - '0';
            p++;
            if (root == NULL) {
                root = (node_t *)malloc(sizeof(node_t));
                root->val = val;
                root->op = '\0';
            } else {
                root->right = (node_t *)malloc(sizeof(node_t));
                root->right->val = val;
                root->right->op = '\0';
            }
        } else if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            op = *p;
            p++;
            if (root == NULL) {
                root = (node_t *)malloc(sizeof(node_t));
                root->val = INF;
                root->op = op;
            } else {
                root->left = (node_t *)malloc(sizeof(node_t));
                root->left->val = INF;
                root->left->op = op;
            }
        } else {
            break;
        }
    }
    return root;
}

void evaluate(node_t *root) {
    if (root == NULL) {
        return;
    }
    if (root->op == '+') {
        evaluate(root->left);
        evaluate(root->right);
        root->val = root->left->val + root->right->val;
    } else if (root->op == '-') {
        evaluate(root->left);
        evaluate(root->right);
        root->val = root->left->val - root->right->val;
    } else if (root->op == '*') {
        evaluate(root->left);
        evaluate(root->right);
        root->val = root->left->val * root->right->val;
    } else if (root->op == '/') {
        evaluate(root->left);
        evaluate(root->right);
        root->val = root->left->val / root->right->val;
    }
}

int main() {
    char str[100];
    sprintf(str, "3 + 4 * 5 - 2 / (1 + 2)");
    node_t *root = parse(str);
    evaluate(root);
    printf("%d\n", root->val);
    return 0;
}
//FormAI DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent tokens in the program
typedef struct {
    char* type;
    char* value;
} Token;

// Create a new token
Token* create_token(char* type, char* value) {
    Token* token = malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

// Separate the input string into tokens
Token** tokenize(char* input) {
    Token** tokens = malloc(strlen(input) * sizeof(Token));
    char* token_str;
    int i = 0;
    while((token_str = strsep(&input, " ")) != NULL) {
        if (strcmp(token_str, "") == 0) {
            continue;
        }
        if (strcmp(token_str, "int") == 0) {
            tokens[i] = create_token("TYPE", "int");
        } else if (strcmp(token_str, "+") == 0) {
            tokens[i] = create_token("PLUS", "+");
        } else if (atoi(token_str) != 0) {
            tokens[i] = create_token("NUM", token_str);
        } else {
            tokens[i] = create_token("VAR", token_str);
        }
        i++;
    }
    return tokens;
}

// Parse the tokens and create tree-like structures
// for each operation and operand
typedef struct Node {
    Token* token;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(Token* token) {
    Node* node = malloc(sizeof(Node));
    node->token = token;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* parse(Token** tokens, int length) {
    Node* root = NULL;
    int i = 0;
    while (i < length) {
        Token* token = tokens[i];
        if (strcmp(token->type, "VAR") == 0) {
            // If the current token is a variable, check if 
            // the next token is a PLUS operator, and if so,
            // create an operation with the variable and the 
            // next number
            if (strcmp(tokens[i+1]->type, "PLUS") == 0) {
                Node* node = create_node(tokens[i+1]);
                node->left = create_node(token);
                node->right = create_node(tokens[i+2]);
                root = node;
                i += 2;
            } else {
                printf("Unexpected token: %s\n", tokens[i+1]->type);
                exit(1);
            }
        }
        i++;
    }
    return root;
}

// Evaluate the expression tree by performing the operations
int evaluate(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (strcmp(root->token->type, "VAR") == 0) {
        return atoi(root->token->value);
    }
    if (strcmp(root->token->type, "PLUS") == 0) {
        return evaluate(root->left) + evaluate(root->right);
    }
    return 0;
}

int main() {
    char input[100];
    printf("Enter an arithmetic expression with variables and integer values: ");
    fgets(input, sizeof(input), stdin);
    Token** tokens = tokenize(input);
    Node* root = parse(tokens, sizeof(tokens)/sizeof(Token));
    int result = evaluate(root);
    printf("Result: %d\n", result);
    return 0;
}
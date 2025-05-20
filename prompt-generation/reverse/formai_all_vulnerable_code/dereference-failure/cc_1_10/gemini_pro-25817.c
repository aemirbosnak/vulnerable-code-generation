//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Data structures representing the syntax tree
typedef struct ParseTreeNode {
    char* value;
    struct ParseTreeNode* left;
    struct ParseTreeNode* right;
} ParseTreeNode;

// Token types
enum TokenType {
    TOKEN_EOF,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN
};

// Token structure
typedef struct Token {
    enum TokenType type;
    char* value;
} Token;

// Parse error handler
void ParseError(const char* message) {
    printf("Parse error: %s\n", message);
    exit(1);
}

// Tokenizer
Token GetNextToken(const char* input) {
    static int index = 0;
    Token token;

    if (input[index] == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }

    while (input[index] == ' ') index++;  // Skip whitespace

    if (isdigit(input[index])) {  // Number
        int start = index;
        while (isdigit(input[index])) index++;
        token.type = TOKEN_NUMBER;
        token.value = strndup(input + start, index - start);
    } else if (isalpha(input[index])) {  // Identifier
        int start = index;
        while (isalpha(input[index])) index++;
        token.type = TOKEN_IDENTIFIER;
        token.value = strndup(input + start, index - start);
    } else {
        switch (input[index]) {
            case '+':
                token.type = TOKEN_PLUS;
                break;
            case '-':
                token.type = TOKEN_MINUS;
                break;
            case '*':
                token.type = TOKEN_MULTIPLY;
                break;
            case '/':
                token.type = TOKEN_DIVIDE;
                break;
            case '(':
                token.type = TOKEN_LPAREN;
                break;
            case ')':
                token.type = TOKEN_RPAREN;
                break;
            default:
                ParseError("Invalid character");
        }

        index++;
        token.value = NULL;
    }

    return token;
}

// Expression parser
ParseTreeNode* ParseExpression(const char* input) {
    Token token = GetNextToken(input);

    if (token.type == TOKEN_EOF) {
        return NULL;  // End of input
    }

    if (token.type == TOKEN_NUMBER || token.type == TOKEN_IDENTIFIER) {
        ParseTreeNode* node = malloc(sizeof(ParseTreeNode));
        node->value = token.value;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (token.type == TOKEN_PLUS || token.type == TOKEN_MINUS || token.type == TOKEN_MULTIPLY || token.type == TOKEN_DIVIDE) {
        ParseTreeNode* node = malloc(sizeof(ParseTreeNode));
        node->value = token.value;
        node->left = ParseExpression(input);
        node->right = ParseExpression(input);
        return node;
    }

    if (token.type == TOKEN_LPAREN) {
        ParseTreeNode* node = ParseExpression(input);
        token = GetNextToken(input);

        if (token.type != TOKEN_RPAREN) {
            ParseError("Expected closing parenthesis");
        }

        return node;
    }

    ParseError("Invalid expression");
}

// Print syntax tree
void PrintSyntaxTree(ParseTreeNode* root) {
    if (root == NULL) return;

    printf("%s ", root->value);
    PrintSyntaxTree(root->left);
    PrintSyntaxTree(root->right);
}

// Free syntax tree
void FreeSyntaxTree(ParseTreeNode* root) {
    if (root == NULL) return;

    FreeSyntaxTree(root->left);
    FreeSyntaxTree(root->right);
    free(root->value);
    free(root);
}

int main() {
    char* input = "1 + 2 * (3 - 4)";

    ParseTreeNode* root = ParseExpression(input);
    PrintSyntaxTree(root);

    FreeSyntaxTree(root);

    return 0;
}
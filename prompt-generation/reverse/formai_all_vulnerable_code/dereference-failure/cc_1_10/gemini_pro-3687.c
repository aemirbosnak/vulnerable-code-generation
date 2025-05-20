//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: artistic
// A tapestry woven with syntax,
// A dance of symbols, an art's genesis.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Keywords, a constellation of meaning,
// Guiding our thoughts, their essence gleaning.
char* keywords[] = {
    "int", "float", "double", "char", "void",
    "if", "else", "while", "do", "for",
    "return", "break", "continue"
};

// Tokens, building blocks of our code,
// Each type a brushstroke, shaping the mode.
typedef enum {
    TK_IDENTIFIER, TK_NUMBER, TK_STRING,
    TK_KEYWORD, TK_OPERATOR, TK_PUNCTUATOR
} TokenType;

// A stream of tokens, a flowing cascade,
// From which we weave our syntax's facade.
typedef struct Token {
    TokenType type;
    char* value;
    struct Token* next;
} Token;

// A lexer, a weaver of tokens from text,
// Decomposing code, unraveling its zest.
Token* lex(char* code) {
    Token* head = NULL;
    Token* tail = NULL;
    char* start = code;
    while (*code) {
        // Skip whitespace and comments
        if (*code == ' ' || *code == '\t' || *code == '\n') {
            code++;
            continue;
        }

        TokenType type;
        // Numbers, a sequence of digits, bold,
        if (isdigit(*code)) {
            type = TK_NUMBER;
            while (isdigit(*code)) code++;
            code--;
        }
        // Strings, enclosed in quotes, their tale untold,
        else if (*code == '"') {
            type = TK_STRING;
            code++;
            while (*code != '"' && *code) code++;
        }
        // Keywords, predefined, their meaning known,
        else if (isalpha(*code)) {
            char buf[256];
            int i = 0;
            while (isalpha(*code)) {
                buf[i++] = *code++;
            }
            buf[i] = '\0';
            code--;
            for (int j = 0; j < sizeof(keywords) / sizeof(char*); j++) {
                if (strcmp(buf, keywords[j]) == 0) {
                    type = TK_KEYWORD;
                    break;
                }
            }
            if (type != TK_KEYWORD) type = TK_IDENTIFIER;
        }
        // Operators, symbols of math's embrace,
        else if (strchr("+-*/%^&|~<>", *code)) {
            type = TK_OPERATOR;
        }
        // Punctuators, grammar's graceful grace,
        else if (strchr("(){};,", *code)) {
            type = TK_PUNCTUATOR;
        } else {
            fprintf(stderr, "Unexpected character: '%c'\n", *code);
            exit(1);
        }

        Token* token = malloc(sizeof(Token));
        token->type = type;
        token->value = strndup(start, code - start + 1);
        token->next = NULL;

        if (!head) head = tail = token;
        else {
            tail->next = token;
            tail = token;
        }

        code++;
        start = code;
    }

    return head;
}

// A parser, a weaver of meaning from tokens,
// Building a tapestry of syntax, it reckons.
typedef struct Node {
    char* value;
    struct Node* left;
    struct Node* right;
} Node;

Node* parse(Token* tokens) {
    Node* root = NULL;
    if (tokens) {
        // Primary expressions, parsing's initial quest,
        if (tokens->type == TK_IDENTIFIER || tokens->type == TK_NUMBER || tokens->type == TK_STRING) {
            root = malloc(sizeof(Node));
            root->value = tokens->value;
            root->left = root->right = NULL;
            tokens = tokens->next;
        }
        // Parentheses, enclosing subexpressions, a nest,
        else if (tokens->type == TK_PUNCTUATOR && tokens->value[0] == '(') {
            tokens = tokens->next;
            root = parse(tokens);
            if (!root) return NULL;
            if (tokens->type != TK_PUNCTUATOR || tokens->value[0] != ')') {
                fprintf(stderr, "Expected ')'\n");
                exit(1);
            }
            tokens = tokens->next;
        }
        // Binary expressions, operators' dance, a blend,
        else if (tokens->type == TK_OPERATOR) {
            Node* left = parse(tokens->next);
            if (!left) return NULL;
            tokens = tokens->next->next;
            Node* right = parse(tokens);
            if (!right) return NULL;
            root = malloc(sizeof(Node));
            root->value = tokens->value;
            root->left = left;
            root->right = right;
        }
    }

    return root;
}

// A pretty-printer, pixels on syntax's screen,
// Displaying the tree, its structure unseen.
void print_node(Node* node, int depth) {
    if (node) {
        for (int i = 0; i < depth; i++) printf("    ");
        printf("%s", node->value);
        if (node->left) {
            printf("\n");
            print_node(node->left, depth + 1);
        }
        if (node->right) {
            printf("\n");
            print_node(node->right, depth + 1);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <code file>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char* code = malloc(1024);
    int len = fread(code, 1, 1024, file);
    fclose(file);

    Token* tokens = lex(code);
    Node* root = parse(tokens);

    print_node(root, 0);

    return 0;
}
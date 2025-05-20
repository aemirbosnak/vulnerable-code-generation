//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char* keyword;
    char* description;
} Token;

Token* createToken(char* keyword, char* description) {
    Token* token = malloc(sizeof(Token));
    token->keyword = strdup(keyword);
    token->description = strdup(description);
    return token;
}

typedef struct {
    Token* token;
    int index;
} TokenNode;

int parseCode(char* code, Token** tokens, int numTokens, TokenNode** tokenNodes) {
    int numNodes = 0;
    char* currentWord = strtok(code, " ");
    while(currentWord != NULL) {
        for(int i = 0; i < numTokens; i++) {
            if(strcmp(currentWord, tokens[i]->keyword) == 0) {
                TokenNode* node = malloc(sizeof(TokenNode));
                node->token = tokens[i];
                node->index = i;
                tokenNodes[numNodes++] = node;
                break;
            }
        }
        currentWord = strtok(NULL, " ");
    }
    return numNodes;
}

int main() {
    // Define the keywords to parse
    Token* tokens[3];
    tokens[0] = createToken("if", "Conditional statement");
    tokens[1] = createToken("else", "Conditional statement");
    tokens[2] = createToken("int", "Data Type");

    // The code to parse
    char* code = "if (1 == 1) {int x = 10;} else {int y = 20;}";

    // Parse the code into token nodes
    TokenNode* tokenNodes[10];
    int numNodes = parseCode(code, tokens, 3, tokenNodes);

    // Print out the tokens and their description
    printf("%d tokens found:\n", numNodes);
    for(int i = 0; i < numNodes; i++) {
        TokenNode* node = tokenNodes[i];
        printf("%s: %s\n", node->token->keyword, node->token->description);
    }

    // Clean up memory allocated for tokens and token nodes
    for(int i = 0; i < 3; i++) {
        free(tokens[i]->keyword);
        free(tokens[i]->description);
        free(tokens[i]);
    }
    for(int i = 0; i < numNodes; i++) {
        free(tokenNodes[i]);
    }

    return 0;
}
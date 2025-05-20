//FormAI DATASET v1.0 Category: Syntax parsing ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

// Data type for the tokens
typedef struct Token{
    char type[10];
    char value[MAX];
}Token;

// Structure for the AST nodes
typedef struct AST{
    char type[10];
    char value[MAX];
    struct AST *left;
    struct AST *right;
}AST;

// Function to tokenize the input string
Token* tokenize(char* input){
    Token *tokens = (Token*)malloc(sizeof(Token) * MAX);
    int i = 0, j = 0;

    while(input[i] != '\0'){
        // Check for whitespace
        if(input[i] == ' '){
            i++;
            continue;
        }

        // Check for numbers
        else if(input[i] >= '0' && input[i] <= '9'){
            tokens[j].type[0] = 'I';
            int k = 0;

            while(input[i] >= '0' && input[i] <= '9'){
                tokens[j].value[k++] = input[i++];
            }

            tokens[j].value[k] = '\0';
            j++;
        }

        // Check for operators
        else{
            tokens[j].type[0] = 'O';
            tokens[j].value[0] = input[i];
            tokens[j].value[1] = '\0';
            j++;
            i++;
        }
    }

    return tokens;
}

// Function to create a new AST node
AST* createNode(char type[], char value[]){
    AST *newNode = (AST*)malloc(sizeof(AST));
    strcpy(newNode->type, type);
    strcpy(newNode->value, value);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to parse the tokens and generate the AST
AST* parse(Token *tokens, int start, int end){
    AST *root = NULL;

    // Base case
    if(start > end){
        return NULL;
    }

    // Single number
    else if(start == end){
        root = createNode("I", tokens[start].value);
        return root;
    }

    // Multiple numbers and operators
    else{
        int openBrackets = 0;
        int closeBrackets = 0;

        // Find the root node
        for(int i = start; i <= end; i++){
            if(tokens[i].type[0] == 'O'){
                if(tokens[i].value[0] == '('){
                    openBrackets++;
                }
                else if(tokens[i].value[0] == ')'){
                    closeBrackets++;
                }
                else if(openBrackets == closeBrackets){
                    // Create new node
                    root = createNode("O", tokens[i].value);

                    // Recursively generate left and right subtrees
                    root->left = parse(tokens, start, i - 1);
                    root->right = parse(tokens, i + 1, end);

                    break;
                }
            }
        }
    }

    return root;
}

// Function to print the AST in inorder traversal
void printAST(AST *root){
    if(root != NULL){
        printAST(root->left);
        printf("%s ", root->value);
        printAST(root->right);
    }
}

// Main function
int main(){
    char input[MAX];
    printf("Enter an arithmetic expression: ");
    fgets(input, MAX, stdin);
    Token *tokens = tokenize(input);
    AST *root = parse(tokens, 0, strlen(input) - 2);
    printf("Inorder traversal of the AST: ");
    printAST(root);
    return 0;
}
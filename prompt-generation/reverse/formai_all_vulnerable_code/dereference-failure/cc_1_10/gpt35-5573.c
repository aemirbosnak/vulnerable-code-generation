//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODE_COUNT 1000

struct Node {
    char symbol;
    int frequency;
    struct Node *left;
    struct Node *right;
};

int nodeCount = 0;
struct Node *nodes[MAX_NODE_COUNT];

void addNode(struct Node *newNode){
   if(nodeCount >= MAX_NODE_COUNT){
        printf("Too many nodes!!\n");
        exit(1);
    }
    nodes[nodeCount] = newNode;
    nodeCount++;
}

void removeNode(struct Node *toRemove){
    bool found = false;
    for(int i=0; i<nodeCount; i++){
        if(found){
            nodes[i-1] = nodes[i];
        }
        else if(nodes[i] == toRemove){
            found = true;
        }
    }
    if(found){
        nodeCount--;
    }
}

void printTree(struct Node *root, int depth){
    char symbol = root->symbol;
    if(symbol == '\0'){
        symbol = '_';
    }
    printf("%*c(%c, %d)\n", depth*4, ' ', symbol, root->frequency);
    if(root->left != NULL){
        printTree(root->left, depth+1);
    }
    if(root->right != NULL){
        printTree(root->right, depth+1);
    }
}

int compare(const void *a, const void *b){
    const struct Node *na = *(const struct Node**)a;
    const struct Node *nb = *(const struct Node**)b;
    return na->frequency - nb->frequency;
}

struct Node* createHuffmanTree(char symbols[], int frequencies[], int count){
    for(int i=0; i<count; i++){
        char symbol = symbols[i];
        int frequency = frequencies[i];
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->symbol = symbol;
        newNode->frequency = frequency;
        newNode->left = NULL;
        newNode->right = NULL;
        addNode(newNode);
    }
    while(nodeCount > 1){
        qsort(nodes, nodeCount, sizeof(struct Node*), compare);
        struct Node *left = nodes[0];
        struct Node *right = nodes[1];
        struct Node *parent = (struct Node*) malloc(sizeof(struct Node));
        parent->symbol = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;
        removeNode(left);
        removeNode(right);
        addNode(parent);
    }
    return nodes[0];
}

void printHuffmanCode(struct Node *root, char code[], int depth){
    if(root->left == NULL && root->right == NULL){
        char symbol = root->symbol;
        if(symbol == '\0'){
            symbol = '_';
        }
        code[depth] = '\0';
        printf("%c: %s\n", symbol, code);
    }
    else{
        if(root->left != NULL){
            code[depth] = '0';
            printHuffmanCode(root->left, code, depth+1);
        }
        if(root->right != NULL){
            code[depth] = '1';
            printHuffmanCode(root->right, code, depth+1);
        }
    }
}

int main(){
    char symbols[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {30, 10, 20, 15, 5, 20};
    int count = sizeof(symbols) / sizeof(symbols[0]);
    struct Node *root = createHuffmanTree(symbols, frequencies, count);
    printTree(root, 0);
    char code[MAX_NODE_COUNT];
    printHuffmanCode(root, code, 0);
    return 0;
}
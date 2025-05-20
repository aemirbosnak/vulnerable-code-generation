//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for Huffman tree
typedef struct node {
    int freq;
    char chr;
    struct node* left;
    struct node* right;
} Node;

// Define a linked list node for storing Huffman codes
typedef struct codeNode {
    char chr;
    char* code;
    struct codeNode* next;
} CodeNode;

// Function to create a new node for Huffman tree
Node* createNode(int freq, char chr) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->freq = freq;
    node->chr = chr;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new node for Huffman codes
CodeNode* createCodeNode(char chr, char* code) {
    CodeNode* node = (CodeNode*) malloc(sizeof(CodeNode));
    node->chr = chr;
    node->code = code;
    node->next = NULL;
    return node;
}

// Function to insert a new node into a linked list
void insertCodeNode(CodeNode** head, CodeNode* node) {
    if (*head == NULL) {
        *head = node;
    } else {
        CodeNode* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

// Function to print Huffman codes
void printCodes(CodeNode* head) {
    printf("Huffman Codes:\n");
    CodeNode* curr = head;
    while (curr != NULL) {
        printf("%c: %s\n", curr->chr, curr->code);
        curr = curr->next;
    }
}

// Function to calculate frequencies of each character in a given string
int* getFrequencies(char* str) {
    int* freqs = (int*) calloc(256, sizeof(int));
    int i;
    for (i = 0; i < strlen(str); i++) {
        freqs[str[i]]++;
    }
    return freqs;
}

// Function to sort an array of nodes in ascending order of frequency
void sortNodes(Node** nodes, int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (nodes[i]->freq > nodes[j]->freq) {
                Node* temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
}

// Function to combine two nodes into one
Node* combineNodes(Node* node1, Node* node2) {
    Node* node = createNode(node1->freq + node2->freq, '\0');
    node->left = node1;
    node->right = node2;
    return node;
}

// Function to build Huffman tree
Node* buildTree(int* freqs) {
    Node* nodes[256] = {NULL};
    int i, j;
    for (i = 0, j = 0; i < 256; i++) {
        if (freqs[i] > 0) {
            nodes[j] = createNode(freqs[i], i);
            j++;
        }
    }
    int size = j;
    while (size > 1) {
        sortNodes(nodes, size);
        Node* node1 = nodes[0];
        Node* node2 = nodes[1];
        nodes[0] = combineNodes(node1, node2);
        nodes[1] = nodes[size - 1];
        size--;
    }
    return nodes[0];
}

// Function to generate Huffman codes for each character in the given tree
void generateCodes(CodeNode** head, Node* node, char* code, int len) {
    if (node->left == NULL && node->right == NULL) {
        char* strCode = (char*) malloc(len + 1);
        strncpy(strCode, code, len);
        strCode[len] = '\0';
        CodeNode* node = createCodeNode(node->chr, strCode);
        insertCodeNode(head, node);
    } else {
        code[len] = '0';
        generateCodes(head, node->left, code, len + 1);
        code[len] = '1';
        generateCodes(head, node->right, code, len + 1);
    }
}

// Function to free memory allocated to Huffman tree
void freeTree(Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// Function to free memory allocated to linked list of Huffman codes
void freeCodeList(CodeNode* head) {
    CodeNode* curr = head;
    while (curr != NULL) {
        CodeNode* temp = curr;
        curr = curr->next;
        free(temp->code);
        free(temp);
    }
}

// Main function
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int* freqs = getFrequencies(str);
    Node* tree = buildTree(freqs);
    CodeNode* codes = NULL;
    char code[256] = {'\0'};
    generateCodes(&codes, tree, code, 0);
    printCodes(codes);
    freeTree(tree);
    freeCodeList(codes);
    free(freqs);
    return 0;
}
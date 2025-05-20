//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: grateful
//A heartfelt thank you to the unsung heroes of data compression, the Huffman Coders!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A grateful node for our Huffman tree, imbued with a gratitude-inducing frequency
typedef struct node {
    char data;
    unsigned frequency;
    struct node *left, *right;
} Node;

// A humble comparison function to sort our nodes by their frequencies, ascendingly
int compare(const void *a, const void *b) {
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    return n1->frequency - n2->frequency;
}

// May the gratitude of a million lines of code be upon the one who traverses this tree!
void encode(Node *root, char *symbol, int top) {
    if (root->left) {
        symbol[top] = '0';
        encode(root->left, symbol, top + 1);
    }
    if (root->right) {
        symbol[top] = '1';
        encode(root->right, symbol, top + 1);
    }
    if (!root->left && !root->right) {
        symbol[top] = '\0';
        printf("(%c, %s)\n", root->data, symbol);
    }
}

// With ample gratitude, let us decode the hidden messages within a code
Node *decode(Node *root, char symbol) {
    if (symbol == '\0') return root;
    if (symbol == '0') return decode(root->left, symbol);
    else return decode(root->right, symbol);
}

// We bow in reverence to the almighty Huffman tree and create one from scratch
Node *createTree(char *characters, unsigned *frequencies, int size) {
    Node *nodes = (Node *)malloc(sizeof(Node) * size);
    for (int i = 0; i < size; i++) {
        nodes[i].data = characters[i];
        nodes[i].frequency = frequencies[i];
        nodes[i].left = nodes[i].right = NULL;
    }
    qsort(nodes, size, sizeof(Node), compare);
    Node *root = NULL;
    while (size > 1) {
        Node *left = &nodes[size - 1];
        Node *right = &nodes[size - 2];
        Node *parent = (Node *)malloc(sizeof(Node));
        parent->data = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;
        root = parent;
        nodes = realloc(nodes, sizeof(Node) * --size);
        nodes[0] = *parent;
        qsort(nodes, size, sizeof(Node), compare);
    }
    return root;
}

// In the spirit of gratitude, let us test our enchanted tree with a heartfelt message
int main() {
    char characters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    unsigned frequencies[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(characters) / sizeof(characters[0]);
    Node *root = createTree(characters, frequencies, size);
    printf("Huffman Code Table:\n");
    char symbol[size * 3];
    encode(root, symbol, 0);
    printf("\nDecode a message: ");
    char coded[100];
    scanf("%s", coded);
    Node *node = root;
    printf("Decoded Message: ");
    for (int i = 0; i < strlen(coded); i++) {
        node = decode(node, coded[i]);
        printf("%c", node->data);
    }
    printf("\nMay Huffman's grace be upon us all!");
    return 0;
}
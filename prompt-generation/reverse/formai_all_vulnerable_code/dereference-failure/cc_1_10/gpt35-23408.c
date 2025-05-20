//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Define the maximum number of characters in the input */
#define MAX_CHARACTERS 256

/* Define the node structure for the Huffman tree */
typedef struct node {
    char character;
    int frequency;
    struct node* left;
    struct node* right;
} Node;

/* Define the structure for each Huffman code */
typedef struct code {
    char character;
    char* bits;
} Code;

/* Define the function to create a new node for the Huffman tree */
Node* newNode(char character, int frequency) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Define the comparison function for the Huffman tree priority queue */
int compare(const void* a, const void* b) {
    Node** nodeA = (Node**)a;
    Node** nodeB = (Node**)b;
    return (*nodeA)->frequency - (*nodeB)->frequency;
}

/* Define the function to build the Huffman tree */
Node* buildTree(int* frequencies) {
    Node* tree[MAX_CHARACTERS];
    int i, count = 0;

    /* Create a priority queue using nodes of characters with non-zero frequencies */
    for (i = 0; i < MAX_CHARACTERS; i++) {
        if (frequencies[i] > 0) {
            tree[count++] = newNode((char)i, frequencies[i]);
        }
    }
    while (count > 1) {
        /* Sort the nodes by frequency */
        qsort(tree, count, sizeof(Node*), compare);
        /* Create a new node with the two smallest frequencies as its children */
        Node* left = tree[0];
        Node* right = tree[1];
        Node* parent = newNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        /* Remove the two smallest frequencies from the queue and add the new node to the queue */
        tree[0] = parent;
        tree[1] = tree[--count];
    }
    /* The remaining node in the queue is the root of the Huffman tree */
    return tree[0];
}

/* Define the function to generate the Huffman codes */
void generateCodes(Node* node, char* bits, int depth, Code* codes) {
    if (node->left != NULL) {
        /* Recursive case for internal nodes */
        bits[depth] = '0';
        generateCodes(node->left, bits, depth + 1, codes);
        bits[depth] = '1';
        generateCodes(node->right, bits, depth + 1, codes);
    } else {
        /* Base case for leaf nodes */
        int i;
        for (i = 0; i < strlen(bits); i++) {
            codes[node->character].bits[i] = bits[i];
        }
        codes[node->character].bits[i] = '\0';
    }
}

/* Define the main function */
int main() {
    int frequencies[MAX_CHARACTERS] = {0};
    char* input = "This is an example program for Huffman coding implementation.";
    int i;

    /* Calculate the frequency of each character in the input */
    for (i = 0; i < strlen(input); i++) {
        frequencies[(int)input[i]]++;
    }

    /* Build the Huffman tree */
    Node* tree = buildTree(frequencies);

    /* Generate the Huffman codes */
    char bits[MAX_CHARACTERS] = {'\0'};
    Code codes[MAX_CHARACTERS];
    for (i = 0; i < MAX_CHARACTERS; i++) {
        codes[i].character = (char)i;
        codes[i].bits = (char*)malloc(sizeof(char) * MAX_CHARACTERS);
    }
    generateCodes(tree, bits, 0, codes);

    /* Print the Huffman codes for each character */
    printf("Huffman codes:\n");
    for (i = 0; i < MAX_CHARACTERS; i++) {
        if (frequencies[i] > 0) {
            printf("%c: %s\n", codes[i].character, codes[i].bits);
        }
    }

    /* Free memory */
    for (i = 0; i < MAX_CHARACTERS; i++) {
        free(codes[i].bits);
    }
    free(tree);

    return 0;
}
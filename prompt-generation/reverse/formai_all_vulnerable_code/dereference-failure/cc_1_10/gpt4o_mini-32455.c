//GPT-4o-mini DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The tree magic for our Huffman coding adventure
struct Node {
    char character;    // The character we're encoding
    int frequency;     // How much the character shows up
    struct Node *left; // Left potion in our tree
    struct Node *right;// Right potion in our tree
};

struct Node* createNode(char character, int frequency) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// A silly comparison function for our funny min-heap
int compare(const void* a, const void* b) {
    return ((struct Node*)a)->frequency - ((struct Node*)b)->frequency;
}

// A very clever function that heroicly builds the Huffman tree
struct Node* buildHuffmanTree(char characters[], int frequencies[], int size) {
    // Behold! Our very own heap array!
    struct Node** heapArray = (struct Node**)malloc(size * sizeof(struct Node*));
    
    for (int i = 0; i < size; i++) {
        heapArray[i] = createNode(characters[i], frequencies[i]);
    }

    // Who needs sorting? Let's just build!
    while (size > 1) {
        qsort(heapArray, size, sizeof(struct Node*), compare);
        
        struct Node* left = heapArray[0];
        struct Node* right = heapArray[1];
        struct Node* newNode = createNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        heapArray[0] = newNode;
        heapArray[1] = heapArray[size - 1]; // Hug goodbye to the last element
        size--; // One less poof in our array
    }

    struct Node* root = heapArray[0];
    free(heapArray);
    return root;
}

// The magical reciter that assigns codes to characters
void printHuffmanCodes(struct Node* root, int arr[], int top) {
    // Did you hear about the character who kept running away? It was 'separation anxiety'!
    if (root->left) {
        arr[top] = 0; // Left dive!
        printHuffmanCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1; // Right reliever!
        printHuffmanCodes(root->right, arr, top + 1);
    }
    
    if (!(root->left) && !(root->right)) {
        // Here we go - let’s show off our characters
        printf("Character: %c, Huffman Code: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]); // It's just like Morse code but cooler!
        }
        printf("\n");
    }
}

// A dizzy function to free the memory
void freeHuffmanTree(struct Node* root) {
    if (root) {
        freeHuffmanTree(root->left);
        freeHuffmanTree(root->right);
        free(root);
    }
}

// And now, the dramatic main event!
int main() {
    // Characters and their enlightened frequencies
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);
    
    // Building excitement with our Huffman tree
    struct Node* root = buildHuffmanTree(characters, frequencies, size);
    
    // What’s this? Memory decoded!
    int arr[100], top = 0;
    
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);
    
    // Time to say farewell to our tree
    freeHuffmanTree(root);
    return 0;
}
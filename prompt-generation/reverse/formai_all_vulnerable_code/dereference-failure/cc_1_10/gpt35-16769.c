//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Romeo and Juliet
// 'Tis a tale of fair Romeo and his love,
// The fair and gentle Juliet, 'twas sent from above.
// They wished to keep their words from prying eyes,
// So they turned to Huffman coding, to their surprise.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a tree for the Huffman coding.
struct Tree {
    unsigned freq;
    char letter;
    struct Tree *left, *right;
};

// Create a new tree node.
struct Tree* new_node(char letter, unsigned freq) {
    struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
    node->left = node->right = NULL;
    node->letter = letter;
    node->freq = freq;
    return node;
}

// A comparison function for sorting the tree nodes.
int compare(const void* a, const void* b) {
    struct Tree* x = *(struct Tree**)a;
    struct Tree* y = *(struct Tree**)b;
    return x->freq - y->freq;
}

// A function to create the Huffman tree.
struct Tree* create_tree(char letter[], int freq[], int n) {
    struct Tree *left, *right, *top;
    int i = 0;

    // Allocate space for the tree nodes.
    struct Tree** nodes = (struct Tree**)malloc(n * sizeof(struct Tree*));

    // Create the nodes and add them to the nodes array.
    for(i = 0; i < n; i++) {
        nodes[i] = new_node(letter[i], freq[i]);
    }

    // Sort the nodes by their frequency.
    qsort(nodes, n, sizeof(struct Tree*), compare);

    // Build the tree until only one node remains.
    while (n > 1) {
        left = nodes[0];
        right = nodes[1];

        // Create a new node with the sum of the two nodes frequencies.
        top = new_node('$', left->freq + right->freq);

        // Make the left and right nodes children of the new node.
        top->left = left;
        top->right = right;

        // Remove the two processed nodes from the nodes array.
        nodes[0] = top;
        nodes[1] = nodes[n-1];
        n--;

        // Re-sort the nodes by their frequency.
        qsort(nodes, n, sizeof(struct Tree*), compare);
    }

    // Return the root of the tree.
    return nodes[0];
}

// A function to print the Huffman codes for each letter.
void print_codes(struct Tree* root, int arr[], int top) {
    // Base case: leaf node.
    if (root->left == NULL && root->right == NULL) {
        printf("%c : ", root->letter);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }

    // Traverse left and add 0 to the path.
    arr[top] = 0;
    print_codes(root->left, arr, top + 1);

    // Traverse right and add 1 to the path.
    arr[top] = 1;
    print_codes(root->right, arr, top + 1);
}

// The main function of the tale - Romeo and Juliet
int main() {
    char letters[] = {'r', 'o', 'm', 'e', 'j', 'u', 'l', 't', 'i'};
    int frequencies[] = {2, 4, 1, 3, 1, 3, 1, 2, 2};
    int n = sizeof(letters)/sizeof(letters[0]);

    // Create the Huffman tree.
    struct Tree* root = create_tree(letters, frequencies, n);

    // Print the Huffman codes for each letter.
    int arr[100], top = 0;
    printf("Huffman Codes for Romeo and Juliet:\n");
    print_codes(root, arr, top);

    return 0;
}
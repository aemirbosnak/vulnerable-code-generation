//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Node of tree
struct node {
    char c;                  // Character stored in node
    int freq;               // Frequency of character
    struct node* left;   // Pointer to left subtree
    struct node* right; // Pointer to right subtree
};

// Create new node
struct node* create_node(char c, int freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->c = c;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Create array of nodes from characters and their frequencies
struct node** create_array(char chars[], int freqs[], int n) {
    struct node** arr = (struct node**)malloc(n * sizeof(struct node*));
    int i;
    for(i = 0; i < n; i++) {
        arr[i] = create_node(chars[i], freqs[i]);
    }
    return arr;
}

// Swap nodes
void swap_nodes(struct node** a, struct node** b) {
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort nodes in array
void sort_array(struct node** arr, int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j]->freq > arr[j+1]->freq) {
                swap_nodes(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Build Huffman tree
struct node* build_huffman_tree(struct node** arr, int n) {
    int size = n;
    while(size > 1) {
        sort_array(arr, size);
        struct node* left = arr[0];
        struct node* right = arr[1];
        int freq = left->freq + right->freq;
        struct node* temp = create_node('$', freq);
        temp->left = left;
        temp->right = right;
        arr[0] = temp;
        int i;
        for(i = 1; i < size-1; i++) {
            arr[i] = arr[i+1];
        }
        size--;
    }
    return arr[0];
}

// Print Huffman code for each character in tree
void print_codes(struct node* root, char code[], int depth) {
    if(root->left) {
        code[depth] = '0';
        print_codes(root->left, code, depth+1);
    }
    if(root->right) {
        code[depth] = '1';
        print_codes(root->right, code, depth+1);
    }
    if(!root->left && !root->right) {
        code[depth] = '\0';
        printf("%c: %s\n", root->c, code);
    }
}

// Main function
int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freqs[] = {3, 9, 6, 5, 2, 1};
    int n = sizeof(chars)/sizeof(chars[0]);
    struct node** arr = create_array(chars, freqs, n);
    struct node* root = build_huffman_tree(arr, n);
    char code[n];
    print_codes(root, code, 0);
    return 0;
}
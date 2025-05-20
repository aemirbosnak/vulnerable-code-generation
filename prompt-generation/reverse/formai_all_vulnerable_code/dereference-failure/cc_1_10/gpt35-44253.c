//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct huff_node {
    int data;
    struct huff_node* left;
    struct huff_node* right;
};

struct freq_node {
    char character;
    int freq;
};

int freq_cmp(const void* a, const void* b) {
    return ((struct freq_node*)a)->freq - ((struct freq_node*)b)->freq;
}

void print_code(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void generate_codes(struct huff_node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        generate_codes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        generate_codes(root->right, arr, top + 1);
    }
    
    if (!root->left && !root->right) {
        printf("%d: ", root->data);
        print_code(arr, top);
    }
}

void huffman_code(struct freq_node freq[], int n) {
    struct huff_node *left, *right, *top;
    int i, j, k;
    int arr[n];
    qsort(freq, n, sizeof(struct freq_node), freq_cmp); 
    
    struct huff_node* node[n];
 
    for (i = 0; i < n; i++) {
        node[i] = (struct huff_node*) malloc(sizeof(struct huff_node));
        node[i]->data = freq[i].freq;
        node[i]->left = NULL;
        node[i]->right = NULL;
    }
    
    while (n > 1) {
        left = node[0];
        right = node[1];
        top = (struct huff_node*) malloc(sizeof(struct huff_node));
        top->data = left->data + right->data;
        top->left = left;
        top->right = right;
 
        for (i = 0; i < n-1; i++) {
            if (top->data > node[i+1]->data) {
                node[i] = node[i+1];
            } else {
                break;
            }
        }
        node[i] = top;
        n--;
    }
    generate_codes(node[0], arr, 0);
}

void main() {
    struct freq_node freq[] = { {'a', 5}, {'b', 9}, {'c', 12}, {'d', 13},
                                {'e', 16}, {'f', 45} };
    int n = sizeof(freq)/sizeof(freq[0]);
    huffman_code(freq, n);
    printf("I am surprised that the Huffman Coding program compiled and ran without any errors!\n");
}
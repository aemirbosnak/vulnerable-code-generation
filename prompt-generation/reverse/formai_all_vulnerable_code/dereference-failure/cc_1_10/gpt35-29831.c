//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

struct node {
    char symbol;
    int frequency;
    struct node *left, *right;
};

struct node* create_node(char symbol, int frequency) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->symbol = symbol;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

void print_codes(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top+1);
    }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top+1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->symbol);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void huffman_encoding(char symbols[], int frequencies[], int n) {
    struct node *left, *right, *top;
    int arr[MAX_TREE_HT], top_index = 0;

    struct node** nodes = (struct node**)malloc(n * sizeof(struct node*));
    for (int i = 0; i < n; i++)
        nodes[i] = create_node(symbols[i], frequencies[i]);

    while (n > 1) {
        left = nodes[n-1];
        right = nodes[n-2];

        top = create_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        nodes[n-2] = top;
        n--;
        
        for (int i = n-2; i >= 0; i--) {
            if (nodes[i]->frequency > top->frequency) {
                nodes[i+1] = nodes[i];
            } else {
                nodes[i+1] = top;
                break;
            }
            if (i == 0) nodes[i] = top;
        }
    }
    print_codes(nodes[0], arr, top_index);
}

int main() {
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(symbols)/sizeof(symbols[0]);

    huffman_encoding(symbols, frequencies, n);

    return 0;
}
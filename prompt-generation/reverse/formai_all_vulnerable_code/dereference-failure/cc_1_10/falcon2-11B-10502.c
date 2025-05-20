//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int symbol;
    int freq;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* root, int symbol, int freq) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        root = newNode;
    } else {
        struct Node* curr = root;
        while (1) {
            if (symbol < curr->symbol) {
                if (curr->left == NULL) {
                    curr->left = newNode;
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == NULL) {
                    curr->right = newNode;
                    break;
                }
                curr = curr->right;
            }
        }
    }

    return root;
}

int calculateFrequency(struct Node* root) {
    int frequency = 0;
    if (root!= NULL) {
        frequency = root->freq;
        frequency += calculateFrequency(root->left);
        frequency += calculateFrequency(root->right);
    }
    return frequency;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 'a', 4);
    root = insert(root, 'b', 3);
    root = insert(root, 'c', 2);
    root = insert(root, 'd', 1);

    printf("Frequency of all symbols: %d\n", calculateFrequency(root));

    return 0;
}
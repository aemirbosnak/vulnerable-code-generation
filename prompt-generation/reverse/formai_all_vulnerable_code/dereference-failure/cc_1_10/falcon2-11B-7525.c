//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char bit;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char bit, int freq) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->bit = bit;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(Node* root) {
    if (root!= NULL) {
        inOrder(root->left);
        printf("%c", root->bit);
        inOrder(root->right);
    }
}

int main() {
    int freq[256] = {0};
    char bits[256] = {0};

    printf("Enter a string: ");
    fgets(bits, 256, stdin);

    for (int i = 0; bits[i]!= '\0'; i++) {
        freq[bits[i]]++;
    }

    Node* root = createNode('\0', 0);
    for (int i = 0; i < 256; i++) {
        if (freq[i]!= 0) {
            Node* temp = root;
            while (temp!= NULL) {
                if (temp->bit == i) {
                    break;
                }
                temp = temp->left;
            }
            if (temp->bit == i) {
                temp->left = createNode(i, freq[i]);
            } else {
                temp->right = createNode(i, freq[i]);
            }
        }
    }

    inOrder(root);
    return 0;
}
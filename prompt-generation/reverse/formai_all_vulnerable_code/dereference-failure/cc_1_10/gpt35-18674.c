//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int freq;
    char data;
    struct node *left, *right;
};

struct node *newNode(char data, int freq) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

void printCodes(struct node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void Huffman(char data[], int freq[], int size) {
    struct node *left, *right, *top;
    left = right = top = NULL;
    struct node *nodes[size];

    for (int i = 0; i < size; i++) {
        nodes[i] = newNode(data[i], freq[i]);
    }

    while (size > 1) {
        left = nodes[size - 1];
        right = nodes[size - 2];

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        size--;
        int i, j;
        for (i = 0; i < size; i++) {
            if (nodes[i]->freq > top->freq) {
                break;
            }
        }
        for (j = size; j > i; j--) {
            nodes[j] = nodes[j - 1];
        }
        nodes[i] = top;
        size++;
    }
    int arr[size];
    printCodes(nodes[0], arr, 0);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Huffman Codes:\n");
    Huffman(data, freq, size);

    return 0;
}
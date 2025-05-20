//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct node {
    int freq;
    char data;
    struct node *left, *right;
};

// function prototypes
void printCodes(struct node*, int[], int);
void heapify(struct node**, int, int);
struct node* buildHuffmanTree(char[], int[], int);
void printHuffmanTree(struct node*, int);

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct node* root = buildHuffmanTree(data, freq, size);

    int codes[size], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, codes, top);

    printf("\nHuffman Tree:\n");
    printHuffmanTree(root, 0);

    return 0;
}

void printCodes(struct node* root, int codes[], int top) {
    if (root->left) {
        codes[top] = 0;
        printCodes(root->left, codes, top + 1);
    }
    
    if (root->right) {
        codes[top] = 1;
        printCodes(root->right, codes, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

void heapify(struct node** arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->freq > arr[largest]->freq) {
        largest = left;
    }

    if (right < n && arr[right]->freq > arr[largest]->freq) {
        largest = right;
    }

    if (largest != i) {
        struct node* temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

struct node* buildHuffmanTree(char data[], int freq[], int size) {
    struct node* arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = malloc(sizeof(struct node));
        arr[i]->freq = freq[i];
        arr[i]->data = data[i];
        arr[i]->left = arr[i]->right = NULL;
    }

    while (size > 1) {
        heapify(arr, size, 0);
        struct node* left = arr[0];
        arr[0] = arr[--size];
        heapify(arr, size, 0);
        struct node* right = arr[0];

        struct node* root = malloc(sizeof(struct node));
        root->freq = left->freq + right->freq;
        root->data = '-';
        root->left = left;
        root->right = right;

        arr[size] = root;
    }

    return arr[0];
}

void printHuffmanTree(struct node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5;

    printHuffmanTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    } 
    if (root->data == '-') {
        printf("%d\n", root->freq);
    } else {
        printf("%c:%d\n", root->data, root->freq);
    }
    printHuffmanTree(root->left, space);
}
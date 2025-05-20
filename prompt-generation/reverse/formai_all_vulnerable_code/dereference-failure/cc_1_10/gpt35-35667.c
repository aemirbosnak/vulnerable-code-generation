//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

// define the structure of a binary tree node
struct Node {
    char value;
    int frequency;
    struct Node* left;
    struct Node* right;
};

// function to create a binary tree node
struct Node* createNode(char value, int frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to swap two nodes
void swap(struct Node** first, struct Node** second) {
    struct Node* temp = *first;
    *first = *second;
    *second = temp;
}

// function to heapify a binary tree
void heapify(struct Node** arr, int length, int index) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    
    if (left < length && arr[left]->frequency > arr[largest]->frequency) {
        largest = left;
    }
    
    if (right < length && arr[right]->frequency > arr[largest]->frequency) {
        largest = right;
    }
    
    if (largest != index) {
        swap(&arr[index], &arr[largest]);
        heapify(arr, length, largest);
    }
}

// function to build a binary tree using a heap
struct Node* buildTree(struct Node** arr, int length) {
    struct Node* root = NULL;
    
    while (length > 1) {
        heapify(arr, length, 0);
        struct Node* left = arr[length-1];
        struct Node* right = arr[length-2];
        struct Node* parent = createNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        arr[length-2] = parent;
        length--;
    }
    
    root = arr[0];
    return root;
}

// function to print code values for each character in Huffman tree
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    
    if (root->value != '\0') {
        printf("%c: ", root->value);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// main function
int main() {
    char str[] = "Hello world!";
    int freq[256] = {0};
    int length = strlen(str);
    
    // calculate frequency of each character
    for (int i = 0; i < length; i++) {
        freq[(int)str[i]]++;
    }
    
    struct Node* arr[256];
    int j = 0;
    
    // create an array of binary tree nodes
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            arr[j] = createNode((char)i, freq[i]);
            j++;
        }
    }
    
    // build a binary tree using the array of binary tree nodes
    struct Node* root = buildTree(arr, j);
    
    int code[256];
    int top = 0;
    
    // print code values for each character in the Huffman tree
    printCodes(root, code, top);
    
    return 0;
}
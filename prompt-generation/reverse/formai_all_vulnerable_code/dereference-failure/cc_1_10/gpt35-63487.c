//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

// Priority queue node structure
struct PQueueNode {
    struct Node *data;
    struct PQueueNode *next;
};

// Function to create new node for Huffman Tree
struct Node* createHuffNode(char ch, int freq, struct Node* left, struct Node* right) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = left;
    temp->right = right;
    return temp;
}

// Function to create a new priority queue node
struct PQueueNode* createPQueueNode(struct Node* data) {
    struct PQueueNode* temp = (struct PQueueNode*)malloc(sizeof(struct PQueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to enQueue a node in the priority queue
void enQueue(struct PQueueNode** head_ref, struct PQueueNode* new_node) {
    if (*head_ref == NULL || (*head_ref)->data->freq >= new_node->data->freq) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        struct PQueueNode* temp = *head_ref;
        while (temp->next != NULL && temp->next->data->freq < new_node->data->freq) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Function to deQueue a node from the priority queue
struct PQueueNode* deQueue(struct PQueueNode** head_ref) {
    if (*head_ref == NULL) {
        return NULL;
    }
    else {
        struct PQueueNode* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        return temp;
    }
}

// Function to check if a node is leaf node
int isLeafNode(struct Node* root) {
    return !(root->left) && !(root->right);
}

// Function to print Huffman codes from the root of a Huffman Tree
void printHuffmanCodes(struct Node* root, int arr[], int top) {
    if (root->left != NULL) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right != NULL) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (isLeafNode(root)) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Function to construct Huffman Tree
struct Node* constructHuffTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct PQueueNode *head, *pQueueNodeLeft, *pQueueNodeRight;
    head = NULL;

    // Create a priority queue with all the leaf nodes
    for (int i = 0; i < size; i++) {
        enQueue(&head, createPQueueNode(createHuffNode(data[i], freq[i], NULL, NULL)));
    }

    // Construct a Huffman Tree
    while (head != NULL && head->next != NULL) {
        pQueueNodeLeft = deQueue(&head);
        pQueueNodeRight = deQueue(&head);
        left = pQueueNodeLeft->data;
        right = pQueueNodeRight->data;
        top = createHuffNode('$', left->freq + right->freq, left, right);
        enQueue(&head, createPQueueNode(top));
    }
    return deQueue(&head)->data;    
}

// main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    int arr[MAX_TREE_HT], top = 0;
    struct Node* root = constructHuffTree(data, freq, size); 
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);
    return 0;
}
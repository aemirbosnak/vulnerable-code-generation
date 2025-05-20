//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

// Struct to hold a character and its frequency
typedef struct Node{
    char c;
    int freq;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* newNode(char c, int freq){
    Node* node = (Node*)malloc(sizeof(Node));
    node->c = c;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to create a priority queue and add nodes to it
void addToQueue(Node** queue, Node* node, int* rear){
    int i;
    if(*rear==0){
        queue[*rear] = node;
        (*rear)++;
    }
    else{
        for(i=*rear-1; i>=0; i--){
            if(node->freq < queue[i]->freq){
                queue[i+1] = queue[i];
            }
            else{
                break;
            }
        }
        queue[i+1] = node;
        (*rear)++;
    }
}

// Function to build the Huffman tree
Node* buildHuffmanTree(char* str, int n){
    Node* queue[n];
    int rear=0, front=0;
    int i;

    // Create nodes for each character and add them to queue
    for(i=0; i<n; i++){
        Node* node = newNode(str[i], 1);
        addToQueue(queue, node, &rear);
    }

    // Combine nodes until there is only one node left
    while(rear-front>1){
        Node* left = queue[front++];
        Node* right = queue[front++];
        Node* parent = newNode('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        addToQueue(queue, parent, &rear);
    }

    return queue[0];
}

// Function to print codes for each character
void printCodes(Node* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if(!root->left && !root->right){
        printf("%c: ", root->c);
        for(int i=0; i<top; i++){
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main(){
    // Get input string from user
    char str[100];
    printf("Enter a string to compress: ");
    scanf("%s", str);

    // Build Huffman tree and print codes
    Node* root = buildHuffmanTree(str, strlen(str));
    int arr[100], top=0;
    printCodes(root, arr, top);

    return 0;
}
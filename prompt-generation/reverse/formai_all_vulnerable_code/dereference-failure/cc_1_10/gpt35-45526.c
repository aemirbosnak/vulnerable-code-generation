//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100000

typedef struct Node{
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

bool isLeaf(Node *node){
    return !node->left && !node->right;
}

Node *createNode(char character, int frequency){
    Node *node = (Node *)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

void enqueue(Node **queue, int *size, int *rear, Node *item){
    queue[*rear] = item;
    *rear = (*rear + 1) % (*size);
}

Node *dequeue(Node **queue, int *size, int *front){
    Node *temp = queue[*front];
    *front = (*front + 1) % (*size);
    return temp;
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

void getCode(Node *root, int arr[], int top, char *codes[]){
    if(root->left){
        arr[top] = 0;
        getCode(root->left, arr, top + 1, codes);
    }
    if(root->right){
        arr[top] = 1;
        getCode(root->right, arr, top + 1, codes);
    }
    if(isLeaf(root)){
        char *code = (char *)calloc(MAX_LEN, sizeof(char));
        for(int i=0; i<top; i++){
            sprintf(code + strlen(code), "%d", arr[i]);
        }
        codes[root->character] = code;
    }
}

void buildHuffmanTree(char *input, char *codes[]){
    int freq[128] = {0};
    for(int i=0; input[i]!='\0'; i++){
        freq[input[i]]++;
    }

    Node **queue = (Node **)malloc(128 * sizeof(Node *));
    int size = 128;
    int front = 0, rear = 0;

    for(int i=0; i<128; i++){
        if(freq[i] != 0){
            enqueue(queue, &size, &rear, createNode(i, freq[i]));
        }
    }

    while(rear - front > 1){
        Node *x = dequeue(queue, &size, &front);
        Node *y = dequeue(queue, &size, &front);
        Node *z = createNode('$', x->frequency + y->frequency);
        z->left = x;
        z->right = y;
        enqueue(queue, &size, &rear, z);
    }

    int arr[MAX_LEN];
    getCode(queue[front], arr, 0, codes);
}

int main(){
    char input[MAX_LEN];
    printf("Enter the input string:\n");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *codes[128] = {NULL};
    buildHuffmanTree(input, codes);

    printf("Huffman Codes for each character:\n");
    for(int i=0; i<128; i++){
        if(codes[i]){
            printf("%c: %s\n", i, codes[i]);
        }
    }

    return 0;
}
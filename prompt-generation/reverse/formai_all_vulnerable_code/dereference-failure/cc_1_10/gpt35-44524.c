//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

typedef struct{
    char data;
    unsigned freq;
    int left, right;
}Node;

typedef struct{
    char item[MAX_TREE_HT];
    int top;
}Stack;

typedef struct{
    Node** arr;
    int size, capacity;
}MinHeap;

Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isStackEmpty(Stack* stack){
    return stack->top == -1;
}

void push(Stack* stack, char item){
    stack->item[++stack->top] = item;
}

char pop(Stack* stack){
    if(isStackEmpty(stack)) return '\0';
    return stack->item[stack->top--];
}

Node* createNode(char data, unsigned freq){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

MinHeap* createMinHeap(int capacity){
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->arr = (Node**)malloc(capacity * sizeof(Node*));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    return minHeap;
}

void swapNode(Node** a, Node** b){
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < minHeap->size && minHeap->arr[left]->freq < minHeap->arr[smallest]->freq){
        smallest = left;
    }

    if(right < minHeap->size && minHeap->arr[right]->freq < minHeap->arr[smallest]->freq){
        smallest = right;
    }

    if(smallest != index){
        swapNode(&minHeap->arr[smallest], &minHeap->arr[index]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap){
    return minHeap->size == 1;
}

Node* extractMin(MinHeap* minHeap){
    Node* temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertNode(MinHeap* minHeap, Node* node){
    ++minHeap->size;
    int index = minHeap->size - 1;

    while(index && node->freq < minHeap->arr[(index - 1) / 2]->freq){
        minHeap->arr[index] = minHeap->arr[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    minHeap->arr[index] = node;
}

void buildMinHeap(MinHeap* minHeap){
    int n = minHeap->size - 1;
    for(int i=(n-1)/2; i>=0; --i){
        minHeapify(minHeap, i);
    }
}

void printArr(int arr[], int n){
    for(int i=0; i<n; ++i){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int isLeaf(Node* root){
    return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    MinHeap* minHeap = createMinHeap(size);
    for(int i=0; i<size; ++i){
        minHeap->arr[i] = createNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

Node* buildHuffmanTree(char data[], int freq[], int size){
    Node *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while(!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(minHeap, top);
    }

    return extractMin(minHeap);
}

void encode(Node* root, char* s, int level, int arr[]){
    if(root){
        if(isLeaf(root)){
            printf("   %c   | %*d | ", root->data, level*2, level);
            printArr(arr, level);
            for(int i=0; i<level; ++i){
                printf("     ");
            }
            printf("    | %s\n", s);
            return;
        }
        arr[level] = 0;
        s[level] = '0';
        encode(root->left, s, level+1, arr);
        arr[level] = 1;
        s[level] = '1';
        encode(root->right, s, level+1, arr);
    }
}

void HuffmanCodes(char data[], int freq[], int size){
    Node* root = buildHuffmanTree(data, freq, size);
    char codes[MAX_TREE_HT];
    int arr[MAX_TREE_HT] = {0};
    printf(" Char  | Freq | Code\n");
    printf("--------------------\n");
    encode(root, codes, 0, arr);
}

int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
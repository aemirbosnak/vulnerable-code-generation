//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 40
#define MAX_LEN 50

typedef struct MinHeapNode{
    char data; 
    unsigned freq; 
    struct MinHeapNode *left, *right; 
} MinHeapNode;

typedef struct MinHeap{
    unsigned size; 
    unsigned capacity; 
    MinHeapNode **array; 
        
} MinHeap;

typedef struct HuffmanCodes{
    char data; 
    char bits[MAX_LEN];
    int length;
} HuffmanCodes;

MinHeapNode* newNode(char data, unsigned freq) 
{ 
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode)); 
    node->left = node->right = NULL; 
    node->data = data; 
    node->freq = freq; 
    return node; 
}

MinHeap* createMinHeap(unsigned capacity) 
{ 
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap)); 
    minHeap->size = 0; 
    minHeap->capacity = capacity; 
    minHeap->array = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*)); 
    return minHeap; 
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) 
{ 
    MinHeapNode* t = *a; 
    *a = *b; 
    *b = t; 
}

void minHeapify(MinHeap* minHeap, int idx) 
{ 
    int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) 
        smallest = left; 

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) 
        smallest = right; 

    if (smallest != idx) { 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
        minHeapify(minHeap, smallest); 
    } 
}

int isSizeOne(MinHeap* minHeap) 
{ 
    return (minHeap->size == 1); 
}

MinHeapNode* extractMin(MinHeap* minHeap) 
{ 
    MinHeapNode* temp = minHeap->array[0]; 
    minHeap->array[0] = minHeap->array[minHeap->size - 1]; 
    --minHeap->size; 
    minHeapify(minHeap, 0); 
    return temp; 
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) 
{ 
    ++minHeap->size; 
    int i = minHeap->size - 1; 
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) { 
        minHeap->array[i] = minHeap->array[(i - 1) / 2]; 
        i = (i - 1) / 2; 
    } 
    minHeap->array[i] = minHeapNode; 
}

void buildMinHeap(MinHeap* minHeap) 
{ 
    int n = minHeap->size - 1; 
    int i; 

    for (i = (n - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i); 
}

int isLeaf(MinHeapNode* root) 
{ 
    return !(root->left) && !(root->right); 
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) 
{ 
    MinHeap* minHeap = createMinHeap(size); 
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]); 
    minHeap->size = size; 
    buildMinHeap(minHeap); 
    return minHeap; 
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
{ 
    MinHeapNode *left, *right, *top; 

    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 

    while (!isSizeOne(minHeap)) { 

        left = extractMin(minHeap); 
        right = extractMin(minHeap); 
        top = newNode('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        insertMinHeap(minHeap, top); 
    } 
    return extractMin(minHeap); 
}

void printCodes(MinHeapNode* root, int arr[], int top,HuffmanCodes arrCodes[]) 
{ 
    if (root->left) { 
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1,arrCodes); 
    } 

    if (root->right) { 
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1,arrCodes); 
    } 

    if (isLeaf(root)) { 
        int i;
        for(i=0;i<top;i++){
            arrCodes[(int)root->data].bits[i]=arr[i]+'0';
        }
        arrCodes[(int)root->data].bits[i]='\0';
        arrCodes[(int)root->data].length=i;
    } 
} 

void HuffmanEncode(char data[], int freq[], int size) 
{ 
    MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    HuffmanCodes arrCodes[size];

    printCodes(root, arr, top,arrCodes); 
    int i,j;
    printf("\nHuffman Codes: \n"); 
    for(i=0;i<size;i++){
        printf("%c: ",data[i]);
        for(j=0;j<arrCodes[(int)data[i]].length;j++){
            printf("%c",arrCodes[(int)data[i]].bits[j]);
        }
        printf("\n");
    }
}

void main()
{
    char arr[] = {'a', 'b', 'c', 'd'};
    int freq[] = {5, 1, 6, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanEncode(arr, freq, size);
}
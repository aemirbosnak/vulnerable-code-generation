//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode{
    char data;
    unsigned freq;
    struct MinHeapNode* left;
    struct MinHeapNode* right;
}MinHeapNode;

typedef struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
}MinHeap;

typedef struct HuffNode{
    char data;
    char* code;
    struct HuffNode* left;
    struct HuffNode* right;
}HuffNode;

typedef struct HuffTree{
    HuffNode* root;
}HuffTree;

MinHeapNode* newNode(char data, unsigned freq){
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap* createMinHeap(unsigned capacity){
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b){
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx){
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap){
    return (minHeap->size == 1);
}

MinHeapNode* extractMin(MinHeap* minHeap){
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq){
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap* minHeap){
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(MinHeapNode* root){
    return !(root->left) && !(root->right) ;
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

HuffNode* createHuffNode(char data, char* code){
    HuffNode* node = (HuffNode*) malloc(sizeof(HuffNode));
    node->data = data;
    node->code = (char*) malloc(strlen(code) * sizeof(char));
    strcpy(node->code, code);
    node->left = node->right = NULL;
    return node;
}

void saveHuffmanCodes(MinHeapNode* root, char* codes[], char* tempCode, int top){
    if (root->left){
        tempCode[top] = '0';
        saveHuffmanCodes(root->left, codes, tempCode, top + 1);
    }
    if (root->right){
        tempCode[top] = '1';
        saveHuffmanCodes(root->right, codes, tempCode, top + 1);
    }
    if (isLeaf(root)){
        char character = root->data;
        int index = character - '\0';
        codes[index] = (char*) malloc((top + 1) * sizeof(char));
        strcpy(codes[index], tempCode);
    }
}

HuffTree* generateHuffmanTree(char data[], int freq[], int size){
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)){
        MinHeapNode* left = extractMin(minHeap);
        MinHeapNode* right = extractMin(minHeap);

        MinHeapNode* top = newNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    char* codes[MAX_TREE_HT];
    char tempCode[MAX_TREE_HT];
    tempCode[0] = '\0';
    saveHuffmanCodes(minHeap->array[0], codes, tempCode, 0);
    HuffTree* huffTree = (HuffTree*) malloc(sizeof(HuffTree));
    huffTree->root = createHuffNode('\0', "");
    for (int i=0;i<size;i++){
        char character = data[i];
        int index = character - '\0';
        HuffNode* curr = huffTree->root;
        for (int j=0;j<strlen(codes[index]);j++){
            if (codes[index][j] == '0'){
                if (curr->left == NULL)
                    curr->left = createHuffNode('\0', "");
                curr = curr->left;
            }else{
                if (curr->right == NULL)
                    curr->right = createHuffNode('\0', "");
                curr = curr->right;
            }
        }
        curr->data = character;
        curr->code = (char*) malloc((strlen(codes[index])+1) * sizeof(char));
        strcpy(curr->code, codes[index]);
    }
    return huffTree;
}

void printHuffmanCodes(HuffNode* root, char* buffer, int level){
    if (root){
        if (root->data){
            printf("%c: %s\n", root->data, buffer);
        }
        buffer[level] = '0';
        printHuffmanCodes(root->left, buffer, level + 1);
        buffer[level] = '1';
        printHuffmanCodes(root->right, buffer, level + 1);
    }
}

int main(){
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data)/sizeof(data[0]);
  HuffTree* huffTree = generateHuffmanTree(data, freq, size);
  char buffer[MAX_TREE_HT];
  memset(buffer, '\0', sizeof(buffer));
  printHuffmanCodes(huffTree->root, buffer, 0);
  return 0;
}
//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 10

// Huffman tree node
struct MinHeapNode {
	char data;
	unsigned freq;
	struct MinHeapNode *left, *right;
};

// Min heap: Collection of minimum heap nodes
struct MinHeap {
	unsigned size, capacity;
	struct MinHeapNode **array;
};

// Create a new heap node
struct MinHeapNode* newNode(char data, unsigned freq) {
	struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}

// Create a min heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
	struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

// Swap two nodes of the min heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
	struct MinHeapNode* temp = *a;
	*a = *b;
	*b = temp;
}

// Heapify the min heap (i.e. fix heap property)
void minHeapify(struct MinHeap* minHeap, int idx) {
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

// Check if size of heap is 1
int isSizeOne(struct MinHeap* minHeap) {
	return (minHeap->size == 1);
}

// Extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	minHeapify(minHeap, 0);
	return temp;
}

// Insert new node to the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

// Build min heap with given string input
struct MinHeap* buildMinHeap(char data[], int freq[], int size) {
	struct MinHeap* minHeap = createMinHeap(size);
	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);
	minHeap->size = size;
	for (int i = (minHeap->size - 2) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
	return minHeap;
}

// Check if given node is a leaf node
int isLeaf(struct MinHeapNode* root) {
	return !(root->left) && !(root->right);
}

// This function frees memory of each tree node
void freeHuffmanTree(struct MinHeapNode* node){
    if(node == NULL)
        return;
    
    freeHuffmanTree(node->left);
    freeHuffmanTree(node->right);
    free(node);
}

// Build the Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
	struct MinHeapNode *left, *right, *top;
	struct MinHeap* minHeap = buildMinHeap(data, freq, size);
	while (!isSizeOne(minHeap)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top);
	}
	struct MinHeapNode* root = extractMin(minHeap);
	free(minHeap);
	return root;
}

// Print Huffman codes from root of Huffman tree
void printCodes(struct MinHeapNode* root, int arr[], int top) {
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (isLeaf(root)) {
		printf("%c: ", root->data);
		for (int i = 0; i < top; ++i)
			printf("%d", arr[i]);
		printf("\n");
	}
}

// Wrapper function to build the Huffman tree and print codes
void HuffmanCodes(char data[], int freq[], int size) {
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);
    freeHuffmanTree(root);
}

// Test Huffman coding
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size = sizeof(data) / sizeof(data[0]);
	HuffmanCodes(data, freq, size);
	return 0;
}
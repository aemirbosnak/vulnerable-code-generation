//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char character;
    int frequency;
    struct node* left;
    struct node* right;
} node;

typedef struct minheap {
    int size;
    int capacity;
    node** array;
} minheap;

node* create_node(char character, int frequency) {
    node* n = (node*)malloc(sizeof(node));
    n -> character = character;
    n -> frequency = frequency;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

minheap* create_minheap(int capacity) {
    minheap* mh = (minheap*)malloc(sizeof(minheap));
    mh -> size = 0;
    mh -> capacity = capacity;
    mh -> array = (node**)malloc(sizeof(node*) * capacity);
    return mh;
}

void swap(node** a, node** b) {
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void minheapify(minheap* mh, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < mh -> size && mh -> array[left] -> frequency < mh -> array[smallest] -> frequency) {
        smallest = left;
    }
    if (right < mh -> size && mh -> array[right] -> frequency < mh -> array[smallest] -> frequency) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&(mh -> array[i]), &(mh -> array[smallest]));
        minheapify(mh, smallest);
    }
}

int is_size_one(minheap* mh) {
    return (mh -> size == 1);
}

node* extract_min(minheap* mh) {
    node* temp = mh -> array[0];
    mh -> array[0] = mh -> array[mh -> size - 1];
    mh -> size--;
    minheapify(mh, 0);
    return temp;
}

void insert(minheap* mh, node* n) {
    int i = mh -> size;
    mh -> size++;
    while (i && n -> frequency < mh -> array[(i - 1) / 2] -> frequency) {
        mh -> array[i] = mh -> array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    mh -> array[i] = n;
}

int is_leaf(node* n) {
    return !(n -> left) && !(n -> right);
}

minheap* build_minheap(char* characters, int* frequencies, int size) {
    minheap* mh = create_minheap(size);
    for (int i = 0; i < size; i++) {
        node* n = create_node(characters[i], frequencies[i]);
        insert(mh, n);
    }
    return mh;
}

node* build_huffman_tree(char* characters, int* frequencies, int size) {
    node *left, *right, *top;
    minheap* mh = build_minheap(characters, frequencies, size);
    
    while (!is_size_one(mh)) {
        left = extract_min(mh);
        right = extract_min(mh);
        top = create_node('$', left -> frequency + right -> frequency);
        top -> left = left;
        top -> right = right;
        insert(mh, top);
    }
    return extract_min(mh);
}

void print_codes(node* root, int* arr, int top) {
    if (root -> left) {
        arr[top] = 0;
        print_codes(root -> left, arr, top + 1);
    }
    
    if (root -> right) {
        arr[top] = 1;
        print_codes(root -> right, arr, top + 1);
    }
    
    if (is_leaf(root)) {
        printf(" %c ", root -> character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void Huffman_Coding(char* characters, int* frequencies, int size) {
    node* root = build_huffman_tree(characters, frequencies, size);
    int arr[100], top = 0;
    print_codes(root, arr, top);
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);
    Huffman_Coding(characters, frequencies, size);
    return 0;
}
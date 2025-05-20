//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ASCII 256
#define MAX_LEN 32

struct huffman_node {
    char symbol;
    int frequency;
    struct huffman_node *left, *right;
};

typedef struct huffman_node hnode;

struct huffman_queue {
    int size, capacity;
    hnode **array;
};

typedef struct huffman_queue hqueue;

// Function to create a new huffman tree node
hnode* new_node(char symbol, int frequency) {
    hnode *new = (hnode*) malloc(sizeof (hnode));
    new->symbol = symbol;
    new->frequency = frequency;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Function to create a new huffman queue node
hqueue* create_queue(int capacity) {
    hqueue *new = (hqueue*) malloc(sizeof (hqueue));
    new->size = 0;
    new->capacity = capacity;
    new->array = (hnode**) malloc(capacity * sizeof (hnode*));
    return new;
}

// Function to swap two huffman queue nodes
void swap_nodes(hnode **a, hnode **b) {
    hnode *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sift down a huffman queue node
void sift_down(hqueue *que, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < que->size &&
        que->array[left]->frequency < que->array[smallest]->frequency)
        smallest = left;
    if (right < que->size &&
        que->array[right]->frequency < que->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx) {
        swap_nodes(&que->array[smallest], &que->array[idx]);
        sift_down(que, smallest);
    }
}

// Function to insert a new huffman tree node into the queue
void insert_node(hqueue *que, hnode *new) {
    if (que->size == que->capacity) return;
    int i = que->size;
    que->array[i] = new;
    que->size++;
    while (i > 0 && que->array[(i-1)/2]->frequency > que->array[i]->frequency) {
        swap_nodes(&que->array[(i-1)/2], &que->array[i]);
        i = (i-1)/2;
    }
}

// Function to remove the smallest huffman tree node from the queue
hnode* remove_min(hqueue *que) {
    if (que->size == 0) return NULL;
    hnode *min = que->array[0];
    que->array[0] = que->array[que->size-1];
    que->size--;
    sift_down(que, 0);
    return min;
}

// Function to build the huffman tree from the frequency table
hnode* build_tree(int *freq) {
    hqueue *que = create_queue(MAX_ASCII);
    for (int i = 0; i < MAX_ASCII; i++) {
        if (freq[i] > 0) {
            hnode *new = new_node(i, freq[i]);
            insert_node(que, new);
        }
    }
    while (que->size > 1) {
        hnode *left = remove_min(que);
        hnode *right = remove_min(que);
        hnode *new = new_node('$', left->frequency + right->frequency);
        new->left = left;
        new->right = right;
        insert_node(que, new);
    }
    return remove_min(que);
}

// Function to print the huffman codes recursively
void print_codes(hnode *node, int *bits, int depth) {
    if (node->left) {
        bits[depth] = 0;
        print_codes(node->left, bits, depth+1);
    }
    if (node->right) {
        bits[depth] = 1;
        print_codes(node->right, bits, depth+1);
    }
    if (!node->left && !node->right) {
        printf("%c: ", node->symbol);
        for (int i = 0; i < depth; i++)
            printf("%d", bits[i]);
        printf("\n");
    }
}

// Driver function for the huffman coding
void huffman_code(char message[]) {
    int freq[MAX_ASCII] = {0};
    int len = 0;
    while (message[len] != '\0') {
        freq[message[len]]++;
        len++;
    }
    hnode *root = build_tree(freq);
    int bits[MAX_LEN];
    print_codes(root, bits, 0);
}

// Main function to test the huffman coding
int main() {
    char message[] = "hello world";
    huffman_code(message);
    return 0;
}
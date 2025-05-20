//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct huffman_node {
    char data;
    unsigned freq;
    struct huffman_node *left, *right;
};

// Huffman priority queue node
struct pq_node {
    struct huffman_node *node;
    struct pq_node *next;
};

// Huffman tree and priority queue
struct huffman {
    struct huffman_node *root;
    struct pq_node *front, *rear;
};

// function to create a Huffman node
struct huffman_node* new_huffman_node(char data, unsigned freq) {
    struct huffman_node *node = (struct huffman_node*) malloc(sizeof(struct huffman_node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

// function to create a priority queue node
struct pq_node* new_pq_node(struct huffman_node *node) {
    struct pq_node *pq_node = (struct pq_node*) malloc(sizeof(struct pq_node));
    pq_node->node = node;
    pq_node->next = NULL;

    return pq_node;
}

// function to check if priority queue is empty
bool is_pq_empty(struct huffman *huff) {
    return (huff->front == NULL);
}

// function to enqueue a node in the priority queue
void pq_enqueue(struct huffman *huff, struct huffman_node *node) {
    struct pq_node *pq_node = new_pq_node(node);

    if (huff->rear == NULL) {
        huff->front = huff->rear = pq_node;
        return;
    }

    if (node->freq < huff->front->node->freq) {
        pq_node->next = huff->front;
        huff->front = pq_node;

        return;
    }

    if (node->freq > huff->rear->node->freq) {
        huff->rear->next = pq_node;
        huff->rear = pq_node;

        return;
    }

    struct pq_node *temp = huff->front->next;

    while (temp->node->freq < node->freq) {
        temp = temp->next;
    }

    pq_node->next = temp->next;
    temp->next = pq_node;
}

// function to dequeue a node from the priority queue
struct pq_node* pq_dequeue(struct huffman *huff) {
    struct pq_node *temp = huff->front;

    if (huff->front == NULL) {
        return NULL;
    }

    huff->front = huff->front->next;

    if (huff->front == NULL) {
        huff->rear = NULL;
    }

    return temp;
}

// function to create a Huffman tree and return its root
struct huffman_node* build_huffman_tree(char data[], int freq[], int size) {
    struct huffman *huff = (struct huffman*) malloc(sizeof(struct huffman));

    huff->front = huff->rear = NULL;

    for (int i = 0; i < size; ++i) {
        pq_enqueue(huff, new_huffman_node(data[i], freq[i]));
    }

    while (!is_pq_empty(huff) && huff->front->next != NULL) {
        struct huffman_node *left = pq_dequeue(huff)->node;
        struct huffman_node *right = pq_dequeue(huff)->node;

        struct huffman_node *node = new_huffman_node('$', left->freq + right->freq);
        node->left = left;
        node->right = right;

        pq_enqueue(huff, node);
    }

    return pq_dequeue(huff)->node;
}

// function to check if node is a leaf node
bool is_leaf(struct huffman_node *node) {
    return (!node->left && !node->right);
}

// function to print Huffman codes from the root of the tree
void print_huffman_codes(struct huffman_node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_huffman_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_huffman_codes(root->right, arr, top + 1);
    }

    if (is_leaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct huffman_node *root = build_huffman_tree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    print_huffman_codes(root, arr, top);

    return 0;
}
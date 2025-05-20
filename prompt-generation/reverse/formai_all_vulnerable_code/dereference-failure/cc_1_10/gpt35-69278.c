//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of characters that can be encoded
#define MAX_CHARS 256

// define the Huffman tree node structure
struct TreeNode {
    char data;
    int count;
    struct TreeNode* left;
    struct TreeNode* right;
};

// define the Huffman queue node structure
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// define the Huffman queue structure
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// initialize a Huffman queue
struct Queue* init_queue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// check if a Huffman queue is empty
int is_queue_empty(struct Queue* queue) {
    return (queue->front == NULL);
}

// create a new queue node
struct QueueNode* new_queue_node(struct TreeNode* node) {
    struct QueueNode* queue_node = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    queue_node->data = node;
    queue_node->next = NULL;
    return queue_node;
}

// add a new node to a Huffman queue
void enqueue(struct Queue* queue, struct TreeNode* node) {
    struct QueueNode* queue_node = new_queue_node(node);

    if (queue->rear == NULL) {
        queue->front = queue_node;
        queue->rear = queue_node;
        return;
    }

    queue->rear->next = queue_node;
    queue->rear = queue_node;
}

// remove a node from a Huffman queue
struct QueueNode* dequeue(struct Queue* queue) {
    if (is_queue_empty(queue)) {
        return NULL;
    }

    struct QueueNode* queue_node = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return queue_node;
}

// create a new Huffman tree node
struct TreeNode* new_tree_node(char data, int count) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->data = data;
    node->count = count;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// free all memory allocated for a Huffman tree
void free_tree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// build a Huffman tree from an input string
struct TreeNode* build_huffman_tree(char* input, int input_size) {
    // initialize an array to store the counts of each character in the input
    int counts[MAX_CHARS] = {0};

    // calculate the counts of each character in the input
    int i;
    for (i = 0; i < input_size; i++) {
        counts[input[i]]++;
    }

    // create a Huffman tree node for each character with a non-zero count
    struct Queue* queue = init_queue();
    for (i = 0; i < MAX_CHARS; i++) {
        if (counts[i] > 0) {
            struct TreeNode* node = new_tree_node(i, counts[i]);
            enqueue(queue, node);
        }
    }

    // build the Huffman tree by combining the two nodes with the smallest counts
    while (!is_queue_empty(queue)) {
        struct QueueNode* first = dequeue(queue);
        struct QueueNode* second = dequeue(queue);

        if (second == NULL) {
            return first->data;
        }

        struct TreeNode* parent = new_tree_node('\0', first->data->count + second->data->count);
        parent->left = first->data;
        parent->right = second->data;

        enqueue(queue, parent);
    }

    return NULL;
}

// recursive function to print the codes for each character in the Huffman tree
void print_codes(struct TreeNode* root, int* code, int depth) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);

        int i;
        for (i = 0; i < depth; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }

    if (root->left != NULL) {
        code[depth] = 0;
        print_codes(root->left, code, depth + 1);
    }

    if (root->right != NULL) {
        code[depth] = 1;
        print_codes(root->right, code, depth + 1);
    }
}

// print the Huffman codes for each character in the input string
void print_huffman_codes(char* input, int input_size) {
    struct TreeNode* root = build_huffman_tree(input, input_size);

    int code[input_size];
    print_codes(root, code, 0);
    free_tree(root);
}

int main() {
    char input[] = "abracadabra";
    int input_size = sizeof(input) / sizeof(char);

    print_huffman_codes(input, input_size);

    return 0;
}
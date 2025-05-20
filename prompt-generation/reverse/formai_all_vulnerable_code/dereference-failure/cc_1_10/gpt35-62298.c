//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* The struct for each node in the compression tree */
typedef struct node {
    char character; /* The character or symbol stored in the node*/
    int frequency; /* The frequency of appearances of the character or symbol*/
    struct node *left; /* The left child of the node*/
    struct node *right; /* The right child of the node*/
} Node;

/* The struct for the priority queue */
typedef struct queue {
    int size; /* The size of the queue */
    int capacity; /* The capacity of the queue */
    Node **nodes; /* An array to store the pointers to the nodes */
} Queue;

/* The function to create a new node for the compression tree */
Node* new_node(char character, int frequency) {
    Node *node = (Node *) malloc(sizeof(Node));
    node -> character = character;
    node -> frequency = frequency;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

/* The function to create a new queue */
Queue* new_queue(int capacity) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue -> size = 0;
    queue -> capacity = capacity;
    queue -> nodes = (Node **) malloc(capacity * sizeof(Node *));
    return queue;
}

/* The function to swap two nodes in the queue */
void swap_nodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

/* The function to bubble up a node in the queue */
void bubble_up(Queue *queue, int index) {
    while (index > 0 && queue -> nodes[index] -> frequency < queue -> nodes[(index - 1) / 2] -> frequency) {
        swap_nodes(&(queue -> nodes[index]), &(queue -> nodes[(index - 1) / 2]));
        index = (index - 1) / 2;
    }
}

/* The function to sink down a node in the queue */
void sink_down(Queue *queue, int index) {
    int left_child = 2 * index + 1, right_child = 2 * index + 2, smallest = index;
    if (left_child < queue -> size && queue -> nodes[left_child] -> frequency < queue -> nodes[smallest] -> frequency) {
        smallest = left_child;
    }
    if (right_child < queue -> size && queue -> nodes[right_child] -> frequency < queue -> nodes[smallest] -> frequency) {
        smallest = right_child;
    }
    if (smallest != index) {
        swap_nodes(&(queue -> nodes[index]), &(queue -> nodes[smallest]));
        sink_down(queue, smallest);
    }
}

/* The function to add a node to the queue */
void add_node(Queue *queue, Node *node) {
    queue -> nodes[queue -> size] = node;
    queue -> size++;
    bubble_up(queue, queue -> size - 1);
}

/* The function to remove the smallest node from the queue */
Node* remove_min(Queue *queue) {
    Node *min = queue -> nodes[0];
    queue -> nodes[0] = queue -> nodes[queue -> size - 1];
    queue -> size--;
    sink_down(queue, 0);
    return min;
}

/* The function to build the compression tree */
Node* build_tree(Queue *queue) {
    while (queue -> size > 1) {
        Node *left = remove_min(queue);
        Node *right = remove_min(queue);
        Node *parent = new_node('\0', left -> frequency + right -> frequency);
        parent -> left = left;
        parent -> right = right;
        add_node(queue, parent);
    }
    return remove_min(queue);
}

/* The function to recursively print the code for each character in the tree */
void print_codes(Node *root, int *code, int index) {
    if (root -> left == NULL && root -> right == NULL) {
        printf("%c: ", root -> character);
        for (int i = 0; i < index; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    } else {
        code[index] = 0;
        print_codes(root -> left, code, index + 1);
        code[index] = 1;
        print_codes(root -> right, code, index + 1);
    }
}

/* The function to compress a string using the generated codes */
void compress(char *input, Node *root) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        Node *temp = root;
        while (temp -> left != NULL && temp -> right != NULL) {
            if (input[i] == temp -> left -> character) {
                putchar('0');
                temp = temp -> left;
            } else if (input[i] == temp -> right -> character) {
                putchar('1');
                temp = temp -> right;
            }
        }
    }
    printf("\n");
}

int main() {
    /* Example input */
    char input[] = "abracadabra";
    /* Calculate the frequency of each character */
    int frequencies[256] = {0};
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        frequencies[input[i]]++;
    }
    /* Create a queue for the nodes */
    Queue *queue = new_queue(256);
    /* Create a node for each character and add it to the queue */
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            add_node(queue, new_node(i, frequencies[i]));
        }
    }
    /* Build the compression tree */
    Node *root = build_tree(queue);
    /* Print the codes for each character */
    int code[256] = {0};
    print_codes(root, code, 0);
    /* Compress the input string */
    compress(input, root);
    return 0;
}
//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define a Huffman tree node
struct huffman_node {
    char data;
    unsigned weight;
    struct huffman_node *left, *right;
};

// A priority queue node
struct pq_node {
    struct huffman_node *data;
    struct pq_node *next;
};

// A priority queue
struct priority_queue {
    struct pq_node *front, *rear;
};

// Function to create a new Huffman tree node
struct huffman_node *create_huffman_node(char data, unsigned weight) {
    struct huffman_node *node = (struct huffman_node*) malloc(sizeof(struct huffman_node));
    node->data = data;
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

// Function to create a new priority queue node
struct pq_node *create_pq_node(struct huffman_node *data) {
    struct pq_node *node = (struct pq_node*) malloc(sizeof(struct pq_node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create an empty priority queue
struct priority_queue *create_priority_queue() {
    struct priority_queue *queue = (struct priority_queue*) malloc(sizeof(struct priority_queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the priority queue is empty
int is_priority_queue_empty(struct priority_queue *queue) {
    return queue->front == NULL;
}

// Function to insert a new node in the priority queue
void enqueue(struct priority_queue *queue, struct huffman_node *data) {
    struct pq_node *node = create_pq_node(data);
    if(queue->rear == NULL) {
        queue->front = queue->rear = node;
    }
    else if(data->weight < queue->front->data->weight) {
        node->next = queue->front;
        queue->front = node;
    }
    else {
        struct pq_node *temp = queue->front;
        while(temp->next != NULL && temp->next->data->weight <= data->weight) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        if(node->next == NULL) {
            queue->rear = node;
        }
    }
}

// Function to remove the node with the lowest weight from the priority queue
struct huffman_node *dequeue(struct priority_queue *queue) {
    if(!is_priority_queue_empty(queue)) {
        struct pq_node *front = queue->front;
        struct huffman_node *data = front->data;
        queue->front = front->next;
        if(queue->front == NULL) {
            queue->rear = NULL;
        }
        free(front);
        return data;
    }
    return NULL;
}

// Function to build the Huffman tree
struct huffman_node *build_huffman_tree(char data[], unsigned weight[], int n) {
    struct huffman_node *left, *right, *top;
    struct priority_queue *queue = create_priority_queue();
    for(int i=0; i<n; i++) {
        enqueue(queue, create_huffman_node(data[i], weight[i]));
    }
    while(!is_priority_queue_empty(queue)) {
        left = dequeue(queue);
        right = dequeue(queue);
        top = create_huffman_node('$', left->weight + right->weight);
        top->left = left;
        top->right = right;
        enqueue(queue, top);
    }
    return dequeue(queue);
}

// Function to print the Huffman codes
void print_huffman_codes(struct huffman_node *root, int arr[], int top) {
    if(root->left) {
        arr[top] = 0;
        print_huffman_codes(root->left, arr, top+1);
    }
    if(root->right) {
        arr[top] = 1;
        print_huffman_codes(root->right, arr, top+1);
    }
    if(root->data != '$') {
        printf("%c: ", root->data);
        for(int i=0; i<top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Example main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned weight[] = {5, 9, 12, 13, 16, 45};
    int n = 6;
    struct huffman_node *root = build_huffman_tree(data, weight, n);
    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    print_huffman_codes(root, arr, top);
    return 0;
}
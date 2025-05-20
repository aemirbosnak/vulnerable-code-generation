//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the Huffman tree structure
struct huffman_tree
{
    int data;
    unsigned freq;
    struct huffman_tree *left, *right;
};

// Define a priority queue structure
struct priority_queue
{
    unsigned size;
    unsigned capacity;
    struct huffman_tree** array;
};

// Create a new Huffman tree node
struct huffman_tree* create_node(int data, unsigned freq)
{
    struct huffman_tree* node = (struct huffman_tree*) malloc(sizeof(struct huffman_tree));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a priority queue
struct priority_queue* create_queue(unsigned capacity)
{
    struct priority_queue* queue = (struct priority_queue*) malloc(sizeof(struct priority_queue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (struct huffman_tree**) malloc(queue->capacity * sizeof(struct huffman_tree*));
    return queue;
}

// Swap two Huffman tree nodes
void swap(struct huffman_tree** a, struct huffman_tree** b)
{
    struct huffman_tree* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for priority queue
void heapify(struct priority_queue* queue, int index)
{
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    if (left_child < queue->size && queue->array[left_child]->freq < queue->array[smallest]->freq)
        smallest = left_child;
    if (right_child < queue->size && queue->array[right_child]->freq < queue->array[smallest]->freq)
        smallest = right_child;
    if (smallest != index)
    {
        swap(&queue->array[smallest], &queue->array[index]);
        heapify(queue, smallest);
    }
}

// Check if the priority queue contains only one node
int verify_single_node_queue(struct priority_queue* queue)
{
    return queue->size == 1;
}

// Check if the node is a leaf
int check_leaf(struct huffman_tree* node)
{
    return !(node->left) && !(node->right);
}

// Extract the minimum node from the priority queue
struct huffman_tree* extract_minimum(struct priority_queue* queue)
{
    struct huffman_tree* minimum = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    heapify(queue, 0);
    return minimum;
}

// Insert a node into the priority queue
void insert_queue(struct priority_queue* queue, struct huffman_tree* node)
{
    ++queue->size;
    int index = queue->size - 1;
    while (index && node->freq < queue->array[(index - 1)/2]->freq)
    {
        queue->array[index] = queue->array[(index - 1)/2];
        index = (index - 1)/2;
    }
    queue->array[index] = node;
}

// Build Huffman tree
struct huffman_tree* build_tree(int data[], unsigned freq[], int size)
{
    struct huffman_tree *left, *right, *top;
    struct priority_queue* queue = create_queue(size);
    for (int i = 0; i < size; ++i)
        insert_queue(queue, create_node(data[i], freq[i]));
    while (!verify_single_node_queue(queue))
    {
        left = extract_minimum(queue);
        right = extract_minimum(queue);
        top = create_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_queue(queue, top);
    }
    return extract_minimum(queue);
}

// Print Huffman codes for each data
void print_codes(struct huffman_tree* node, int arr[], int top)
{
    if (node->left)
    {
        arr[top] = 0;
        print_codes(node->left, arr, top + 1);
    }
    if (node->right)
    {
        arr[top] = 1;
        print_codes(node->right, arr, top + 1);
    }
    if (check_leaf(node))
    {
        printf("%c: ", node->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Main function
int main()
{
    int data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(data)/sizeof(data[0]);
    struct huffman_tree* root = build_tree(data, freq, size);
    int arr[100], top = 0;
    print_codes(root, arr, top);
    return 0;
}
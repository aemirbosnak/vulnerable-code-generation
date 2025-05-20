//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct node {
    char character;
    int frequency;
    struct node *left, *right;
};

struct priority_queue {
    int size;
    struct node **nodes;
};

/* Function to create a node */
struct node* create_node(char character, int frequency)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->character = character;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

/* Function to min-heapify the priority queue */
void heapify(struct priority_queue *pq, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->nodes[left]->frequency < pq->nodes[smallest]->frequency)
        smallest = left;

    if (right < pq->size && pq->nodes[right]->frequency < pq->nodes[smallest]->frequency)
        smallest = right;

    if (smallest != i) {
        struct node* temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[smallest];
        pq->nodes[smallest] = temp;

        heapify(pq, smallest);
    }
}

/* Function to create a priority queue */
struct priority_queue* create_priority_queue(int capacity)
{
    struct priority_queue *pq = (struct priority_queue *) malloc(sizeof(struct priority_queue));
    pq->size = 0;
    pq->nodes = (struct node **) malloc(capacity * sizeof(struct node *));
    return pq;
}

/* Function to insert a node into the priority queue */
void insert(struct priority_queue *pq, struct node *node)
{
    pq->size += 1;
    int i = pq->size - 1;

    while (i && node->frequency < pq->nodes[(i - 1)/2]->frequency)
    {
        pq->nodes[i] = pq->nodes[(i - 1)/2];
        i = (i - 1)/2;
    }

    pq->nodes[i] = node;
}

/* Function to extract the minimum node from the priority queue */
struct node *extract_min(struct priority_queue *pq)
{
    struct node *node = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size -= 1;
    heapify(pq, 0);
    return node;
}

/* Function to build the Huffman tree */
struct node *build_huffman_tree(char characters[], int frequencies[], int size)
{
    struct node *left, *right, *top;
    struct priority_queue *pq = create_priority_queue(size);

    for (int i = 0; i < size; ++i)
        insert(pq, create_node(characters[i], frequencies[i]));

    while (pq->size != 1)
    {
        left = extract_min(pq);
        right = extract_min(pq);

        top = create_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insert(pq, top);
    }

    return extract_min(pq);
}

/* Function to print the Huffman codes */
void print_codes(struct node *root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

/* Main function */
int main()
{
    char characters[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequencies[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(characters)/sizeof(characters[0]);

    struct node *root = build_huffman_tree(characters, frequencies, size);

    int arr[100], top = 0;
    print_codes(root, arr, top);

    return 0;
}
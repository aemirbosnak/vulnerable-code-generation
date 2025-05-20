//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 256

typedef struct node {
    unsigned char c;
    unsigned int freq;
    struct node *left;
    struct node *right;
} node_t;

typedef struct queue {
    node_t *huff[MAX_NODES];
    int size;
} queue_t;

int frequencies[256];
node_t *nodes[256];
int num_nodes = 0;

void count_frequencies(FILE* fp)
{
    unsigned char c;
    while(fscanf(fp, "%c", &c) != EOF)
        frequencies[c]++;
}

void init_nodes()
{
    for(int i=0; i<256; i++)
        if(frequencies[i] > 0)
            nodes[num_nodes++] = (node_t*)calloc(1, sizeof(node_t));

    for(int i=0; i<num_nodes; i++) {
        nodes[i]->c = (unsigned char)i;
        nodes[i]->freq = frequencies[i];
    }
}

queue_t *create_queue()
{
    queue_t *queue = (queue_t*)calloc(1, sizeof(queue_t));
    queue->size = 0;
    return queue;
}

int left_child(int i) { return 2 * i + 1; }
int right_child(int i) { return 2 * i + 2; }

void min_heapify(queue_t *queue, int i) 
{
    int l = left_child(i), r = right_child(i), smallest = i;
    if(l < queue->size && queue->huff[l]->freq < queue->huff[i]->freq)
        smallest = l;
    if(r < queue->size && queue->huff[r]->freq < queue->huff[smallest]->freq)
        smallest = r;
    if(smallest != i) {
        node_t *temp = queue->huff[i];
        queue->huff[i] = queue->huff[smallest];
        queue->huff[smallest] = temp;
        min_heapify(queue, smallest);
    }
}

void enqueue(queue_t *queue, node_t *node)
{
    queue->huff[queue->size++] = node;
    for(int i=queue->size/2 - 1; i>=0; i--)
        min_heapify(queue, i);
}

node_t *dequeue(queue_t *queue)
{
    node_t *node = queue->huff[0];
    queue->huff[0] = queue->huff[queue->size-1];
    queue->size--;
    min_heapify(queue, 0);
    return node;
}

node_t *create_huff_tree()
{
    queue_t *queue = create_queue();
    for(int i=0; i<num_nodes; i++)
        enqueue(queue, nodes[i]);

    while(queue->size > 1) {
        node_t *l = dequeue(queue);
        node_t *r = dequeue(queue);

        node_t *combined = (node_t*)calloc(1, sizeof(node_t));
        combined->freq = l->freq + r->freq;
        combined->left = l;
        combined->right = r;
        enqueue(queue, combined);
    }
    return dequeue(queue);
}

void print_codes(node_t *root, char *buf, int depth)
{
    if(root == NULL)
        return;

    // leaf node
    if(root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->c, buf);
        return;
    }

    buf[depth] = '0';
    print_codes(root->left, buf, depth+1);

    buf[depth] = '1';
    print_codes(root->right, buf, depth+1);
}

void huffman_encoding(FILE* in, FILE* out)
{
    char buf[CHAR_BIT] = {0};
    unsigned char c;
    while(fscanf(in, "%c", &c) != EOF) {
        for(int i=0; i<num_nodes; i++) {
            if(nodes[i]->c == c) {
                print_codes(nodes[i], buf, 0);
                break;
            }
        }
    }
}

void free_tree(node_t *root)
{
    if(root) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main(int argc, char **argv)
{
    if(argc != 3) {
        printf("Usage: %s <Input File> <Output File>\n", argv[0]);
        exit(1);
    }

    FILE *in = NULL, *out = NULL;
    if((in = fopen(argv[1], "r")) == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }
    if((out = fopen(argv[2], "w")) == NULL) {
        printf("Error opening file %s\n", argv[2]);
        exit(1);
    }

    count_frequencies(in);
    init_nodes();
    node_t *root = create_huff_tree();

    huffman_encoding(in, out);

    fclose(in);
    fclose(out);

    free_tree(root);
    exit(0);
}
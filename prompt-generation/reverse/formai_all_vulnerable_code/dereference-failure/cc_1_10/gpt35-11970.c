//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

//Structure to hold the frequency counts and Huffman tree nodes
struct node{
    int freq;
    char data;
    struct node *left, *right;
};

//Priority queue structure for implementing Huffman algorithm
struct pqueue{
    int size;
    int capacity;
    struct node **queue;
};

//Function to create a new node with given data and frequency
struct node *create_node(char data, int freq){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//Function to create a priority queue with given capacity
struct pqueue *create_pqueue(int capacity){
    struct pqueue *pq = (struct pqueue*)malloc(sizeof(struct pqueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->queue = (struct node**)malloc(sizeof(struct node*) * pq->capacity);

    return pq;
}

//Function to swap two nodes
void swap(struct node **x, struct node **y){
    struct node *temp = *x;
    *x = *y;
    *y = temp;
}

//Function to heapify a node for priority queue
void heapify(struct pqueue *pq, int index){
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < pq->size && pq->queue[left]->freq < pq->queue[smallest]->freq)
        smallest = left;

    if(right < pq->size && pq->queue[right]->freq < pq->queue[smallest]->freq)
        smallest = right;

    if(smallest != index){
        swap(&pq->queue[smallest], &pq->queue[index]);
        heapify(pq, smallest);
    }
}

//Function to insert a node into the priority queue
void insert(struct pqueue *pq, struct node *new_node){
    if(pq->size == pq->capacity)
        return;

    pq->queue[pq->size] = new_node;
    pq->size++;

    int i = pq->size - 1;
    while(i != 0 && pq->queue[(i-1)/2]->freq > pq->queue[i]->freq){
        swap(&pq->queue[(i-1)/2], &pq->queue[i]);
        i = (i-1)/2;
    }
}

//Function to extract minimum node from priority queue
struct node *extract_min(struct pqueue *pq){
    if(pq->size == 0)
        return NULL;

    if(pq->size == 1){
        pq->size--;
        return pq->queue[0];
    }

    struct node *min = pq->queue[0];
    pq->queue[0] = pq->queue[pq->size-1];
    pq->size--;
    heapify(pq, 0);

    return min;
}

//Function to build Huffman tree
struct node *build_tree(char *data, int *freq, int size){
    struct pqueue *pq = create_pqueue(size);

    for(int i=0; i<size; i++){
        struct node *new_node = create_node(data[i], freq[i]);
        insert(pq, new_node);
    }

    while(pq->size > 1){
        struct node *left = extract_min(pq);
        struct node *right = extract_min(pq);

        int freq = left->freq + right->freq;
        struct node *new_node = create_node('$', freq);
        new_node->left = left;
        new_node->right = right;

        insert(pq, new_node);
    }

    struct node *root = extract_min(pq);
    free(pq);

    return root;
}

//Function to traverse the Huffman tree and store codes in an array
void traverse_tree(struct node *root, int *codes, int top){
    if(root->left){
        codes[top] = 0;
        traverse_tree(root->left, codes, top+1);
    }

    if(root->right){
        codes[top] = 1;
        traverse_tree(root->right, codes, top+1);
    }

    if(!root->left && !root->right){
        printf("%c: ", root->data);
        for(int i=0; i<top; i++){
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

int main(){
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);

    struct node *root = build_tree(data, freq, size);

    int codes[100], top = 0;
    traverse_tree(root, codes, top);

    return 0;
}
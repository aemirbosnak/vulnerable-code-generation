//FormAI DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

/* struct definition for the binary tree node */
struct node {
    int value;
    struct node* left;
    struct node* right;
};

/* struct definition for the queue */
struct queue {
    struct node* items[MAX_NODES];
    int front;
    int rear;
};

/* function to create a new binary tree node */
struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* function to create a new queue */
struct queue* createQueue() {
    struct queue* newQueue = (struct queue*) malloc(sizeof(struct queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

/* function to check if the queue is empty */
int isEmpty(struct queue* queue) {
    if (queue->front == -1)
        return 1;
    else
        return 0;
}

/* function to add an item to the queue */
void enqueue(struct queue* queue, struct node* item) {
    if (queue->rear == MAX_NODES - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

/* function to remove an item from the queue */
struct node* dequeue(struct queue* queue) {
    struct node* item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = NULL;
    }
    else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        }
    }
    return item;
}

/* function to insert a node into the binary tree */
void insert(struct node* root, int value) {
    struct queue* queue = createQueue();
    struct node* newNode = createNode(value);
    if (!root) {
        root = newNode;
        return;
    }
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        struct node* temp = dequeue(queue);
        if (temp->left != NULL)
            enqueue(queue, temp->left);
        else {
            temp->left = newNode;
            return;
        }
        if (temp->right != NULL)
            enqueue(queue, temp->right);
        else {
            temp->right = newNode;
            return;
        }
    }
}

/* function to print the binary tree in a level order traversal */
void printLevelOrder(struct node* root) {
    if (!root)
        return;
    struct queue* queue = createQueue();
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        struct node* temp = dequeue(queue);
        printf("%d ", temp->value);
        if (temp->left != NULL)
            enqueue(queue, temp->left);
        if (temp->right != NULL)
            enqueue(queue, temp->right);
    }
}

int main() {
    struct node* root = createNode(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    printf("Level order traversal of the binary tree: ");
    printLevelOrder(root);
    printf("\n");
    return 0;
}
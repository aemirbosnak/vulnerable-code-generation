//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Node structure for linked list
typedef struct node{
    int data;
    struct node* next;
} Node;

//Stack structure using linked list
typedef struct stack{
    Node* top;
} Stack;

//Queue structure using linked list
typedef struct queue{
    Node* front;
    Node* rear;
} Queue;

//Tree structure using linked list
typedef struct tree{
    Node* root;
} Tree;

//Function to create a new node
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to push an element onto the stack
void push(Stack* stack, int data){
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

//Function to pop an element from the stack
int pop(Stack* stack){
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

//Function to enqueue an element onto the queue
void enqueue(Queue* queue, int data){
    Node* newNode = createNode(data);
    if(queue->front == NULL){
        queue->front = newNode;
        queue->rear = newNode;
    }
    else{
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

//Function to dequeue an element from the queue
int dequeue(Queue* queue){
    Node* temp = queue->front;
    int data = temp->data;
    if(queue->front == queue->rear){
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{
        queue->front = temp->next;
    }
    free(temp);
    return data;
}

//Function to insert a node into the binary search tree
void insert(Tree* tree, int data){
    Node* newNode = createNode(data);
    if(tree->root == NULL){
        tree->root = newNode;
    }
    else{
        Node* temp = tree->root;
        while(temp->next!= NULL){
            if(data < temp->next->data){
                temp = temp->next;
            }
            else{
                break;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//Function to perform inorder traversal of the binary search tree
void inorder(Node* node){
    if(node!= NULL){
        inorder(node->next);
        printf("%d ", node->data);
    }
}

//Main function
int main(){
    Stack stack;
    stack.top = NULL;
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    printf("Stack elements: ");
    while(stack.top!= NULL){
        printf("%d ", pop(&stack));
    }
    printf("\n");

    Queue queue;
    queue.front = NULL;
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    printf("Queue elements: ");
    while(queue.front!= NULL){
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    Tree tree;
    tree.root = NULL;
    insert(&tree, 50);
    insert(&tree, 25);
    insert(&tree, 75);
    printf("Inorder traversal of binary search tree: ");
    inorder(tree.root);
    printf("\n");

    return 0;
}
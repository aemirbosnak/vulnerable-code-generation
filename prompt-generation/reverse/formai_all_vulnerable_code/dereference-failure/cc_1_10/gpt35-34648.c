//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 50

typedef struct node{
    int value;
    struct node* next;
} Node;

typedef struct queue{
    Node* head;
    Node* tail;
    int size;
} Queue;

void initQueue(Queue* queue){
    srand(time(NULL));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    for(int i = 0; i < MAX_SIZE; i++){
        int value = rand() % 100;
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->value = value;
        newNode->next = NULL;
        if(queue->head == NULL){
            queue->head = newNode;
            queue->tail = newNode;
        }
        else{
            queue->tail->next = newNode;
            queue->tail = newNode;
        }
        queue->size++;
    }
}

void printQueue(Queue* queue){
    printf("[");
    Node* current = queue->head;
    while(current != NULL){
        printf("%d", current->value);
        current = current->next;
        if(current != NULL){
            printf(", ");
        }
    }
    printf("]\n");
}

void enqueue(Queue* queue, int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if(queue->head == NULL){
        queue->head = newNode;
        queue->tail = newNode;
    }
    else{
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

int dequeue(Queue* queue){
    if(queue->head == NULL){
        printf("Queue is empty.");
        return -1;
    }
    int value = queue->head->value;
    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    queue->size--;
    return value;
}

int main(){
    Queue queue;
    initQueue(&queue);
    printQueue(&queue);
    printf("Queue size: %d\n", queue.size);

    printf("Enqueueing 42...\n");
    enqueue(&queue, 42);
    printQueue(&queue);
    printf("Queue size: %d\n", queue.size);

    printf("Dequeueing twice...\n");
    dequeue(&queue);
    dequeue(&queue);
    printQueue(&queue);
    printf("Queue size: %d\n", queue.size);

    return 0;
}
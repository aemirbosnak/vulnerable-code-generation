//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Baggage{
    int id; // Unique id for each baggage
    int weight;
    int destination; // Destination code of the baggage
};

struct Node{
    struct Baggage data;
    struct Node *next;
};

struct Queue{
    struct Node *front, *rear;
};

void initQueue(struct Queue *queue){
    queue->front = queue->rear = NULL;
}

int isQueueEmpty(struct Queue *queue){
    return queue->front == NULL;
}

void enqueue(struct Queue *queue, struct Baggage baggage){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = baggage;
    newNode->next = NULL;

    if(queue->rear == NULL){
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

struct Baggage dequeue(struct Queue *queue){
    if(isQueueEmpty(queue)){
        struct Baggage emptyBaggage = {.id=0, .weight=0, .destination=0};
        return emptyBaggage;
    }

    struct Node *tempNode = queue->front;
    struct Baggage baggage = tempNode->data;

    queue->front = queue->front->next;

    if(queue->front == NULL)
        queue->rear = NULL;

    free(tempNode);

    return baggage;
}

struct Node* getQueueFront(struct Queue *queue){
    return queue->front;
}

void display(struct Queue *queue){
    struct Node *tempNode = queue->front;
    printf("Queue : ");

    while(tempNode != NULL){
        printf("%d->", tempNode->data.id);
        tempNode = tempNode->next;
    }

    printf("NULL\n");
}

int main(){
    srand(time(NULL)); // Set seed value for generating random numbers

    struct Queue destinationQueues[4];
    for(int i=0; i<4; i++){
        initQueue(&destinationQueues[i]);
    }

    int id = 1;
    for(int i=1; i<=20; i++){
        struct Baggage baggage = {.id=id, .weight=rand()%31+20, .destination=rand()%4};
        enqueue(&destinationQueues[baggage.destination], baggage); // Add the baggage to its corresponding destination queue
        id++;
    }

    printf("***Initial Baggage Queues***\n");
    for(int i=0; i<4; i++){
        printf("Queue %d: ", i);
        display(&destinationQueues[i]);
    }

    printf("\n***Simulating Baggage Handling***\n");

    for(int i=0; i<20; i++){
        int source = rand()%4;
        struct Node *frontNode = getQueueFront(&destinationQueues[source]);
        if(frontNode != NULL){
            struct Baggage baggage = dequeue(&destinationQueues[source]);
            baggage.destination = rand()%4; // Move the baggage to random destination queue after handling at source
            enqueue(&destinationQueues[baggage.destination], baggage); // Add the baggage to its new destination queue
            printf("Baggage %d handled at source %d and moved to destination %d\n", baggage.id, source, baggage.destination);
        }
    }

    printf("\n***Final Baggage Queues***\n");
    for(int i=0; i<4; i++){
        printf("Queue %d: ", i);
        display(&destinationQueues[i]);
    }

    return 0;
}
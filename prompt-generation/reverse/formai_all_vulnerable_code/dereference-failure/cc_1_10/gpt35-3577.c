//FormAI DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

void init(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

int isFull(Queue* queue) {
    return (queue->size == MAX_SIZE);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int size(Queue* queue) {
    return queue->size;
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("The queue is full! Cannot add any more elements.\n");
        return;
    }
    
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = temp;
        queue->rear = temp;
    } else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
    
    queue->size++;
    printf("Element added to the queue.\n");
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty! Cannot remove any elements.\n");
        return -1;
    }
    
    int removedItem = queue->front->data;
    Node* temp = queue->front;
    
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    
    free(temp);
    queue->size--;
    return removedItem;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty!\n");
        return;
    }
    
    Node* temp = queue->front;
    printf("Elements in the queue: ");
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

int main() {
    printf("Welcome to the post-apocalyptic queue!\n");
    printf("Enter the number of survivors: ");
    int n;
    scanf("%d", &n);
    
    Queue survivors;
    init(&survivors);
    
    for (int i = 1; i <= n; i++) {
        printf("Enter the name of survivor %d: ", i);
        char name[20];
        scanf("%s", name);
        enqueue(&survivors, i);
    }
    
    printf("The queue of survivors: ");
    display(&survivors);
    
    printf("The zombie attacks!!!\n");
    printf("Enter the number of survivors to escape: ");
    int escapeCount;
    scanf("%d", &escapeCount);
    
    for (int i = 1; i <= escapeCount; i++) {
        int escapedSurvivor = dequeue(&survivors);
        printf("Survivor %d has escaped!\n", escapedSurvivor);
    }
    
    printf("The queue of remaining survivors: ");
    display(&survivors);
    
    printf("The zombies are getting closer...\n");
    int remainingCount = size(&survivors);
    printf("%d survivors remaining.\n", remainingCount);
    
    printf("The only way to survive is to sacrifice half of the remaining survivors.\n");
    int sacrificeCount = remainingCount / 2;
    
    for (int i = 1; i <= sacrificeCount; i++) {
        int sacrificedSurvivor = dequeue(&survivors);
        printf("Survivor %d has been sacrificed.\n", sacrificedSurvivor);
    }
    
    printf("The queue of final survivors: ");
    display(&survivors);
    
    printf("Congratulations! You have survived the post-apocalypse.\n");
    return 0;
}
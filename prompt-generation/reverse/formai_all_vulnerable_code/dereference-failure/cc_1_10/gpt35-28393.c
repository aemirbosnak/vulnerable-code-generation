//FormAI DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        return -1;
    }

    int data = q->front->data;
    Node* temp = q->front;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }

    free(temp);

    return data;
}

void printQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* curr = q->front;

    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main() {
    srand(time(NULL));

    Queue q;
    initQueue(&q);

    printf("********** Post-Apocalyptic Queue Visualizer **********\n");

    while (1) {
        printf("\n-------------\n");
        printf("Front: ");

        if (!isQueueEmpty(&q)) {
            printf("[%d]\n", q.front->data);
        }
        else {
            printf("[-]\n");
        }

        printf("Rear: ");

        if (!isQueueEmpty(&q)) {
            printf("[%d]\n", q.rear->data);
        }
        else {
            printf("[-]\n");
        }

        printf("\nQueue: ");
        printQueue(&q);

        if (rand() % 2) {
            int data = rand() % 100;
            enqueue(&q, data);
            printf("\n[+] Enqueued %d", data);
        }
        else {
            int data = dequeue(&q);
            if (data == -1) {
                printf("\n[-] Queue is empty!");
            }
            else {
                printf("\n[-] Dequeued %d", data);
            }
        }

        printf("\n");
        printf("\nPress enter to continue...\n");
        getchar();
        system("clear"); // for UNIX-like systems
        // system("cls"); // for Windows
    }

    return 0;
}
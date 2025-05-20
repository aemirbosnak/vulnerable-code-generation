//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int dequeue(Node** head) {
    if (*head == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    Node* temp = *head;
    int data = temp->data;
    free(temp);
    *head = temp->next;
    return data;
}

int isEmpty(Node* head) {
    return head == NULL;
}

void* producer(void* arg) {
    int id = *(int*)arg;
    Node* head = NULL;
    while (1) {
        sleep(1);
        enqueue(&head, id*10+1);
        printf("Producer %d produced %d\n", id, id*10+1);
    }
}

void* consumer(void* arg) {
    int id = *(int*)arg;
    Node* head = NULL;
    while (1) {
        int data = dequeue(&head);
        if (data == -1) {
            continue;
        }
        printf("Consumer %d consumed %d\n", id, data);
    }
}

int main() {
    pthread_t threads[2];
    int ids[2] = {1, 2};
    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, (i == 0)? producer : consumer, &ids[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
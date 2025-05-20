//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void insert(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(Node* node) {
    Node* current = node;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void* threadFunc(void* arg) {
    int data;
    if (arg == NULL) {
        data = 10;
    } else {
        data = *((int*)arg);
    }
    insert(data);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_SIZE];
    int i;

    for (i = 0; i < MAX_SIZE; i++) {
        pthread_create(&threads[i], NULL, threadFunc, &i);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    printList(head);

    return 0;
}
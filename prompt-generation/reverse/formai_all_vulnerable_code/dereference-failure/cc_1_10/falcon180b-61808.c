//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void addNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void* threadFunc(void* arg) {
    int threadID = *(int*)arg;

    for (int i = 0; i < 5; i++) {
        printf("Thread %d is adding node %d\n", threadID, i);
        addNode(i);
    }

    return NULL;
}

int main() {
    pthread_t threads[5];
    int threadIDs[5] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, threadFunc, (void*)&threadIDs[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printList();

    return 0;
}
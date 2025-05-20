//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
pthread_mutex_t lock;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void* addNode(void* arg) {
    int value = *(int*)arg;

    pthread_mutex_lock(&lock);
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Added node with value: %d\n", value);
    pthread_mutex_unlock(&lock);
    return NULL;
}

// Function to print the linked list
void* printList(void* arg) {
    pthread_mutex_lock(&lock);
    Node* temp = head;

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[10];
    pthread_mutex_init(&lock, NULL);
    int values[10];

    // Create threads to add nodes to the list
    for (int i = 0; i < 10; i++) {
        values[i] = i + 1;
        pthread_create(&threads[i], NULL, addNode, &values[i]);
        usleep(100000); // Simulating some delay
    }

    // Wait for all addNode threads to finish
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Create a thread to print the linked list
    pthread_t printThread;
    pthread_create(&printThread, NULL, printList, NULL);
    pthread_join(printThread, NULL);

    // Clean up the linked list
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
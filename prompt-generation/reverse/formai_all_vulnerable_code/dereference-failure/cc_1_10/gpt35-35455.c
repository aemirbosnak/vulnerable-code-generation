//FormAI DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the struct for the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Initialize the linked list with a dummy node
Node* head = NULL;
Node* tail = NULL;

// Initialize the mutex lock for thread safety
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// This function adds a new node to the end of the linked list
void* addNode(void* arg) {
    int data = *(int*)arg;

    // Create the new node and set the data
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // Acquire the lock before modifying the list
    pthread_mutex_lock(&lock);

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    // Otherwise, add the new node to the end
    else {
        tail->next = newNode;
        tail = newNode;
    }

    // Release the lock after modifying the list
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

// This function removes a node with a given value from the linked list
void* removeNode(void* arg) {
    int data = *(int*)arg;

    // Acquire the lock before modifying the list
    pthread_mutex_lock(&lock);

    // If the list is empty, do nothing
    if (head == NULL) {
        printf("List is empty\n");
    }
    // If the first node has the desired value, remove it
    else if (head->data == data) {
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node with value %d removed\n", data);
    }
    // Otherwise, iterate through the list to find the desired value
    else {
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL && curr->data != data) {
            prev = curr;
            curr = curr->next;
        }

        // If the value is not found, do nothing
        if (curr == NULL) {
            printf("Node with value %d not found\n", data);
        }
        // Otherwise, remove the node
        else {
            prev->next = curr->next;
            free(curr);
            printf("Node with value %d removed\n", data);
        }
    }

    // Release the lock after modifying the list
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3, thread4;
    int val1 = 10, val2 = 20, val3 = 30, val4 = 20;

    // Create four threads to add and remove nodes from the list
    pthread_create(&thread1, NULL, addNode, &val1);
    pthread_create(&thread2, NULL, addNode, &val2);
    pthread_create(&thread3, NULL, removeNode, &val3);
    pthread_create(&thread4, NULL, removeNode, &val4);

    // Wait for all threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    // Print the final list
    printf("Final List: ");
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
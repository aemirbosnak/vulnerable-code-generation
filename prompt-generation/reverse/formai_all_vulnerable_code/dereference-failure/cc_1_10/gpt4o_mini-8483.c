//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define a node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the head of the linked list
Node* head = NULL;

// Mutex for synchronizing access to the linked list
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to insert a node at the end of the linked list
void* insert_node(void* arg) {
    int value = *((int*)arg);

    pthread_mutex_lock(&mutex);  // Lock the mutex

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("Inserted: %d\n", value);

    pthread_mutex_unlock(&mutex);  // Unlock the mutex
    return NULL;
}

// Function to delete a node with a specified value
void* delete_node(void* arg) {
    int value = *((int*)arg);

    pthread_mutex_lock(&mutex);  // Lock the mutex

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL) {
            // Deleting the head node
            head = temp->next;
        } else {
            // Bypass the node to delete it
            prev->next = temp->next;
        }
        free(temp);
        printf("Deleted: %d\n", value);
    } else {
        printf("Value %d not found for deletion.\n", value);
    }

    pthread_mutex_unlock(&mutex);  // Unlock the mutex
    return NULL;
}

// Function to display the content of the linked list
void display_list() {
    pthread_mutex_lock(&mutex);  // Lock the mutex

    Node* temp = head;
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    pthread_mutex_unlock(&mutex);  // Unlock the mutex
}

// Main function to demonstrate asynchronous operations
int main() {
    pthread_t threads[10];
    int values_to_insert[5] = {1, 2, 3, 4, 5};
    int values_to_delete[3] = {2, 5, 10};  // 10 is not in the list

    // Creating threads for inserting nodes
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, insert_node, (void*)&values_to_insert[i]);
    }

    // Wait for finished insertions
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    display_list();

    // Creating threads for deleting nodes
    for (int i = 5; i < 8; i++) {
        pthread_create(&threads[i], NULL, delete_node, (void*)&values_to_delete[i-5]);
    }

    // Wait for finished deletions
    for (int i = 5; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }

    display_list();

    return 0;
}
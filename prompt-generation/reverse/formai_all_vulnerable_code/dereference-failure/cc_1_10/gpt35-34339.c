//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h> // For threading

// Node structure of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global variable for head of the linked list
struct Node* head = NULL;

// Lock for concurrent access to the linked list
pthread_mutex_t lock;

// Function to insert a node at the end of the linked list
void insert(int data) {
    // Create the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    // Lock the linked list for concurrent access
    pthread_mutex_lock(&lock);

    // Check if the linked list is empty
    if (head == NULL) {
        head = new_node;
    }
    else {
        // Traverse to the end of the linked list
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Insert the new node at the end of the linked list
        current->next = new_node;
    }

    // Unlock the linked list
    pthread_mutex_unlock(&lock);
}

// Function to delete a node from the linked list by value
void delete(int data) {
    // Lock the linked list for concurrent access
    pthread_mutex_lock(&lock);

    // Check if the linked list is empty
    if (head == NULL) {
        printf("Linked list is empty!");
        return;
    }

    // Check if the head node needs to be deleted
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    else {
        // Traverse the linked list to find the node to delete
        struct Node* current = head->next;
        struct Node* previous = head;
        while (current != NULL && current->data != data) {
            previous = current;
            current = current->next;
        }

        // If the node is found, delete it
        if (current != NULL) {
            struct Node* temp = current;
            previous->next = current->next;
            free(temp);
        }
        else {
            printf("Node not found in linked list!");
        }
    }

    // Unlock the linked list
    pthread_mutex_unlock(&lock);
}

// Function to print the linked list
void print() {
    // Lock the linked list for concurrent access
    pthread_mutex_lock(&lock);

    // Check if the linked list is empty
    if (head == NULL) {
        printf("Linked list is empty!");
        return;
    }

    // Traverse the linked list and print each node's data
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Unlock the linked list
    pthread_mutex_unlock(&lock);
}

// Asynchronous function to insert nodes into the linked list
void* insert_async(void* arg) {
    int data = *((int*)arg);
    insert(data);
    printf("Node with data %d inserted into the linked list asynchronously.\n", data);
    return NULL;
}

// Asynchronous function to delete nodes from the linked list by value
void* delete_async(void* arg) {
    int data = *((int*)arg);
    delete(data);
    printf("Node with data %d deleted from the linked list asynchronously.\n", data);
    return NULL;
}

// Asynchronous function to print the linked list
void* print_async(void* arg) {
    print();
    printf("\n");
    return NULL;
}

// Main function to test the linked list
int main() {
    // Initialize the lock for concurrent access to the linked list
    pthread_mutex_init(&lock, NULL);

    // Create threads to insert nodes into the linked list asynchronously
    pthread_t thread1, thread2;
    int data1 = 1, data2 = 2;
    pthread_create(&thread1, NULL, insert_async, (void*)&data1);
    pthread_create(&thread2, NULL, insert_async, (void*)&data2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Create threads to delete nodes from the linked list asynchronously
    pthread_t thread3, thread4;
    int data3 = 1, data4 = 3;
    pthread_create(&thread3, NULL, delete_async, (void*)&data3);
    pthread_create(&thread4, NULL, delete_async, (void*)&data4);

    // Wait for the threads to finish
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    // Create thread to print the linked list asynchronously
    pthread_t thread5;
    pthread_create(&thread5, NULL, print_async, NULL);

    // Wait for the thread to finish
    pthread_join(thread5, NULL);

    // Destroy the lock for concurrent access to the linked list
    pthread_mutex_destroy(&lock);

    return 0;
}
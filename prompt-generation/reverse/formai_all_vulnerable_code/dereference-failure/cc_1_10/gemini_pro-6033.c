//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Data structure to store a node in a linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Global linked list head
node *head = NULL;

// Global lock for the linked list
pthread_mutex_t lock;

// Thread function to insert a node into the linked list
void *insert_node(void *arg) {
    // Get the data to be inserted
    int data = *(int *) arg;

    // Allocate memory for the new node
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        perror("malloc");
        pthread_exit(NULL);
    }

    // Initialize the new node
    new_node->data = data;
    new_node->next = NULL;

    // Acquire the lock
    pthread_mutex_lock(&lock);

    // Insert the new node into the linked list
    if (head == NULL) {
        head = new_node;
    } else {
        node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    // Release the lock
    pthread_mutex_unlock(&lock);

    // Exit the thread
    pthread_exit(NULL);
}

// Thread function to delete a node from the linked list
void *delete_node(void *arg) {
    // Get the data to be deleted
    int data = *(int *) arg;

    // Acquire the lock
    pthread_mutex_lock(&lock);

    // Find the node to be deleted
    node *current = head;
    node *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    // If the node was found, delete it
    if (current != NULL) {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }

    // Release the lock
    pthread_mutex_unlock(&lock);

    // Exit the thread
    pthread_exit(NULL);
}

// Thread function to print the linked list
void *print_list(void *arg) {
    // Acquire the lock
    pthread_mutex_lock(&lock);

    // Print the linked list
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Release the lock
    pthread_mutex_unlock(&lock);

    // Exit the thread
    pthread_exit(NULL);
}

// Main function
int main() {
    // Initialize the lock
    pthread_mutex_init(&lock, NULL);

    // Create the threads
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        int *data = (int *) malloc(sizeof(int));
        *data = i;
        pthread_create(&threads[i], NULL, insert_node, (void *) data);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the linked list
    pthread_t print_thread;
    pthread_create(&print_thread, NULL, print_list, NULL);
    pthread_join(print_thread, NULL);

    // Delete the linked list
    for (int i = 0; i < 10; i++) {
        int *data = (int *) malloc(sizeof(int));
        *data = i;
        pthread_create(&threads[i], NULL, delete_node, (void *) data);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the lock
    pthread_mutex_destroy(&lock);

    return 0;
}
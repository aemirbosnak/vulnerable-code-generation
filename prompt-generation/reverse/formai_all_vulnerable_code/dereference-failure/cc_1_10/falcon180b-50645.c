//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a node structure for our linked list
struct node {
    int data;
    struct node* next;
};

// Define our linked list
struct node* head = NULL;

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to print the linked list
void print_list(struct node* node) {
    while (node!= NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function for each thread to execute
void* thread_func(void* arg) {
    // Lock the mutex to ensure only one thread is modifying the list at a time
    pthread_mutex_lock(&mutex);

    // Create a new node with random data
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = rand() % 100;
    new_node->next = NULL;

    // Add the new node to the end of the list
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    return NULL;
}

int main() {
    // Create 10 threads
    pthread_t threads[10];
    int i;
    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    // Wait for all threads to finish
    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final linked list
    printf("Final linked list:\n");
    print_list(head);

    return 0;
}
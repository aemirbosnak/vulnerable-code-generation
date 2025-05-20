//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the structure of our linked list
struct node {
    int data;
    struct node *next;
};

// Define global variables and mutex locks for our linked list
struct node *head = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Define the function that will create nodes and add them to our linked list
void *add_node(void *arg) {
    int *num = (int *)arg;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = *num;
    new_node->next = NULL;
    
    // Lock the mutex and add the new node to the list
    pthread_mutex_lock(&mutex);
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    pthread_mutex_unlock(&mutex);
    
    // Signal any waiting threads that the linked list has been updated
    pthread_cond_signal(&cond);
    
    pthread_exit(NULL);
}

// Define the function that will remove a node from our linked list
void *remove_node(void *arg) {
    int *num = (int *)arg;
    
    // Lock the mutex and wait for the linked list to be updated
    pthread_mutex_lock(&mutex);
    while (head == NULL) {
        pthread_cond_wait(&cond, &mutex);
    }
    
    // Traverse the linked list to find the node to remove
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL && temp->data != *num) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the node was found, remove it from the list
    if (temp != NULL) {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
    pthread_mutex_unlock(&mutex);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[10];
    int nums[10] = {5, 8, 2, 6, 4, 9, 1, 7, 3, 0};
    
    // Create threads to add nodes to our linked list
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, add_node, &nums[i]);
        sleep(1);
    }
    
    // Wait for all threads to finish executing
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Display the contents of the linked list
    struct node *temp = head;
    printf("Initial linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    // Create threads to remove nodes from our linked list
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, remove_node, &nums[i]);
        sleep(1);
    }
    
    // Wait for all threads to finish executing
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Display the contents of the modified linked list
    temp = head;
    printf("Modified linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
    return 0;
}
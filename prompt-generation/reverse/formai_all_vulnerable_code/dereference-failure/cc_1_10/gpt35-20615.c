//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

// linked list node structure
typedef struct node {
    int data;
    struct node* next;
} node_t;

// function to create and initialize a new node
node_t* create_node(int data) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// function to insert a node at the beginning of the linked list
void insert_node(node_t** head_ref, int data) {
    node_t* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// function to delete a node with a given value from the linked list
void delete_node(node_t** head_ref, int key) {
    node_t* temp = *head_ref;
    node_t* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// function to print the contents of the linked list
void print_list(node_t* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// global variables and mutex locks
node_t* head = NULL;
pthread_mutex_t insert_lock;
pthread_mutex_t delete_lock;

// function to insert a node asynchronously
void* insert_node_async(void* args) {
    int data = *(int*) args;
    pthread_mutex_lock(&insert_lock);
    insert_node(&head, data);
    printf("Node with data %d inserted successfully.\n", data);
    pthread_mutex_unlock(&insert_lock);
    return NULL;
}

// function to delete a node asynchronously
void* delete_node_async(void* args) {
    int key = *(int*) args;
    pthread_mutex_lock(&delete_lock);
    delete_node(&head, key);
    printf("Node with data %d deleted successfully.\n", key);
    pthread_mutex_unlock(&delete_lock);
    return NULL;
}

// main function
int main() {
    // initialize mutex locks
    pthread_mutex_init(&insert_lock, NULL);
    pthread_mutex_init(&delete_lock, NULL);

    // create threads for asynchronous insertions and deletions
    pthread_t thread1, thread2, thread3;
    int data1 = 10;
    int data2 = 20;
    int key = 10;
    pthread_create(&thread1, NULL, insert_node_async, (void*) &data1);
    pthread_create(&thread2, NULL, insert_node_async, (void*) &data2);
    pthread_create(&thread3, NULL, delete_node_async, (void*) &key);

    // wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    // print the contents of the linked list
    printf("Linked list after asynchronous operations: ");
    print_list(head);

    // free mutex locks and exit
    pthread_mutex_destroy(&insert_lock);
    pthread_mutex_destroy(&delete_lock);
    return 0;
}
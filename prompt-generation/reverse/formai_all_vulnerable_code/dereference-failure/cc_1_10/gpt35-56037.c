//FormAI DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Define node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define linked list structure
typedef struct linked_list {
    node_t *head;
    int count;
    pthread_mutex_t lock;
} linked_list_t;

// Function to initialize a linked list
void ll_init(linked_list_t *list) {
    list->head = NULL;
    list->count = 0;
    pthread_mutex_init(&(list->lock), NULL);
}

// Function to add a node to the linked list
void ll_add(linked_list_t *list, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    pthread_mutex_lock(&(list->lock));
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        node_t *cur = list->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
    list->count++;
    pthread_mutex_unlock(&(list->lock));
}

// Function to remove the first node with the given data from the linked list
void ll_remove(linked_list_t *list, int data) {
    pthread_mutex_lock(&(list->lock));
    node_t *prev = NULL;
    node_t *cur = list->head;
    while (cur != NULL && cur->data != data) {
        prev = cur;
        cur = cur->next;
    }
    if (cur != NULL) {
        if (prev == NULL) {
            list->head = cur->next;
        } else {
            prev->next = cur->next;
        }
        free(cur);
        list->count--;
    }
    pthread_mutex_unlock(&(list->lock));
}

// Function to print the contents of the linked list
void ll_print(linked_list_t *list) {
    pthread_mutex_lock(&(list->lock));
    node_t *cur = list->head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
    pthread_mutex_unlock(&(list->lock));
}

// Function to clean up the linked list
void ll_cleanup(linked_list_t *list) {
    pthread_mutex_lock(&(list->lock));
    node_t *cur = list->head;
    while (cur != NULL) {
        node_t *temp = cur;
        cur = cur->next;
        free(temp);
    }
    pthread_mutex_unlock(&(list->lock));
    pthread_mutex_destroy(&(list->lock));
}

// Thread function to add numbers to the linked list
void *add_thread_func(void *arg) {
    linked_list_t *list = (linked_list_t *)arg;
    for (int i = 0; i < 100; i++) {
        ll_add(list, i);
    }
    return NULL;
}

// Thread function to remove numbers from the linked list
void *remove_thread_func(void *arg) {
    linked_list_t *list = (linked_list_t *)arg;
    for (int i = 0; i < 50; i++) {
        ll_remove(list, i * 2);
    }
    return NULL;
}

// Main function
int main() {
    // Initialize the linked list
    linked_list_t list;
    ll_init(&list);

    // Create threads to add and remove numbers from the linked list
    pthread_t add_thread, remove_thread;
    pthread_create(&add_thread, NULL, add_thread_func, &list);
    pthread_create(&remove_thread, NULL, remove_thread_func, &list);

    // Wait for the threads to finish
    pthread_join(add_thread, NULL);
    pthread_join(remove_thread, NULL);

    // Print the contents of the linked list
    ll_print(&list);

    // Clean up the linked list
    ll_cleanup(&list);

    return 0;
}
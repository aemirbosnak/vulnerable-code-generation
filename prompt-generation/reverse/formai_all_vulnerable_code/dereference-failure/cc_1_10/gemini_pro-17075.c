//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the linked list structure
typedef struct linked_list {
    node_t *head;
    node_t *tail;
    int size;
} linked_list_t;

// Create a new linked list
linked_list_t *create_linked_list() {
    linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(linked_list_t *list, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    list->size++;
}

// Insert a new node at the end of the linked list
void insert_at_end(linked_list_t *list, int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

// Delete a node from the linked list
void delete_node(linked_list_t *list, int data) {
    node_t *current_node = list->head;
    node_t *previous_node = NULL;
    while (current_node != NULL) {
        if (current_node->data == data) {
            if (previous_node == NULL) {
                list->head = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            if (current_node == list->tail) {
                list->tail = previous_node;
            }
            free(current_node);
            list->size--;
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
}

// Print the linked list
void print_linked_list(linked_list_t *list) {
    node_t *current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Free the linked list
void free_linked_list(linked_list_t *list) {
    node_t *current_node = list->head;
    while (current_node != NULL) {
        node_t *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

// Thread function to insert a new node at the beginning of the linked list
void *insert_at_beginning_thread(void *arg) {
    linked_list_t *list = (linked_list_t *)arg;
    int data = rand() % 100;
    insert_at_beginning(list, data);
    printf("Inserted %d at the beginning of the list\n", data);
    return NULL;
}

// Thread function to insert a new node at the end of the linked list
void *insert_at_end_thread(void *arg) {
    linked_list_t *list = (linked_list_t *)arg;
    int data = rand() % 100;
    insert_at_end(list, data);
    printf("Inserted %d at the end of the list\n", data);
    return NULL;
}

// Thread function to delete a node from the linked list
void *delete_node_thread(void *arg) {
    linked_list_t *list = (linked_list_t *)arg;
    int data = rand() % 100;
    delete_node(list, data);
    printf("Deleted %d from the list\n", data);
    return NULL;
}

int main() {
    // Create a new linked list
    linked_list_t *list = create_linked_list();

    // Create a thread pool
    pthread_t thread_pool[10];

    // Create threads to insert and delete nodes from the linked list
    for (int i = 0; i < 10; i++) {
        pthread_create(&thread_pool[i], NULL, insert_at_beginning_thread, (void *)list);
        pthread_create(&thread_pool[i], NULL, insert_at_end_thread, (void *)list);
        pthread_create(&thread_pool[i], NULL, delete_node_thread, (void *)list);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(thread_pool[i], NULL);
    }

    // Print the linked list
    print_linked_list(list);

    // Free the linked list
    free_linked_list(list);

    return 0;
}
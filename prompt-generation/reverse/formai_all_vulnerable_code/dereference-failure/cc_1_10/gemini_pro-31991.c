//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <assert.h>

// Define the linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the linked list
typedef struct list {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

// Create a new node
node_t *new_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

// Create a new list
list_t *new_list() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Push a node to the front of the list
void push_front(list_t *list, int data) {
    node_t *node = new_node(data);
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
    }
    list->size++;
}

// Push a node to the back of the list
void push_back(list_t *list, int data) {
    node_t *node = new_node(data);
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Pop a node from the front of the list
int pop_front(list_t *list) {
    if (list->head == NULL) {
        return -1;
    }
    node_t *node = list->head;
    int data = node->data;
    list->head = node->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(node);
    list->size--;
    return data;
}

// Pop a node from the back of the list
int pop_back(list_t *list) {
    if (list->tail == NULL) {
        return -1;
    }
    node_t *node = list->tail;
    int data = node->data;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        node_t *prev = list->head;
        while (prev->next != list->tail) {
            prev = prev->next;
        }
        prev->next = NULL;
        list->tail = prev;
    }
    free(node);
    list->size--;
    return data;
}

// Print the list
void print_list(list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Free the list
void free_list(list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

// Thread function
void *thread_func(void *arg) {
    list_t *list = (list_t *)arg;

    // Push and pop some nodes
    for (int i = 0; i < 10000; i++) {
        push_front(list, i);
        pop_back(list);
    }

    return NULL;
}

int main() {
    // Create a new list
    list_t *list = new_list();

    // Create some threads
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)list);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the list
    print_list(list);

    // Free the list
    free_list(list);

    return 0;
}
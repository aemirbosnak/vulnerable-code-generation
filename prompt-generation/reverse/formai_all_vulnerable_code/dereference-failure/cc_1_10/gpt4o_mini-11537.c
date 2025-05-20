//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the linked list structure
typedef struct LinkedList {
    Node* head;
    pthread_mutex_t lock;
} LinkedList;

// Function to initialize the linked list
void init_list(LinkedList* list) {
    list->head = NULL;
    pthread_mutex_init(&list->lock, NULL);
}

// Function to create a new node
Node* create_node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void add_node(LinkedList* list, int data) {
    pthread_mutex_lock(&list->lock);
    Node* newNode = create_node(data);
    newNode->next = list->head;
    list->head = newNode;
    pthread_mutex_unlock(&list->lock);
}

// Function to remove a node from the linked list
int remove_node(LinkedList* list, int data) {
    pthread_mutex_lock(&list->lock);
    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            pthread_mutex_unlock(&list->lock);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    pthread_mutex_unlock(&list->lock);
    return 0;
}

// Function to display the linked list
void display_list(LinkedList* list) {
    pthread_mutex_lock(&list->lock);
    Node* current = list->head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    pthread_mutex_unlock(&list->lock);
}

// Thread function for adding nodes
void* add_elements(void* arg) {
    LinkedList* list = (LinkedList*)arg;
    for (int i = 0; i < 5; i++) {
        add_node(list, i);
        printf("Added %d\n", i);
        sleep(1); // Sleep to simulate work
    }
    return NULL;
}

// Thread function for removing nodes
void* remove_elements(void* arg) {
    LinkedList* list = (LinkedList*)arg;
    for (int i = 0; i < 5; i++) {
        if (remove_node(list, i)) {
            printf("Removed %d\n", i);
        } else {
            printf("Did not find %d to remove\n", i);
        }
        sleep(1); // Sleep to simulate work
    }
    return NULL;
}

// Main function
int main() {
    LinkedList list;
    init_list(&list);
    pthread_t add_thread, remove_thread;

    // Create threads for adding and removing nodes
    pthread_create(&add_thread, NULL, add_elements, (void*)&list);
    pthread_create(&remove_thread, NULL, remove_elements, (void*)&list);

    // Wait for both threads to finish
    pthread_join(add_thread, NULL);
    pthread_join(remove_thread, NULL);

    // Display the final state of the linked list
    display_list(&list);

    // Cleanup
    pthread_mutex_destroy(&list.lock);
    return 0;
}
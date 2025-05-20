//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Define the structure of a linked list
struct LinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
};

// Create a new node with the given data
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Add a node to the end of the linked list
void addNode(struct LinkedList *list, int data) {
    struct Node *node = createNode(data);
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Remove a node from the linked list
void removeNode(struct LinkedList *list, int data) {
    struct Node *current = list->head;
    struct Node *previous = NULL;
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found.\n");
    } else {
        if (previous == NULL) {
            list->head = current->next;
        } else {
            previous->next = current->next;
        }
        if (current == list->tail) {
            list->tail = previous;
        }
        free(current);
        list->size--;
    }
}

// Print the contents of the linked list
void printList(struct LinkedList *list) {
    struct Node *current = list->head;
    printf("Contents of the linked list:\n");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    // Add some nodes to the linked list
    addNode(&list, 5);
    addNode(&list, 10);
    addNode(&list, 15);

    // Print the contents of the linked list
    printList(&list);

    // Remove a node from the linked list
    removeNode(&list, 10);

    // Print the contents of the linked list again
    printList(&list);

    return 0;
}
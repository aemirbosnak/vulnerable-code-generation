//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

pthread_t tid; // Declare global thread ID

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct LinkedList list;

// Function to add new node to the Linked List
void addNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list.head == NULL) {
        list.head = newNode;
    } else {
        struct Node* curr = list.head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    list.size++;
}

// Function to remove a node from the Linked List
void removeNode(int data) {
    struct Node* curr = list.head;
    struct Node* prev = NULL;

    while (curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev == NULL) {
            list.head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
        list.size--;
    }
}

// Function to print the Linked List
void printList() {
    struct Node* curr = list.head;

    printf("Linked List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Thread function for adding nodes to the Linked List
void* addThread() {
    for (int i = 1; i <= 5; i++) {
        addNode(i);
        printf("Added %d to Linked List\n", i);
        sleep(1);
    }
    return NULL;
}

// Thread function for removing nodes from the Linked List
void* removeThread() {
    for (int i = 1; i <= 3; i++) {
        removeNode(i);
        printf("Removed %d from Linked List\n", i);
        sleep(2);
    }
    return NULL;
}

int main() {
    list.head = NULL;
    list.size = 0;

    // Create and run thread for adding nodes
    if(pthread_create(&tid, NULL, &addThread, NULL) != 0) {
        printf("Failed to create thread\n");
        return 1;
    }

    // Continuously print the Linked List in the main thread
    while (list.size < 5) {
        printList();
        sleep(1);
    }

    // Create and run thread for removing nodes
    if(pthread_create(&tid, NULL, &removeThread, NULL) != 0) {
        printf("Failed to create thread\n");
        return 1;
    }

    // Continuously print the Linked List in the main thread
    while (list.size > 0) {
        printList();
        sleep(2);
    }

    return 0;
}
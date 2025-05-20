//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// A simple linked list structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// The head of the list
Node* head = NULL;

// An insert function to add elements to the list
void insert(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// A print function to print out the list
void print() {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// A thread function that inserts elements into the list
void* insert_thread(void* arg) {
    int start = *(int*)arg;
    for (int i = start; i < start+5; i++) {
        insert(i);
    }
    pthread_exit(NULL);
}

int main() {
    // Initialize the head of the list
    head = (Node*)malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;

    // Create two threads to insert elements into the list
    pthread_t thread1, thread2;
    int start1 = 0, start2 = 5;
    pthread_create(&thread1, NULL, insert_thread, (void*)&start1);
    pthread_create(&thread2, NULL, insert_thread, (void*)&start2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print out the final list
    print();

    // Free memory
    Node *current = head, *prev;
    while (current != NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

pthread_mutex_t mutex;

Node* insertAtTail(Node* head, char* data) {
    pthread_mutex_lock(&mutex);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    pthread_mutex_unlock(&mutex);

    return head;
}

int search(Node* head, char* data) {
    pthread_mutex_lock(&mutex);

    Node* current = head;
    while (current) {
        if (strcmp(current->data, data) == 0) {
            pthread_mutex_unlock(&mutex);
            return 1;
        }
        current = current->next;
    }

    pthread_mutex_unlock(&mutex);
    return 0;
}

int main() {
    Node* head = NULL;

    insertAtTail(head, "John Doe");
    insertAtTail(head, "Jane Doe");
    insertAtTail(head, "Peter Pan");

    if (search(head, "Jane Doe") == 1) {
        printf("Jane Doe found.\n");
    } else {
        printf("Jane Doe not found.\n");
    }

    return 0;
}
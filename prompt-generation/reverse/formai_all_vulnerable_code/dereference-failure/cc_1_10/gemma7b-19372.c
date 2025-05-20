//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

pthread_mutex_t mutex;

Node* insert(Node* head, char* name) {
    pthread_mutex_lock(&mutex);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    pthread_mutex_unlock(&mutex);

    return head;
}

void search(Node* head, char* name) {
    pthread_mutex_lock(&mutex);

    Node* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %s\n", temp->name);
            break;
        }
        temp = temp->next;
    }

    pthread_mutex_unlock(&mutex);
}

int main() {
    Node* head = NULL;

    insert(head, "John Doe");
    insert(head, "Jane Doe");
    insert(head, "Peter Pan");

    search(head, "Jane Doe");

    return 0;
}
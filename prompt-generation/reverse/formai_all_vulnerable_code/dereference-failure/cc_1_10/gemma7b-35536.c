//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INDEX 1024

typedef struct Node {
    char name[256];
    struct Node* next;
} Node;

pthread_mutex_t mutex;

Node** index_head = NULL;

void insert_node(char* name) {
    pthread_mutex_lock(&mutex);

    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (index_head == NULL) {
        index_head = new_node;
    } else {
        Node* tail = index_head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_node;
    }

    pthread_mutex_unlock(&mutex);
}

int search_node(char* name) {
    pthread_mutex_lock(&mutex);

    Node* current = index_head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    insert_node("John Doe");
    insert_node("Jane Doe");
    insert_node("Peter Pan");

    if (search_node("John Doe")) {
        printf("John Doe is in the list.\n");
    }

    if (search_node("Bob Smith")) {
        printf("Bob Smith is in the list.\n");
    }

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SIZE 100

typedef struct Node {
    char name[MAX_SIZE];
    struct Node* next;
} Node;

pthread_t thread_id;

Node* head = NULL;

void insert(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void search(char* name) {
    Node* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %s\n", temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("Not found: %s\n", name);
}

void delete(char* name) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Not found: %s\n", name);
}

int main() {
    insert("John Doe");
    insert("Jane Doe");
    insert("Peter Pan");

    search("Jane Doe");
    delete("Peter Pan");

    search("Jane Doe");

    return 0;
}
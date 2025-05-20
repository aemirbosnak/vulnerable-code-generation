//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Database {
    Node* head;
    int size;
};

void insert(struct Database* db, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (db->head == NULL) {
        db->head = newNode;
    } else {
        db->head->next = newNode;
    }

    db->size++;
}

void traverse(struct Database* db) {
    Node* current = db->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Database* db = malloc(sizeof(struct Database));
    db->head = NULL;
    db->size = 0;

    insert(db, 10);
    insert(db, 20);
    insert(db, 30);

    traverse(db);

    free(db);

    return 0;
}
//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Database {
    Node* head;
    int size;
};

void insert(struct Database* db, char data) {
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

void search(struct Database* db, char data) {
    Node* current = db->head;

    while (current) {
        if (current->data == data) {
            printf("Data found: %c\n", data);
            return;
        }

        current = current->next;
    }

    printf("Data not found: %c\n", data);
}

int main() {
    struct Database* db = malloc(sizeof(struct Database));
    db->head = NULL;
    db->size = 0;

    insert(db, 'a');
    insert(db, 'b');
    insert(db, 'c');
    insert(db, 'd');

    search(db, 'b');
    search(db, 'e');

    free(db);

    return 0;
}
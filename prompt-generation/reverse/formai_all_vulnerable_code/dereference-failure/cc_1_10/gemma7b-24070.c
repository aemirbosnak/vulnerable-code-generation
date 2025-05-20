//Gemma-7B DATASET v1.0 Category: Database querying ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 255

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Database {
    Node* head;
    int size;
} Database;

Database* createDatabase() {
    Database* db = malloc(sizeof(Database));
    db->head = NULL;
    db->size = 0;
    return db;
}

void insertNode(Database* db, char data) {
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

int queryDatabase(Database* db, char query) {
    Node* current = db->head;
    while (current) {
        if (current->data == query) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main() {
    Database* db = createDatabase();
    insertNode(db, 'a');
    insertNode(db, 'b');
    insertNode(db, 'c');

    if (queryDatabase(db, 'b') == 1) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    return 0;
}
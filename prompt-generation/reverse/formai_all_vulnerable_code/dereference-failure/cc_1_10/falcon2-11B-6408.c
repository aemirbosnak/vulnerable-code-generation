//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    int value;
    struct node *next;
} Node;

typedef struct database {
    Node *head;
    Node *tail;
    int size;
} Database;

Database* createDatabase() {
    Database *db = (Database*)malloc(sizeof(Database));
    if (db == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for database\n");
        exit(EXIT_FAILURE);
    }
    db->head = NULL;
    db->tail = NULL;
    db->size = 0;
    return db;
}

void insertKeyValue(Database *db, int key, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for node\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (db->head == NULL) {
        db->head = newNode;
        db->tail = newNode;
    } else {
        db->tail->next = newNode;
        db->tail = newNode;
    }
    db->size++;
}

void printDatabase(Database *db) {
    Node *current = db->head;
    while (current!= NULL) {
        printf("Key: %d, Value: %d\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    Database *db = createDatabase();
    if (db == NULL) {
        fprintf(stderr, "Error: Failed to create database\n");
        exit(EXIT_FAILURE);
    }

    insertKeyValue(db, 1, 10);
    insertKeyValue(db, 2, 20);
    insertKeyValue(db, 3, 30);

    printDatabase(db);

    return 0;
}
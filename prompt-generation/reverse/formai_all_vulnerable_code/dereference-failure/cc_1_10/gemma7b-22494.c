//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

struct Index {
    char key[MAX_SIZE];
    struct Node* node;
};

struct Database {
    struct Index** indices;
    int size;
};

void insert(struct Database* db, char* key, char* data) {
    int i = db->size++;
    db->indices = realloc(db->indices, (db->size) * sizeof(struct Index));
    db->indices[i] = malloc(sizeof(struct Index));
    strcpy(db->indices[i]->key, key);
    strcpy(db->indices[i]->node->data, data);
    db->indices[i]->node->next = NULL;
}

int search(struct Database* db, char* key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->indices[i]->key, key) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Database* db = malloc(sizeof(struct Database));
    db->size = 0;
    db->indices = NULL;

    insert(db, "John Doe", "123 Main St.");
    insert(db, "Jane Doe", "456 Oak Ave.");
    insert(db, "Bill Smith", "789 Oak St.");

    int index = search(db, "Jane Doe");
    if (index != -1) {
        printf("Data for Jane Doe: %s", db->indices[index]->node->data);
    } else {
        printf("Key not found");
    }

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Index {
    int key;
    int value;
    struct Index *next;
};

struct Database {
    struct Index *head;
};

struct Database *create_database() {
    struct Database *db = malloc(sizeof(struct Database));
    if (db == NULL) {
        return NULL;
    }
    db->head = NULL;
    return db;
}

void destroy_database(struct Database *db) {
    struct Index *current = db->head;
    while (current != NULL) {
        struct Index *next = current->next;
        free(current);
        current = next;
    }
    free(db);
}

bool insert_index(struct Database *db, int key, int value) {
    struct Index *new_index = malloc(sizeof(struct Index));
    if (new_index == NULL) {
        return false;
    }
    new_index->key = key;
    new_index->value = value;
    new_index->next = db->head;
    db->head = new_index;
    return true;
}

int get_value(struct Database *db, int key) {
    struct Index *current = db->head;
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

bool delete_index(struct Database *db, int key) {
    struct Index *current = db->head;
    struct Index *previous = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (previous == NULL) {
                db->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}

void print_database(struct Database *db) {
    struct Index *current = db->head;
    while (current != NULL) {
        printf("(%d, %d) ", current->key, current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Database *db = create_database();

    insert_index(db, 1, 10);
    insert_index(db, 2, 20);
    insert_index(db, 3, 30);
    insert_index(db, 4, 40);
    insert_index(db, 5, 50);

    print_database(db);

    printf("Value of key 3: %d\n", get_value(db, 3));

    delete_index(db, 2);

    print_database(db);

    destroy_database(db);

    return 0;
}
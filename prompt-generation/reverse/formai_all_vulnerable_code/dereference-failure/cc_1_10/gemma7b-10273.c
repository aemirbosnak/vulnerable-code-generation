//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a database structure
typedef struct Database {
    char **data;
    int size;
    int capacity;
} Database;

// Function to create a new database
Database *createDatabase(int capacity) {
    Database *db = malloc(sizeof(Database));
    db->data = NULL;
    db->size = 0;
    db->capacity = capacity;

    return db;
}

// Function to insert data into the database
int insertData(Database *db, char *data) {
    if (db->size >= db->capacity) {
        return -1;
    }

    db->data = realloc(db->data, (db->size + 1) * sizeof(char *));
    db->data[db->size++] = data;

    return 0;
}

// Function to search for data in the database
char *searchData(Database *db, char *key) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->data[i], key) == 0) {
            return db->data[i];
        }
    }

    return NULL;
}

int main() {
    Database *db = createDatabase(10);

    insertData(db, "John Doe");
    insertData(db, "Jane Doe");
    insertData(db, "Peter Pan");

    char *data = searchData(db, "Jane Doe");

    if (data) {
        printf("Data: %s\n", data);
    } else {
        printf("Data not found.\n");
    }

    return 0;
}
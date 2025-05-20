//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Index structure
struct index {
    int key;
    int value;
};

// Database structure
struct database {
    int size;
    struct index *indexes;
};

// Create a new database
struct database *create_database() {
    struct database *db = malloc(sizeof(struct database));
    db->size = 0;
    db->indexes = malloc(0);
    return db;
}

// Insert a new record into the database
void insert_record(struct database *db, int key, int value) {
    // Check if the key already exists
    for (int i = 0; i < db->size; i++) {
        if (db->indexes[i].key == key) {
            db->indexes[i].value = value;
            return;
        }
    }

    // Add the new record to the database
    db->size++;
    db->indexes = realloc(db->indexes, sizeof(struct index) * db->size);
    db->indexes[db->size - 1].key = key;
    db->indexes[db->size - 1].value = value;
}

// Get the value of a record from the database
int get_record(struct database *db, int key) {
    // Check if the key exists
    for (int i = 0; i < db->size; i++) {
        if (db->indexes[i].key == key) {
            return db->indexes[i].value;
        }
    }

    // The key was not found
    return -1;
}

// Delete a record from the database
void delete_record(struct database *db, int key) {
    // Check if the key exists
    int index = -1;
    for (int i = 0; i < db->size; i++) {
        if (db->indexes[i].key == key) {
            index = i;
            break;
        }
    }

    // If the key was not found, do nothing
    if (index == -1) {
        return;
    }

    // Remove the record from the database
    for (int i = index; i < db->size - 1; i++) {
        db->indexes[i] = db->indexes[i + 1];
    }

    db->size--;
    db->indexes = realloc(db->indexes, sizeof(struct index) * db->size);
}

// Print the database
void print_database(struct database *db) {
    printf("Database:\n");
    for (int i = 0; i < db->size; i++) {
        printf("%d: %d\n", db->indexes[i].key, db->indexes[i].value);
    }
}

// Destroy the database
void destroy_database(struct database *db) {
    free(db->indexes);
    free(db);
}

int main() {
    // Create a new database
    struct database *db = create_database();

    // Insert some records into the database
    insert_record(db, 1, 10);
    insert_record(db, 2, 20);
    insert_record(db, 3, 30);

    // Print the database
    print_database(db);

    // Get the value of a record from the database
    int value = get_record(db, 2);
    printf("The value of record 2 is %d\n", value);

    // Delete a record from the database
    delete_record(db, 2);

    // Print the database again
    print_database(db);

    // Destroy the database
    destroy_database(db);

    return 0;
}
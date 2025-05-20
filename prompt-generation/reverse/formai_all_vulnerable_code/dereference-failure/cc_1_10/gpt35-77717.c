//FormAI DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing data in the index.
typedef struct {
    int key;
    char value[50];
} Index;

// Define the structure for the database to be indexed.
typedef struct {
    int size;
    char name[50];
    int* data;
} Database;

// Define the function to add data to a database.
void add_data(Database* db, int value) {
    // Increase the size of the database.
    db->size++;

    // Reallocate memory for the new data.
    db->data = (int*) realloc(db->data, db->size * sizeof(int));

    // Add the new data to the end of the database.
    db->data[db->size - 1] = value;
}

// Define the function to create a new index.
Index create_index(int key, char* value) {
    Index ind;
    ind.key = key;
    strcpy(ind.value, value);
    return ind;
}

// Define the function to add an index to the index list.
void add_index(Index* index_list, int* index_count, Index ind) {
    // Increase the index count.
    *index_count++;
    // Reallocate memory for the new index.
    index_list = (Index*) realloc(index_list, *index_count * sizeof(Index));
    // Add the new index to the end of the index list.
    index_list[*index_count - 1] = ind;
}

int main() {
    // Create a new database.
    Database db;
    db.size = 0;
    strcpy(db.name, "My Database");
    db.data = NULL;

    // Add some data to the database.
    add_data(&db, 5);
    add_data(&db, 10);
    add_data(&db, 15);
    add_data(&db, 20);
    add_data(&db, 25);

    // Create a new index list.
    Index* index_list = NULL;
    int index_count = 0;

    // Loop through the data in the database and create an index for each value.
    for (int i = 0; i < db.size; i++) {
        add_index(index_list, &index_count, create_index(i, "My Value"));
    }

    // Print the contents of the database.
    printf("Database: %s\n", db.name);
    printf("Data: ");
    for (int i = 0; i < db.size; i++) {
        printf("%d ", db.data[i]);
    }
    printf("\n");

    // Print the contents of the index list.
    printf("Index List:\n");
    for (int i = 0; i < index_count; i++) {
        printf("Key: %d, Value: %s\n", index_list[i].key, index_list[i].value);
    }

    // Free memory allocated for the database and index list.
    free(db.data);
    free(index_list);

    return 0;
}
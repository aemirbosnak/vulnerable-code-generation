//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the database structure
typedef struct {
    int id;
    char *name;
    char *email;
    char *phone;
} record;

// Create a new database
record *create_database() {
    record *db = malloc(sizeof(record) * 100);
    for (int i = 0; i < 100; i++) {
        db[i].id = i;
        db[i].name = NULL;
        db[i].email = NULL;
        db[i].phone = NULL;
    }
    return db;
}

// Insert a new record into the database
void insert_record(record *db, int id, char *name, char *email, char *phone) {
    db[id].id = id;
    db[id].name = name;
    db[id].email = email;
    db[id].phone = phone;
}

// Print the database
void print_database(record *db) {
    for (int i = 0; i < 100; i++) {
        printf("%d %s %s %s\n", db[i].id, db[i].name, db[i].email, db[i].phone);
    }
}

// Delete a record from the database
void delete_record(record *db, int id) {
    db[id].id = -1;
    db[id].name = NULL;
    db[id].email = NULL;
    db[id].phone = NULL;
}

// Update a record in the database
void update_record(record *db, int id, char *name, char *email, char *phone) {
    db[id].name = name;
    db[id].email = email;
    db[id].phone = phone;
}

// Search for a record in the database
int search_record(record *db, char *name) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(db[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {
    // Create a new database
    record *db = create_database();

    // Insert some records into the database
    insert_record(db, 0, "John Smith", "john.smith@example.com", "555-1212");
    insert_record(db, 1, "Jane Doe", "jane.doe@example.com", "555-1213");
    insert_record(db, 2, "Bill Jones", "bill.jones@example.com", "555-1214");

    // Print the database
    print_database(db);

    // Delete a record from the database
    delete_record(db, 1);

    // Update a record in the database
    update_record(db, 2, "Bill Johnson", "bill.johnson@example.com", "555-1215");

    // Search for a record in the database
    int index = search_record(db, "Bill Johnson");
    if (index != -1) {
        printf("Found record: %d %s %s %s\n", db[index].id, db[index].name, db[index].email, db[index].phone);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}
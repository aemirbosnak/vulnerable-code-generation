//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a record in the database
typedef struct {
    char name[50];
    int age;
    char address[100];
} Record;

// Function to insert a record into the database
void insert_record(Record *db, int size, Record rec) {
    if (size == 0) {
        db[0] = rec;
    } else {
        for (int i = 0; i < size - 1; i++) {
            db[i + 1] = db[i];
        }
        db[size - 1] = rec;
    }
}

// Function to search for a record in the database
Record* search_record(Record *db, int size, char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(db[i].name, name) == 0) {
            return &db[i];
        }
    }
    return NULL;
}

// Function to print the entire database
void print_database(Record *db, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s, Age: %d, Address: %s\n", db[i].name, db[i].age, db[i].address);
    }
}

int main() {
    // Create an empty database
    Record *db = (Record*)malloc(sizeof(Record));
    int size = 0;

    // Insert some records into the database
    Record rec1 = {"John Doe", 25, "123 Main St"};
    insert_record(db, size, rec1);
    Record rec2 = {"Jane Smith", 30, "456 Elm St"};
    insert_record(db, size, rec2);
    Record rec3 = {"Bob Johnson", 35, "789 Oak St"};
    insert_record(db, size, rec3);

    // Print the entire database
    printf("Database:\n");
    print_database(db, size);

    // Search for a record in the database
    Record *result = search_record(db, size, "Jane Smith");
    if (result!= NULL) {
        printf("Found record: Name: %s, Age: %d, Address: %s\n", result->name, result->age, result->address);
    } else {
        printf("Record not found\n");
    }

    free(db);
    return 0;
}
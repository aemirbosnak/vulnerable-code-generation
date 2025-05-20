//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: shocked
// ** SHOCKING DATABASE SIMULATION ** //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define database structure
typedef struct {
    char name[50];
    int age;
} person;

// Define array to store database
person db[10];

// Function to insert data into database
void insert_data(person *db, int size) {
    int i;
    for (i = 0; i < size; i++) {
        // Generate random name and age
        sprintf(db[i].name, "Person %d", i);
        db[i].age = (rand() % 50) + 1;
    }
}

// Function to retrieve data from database
void retrieve_data(person *db, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d - %s\n", db[i].age, db[i].name);
    }
}

// Function to update data in database
void update_data(person *db, int size) {
    int i;
    for (i = 0; i < size; i++) {
        // Generate random new age
        int new_age = (rand() % 50) + 1;
        db[i].age = new_age;
    }
}

// Function to delete data from database
void delete_data(person *db, int size) {
    int i;
    for (i = 0; i < size; i++) {
        // Randomly select record to delete
        int delete_idx = (rand() % size);
        memmove(db + delete_idx, db + delete_idx + 1, (size - delete_idx) * sizeof(person));
        size--;
    }
}

int main() {
    // Initialize database with 10 records
    insert_data(db, 10);

    // Retrieve data from database
    retrieve_data(db, 10);

    // Update data in database
    update_data(db, 10);

    // Delete data from database
    delete_data(db, 10);

    return 0;
}
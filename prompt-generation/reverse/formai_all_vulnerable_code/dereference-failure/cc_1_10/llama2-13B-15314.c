//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: surprised
// Oh my gosh, I can't believe it! A database simulation program!? 😱

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for our database records
typedef struct {
    int id;
    char name[50];
    char email[50];
} record_t;

// Define the maximum number of records we can store
#define MAX_RECORDS 100

// Define a function to insert a new record into the database
void insert_record(record_t* records, int* num_records, const char* name, const char* email) {
    // Oh my gosh, we're getting a new record! 😮
    record_t new_record = {0};
    strcpy(new_record.name, name);
    strcpy(new_record.email, email);
    // Add the new record to the end of the array
    *num_records += 1;
    records = realloc(records, sizeof(record_t) * *num_records);
    records[*num_records - 1] = new_record;
}

// Define a function to retrieve all the records from the database
void print_all_records(record_t* records, int num_records) {
    // Oh my gosh, we're printing all the records! 😲
    for (int i = 0; i < num_records; i++) {
        printf("%d - %s - %s\n", records[i].id, records[i].name, records[i].email);
    }
}

int main() {
    // Create an array to store our records
    record_t* records = malloc(sizeof(record_t) * MAX_RECORDS);
    int num_records = 0;

    // Insert some records into the database
    insert_record(records, &num_records, "Alice", "alice@example.com");
    insert_record(records, &num_records, "Bob", "bob@example.com");
    insert_record(records, &num_records, "Charlie", "charlie@example.com");

    // Print all the records from the database
    print_all_records(records, num_records);

    // Free the memory allocated for the records
    free(records);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DATABASE_NAME "my_database.db"
#define MAX_RECORDS 100

// Structure to hold a single record
typedef struct {
    int id;
    char name[50];
    char email[50];
} record_t;

// Function to create a new record
record_t *new_record(int id, char *name, char *email) {
    record_t *record = malloc(sizeof(record_t));
    record->id = id;
    strcpy(record->name, name);
    strcpy(record->email, email);
    return record;
}

// Function to read a record from the database
record_t *read_record(int id) {
    // Open the database file in read-only mode
    int fd = open(DATABASE_NAME, O_RDONLY);
    if (fd == -1) {
        perror("Error opening database file");
        return NULL;
    }

    // Seek to the record with the given ID
    lseek(fd, (id - 1) * sizeof(record_t), SEEK_SET);

    // Read the record from the database
    record_t *record = malloc(sizeof(record_t));
    read(fd, record, sizeof(record_t));

    // Close the database file
    close(fd);

    return record;
}

// Function to write a record to the database
void write_record(int id, char *name, char *email) {
    // Open the database file in write-only mode
    int fd = open(DATABASE_NAME, O_RDWR);
    if (fd == -1) {
        perror("Error opening database file");
        return;
    }

    // Seek to the record with the given ID
    lseek(fd, (id - 1) * sizeof(record_t), SEEK_SET);

    // Write the record to the database
    record_t *record = malloc(sizeof(record_t));
    record->id = id;
    strcpy(record->name, name);
    strcpy(record->email, email);
    write(fd, record, sizeof(record_t));

    // Close the database file
    close(fd);
}

int main() {
    // Create some records
    record_t *record1 = new_record(1, "John", "john@example.com");
    record_t *record2 = new_record(2, "Jane", "jane@example.com");
    record_t *record3 = new_record(3, "Bob", "bob@example.com");

    // Write the records to the database
    write_record(1, "John", "john@example.com");
    write_record(2, "Jane", "jane@example.com");
    write_record(3, "Bob", "bob@example.com");

    // Read the records from the database
    record_t *record1_from_db = read_record(1);
    record_t *record2_from_db = read_record(2);
    record_t *record3_from_db = read_record(3);

    // Print the records
    printf("Record 1: %d, %s, %s\n", record1->id, record1->name, record1->email);
    printf("Record 2: %d, %s, %s\n", record2->id, record2->name, record2->email);
    printf("Record 3: %d, %s, %s\n", record3->id, record3->name, record3->email);

    // Free the memory allocated for the records
    free(record1);
    free(record2);
    free(record3);

    return 0;
}
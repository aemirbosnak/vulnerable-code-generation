//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define DATABASE_SIZE 10000
#define RECORD_SIZE 50

// Structure to represent a record in the database
typedef struct {
    char name[50];
    char address[50];
    int age;
} record_t;

// Function to create a new record in the database
void insert_record(record_t *record) {
    // Open the database file in write mode
    int fd = open("database.dat", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening database file");
        return;
    }

    // Allocate memory for the record using mmap
    void *addr = mmap(NULL, RECORD_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Error mapping record");
        close(fd);
        return;
    }

    // Copy the record into the memory mapped region
    memcpy(addr, record, RECORD_SIZE);

    // Unlock the memory mapped region
    munmap(addr, RECORD_SIZE);

    // Close the database file
    close(fd);
}

// Function to search for a record in the database
record_t *search_record(char *name) {
    // Open the database file in read mode
    int fd = open("database.dat", O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening database file");
        return NULL;
    }

    // Allocate memory for the record using mmap
    void *addr = mmap(NULL, RECORD_SIZE, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Error mapping record");
        close(fd);
        return NULL;
    }

    // Search for the record in the memory mapped region
    for (int i = 0; i < DATABASE_SIZE; i++) {
        record_t *record = (record_t *)(addr + i * RECORD_SIZE);
        if (strcmp(record->name, name) == 0) {
            // Found the record, return it
            return record;
        }
    }

    // Not found, return NULL
    return NULL;
}

int main() {
    // Create some records and insert them into the database
    record_t record1 = {"Alice", "123 Main St", 25};
    record_t record2 = {"Bob", "456 Elm St", 30};
    record_t record3 = {"Charlie", "789 Oak St", 35};
    insert_record(&record1);
    insert_record(&record2);
    insert_record(&record3);

    // Search for a record by name
    record_t *found = search_record("Alice");
    if (found != NULL) {
        printf("Found record: %s %s %d\n", found->name, found->address, found->age);
    } else {
        printf("Record not found\n");
    }

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_RECORDS 1000
#define RECORD_SIZE 50

// Structure to represent a record
typedef struct {
    char name[50];
    int age;
} record_t;

// Function to create a database file
void create_db(const char *filename) {
    // Open the file in write-only mode
    int fd = open(filename, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error creating database file");
        exit(1);
    }

    // Allocate memory for the database
    size_t size = MAX_RECORDS * RECORD_SIZE;
    void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED) {
        perror("Error allocating memory for database");
        exit(1);
    }

    // Fill the database with some sample records
    for (int i = 0; i < MAX_RECORDS; i++) {
        record_t *rec = (record_t *)((char *)mem + i * RECORD_SIZE);
        strcpy(rec->name, "Person ");
        rec->age = i % 2 == 0 ? 25 : 35;
    }

    // Unmap the memory
    munmap(mem, size);

    // Close the file
    close(fd);
}

// Function to read a record from the database
record_t *read_record(const char *filename) {
    // Open the file in read-only mode
    int fd = open(filename, O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening database file");
        exit(1);
    }

    // Allocate memory for the record
    size_t size = RECORD_SIZE;
    void *mem = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED) {
        perror("Error allocating memory for record");
        exit(1);
    }

    // Read the record
    record_t *rec = (record_t *)mem;
    return rec;
}

// Function to write a record to the database
void write_record(const char *filename, record_t *rec) {
    // Open the file in write-only mode
    int fd = open(filename, O_RDWR, 0644);
    if (fd == -1) {
        perror("Error opening database file");
        exit(1);
    }

    // Allocate memory for the record
    size_t size = RECORD_SIZE;
    void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mem == MAP_FAILED) {
        perror("Error allocating memory for record");
        exit(1);
    }

    // Write the record
    *(record_t *)mem = *rec;

    // Unmap the memory
    munmap(mem, size);

    // Close the file
    close(fd);
}

int main() {
    // Create a sample database file
    create_db("sample_db.dat");

    // Read a record from the database
    record_t *rec = read_record("sample_db.dat");
    printf("Name: %s, Age: %d\n", rec->name, rec->age);

    // Write a new record to the database
    record_t new_rec = {"John", 30};
    write_record("sample_db.dat", &new_rec);

    // Read the updated database
    rec = read_record("sample_db.dat");
    printf("Name: %s, Age: %d\n", rec->name, rec->age);

    return 0;
}
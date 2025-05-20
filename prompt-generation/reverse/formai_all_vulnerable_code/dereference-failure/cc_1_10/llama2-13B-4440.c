//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#define DB_NAME "my_database"
#define DB_SIZE 1000

// Structure to hold a record in the database
typedef struct {
    char name[50];
    char email[50];
} record_t;

// Function to create the database file
void create_db(void) {
    // Create the database file
    int fd = open(DB_NAME, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error creating database file");
        exit(1);
    }

    // Set the size of the database file
    ftruncate(fd, DB_SIZE);

    // Map the database file into memory
    void* addr = mmap(NULL, DB_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Error mapping database file into memory");
        exit(1);
    }

    // Set the database file pointer
    record_t* db = (record_t*)addr;

    // Fill the database with some data
    for (int i = 0; i < DB_SIZE / sizeof(record_t); i++) {
        strcpy(db[i].name, "Person");
        strcpy(db[i].email, "person@example.com");
    }

    // Unmap the database file from memory
    munmap(addr, DB_SIZE);

    close(fd);
}

// Function to read data from the database
void read_db(void) {
    // Open the database file
    int fd = open(DB_NAME, O_RDONLY, 0644);
    if (fd == -1) {
        perror("Error opening database file");
        exit(1);
    }

    // Map the database file into memory
    void* addr = mmap(NULL, DB_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Error mapping database file into memory");
        exit(1);
    }

    // Set the database file pointer
    record_t* db = (record_t*)addr;

    // Print out the data in the database
    for (int i = 0; i < DB_SIZE / sizeof(record_t); i++) {
        printf("%s %s\n", db[i].name, db[i].email);
    }

    // Unmap the database file from memory
    munmap(addr, DB_SIZE);

    close(fd);
}

// Function to write data to the database
void write_db(void) {
    // Open the database file
    int fd = open(DB_NAME, O_RDWR, 0644);
    if (fd == -1) {
        perror("Error opening database file");
        exit(1);
    }

    // Map the database file into memory
    void* addr = mmap(NULL, DB_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Error mapping database file into memory");
        exit(1);
    }

    // Set the database file pointer
    record_t* db = (record_t*)addr;

    // Overwrite the data in the database
    for (int i = 0; i < DB_SIZE / sizeof(record_t); i++) {
        strcpy(db[i].name, "New Person");
        strcpy(db[i].email, "new_person@example.com");
    }

    // Unmap the database file from memory
    munmap(addr, DB_SIZE);

    close(fd);
}

int main(void) {
    // Create the database
    create_db();

    // Read data from the database
    read_db();

    // Write data to the database
    write_db();

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define DATABASE_SIZE 1024
#define MAX_RECORDS 100
#define RECORD_SIZE 512

struct record {
    char name[50];
    int age;
    char address[100];
};

int main() {
    // Create a shared memory segment for the database
    key_t key = IPC_PRIVATE;
    size_t size = DATABASE_SIZE;
    void *shm_addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, -1, 0);
    if (shm_addr == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Create a file to store the database records
    int fd = open("database.dat", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open() failed");
        munmap(shm_addr, size);
        return 1;
    }

    // Write the database header to the file
    char header[100];
    sprintf(header, "Database header\n");
    write(fd, header, strlen(header));

    // Read the database header from the shared memory
    char *shm_header = (char *)shm_addr;
    if (strcmp(shm_header, "Database header\n") != 0) {
        fprintf(stderr, "Invalid database header\n");
        close(fd);
        munmap(shm_addr, size);
        return 1;
    }

    // Allocate memory for the database records
    struct record *records = (struct record *)calloc(MAX_RECORDS, sizeof(struct record));
    if (records == NULL) {
        perror("calloc() failed");
        close(fd);
        munmap(shm_addr, size);
        return 1;
    }

    // Read the database records from the shared memory
    char *shm_records = (char *)(shm_addr + strlen(shm_header) + 1);
    for (int i = 0; i < MAX_RECORDS; i++) {
        struct record *record = records + i;
        char *record_ptr = shm_records + (i * RECORD_SIZE);
        sscanf(record_ptr, "%s %d %s", record->name, &record->age, record->address);
    }

    // Write the database records to the file
    for (int i = 0; i < MAX_RECORDS; i++) {
        struct record *record = records + i;
        write(fd, record, RECORD_SIZE);
    }

    // Close the file and unmap the shared memory
    close(fd);
    munmap(shm_addr, size);

    return 0;
}
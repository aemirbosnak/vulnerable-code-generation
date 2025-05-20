//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIZE 1000000
#define BLOCK 64
#define FILENAME "benchmark.dat"

typedef struct {
    int id;
    char name[50];
} Person;

void generate_data(Person* data) {
    for (int i = 0; i < SIZE; i++) {
        sprintf(data[i].name, "Person %d", i);
        data[i].id = i;
    }
}

void write_file(Person* data) {
    int fd = open(FILENAME, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    size_t size = SIZE * sizeof(Person);
    void* addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }

    memcpy(addr, data, size);
    msync(addr, size, MS_SYNC);
    close(fd);

    munmap(addr, size);
}

void read_file(Person* data) {
    int fd = open(FILENAME, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    size_t size = SIZE * sizeof(Person);
    void* addr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);

    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }

    memcpy(data, addr, size);
    msync(addr, size, MS_SYNC);
    close(fd);

    munmap(addr, size);
}

int main() {
    srand(time(NULL));
    Person* data = malloc(SIZE * sizeof(Person));

    generate_data(data);
    write_file(data);

    Person* read_data = malloc(SIZE * sizeof(Person));
    read_file(read_data);

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(data[i].name, read_data[i].name) != 0) {
            fprintf(stderr, "Data is corrupted!\n");
            free(data);
            free(read_data);
            exit(EXIT_FAILURE);
        }
    }

    printf("Data is correct!\n");

    for (int i = 0; i < SIZE; i++) {
        free(data + i);
    }
    free(data);
    free(read_data);

    sleep(1); // Just for fun, let's make the program wait for a second before exiting
    return EXIT_SUCCESS;
}
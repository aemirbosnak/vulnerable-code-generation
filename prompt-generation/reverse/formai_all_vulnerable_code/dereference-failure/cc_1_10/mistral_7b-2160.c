//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>
#include <signal.h>

#define MAX_LINE_LEN 256
#define EPHEMERAL_FILE "/tmp/ephemeral.dat"

typedef struct Ephemeral {
    int id;
    char name[MAX_LINE_LEN];
    char description[MAX_LINE_LEN];
} Ephemeral;

void create_ephemeral(Ephemeral* ephemeral) {
    int fd = open(EPHEMERAL_FILE, O_CREAT | O_RDWR | O_EXCL, 0644);

    if (fd < 0) {
        perror("Failed to create ephemeral file.");
        exit(EXIT_FAILURE);
    }

    memset(ephemeral, 0, sizeof(Ephemeral));
    ephemeral->id = getpid();

    if (write(fd, ephemeral, sizeof(Ephemeral)) != sizeof(Ephemeral)) {
        perror("Failed to write ephemeral data.");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

Ephemeral* read_ephemeral() {
    int fd = open(EPHEMERAL_FILE, O_RDONLY);

    if (fd < 0) {
        perror("Failed to open ephemeral file.");
        exit(EXIT_FAILURE);
    }

    size_t size = sizeof(Ephemeral);
    Ephemeral* ephemeral = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);

    if (ephemeral == MAP_FAILED) {
        perror("Failed to map ephemeral data.");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return ephemeral;
}

void print_ephemeral(Ephemeral* ephemeral) {
    printf("ID: %d\n", ephemeral->id);
    printf("Name: %s\n", ephemeral->name);
    printf("Description: %s\n", ephemeral->description);
}

void signal_handler(int signal) {
    printf("Caught signal %d, deleting ephemeral data...\n", signal);

    Ephemeral* ephemeral = read_ephemeral();
    unlink(EPHEMERAL_FILE);
    munmap((void*)ephemeral, sizeof(Ephemeral));

    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    Ephemeral* ephemeral = malloc(sizeof(Ephemeral));
    create_ephemeral(ephemeral);

    strcpy(ephemeral->name, "A creative ephemeral example");
    strcpy(ephemeral->description, "A random program that creates an ephemeral file and writes some data to it, then reads it back and prints it before deleting the file.");

    printf("Created ephemeral data:\n");
    print_ephemeral(ephemeral);

    free(ephemeral);

    sleep(5);

    printf("Deleting ephemeral data...\n");
}
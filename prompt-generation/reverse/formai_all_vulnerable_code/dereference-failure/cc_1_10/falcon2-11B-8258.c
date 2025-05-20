//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

// Structure to hold the memory information
struct MemoryInfo {
    char* filename;
    int fd;
    char* text;
    int text_size;
    char* data;
    int data_size;
    char* mapped;
    int mapped_size;
    int status;
};

// Function to read memory information from file
void readMemoryInfo(struct MemoryInfo* mi) {
    // Read file into memory
    char* buf = NULL;
    size_t buf_len = 0;
    int ret = 0;

    ret = read(mi->fd, &buf_len, sizeof(size_t));
    if (ret == -1) {
        perror("read");
        exit(1);
    }

    buf = malloc(buf_len);
    if (buf == NULL) {
        perror("malloc");
        exit(1);
    }

    ret = read(mi->fd, buf, buf_len);
    if (ret == -1) {
        perror("read");
        exit(1);
    }

    mi->text = buf;
    mi->text_size = buf_len;
}

// Function to print memory information
void printMemoryInfo(struct MemoryInfo* mi) {
    printf("File: %s\n", mi->filename);
    printf("Text Size: %d\n", mi->text_size);
    printf("Data Size: %d\n", mi->data_size);
    printf("Mapped Size: %d\n", mi->mapped_size);
}

// Function to set the status of the memory information
void setMemoryStatus(struct MemoryInfo* mi, int status) {
    mi->status = status;
}

// Function to update the memory information
void updateMemoryInfo(struct MemoryInfo* mi) {
    // Read memory information from file
    readMemoryInfo(mi);

    // Print memory information
    printMemoryInfo(mi);

    // Set status
    setMemoryStatus(mi, 0);
}

// Function to handle SIGUSR1 signal
void handler(int sig) {
    struct MemoryInfo mi;

    // Open file
    int fd = open("memory.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    mi.filename = "memory.txt";
    mi.fd = fd;

    // Read memory information
    readMemoryInfo(&mi);

    // Update memory information
    updateMemoryInfo(&mi);

    // Close file
    close(fd);
}

// Function to check for memory leak
void checkMemoryLeak() {
    struct MemoryInfo mi;

    // Open file
    int fd = open("memory.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    mi.filename = "memory.txt";
    mi.fd = fd;

    // Read memory information
    readMemoryInfo(&mi);

    // Update memory information
    updateMemoryInfo(&mi);

    // Close file
    close(fd);
}

// Main function
int main(int argc, char* argv[]) {
    // Register signal handler
    struct sigaction sa;
    sa.sa_handler = handler;
    sigaction(SIGUSR1, &sa, NULL);

    // Check for memory leak
    checkMemoryLeak();

    return 0;
}
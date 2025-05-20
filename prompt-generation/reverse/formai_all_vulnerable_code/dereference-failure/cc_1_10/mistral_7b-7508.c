//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/sysinfo.h>

#define HEAP_SIZE (1024*1024)
#define BUFFER_SIZE (1024)
#define FILENAME "/tmp/ram_usage.log"
#define STAMP_SIZE 32

struct ram_usage {
    struct stat file_stat;
    unsigned long long used_ram;
    unsigned long long total_ram;
    char stamp[STAMP_SIZE];
};

void log_ram_usage(struct stat file_stat, unsigned long long used_ram, unsigned long long total_ram) {
    struct ram_usage usage;
    usage.file_stat = file_stat;
    usage.used_ram = used_ram;
    usage.total_ram = total_ram;
    strftime(usage.stamp, STAMP_SIZE, "%Y-%m-%d %H:%M:%S", localtime(NULL));

    int fd = open(FILENAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }

    if (write(fd, &usage, sizeof(struct ram_usage)) != sizeof(struct ram_usage)) {
        perror("Failed to write to log file");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

int main() {
    unsigned char *heap = mmap(NULL, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (heap == MAP_FAILED) {
        perror("Failed to allocate heap");
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    if (stat("/dev/shm", &file_stat) != 0) {
        perror("Failed to get size of /dev/shm");
        exit(EXIT_FAILURE);
    }

    unsigned long long total_ram = file_stat.st_size;
    unsigned long long used_ram = (unsigned long long) (heap - (unsigned char *) 0);

    log_ram_usage(file_stat, used_ram, total_ram);

    for (unsigned long long i = 0; i < HEAP_SIZE; ++i) {
        heap[i] = i % 255;
    }

    struct stat new_file_stat;
    if (stat("/dev/shm", &new_file_stat) != 0) {
        perror("Failed to get new size of /dev/shm");
        exit(EXIT_FAILURE);
    }

    used_ram = (unsigned long long) (new_file_stat.st_size - file_stat.st_size);
    log_ram_usage(new_file_stat, used_ram, total_ram);

    munmap(heap, HEAP_SIZE);

    return EXIT_SUCCESS;
}
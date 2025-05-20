//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RAM_SIZE 1024 * 1024 // 1 MB
#define BUF_SIZE 1024
#define FILENAME "/tmp/ramusage.txt"

volatile size_t used_memory = 0;
char *ram_buffer;

void init_ram_buffer() {
    int fd = open(FILENAME, O_CREAT | O_TRUNC | O_RDWR, 0644);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    ram_buffer = mmap(NULL, RAM_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (ram_buffer == MAP_FAILED) {
        perror("Error mapping memory");
        exit(1);
    }

    close(fd);
}

void print_ram_usage() {
    printf("\nRAM Usage:\n");
    printf("-----------\n");
    printf("Total RAM: %ld bytes\n", RAM_SIZE);
    printf("Used RAM: %ld bytes\n", used_memory);
    printf("Free RAM: %ld bytes\n", RAM_SIZE - used_memory);
    printf("Percentage: %.2f%%\n", ((float)used_memory / (float)RAM_SIZE) * 100);
}

void usage(char *msg) {
    if (msg != NULL)
        fprintf(stderr, "%s\n", msg);

    fprintf(stderr, "Usage: %s [init|print|exit]\n", __FILE__);
}

int main(int argc, char **argv) {
    int command = 0;

    if (argc < 2)
        usage(NULL);

    command = strcmp(argv[1], "init");
    if (command == 0) {
        init_ram_buffer();
        used_memory = 0;
        printf("RAM initialized successfully.\n");
    } else if (command == 1) {
        print_ram_usage();
    } else if (command == 2) {
        size_t read_bytes = write(fileno(stdout), ram_buffer, used_memory);
        if (read_bytes < 0) {
            perror("Error writing to stdout");
            exit(1);
        }
        used_memory = 0;
        printf("RAM data dumped to stdout.\n");
    } else {
        usage("Invalid command.");
    }

    return 0;
}
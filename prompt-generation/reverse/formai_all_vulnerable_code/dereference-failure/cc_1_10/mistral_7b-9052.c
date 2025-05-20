//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define BINARY_MAGIC_NUMBER 0xDEADBEEF
#define BINARY_HEADER_SIZE 16
#define BINARY_DATA_START 16
#define BINARY_DATA_END (sizeof(char) * 100000)

typedef struct binary_header {
    unsigned int magic_number;
    unsigned int header_size;
    unsigned int data_size;
} binary_header;

void signal_handler(int sig) {
    printf("You pressed Ctrl+C. Exiting gracefully...\n");
    exit(EXIT_SUCCESS);
}

bool binary_is_valid(void* binary_data) {
    binary_header* header = (binary_header*) binary_data;
    return header->magic_number == BINARY_MAGIC_NUMBER && header->header_size == BINARY_HEADER_SIZE;
}

int main() {
    signal(SIGINT, signal_handler);

    int binary_file_fd = open("binary_file.bin", O_RDWR);
    if (binary_file_fd < 0) {
        perror("Error opening binary file");
        exit(EXIT_FAILURE);
    }

    size_t binary_file_size = lseek(binary_file_fd, 0, SEEK_END);
    lseek(binary_file_fd, 0, SEEK_SET);

    char* binary_data = mmap(NULL, binary_file_size, PROT_READ | PROT_WRITE, MAP_SHARED, binary_file_fd, 0);
    if (binary_data == MAP_FAILED) {
        perror("Error mapping binary data to memory");
        exit(EXIT_FAILURE);
    }

    if (!binary_is_valid(binary_data)) {
        printf("Invalid binary file.\n");
        munmap(binary_data, binary_file_size);
        close(binary_file_fd);
        exit(EXIT_FAILURE);
    }

    binary_header* header = (binary_header*) binary_data;

    printf("Magic Number: 0x%x\n", header->magic_number);
    printf("Header Size: %d bytes\n", header->header_size);
    printf("Data Size: %d bytes\n", header->data_size);

    if (header->data_size > BINARY_DATA_END - BINARY_DATA_START) {
        printf("Binary data size is too large.\n");
        munmap(binary_data, binary_file_size);
        close(binary_file_fd);
        exit(EXIT_FAILURE);
    }

    char binary_data_start[BINARY_DATA_START];
    memcpy(binary_data_start, binary_data + BINARY_HEADER_SIZE, BINARY_DATA_START);

    printf("Binary Data (first %d bytes):\n", BINARY_DATA_START);
    for (int i = 0; i < BINARY_DATA_START; ++i) {
        printf("%.2X ", binary_data_start[i]);
    }
    printf("\n");

    munmap(binary_data, binary_file_size);
    close(binary_file_fd);

    return EXIT_SUCCESS;
}
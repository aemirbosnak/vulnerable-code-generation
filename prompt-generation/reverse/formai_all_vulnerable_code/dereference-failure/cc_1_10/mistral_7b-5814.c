//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <endian.h>

typedef struct {
    char magic[4];
    uint32_t num_entries;
    uint32_t entry_size;
} binary_header;

typedef struct {
    uint32_t address;
    uint32_t size;
} binary_entry;

void signal_handler(int signum) {
    printf("\n[!] Received SIGINT. Exiting gracefully...\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "[!] Usage: %s <binary_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    signal(SIGINT, signal_handler);

    const char *binary_file = argv[1];

    int fd = open(binary_file, O_RDONLY);
    if (fd < 0) {
        perror("[!] Failed to open binary file");
        return EXIT_FAILURE;
    }

    off_t file_size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    binary_header header;
    read(fd, &header, sizeof(binary_header));

    if (memcmp(header.magic, "BINAR", 5) != 0) {
        fprintf(stderr, "[!] File is not a valid binary file\n");
        close(fd);
        return EXIT_FAILURE;
    }

    uint32_t num_entries = be32toh(header.num_entries);
    uint32_t entry_size = be32toh(header.entry_size);

    binary_entry *entries = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (entries == MAP_FAILED) {
        perror("[!] Failed to map binary file to memory");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("[*] Parsed binary file successfully.\n");
    printf("[*] Processing binary entries...\n");

    for (uint32_t i = 0; i < num_entries; i++) {
        binary_entry entry = entries[i];
        printf("[%2d] Address: 0x%08X, Size: 0x%08X\n", i + 1, be32toh(entry.address), be32toh(entry.size));
    }

    munmap(entries, file_size);
    close(fd);

    return EXIT_SUCCESS;
}
//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
// My Unique Metadata Extractor (MUME)
// By: Cool Coder (cool.coder@coolcoding.com)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE (1024*1024)
#define HEADER_MAGIC "MUME"
#define METADATA_SIZE 100

typedef struct metadata_s {
    char name[50];
    int value;
} metadata_t;

void print_usage() {
    printf("Usage: %s <input_file>\n", "MyUniqueMetadataExtractor.out");
}

int main(int argc, char *argv[]) {
    int fd, ret;
    void *map_base;
    size_t file_size;
    metadata_t *metadata;

    if (argc != 2) {
        print_usage();
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file.");
        return 1;
    }

    file_size = lseek(fd, 0, SEEK_END);
    if (file_size > MAX_FILE_SIZE) {
        printf("File size too big.\n");
        close(fd);
        return 1;
    }

    map_base = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    if (map_base == MAP_FAILED) {
        perror("Error mapping file.");
        return 1;
    }

    if (memcmp(map_base, HEADER_MAGIC, 4) != 0) {
        printf("Invalid file format.\n");
        munmap(map_base, file_size);
        return 1;
    }

    metadata = (metadata_t *)((char *)map_base + 4);

    printf("Extracted metadata:\n");
    for (int i = 0; i < METADATA_SIZE; i++) {
        printf("Name: %s, Value: %d\n", metadata[i].name, metadata[i].value);
        for (int j = 0; j < strlen(metadata[i].name); j++) {
            putchar(toupper(metadata[i].name[j]));
        }
        putchar('\n');
    }

    munmap(map_base, file_size);
    return 0;
}
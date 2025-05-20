//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define STRLEN(x) (sizeof(x)/sizeof(x[0]))

const char *magic = "MTEP"; // Metadata Extractor Program Magic Number
const int header_size = 4;

typedef struct {
    int size;
    char name[32];
} metadata_entry;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("Error getting file stats");
        close(fd);
        return 1;
    }

    char *buf = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buf == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        return 1;
    }

    if (strncmp((char *)buf, magic, header_size) != 0) {
        printf("Error: file is not a Metadata Extractor file\n");
        munmap(buf, st.st_size);
        close(fd);
        return 1;
    }

    metadata_entry *entries = (metadata_entry *)((char *)buf + header_size);
    int num_entries = st.st_size / sizeof(metadata_entry) - 1;

    printf("Surprising Metadata Extractor Results:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s, Size: %d\n", entries[i].name, entries[i].size);
        if (strcmp(entries[i].name, "Surprise!") == 0) {
            printf("A surprise entry was found!\n");
            printf("Size: %d\n", entries[i].size);
            void *surprise_data = (void *)((char *)buf + sizeof(metadata_entry) * i + header_size);
            printf("Data:");
            for (int j = 0; j < entries[i].size; j++) {
                printf("%c", ((char *)surprise_data)[j]);
            }
            printf("\n");
        }
    }

    munmap(buf, st.st_size);
    close(fd);

    return 0;
}
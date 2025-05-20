//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define SIGNATURE_SIZE 16
#define SECTOR_SIZE 512
#define BLOCK_SIZE 4096
#define NUM_SIGS 5

typedef struct {
    char signature[SIGNATURE_SIZE];
    off_t offset;
} Signature;

Signature sigs[NUM_SIGS] = {{"JAva VaRiAns", 0}, {"SusPicIoUs_FiLe", 0}, {"mAlWaRe", 0}, {"wOrM_lOadEr", 0}, {"tROJaN_hOrSe", 0}};

int scan_file(char *filename) {
    int i, j;
    off_t file_size;
    int fd;
    char *map_base;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    fseek(fd, 0, SEEK_END);
    file_size = ftell(fd);
    close(fd);

    fd = open(filename, O_RDONLY);
    map_base = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    for (i = 0; i < NUM_SIGS; i++) {
        for (j = 0; j < file_size - SIGNATURE_SIZE; j += SECTOR_SIZE) {
            if (memcmp(&map_base[j], sigs[i].signature, SIGNATURE_SIZE) == 0) {
                sigs[i].offset = j;
                break;
            }
        }
        if (sigs[i].offset != 0) break;
    }

    munmap(map_base, file_size);

    if (i == NUM_SIGS) return 0;

    printf("Suspicious file found:\n%s\nOffset: %llu\n", filename, sigs[i].offset);

    return 1;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    if (scan_file(argv[1])) exit(1);

    for (i = 0; i < NUM_SIGS; i++) if (sigs[i].offset != 0) break;

    if (i == NUM_SIGS) printf("File is clean.\n");

    return 0;
}
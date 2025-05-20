//MISTRAL-7B DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define VIRUS_SIG "EVIL_VIRUS"
#define VIRUS_SIZE 5

typedef struct {
    char signature[VIRUS_SIZE];
    int size;
    int location;
} VirusSignature;

VirusSignature signatures[] = {
    {"EVIL_VIRUS", 5, 0xDEADBEEF},
    {"MAL_WORM", 6, 0xCAFEBABE},
    {"TROJAN_HORSE", 11, 0x1337C0DE}
};

void scan_file(char *filename) {
    int fd, i;
    struct stat file_stat;
    char *file_map;

    if (stat(filename, &file_stat) < 0) {
        perror("Error statting file");
        return;
    }

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    file_map = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    for (i = 0; i < sizeof(signatures) / sizeof(VirusSignature); i++) {
        int j;
        for (j = 0; j < signatures[i].size && file_map[signatures[i].location + j] == signatures[i].signature[j]; j++);
        if (j == signatures[i].size) {
            printf("%s: Virus detected!\n", filename);
            exit(1);
        }
        signatures[i].location += j + 1;
    }

    munmap(file_map, file_stat.st_size);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_to_scan>\n", argv[0]);
        exit(1);
    }

    scan_file(argv[1]);

    return 0;
}
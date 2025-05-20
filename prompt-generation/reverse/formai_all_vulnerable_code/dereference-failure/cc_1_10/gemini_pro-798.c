//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define PAGE_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filepath>\n", argv[0]);
        exit(1);
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    void *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    char *buf = malloc(PAGE_SIZE);
    if (buf == NULL) {
        perror("malloc");
        exit(1);
    }

    int i;
    for (i = 0; i < st.st_size; i += PAGE_SIZE) {
        memcpy(buf, map + i, PAGE_SIZE);
        if (memcmp(buf, "virus", 5) == 0) {
            printf("Virus detected at offset %d\n", i);
            break;
        }
    }

    free(buf);
    munmap(map, st.st_size);
    close(fd);

    return 0;
}
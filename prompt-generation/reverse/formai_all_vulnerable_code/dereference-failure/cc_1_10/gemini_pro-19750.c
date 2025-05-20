//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024 * 1024

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    if (st.st_size > MAX_FILE_SIZE) {
        printf("File is too large to scan\n");
        exit(EXIT_FAILURE);
    }

    char *buf = malloc(st.st_size);
    if (buf == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (read(fd, buf, st.st_size) != st.st_size) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(fd);

    // Scan the file
    int i;
    for (i = 0; i < st.st_size; i++) {
        if (buf[i] == 0x00) {
            printf("Found a null byte at offset %d\n", i);
        }
    }

    free(buf);

    return 0;
}
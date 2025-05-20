//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define VIRUS_SIG "MALWARE"

typedef struct {
    char *name;
    size_t size;
    char *data;
} file_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    struct stat st;
    if (stat(filename, &st) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    file_t file;
    file.size = st.st_size;
    file.data = malloc(file.size);
    if (file.data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (read(fd, file.data, file.size) != file.size) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(fd);

    char *ptr = file.data;
    while (ptr < file.data + file.size) {
        if (memcmp(ptr, VIRUS_SIG, strlen(VIRUS_SIG)) == 0) {
            printf("Virus detected!\n");
            return EXIT_FAILURE;
        }
        ptr++;
    }

    printf("No virus detected.\n");
    return EXIT_SUCCESS;
}
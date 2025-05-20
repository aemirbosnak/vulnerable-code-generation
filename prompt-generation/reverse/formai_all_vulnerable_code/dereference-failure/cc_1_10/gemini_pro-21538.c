//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SECTOR_SIZE 512

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <output-filename>\n", argv[0]);
        return 1;
    }

    // Open the input file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get the file size
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return 1;
    }

    // Allocate a buffer to hold the file data
    char *buffer = malloc(st.st_size);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    // Read the file into the buffer
    if (read(fd, buffer, st.st_size) != st.st_size) {
        perror("read");
        return 1;
    }

    // Close the input file
    close(fd);

    // Open the output file
    fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Write the data from the buffer to the output file
    if (write(fd, buffer, st.st_size) != st.st_size) {
        perror("write");
        return 1;
    }

    // Close the output file
    close(fd);

    // Free the buffer
    free(buffer);

    return 0;
}
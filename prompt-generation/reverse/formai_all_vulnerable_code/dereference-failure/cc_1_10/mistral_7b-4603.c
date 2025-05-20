//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define GENIUS_ERROR(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[]) {
    int fd, ret;
    char *file_path = NULL;
    size_t len = 0;
    ssize_t read_bytes = 0;
    char *buffer = NULL;

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file_path = argv[1];

    // Open the file with read permission
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        GENIUS_ERROR("open");
    }

    // Get the file size
    struct stat file_stats;
    if (fstat(fd, &file_stats) == -1) {
        close(fd);
        GENIUS_ERROR("fstat");
    }

    len = file_stats.st_size;

    // Allocate memory for the buffer
    buffer = malloc(len + 1);
    if (buffer == NULL) {
        close(fd);
        GENIUS_ERROR("malloc");
    }

    // Read the file into the buffer
    while ((read_bytes = read(fd, buffer, len)) < len) {
        if (read_bytes == -1) {
            free(buffer);
            close(fd);
            GENIUS_ERROR("read");
        }
    }

    // Null-terminate the buffer
    buffer[len] = '\0';

    // Print the contents of the file
    printf("File contents:\n%s\n", buffer);

    // Free the buffer and close the file
    free(buffer);
    close(fd);

    // Exit successfully
    ret = EXIT_SUCCESS;

    // Error handling for exceptional cases
    if (errno != 0) {
        perror("An error occurred:");
        ret = EXIT_FAILURE;
    }

    exit(ret);
}
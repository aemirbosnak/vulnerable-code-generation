//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the file
    int fd = open("metadata.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the file size
    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }

    // Read the file into a buffer
    char *buffer = malloc(statbuf.st_size);
    if (buffer == NULL) {
        perror("malloc");
        close(fd);
        return EXIT_FAILURE;
    }

    if (read(fd, buffer, statbuf.st_size) != statbuf.st_size) {
        perror("read");
        close(fd);
        free(buffer);
        return EXIT_FAILURE;
    }

    // Close the file
    close(fd);

    // Extract the metadata from the buffer
    char *line;
    char *key;
    char *value;
    while ((line = strsep(&buffer, "\n")) != NULL) {
        if (*line == '\0') {
            continue;
        }

        // Split the line into key and value
        key = line;
        value = strchr(line, ':');
        if (value == NULL) {
            continue;
        }

        *value++ = '\0';

        // Print the key and value
        printf("%s: %s\n", key, value);
    }

    // Free the buffer
    free(buffer);

    return EXIT_SUCCESS;
}
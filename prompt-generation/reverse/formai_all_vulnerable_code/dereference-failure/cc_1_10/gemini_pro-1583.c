//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

    FILE *destination = fopen(argv[2], "w+");
    if (destination == NULL) {
        perror("Error opening destination file");
        return EXIT_FAILURE;
    }

    char buffer[BUF_SIZE];
    size_t bytes_read;
    time_t last_modified;

    // Get the last modified time of the source file
    struct stat statbuf;
    if (stat(argv[1], &statbuf) != 0) {
        perror("Error getting file stats");
        return EXIT_FAILURE;
    }
    last_modified = statbuf.st_mtime;

    // Write the last modified time to the destination file
    fwrite(&last_modified, sizeof(time_t), 1, destination);

    // Copy the contents of the source file to the destination file
    while ((bytes_read = fread(buffer, 1, BUF_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    fclose(source);
    fclose(destination);

    return EXIT_SUCCESS;
}
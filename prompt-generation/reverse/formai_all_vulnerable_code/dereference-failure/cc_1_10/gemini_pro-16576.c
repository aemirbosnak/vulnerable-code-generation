//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open source file
    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Open destination file
    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Create buffer
    char buffer[BUF_SIZE];

    // Copy file
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUF_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    // Close files
    fclose(source);
    fclose(destination);

    // Get current time
    time_t now = time(NULL);

    // Get file modification time
    struct stat statbuf;
    if (stat(argv[2], &statbuf) != 0) {
        perror("stat");
        return EXIT_FAILURE;
    }

    // Check if file was modified after backup
    if (statbuf.st_mtime > now) {
        fprintf(stderr, "File was modified after backup. Backup may be incomplete.\n");
        return EXIT_FAILURE;
    }

    // Success
    return EXIT_SUCCESS;
}
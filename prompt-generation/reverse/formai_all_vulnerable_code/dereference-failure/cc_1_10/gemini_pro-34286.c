//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

// Paranoid error checking macro
#define PARANOID_CHECK(condition, message) do { \
    if (!(condition)) { \
        fprintf(stderr, "Error: %s\n", message); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

// Extract metadata from a file
int extract_metadata(const char *filename) {
    // Paranoid check if file exists
    struct stat file_info;
    PARANOID_CHECK(stat(filename, &file_info) == 0, "File does not exist");

    // Paranoid check if file is readable
    PARANOID_CHECK((file_info.st_mode & S_IRUSR) != 0, "File is not readable");

    // Open the file
    int fd = open(filename, O_RDONLY);
    PARANOID_CHECK(fd != -1, "Failed to open file");

    // Read the file contents into a buffer
    char *buffer = malloc(file_info.st_size + 1);
    PARANOID_CHECK(buffer != NULL, "Failed to allocate memory");

    ssize_t bytes_read = read(fd, buffer, file_info.st_size);
    PARANOID_CHECK(bytes_read == file_info.st_size, "Failed to read file contents");

    // Close the file
    close(fd);

    // Paranoid check if buffer is null-terminated
    buffer[file_info.st_size] = '\0';

    // Extract metadata from the buffer
    char *metadata = strstr(buffer, "<!-- Metadata: ");
    PARANOID_CHECK(metadata != NULL, "Metadata not found in file");

    metadata += strlen("<!-- Metadata: ");

    char *end_metadata = strchr(metadata, "-->");
    PARANOID_CHECK(end_metadata != NULL, "Invalid metadata format");

    *end_metadata = '\0';

    // Print the metadata
    printf("%s\n", metadata);

    // Free the buffer
    free(buffer);

    return 0;
}

int main(int argc, char *argv[]) {
    // Paranoid check if a filename is provided
    PARANOID_CHECK(argc == 2, "Usage: metadata_extractor <filename>");

    // Extract metadata from the file
    return extract_metadata(argv[1]);
}
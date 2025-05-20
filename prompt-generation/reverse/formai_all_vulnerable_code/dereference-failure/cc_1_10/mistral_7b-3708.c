//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE (1ULL << 30)

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <character>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char character = argv[2][0];
    int char_count = 0;

    int file_fd = open(filename, O_RDONLY);
    if (file_fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat file_stats;
    if (fstat(file_fd, &file_stats) < 0) {
        perror("Error getting file size");
        close(file_fd);
        return 1;
    }

    char *file_buffer;
    if ((file_buffer = malloc(file_stats.st_size)) == NULL) {
        perror("Error allocating memory for file buffer");
        close(file_fd);
        return 1;
    }

    ssize_t bytes_read = read(file_fd, file_buffer, file_stats.st_size);
    if (bytes_read < 0) {
        perror("Error reading file");
        free(file_buffer);
        close(file_fd);
        return 1;
    }

    char *buffer_start = file_buffer;
    while (buffer_start < file_buffer + bytes_read) {
        if (*buffer_start == character) {
            char_count++;
        }
        buffer_start++;
    }

    printf("Character '%c' occurs %d times in file '%s'\n", character, char_count, filename);

    free(file_buffer);
    close(file_fd);

    return 0;
}
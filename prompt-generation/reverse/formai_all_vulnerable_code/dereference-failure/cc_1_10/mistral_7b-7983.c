//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void reverse_file_contents(FILE *src, FILE *dest);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *source_file = fopen(argv[1], "r");
    if (!source_file) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

    FILE *destination_file = fopen(argv[2], "w");
    if (!destination_file) {
        perror("Error opening destination file");
        fclose(source_file);
        return EXIT_FAILURE;
    }

    reverse_file_contents(source_file, destination_file);
    fclose(source_file);
    fclose(destination_file);

    printf("File contents reversed successfully!\n");
    return EXIT_SUCCESS;
}

void reverse_file_contents(FILE *src, FILE *dest) {
    char buffer[BUFFER_SIZE];

    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src)) > 0) {
        size_t bytes_written = fwrite(&buffer[bytes_read - 1], sizeof(char), bytes_read, dest);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            fclose(src);
            fclose(dest);
            return;
        }
    }

    if (feof(src)) {
        if (ferror(src)) {
            perror("Error reading from source file");
            fclose(src);
            fclose(dest);
            return;
        }
    }
}
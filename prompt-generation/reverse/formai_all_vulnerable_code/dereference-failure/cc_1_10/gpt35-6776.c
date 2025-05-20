//FormAI DATASET v1.0 Category: System administration ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Function to check if a file exists
int file_exists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to create a directory
void create_dir(char *dirname) {
    if (mkdir(dirname, 0777) == -1) {
        printf("Error creating directory %s: %s\n", dirname, strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        printf("Successfully created directory %s\n", dirname);
    }
}

// Function to copy a file
void copy_file(char *source, char *destination) {
    FILE *source_file = fopen(source, "rb");
    FILE *destination_file = fopen(destination, "wb");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (source_file == NULL) {
        printf("Error opening source file %s: %s\n", source, strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (destination_file == NULL) {
        printf("Error opening destination file %s: %s\n", destination, strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file))) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("Successfully copied file %s to %s\n", source, destination);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [source file] [destination file/directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source = argv[1];
    char *destination = argv[2];

    // Check if source file exists
    if (!file_exists(source)) {
        printf("Error: Source file %s does not exist\n", source);
        exit(EXIT_FAILURE);
    }

    // Check if destination file/directory exists
    if (file_exists(destination)) {
        printf("Error: Destination file/directory %s already exists\n", destination);
        exit(EXIT_FAILURE);
    }

    // If destination is a directory, create it and copy the file inside
    if (destination[strlen(destination) - 1] == '/') {
        create_dir(destination);
        char *filename = strrchr(source, '/');
        char *new_destination = (char *)malloc(strlen(destination) + strlen(filename) + 1);
        strcpy(new_destination, destination);
        strcat(new_destination, filename);
        copy_file(source, new_destination);
        free(new_destination);
    } else {
        copy_file(source, destination);
    }

    return 0;
}
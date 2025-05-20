//Falcon-180B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// Function prototypes
void handle_error(char* msg);
void read_file(char* filename, char** buffer, size_t* size);
void write_file(char* filename, char* buffer, size_t size);

int main(int argc, char** argv) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <message>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* message = argv[3];

    char* buffer = NULL;
    size_t size = 0;

    read_file(input_file, &buffer, &size);

    if (buffer == NULL) {
        handle_error("Error reading input file");
        return 1;
    }

    if (size == 0) {
        handle_error("Input file is empty");
        return 1;
    }

    char* new_message = malloc(strlen(message) + strlen(buffer) + 2);
    if (new_message == NULL) {
        handle_error("Memory allocation error");
        return 1;
    }

    strcpy(new_message, message);
    strcat(new_message, " ");
    strcat(new_message, buffer);

    write_file(output_file, new_message, strlen(new_message));

    free(buffer);
    free(new_message);

    return 0;
}

void handle_error(char* msg) {
    perror(msg);
    exit(1);
}

void read_file(char* filename, char** buffer, size_t* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    rewind(file);

    *buffer = malloc(*size + 1);
    if (*buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    size_t bytes_read = fread(*buffer, 1, *size, file);
    if (bytes_read!= *size) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        exit(1);
    }

    (*buffer)[*size] = '\0';
}

void write_file(char* filename, char* buffer, size_t size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    size_t bytes_written = fwrite(buffer, 1, size, file);
    if (bytes_written!= size) {
        fprintf(stderr, "Error writing file: %s\n", strerror(errno));
        exit(1);
    }

    fclose(file);
}
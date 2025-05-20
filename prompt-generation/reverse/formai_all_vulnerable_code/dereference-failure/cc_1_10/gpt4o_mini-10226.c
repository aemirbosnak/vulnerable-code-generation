//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Custom error codes
typedef enum {
    ERR_OK = 0,
    ERR_FILE_NOT_FOUND,
    ERR_FILE_READ,
    ERR_FILE_WRITE,
    ERR_MEMORY_ALLOC,
    ERR_INVALID_ARGUMENT,
    ERR_UNKNOWN
} ErrorCode;

// Error handling structure
typedef struct {
    ErrorCode code;
    const char *message;
} Error;

// Function to create an error
Error create_error(ErrorCode code, const char *message) {
    Error err;
    err.code = code;
    err.message = message;
    return err;
}

// Function to print the error message
void handle_error(Error err) {
    if (err.code != ERR_OK) {
        fprintf(stderr, "Error (%d): %s\n", err.code, err.message);
        exit(err.code); // Exit with the error code
    }
}

// Function to read a file and return its content
char *read_file(const char *filename, Error *err) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        *err = create_error(ERR_FILE_NOT_FOUND, "File not found");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    
    // Perform memory allocation for file content
    char *buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        fclose(file);
        *err = create_error(ERR_MEMORY_ALLOC, "Memory allocation failed");
        return NULL;
    }

    size_t read_size = fread(buffer, 1, file_size, file);
    if (read_size != file_size) {
        free(buffer);
        fclose(file);
        *err = create_error(ERR_FILE_READ, "Failed to read the entire file");
        return NULL;
    }

    buffer[file_size] = '\0'; // Null-terminate the string
    fclose(file);
    *err = create_error(ERR_OK, "No errors");
    return buffer;
}

// Function to write content to a file
Error write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        return create_error(ERR_FILE_WRITE, "Failed to open file for writing");
    }

    size_t written_size = fwrite(content, sizeof(char), strlen(content), file);
    if (written_size != strlen(content)) {
        fclose(file);
        return create_error(ERR_FILE_WRITE, "Failed to write the entire content to file");
    }

    fclose(file);
    return create_error(ERR_OK, "No errors");
}

// Main function demonstrating file reading and writing
int main(int argc, char *argv[]) {
    if (argc != 3) {
        handle_error(create_error(ERR_INVALID_ARGUMENT, "Usage: ./file_handler <input_file> <output_file>"));
    }

    Error err;
    char *file_content = read_file(argv[1], &err);
    handle_error(err); // Check for read errors

    printf("Content read from '%s':\n%s\n", argv[1], file_content);

    // Write the same content to the output file
    Error write_err = write_file(argv[2], file_content);
    handle_error(write_err); // Check for write errors

    printf("Content written to '%s' successfully.\n", argv[2]);

    free(file_content); // Free the dynamically allocated memory
    return 0;
}
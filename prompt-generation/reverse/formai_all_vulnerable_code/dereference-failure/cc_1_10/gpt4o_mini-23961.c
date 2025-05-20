//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Define a macro for error handling
#define HANDLE_ERROR(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

// Function to read a file and return its content
char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        HANDLE_ERROR("Failed to open file");
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    char *content = malloc(filesize + 1);
    if (!content) {
        fclose(file);
        HANDLE_ERROR("Failed to allocate memory");
    }

    size_t read_size = fread(content, 1, filesize, file);
    if (read_size != filesize) {
        fclose(file);
        free(content);
        HANDLE_ERROR("Failed to read the complete file");
    }
    
    content[filesize] = '\0'; // Null-terminate the string
    fclose(file);
    
    return content;
}

// Function to handle string operations
void process_string(const char* str) {
    if (str == NULL) {
        fprintf(stderr, "Received NULL string for processing\n");
        return;
    }

    printf("Processing string: %s\n", str);
    
    // Example operation: Count characters
    size_t length = strlen(str);
    printf("Length: %zu characters\n", length);

    // Example operation: Convert to uppercase
    for (size_t i = 0; i < length; ++i) {
        putchar(toupper(str[i]));
    }
    putchar('\n');
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    char *file_content = read_file(filename);
    
    process_string(file_content);
    
    free(file_content);
    return EXIT_SUCCESS;
}
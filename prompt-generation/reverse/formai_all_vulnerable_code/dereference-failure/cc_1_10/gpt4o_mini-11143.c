//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

char* allocate_memory(size_t size) {
    char *ptr = (char*)malloc(size);
    if (ptr == NULL) {
        handle_error("Memory allocation failed");
    }
    return ptr;
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        handle_error("Could not open file");
    }

    char *buffer = allocate_memory(BUFFER_SIZE);
    
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        // Simulate processing each line
        if (buffer[0] == '\0') {
            fprintf(stderr, "Warning: Empty line encountered in file\n");
            continue;
        }
        
        // Just an example processing: print the line
        printf("Read line: %s", buffer);
    }

    if (ferror(file)) {
        free(buffer);
        fclose(file);
        handle_error("Error reading from file");
    }
    
    free(buffer);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_file(argv[1]);

    printf("File processing completed successfully.\n");
    return EXIT_SUCCESS;
}